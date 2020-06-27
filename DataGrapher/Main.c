#include <SDL.h>
#include <stdio.h>
#include <Windows.h>

int main() {
	int i = 0;
	float j;
	const char* title = "Data Plotter V1";
	Uint32 width = 380;
	Uint32 height = 700;
	Uint32 graphSizew = 380;
	Uint32 graphSizeh = 600;
	Uint8 quit = 0;			//BOOL
	Uint8 charRead = 1;		//BOOL, 0 when no chars left to read
	Uint8 end = 0;			//BOOL
	SDL_Event event;
	char* file_rBuf = malloc(sizeof(char));			//BUFFER, for reading one char from a file
	char* data_Buf = malloc(sizeof(char) * 5);		//BUFFER
	Uint32 dataNumr = 0;							//counts data number being read
	//FILE* data;				//data stored as chars terminated with \r, must have \r at end of last line
	SDL_Point* points = malloc(sizeof(SDL_Point) * 1000);
	int datapoints[1000];

	HANDLE hComm;							// Handle to the Serial port
	char  ComPortName[] = "\\\\.\\COM4";	// Name of the Serial port(May Change) to be opened,
	BOOL  Status;							// Status of the various operations 
	DWORD dwEventMask;						// Event mask to trigger
	char  TempChar;							// Temperory Character
	char  SerialBuffer[256];				// Buffer Containing Rxed Data
	DWORD NoBytesRead;						// Bytes read by ReadFile()

//#pragma warning(suppress : 4996)							// lets me use the unsafe version of fread()
	//data = fopen("C:\\Users\\bensk\\data.txt", "r");		//open file with points to read
	//if (data == NULL)
	//	return 1;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	Uint32* windowID = malloc(sizeof(Uint32));
	*windowID = SDL_GetWindowID(win);
	/*
	while (charRead) {
		i = 0;
		end = 0;
		/*step through chars and append to data_rBuf until a return char is found. return char is last char in string*//*
		do {
			charRead = fread(file_rBuf, sizeof(char), 1, data);		//returns 0 when no chars left to read, will store one more point, we'll ignore it later
			if (*file_rBuf == '\r')
				end = 1;
			data_Buf[i++] = *file_rBuf;
		} while (!end);
		/*convert data_buf to int. atoi ignores \r at end of string*//*
		datapoints[dataNumr] = atoi(data_Buf);
		points[dataNumr].y = height - atoi(data_Buf);
		points[dataNumr].x = ++dataNumr;
	}*/
	//free(file_rBuf);
	//free(data_Buf);
	//free(charRead);
	//free(data);

	/*open serial port*/
	hComm = CreateFile(L"COM4",                  // Name of the Port to be Opened
		GENERIC_READ | GENERIC_WRITE, // Read/Write Access
		0,                            // No Sharing, ports cant be shared
		NULL,                         // No Security
		OPEN_EXISTING,                // Open existing port only
		0,                            // Non Overlapped I/O
		NULL);                        // Null for Comm Devices

	if (hComm == INVALID_HANDLE_VALUE)
		return 1;
	DCB dcbSerialParams = { 0 };                         // Initializing DCB structure
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	Status = GetCommState(hComm, &dcbSerialParams);      //retreives  the current settings

	if (Status == FALSE)
		return 2;

	dcbSerialParams.BaudRate = CBR_9600;      // Setting BaudRate = 9600
	dcbSerialParams.ByteSize = 8;             // Setting ByteSize = 8
	dcbSerialParams.StopBits = ONESTOPBIT;    // Setting StopBits = 1
	dcbSerialParams.Parity = NOPARITY;        // Setting Parity = None 

	Status = SetCommState(hComm, &dcbSerialParams);  //Configuring the port according to settings in DCB 

	if (Status == FALSE)
	return 3;

	COMMTIMEOUTS timeouts = { 0 };
	timeouts.ReadIntervalTimeout = 50;
	timeouts.ReadTotalTimeoutConstant = 50;
	timeouts.ReadTotalTimeoutMultiplier = 10;
	timeouts.WriteTotalTimeoutConstant = 50;
	timeouts.WriteTotalTimeoutMultiplier = 10;

	if (SetCommTimeouts(hComm, &timeouts) == FALSE)
		return 4;

	while (!quit) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit = 1;
				break;
			case SDL_WINDOWEVENT:
				switch (event.window.event) {
				case SDL_WINDOWEVENT_SIZE_CHANGED:
					width = event.window.data1;
					height = event.window.data2;

					/* update all elements who's position is changed by a window resize */

					break;
				}
				break;
			}
			
		}

		NoBytesRead = 1;
		while (NoBytesRead) {
			i = 0;
			end = 0;
			/*step through chars and append to data_rBuf until a return char is found. return char is last char in string*/
			do {
				ReadFile(hComm, file_rBuf, sizeof(TempChar), &NoBytesRead, NULL);		//returns 0 when no chars left to read, will store one more point, we'll ignore it later
				if (*file_rBuf == '\r')
					end = 1;
				data_Buf[i++] = *file_rBuf;
			} while (!end);
			/*convert data_buf to int. atoi ignores \r at end of string*/
			if (!NoBytesRead)
				break;
			//datapoints[dataNumr] = atoi(data_Buf);
			points[dataNumr].y = graphSizeh - (atoi(data_Buf) / 2);
			points[dataNumr].x = ++dataNumr;
		}

		/*render everything*/
		SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
		SDL_RenderClear(ren);
		/*set color for grid*/
		SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
		/*creates horizontal lines about 50mV apart*/
		for (j = graphSizeh; j >= 0; j -= 10.23) {
			SDL_RenderDrawLine(ren, 0, j, (dataNumr - 1), j);
		}
		/*creates vertical lines 12 points (at 10 seconds per point, 2 minutes per line) apart*/
		for (i = 0; i <= (dataNumr - 1); i += 12) {
			SDL_RenderDrawLine(ren, i, 0, i, graphSizeh);
		}
		/*creates red vertical lines every 10 minutes at 6 samples per second*/
		SDL_SetRenderDrawColor(ren, 150, 150, 150, 255);
		for (i = 0; i <= (dataNumr - 1); i += 60) {
			SDL_RenderDrawLine(ren, i, 0, i, graphSizeh);
		}
		/*creates horizontal red line every 1V with 10-bit 0-5V adc*/
		for (j = graphSizeh; j >= 0; j -= 204.6) {
			SDL_RenderDrawLine(ren, 0, j, (dataNumr - 1), j);
		}
		/*set the color of the points*/
		SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
		/*plot data points and connect them, but not last one since it's garbo*/
		SDL_RenderDrawLines(ren, points, (dataNumr - 1));
		/*put the render color back to white*/

		SDL_RenderPresent(ren);
	}
	SDL_Quit();
	CloseHandle(hComm);//Closing the Serial Port
	return 0;
}