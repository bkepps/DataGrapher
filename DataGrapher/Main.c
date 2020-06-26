#include <SDL.h>
#include <stdio.h>

typedef struct {
	int sampleNum;								//sample # assosiated with data_voltage
	Uint16 rawVoltage;							//raw voltage from adc
	float voltage;								//voltage
} measurement;

int main() {
	int i = 0;
	const char* title = "Oscilloscope V0.0.0005";
	Uint32* width = malloc(sizeof(Uint32));
	Uint32* height = malloc(sizeof(Uint32));
	*width = 388;
	*height = 450;
	Uint8 quit = 0;			//BOOL
	Uint8 charRead = 1;		//BOOL, 0 when no chars left to read
	Uint8 end = 0;			//BOOL
	SDL_Event event;
	char* file_rBuf = malloc(sizeof(char));			//BUFFER, for reading one char from a file
	char* data_Buf = malloc(sizeof(char) * 5);		//BUFFER
	int* data_intBuf = malloc(sizeof(int));
	Uint16 dataNum = 0;
	measurement* data_processed = malloc(sizeof(measurement) * 500);	//array to store points, be sure it has enough space
	data_processed->sampleNum = 0;
	FILE* data;				//data stored as chars terminated with \r, must have \r at end of last line
#pragma warning(suppress : 4996)
	data = fopen("C:\\Users\\bensk\\data.txt", "r");
	if (data == NULL)
		return 1;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, *width, *height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	Uint32* windowID = malloc(sizeof(Uint32));
	*windowID = SDL_GetWindowID(win);

	while (charRead) {
		i = 0;
		end = 0;
		/*step through chars and append to data_rBuf until a return char is found. return char is last char in string*/
		do {
			charRead = fread(file_rBuf, sizeof(char), 1, data);

			if (*file_rBuf == '\r')
				end = 1;
			data_Buf[i++] = *file_rBuf;
		} while (!end);
		/*convert data_buf to int. atoi ignores \r at end of string, then convert 10-bit 5v adc output to a float voltage*/
		data_processed[dataNum].rawVoltage = atoi(data_Buf);
		data_processed[dataNum].voltage = (float)5 / ((float)1023 / (float)data_processed[dataNum].rawVoltage);



		data_processed[dataNum].sampleNum++;
	}

	SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
	SDL_RenderClear(ren);

	while (!quit) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit = 1;
				break;
			case SDL_WINDOWEVENT:
				switch (event.window.event) {
				case SDL_WINDOWEVENT_SIZE_CHANGED:
					*width = event.window.data1;
					*height = event.window.data2;

					/* update all elements who's position is changed by a window resize */

					break;
				}
				break;
			}
		}
		SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
		SDL_RenderClear(ren);

		SDL_RenderPresent(ren);
	}
	SDL_Quit();
	return 0;
}