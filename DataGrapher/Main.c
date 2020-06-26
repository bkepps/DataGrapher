#include <SDL.h>
#include <stdio.h>

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
	Uint32 dataNumr = 0;							//counts data number being read
	FILE* data;				//data stored as chars terminated with \r, must have \r at end of last line
	SDL_Point* points = malloc(sizeof(SDL_Point) * 500);
	int datapoints[500];

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
			charRead = fread(file_rBuf, sizeof(char), 1, data);		//returns 0 when no chars left to read, will store one more point, we'll ignore it later
			if (*file_rBuf == '\r')
				end = 1;
			data_Buf[i++] = *file_rBuf;
		} while (!end);
		/*convert data_buf to int. atoi ignores \r at end of string*/
		datapoints[dataNumr] = atoi(data_Buf);
		points[dataNumr].y = *height - atoi(data_Buf);
		points[dataNumr].x = ++dataNumr;

	}


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


		SDL_RenderClear(ren);
		/*set the color of the points*/
		SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
		/*plot data points, but not last one since it's garbo*/
		SDL_RenderDrawPoints(ren, points, (dataNumr - 1));
		/*put the render color back to white*/
		SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
		SDL_RenderPresent(ren);
	}
	SDL_Quit();
	return 0;
}