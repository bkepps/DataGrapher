#include "MainHead.h"

int main() {
	const char* title = "Data Plotter V2";
	Uint32 width = 800;
	Uint32 height = 700;
	Uint8 quit = 0;			//BOOL
	SDL_Event event;

	gather_data* data = init_gather_data();

	/*initialize SDL*/
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	Uint32* windowID = malloc(sizeof(Uint32));
	*windowID = SDL_GetWindowID(win);

	init_port(data);

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

			graph_Update(data, ren);
			SDL_RenderPresent(ren);
		}
		/*start new thread to update data points if gather thread is not running*/
		if(!data->run) {
			_beginthread(data_Gather, 0, data);
			data->run = 1;
		}

	}

	while (data->run)		//wait for gather thread to complete before quitting to avoid memory access error
		Sleep(10);

	SDL_Quit();
	CloseHandle(data->port);//Close the Serial Port
	return 0;
}