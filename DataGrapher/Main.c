#include "MainHead.h"

int main() {
	const char* title = "Data Plotter V2";
	Uint32 width = 800;
	Uint32 height = 700;
	Uint8 quit = 0;			//BOOL
	SDL_Event event;

	gather_data* data = malloc(sizeof(gather_data));
	data->graphHeight = 400;
	data->graphWidth = 500;
	data->numOfPoints = data->graphWidth + 20;
	data->points = malloc(sizeof(SDL_Point) * data->numOfPoints);
	data->updated = 0;
	data->run = 0;
	data->valueMax = 1023;


	/*initialize SDL*/
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	Uint32* windowID = malloc(sizeof(Uint32));
	*windowID = SDL_GetWindowID(win);

	/*open serial port*/
	data->port = CreateFile(L"COM4",                  // Name of the Port to be Opened
		GENERIC_READ,							// Read Access
		0,                            // No Sharing, ports cant be shared
		NULL,                         // No Security
		OPEN_EXISTING,                // Open existing port only
		0,                            // Non Overlapped I/O
		NULL);                        // Null for Comm Devices

	if (data->port == INVALID_HANDLE_VALUE)
		return 1;
	DCB dcbSerialParams = { 0 };                         // Initializing DCB structure
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	GetCommState(data->port, &dcbSerialParams);      //retreives  the current settings

	dcbSerialParams.BaudRate = CBR_256000;      // Setting BaudRate = 9600
	dcbSerialParams.ByteSize = 8;             // Setting ByteSize = 8
	dcbSerialParams.StopBits = ONESTOPBIT;    // Setting StopBits = 1
	dcbSerialParams.Parity = NOPARITY;        // Setting Parity = None 

	SetCommState(data->port, &dcbSerialParams);  //Configuring the port according to settings in DCB 

	COMMTIMEOUTS timeouts = { 0 };
	timeouts.ReadIntervalTimeout = 50;
	timeouts.ReadTotalTimeoutConstant = 50;
	timeouts.ReadTotalTimeoutMultiplier = 10;
	timeouts.WriteTotalTimeoutConstant = 50;
	timeouts.WriteTotalTimeoutMultiplier = 10;

	if (SetCommTimeouts(data->port, &timeouts) == FALSE)
		return 4;

	/*enter window loop*/
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

		/*update graph if data points have been updated / gather thread is complete*/
		if (data->updated) {

			/*render everything*/
			SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
			SDL_RenderClear(ren);

			GraphUpdate(data, ren);
			SDL_RenderPresent(ren);
		}
		/*start new thread to update data points if gather thread is not running*/
		if(!data->run) {
			_beginthread(Gather, 0, data);
			data->run = 1;
		}

	}

	while (data->run)		//wait for gather thread to complete before quitting to avoid memory access error
		Sleep(10);

	SDL_Quit();
	CloseHandle(data->port);//Close the Serial Port
	return 0;
}