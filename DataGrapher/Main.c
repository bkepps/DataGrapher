#include "MainHead.h"

int main() {
	const char* title = "Data Plotter V2";
	Uint32 width = 800;
	Uint32 height = 700;
	Uint8 quit = 0;			//BOOL
	Uint8 status = 0;		//BOOL
	SDL_Event event;
	SDL_Point mousePos;

	//variables to keep track of threads
	SDL_Thread* gatherThread;
	

	const char* basePath = SDL_GetBasePath();
	char* rBasePath = malloc(sizeof(char) * strlen(basePath));

	/*initialize SDL*/
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	Uint32* windowID = malloc(sizeof(Uint32));
	*windowID = SDL_GetWindowID(win);

	/*initialize structs and stuff*/
	Textures* textures = init_Textures(basePath, ren);		//load textures
	gather_data* data = init_gather_data();
	status = init_port(data);
	if (status)
		return status;

	/*initialize gui elements*/
	Slider* timeSlide = init_slider(0, 10, 200, (width - 50), 50);

	
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
					Slider_UpdatePosition(width - 50, NULL, timeSlide);
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT) {
					SDL_GetMouseState(&mousePos.x, &mousePos.y);
					/*if the left mouse button is pushed down while over the slider rail or arrow, begin slider move event*/
					if (SDL_PointInRect(&mousePos, &timeSlide->slideRailRectangle) || SDL_PointInRect(&mousePos, &timeSlide->sliderArrowRectangle))
						timeSlide->move = 1;
				}
				break;

			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT) {
					SDL_GetMouseState(&mousePos.x, &mousePos.y);
					/*if a slider motion event is occuring, and the mouse button goes up, end move event, and set final position*/
					if (timeSlide->move) {
						timeSlide->move = 0;
						Slider_MoveWithMouse(mousePos, timeSlide);
					}
				}
				break;

			case SDL_MOUSEMOTION:
				mousePos.y = event.motion.y;
				/*if slider move event is underway, have slider arrow follow the mouse*/
				if (timeSlide->move)
					Slider_MoveWithMouse(mousePos, timeSlide);
				break;
			}
			
		}
		if (!SDL_TryLockMutex(data->dataMutex)) {
			if (data->run) {
				SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
				SDL_RenderClear(ren);
				/*render any and all GUI elements other than graph*/
				Slider_Render(ren, textures, timeSlide);
				/*render graph*/
				//graph_Update(data, ren);
				//SDL_RenderPresent(ren);
			}
			SDL_UnlockMutex(data->dataMutex);
			gatherThread = SDL_CreateThread(data_Gather, "data_Gather", data);
			SDL_DetachThread(gatherThread);
		}
	}

		//wait for gather thread to complete before quitting to avoid memory access error

	SDL_Quit();
	CloseHandle(data->port);//Close the Serial Port
	return 0;
}