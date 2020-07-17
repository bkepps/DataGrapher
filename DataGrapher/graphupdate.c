/*draws graph with points to renderer when given gather_data* and SDL_Renderer*/
#include "MainHead.h"

void graph_Update(gather_data* data, SDL_Renderer* ren) {
	float j;
	int i;
	Uint16 hDiv10 = data->graphHeight / 10;
	Uint16 hDiv100 = data->graphHeight / 80;
	Uint16 wDiv10 = data->graphWidth / 10;
	Uint16 wDiv100 = data->graphWidth / 80;

	SDL_SetRenderDrawColor(ren, 220, 220, 220, 255);
	/*creates horizontal lines about 50mV apart*/
	for (j = data->graphHeight; j >= 0; j -= hDiv100) {
		SDL_RenderDrawLine(ren, 0, j, (data->graphWidth), j);
	}
	/*creates vertical lines 10 points apart*/
	for (i = 0; i <= (data->graphWidth); i += wDiv100) {
		SDL_RenderDrawLine(ren, i, 0, i, data->graphHeight);
	}

	SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
	/*creates darker horizontal line every 1V with 10-bit 0-5V adc*/
	for (j = data->graphHeight; j >= 0; j -= hDiv10) {
		SDL_RenderDrawLine(ren, 0, j, (data->graphWidth), j);
	}
	/*creates darker vertical lines every 50 points*/
	for (i = 0; i <= (data->graphWidth); i += wDiv10) {
		SDL_RenderDrawLine(ren, i, 0, i, data->graphHeight);
	}

	/*draw crosshairs*/
	SDL_SetRenderDrawColor(ren, 150, 150, 150, 255);
	SDL_RenderDrawLine(ren, 0, data->graphHeight / 2, data->graphWidth, data->graphHeight / 2);
	SDL_RenderDrawLine(ren, data->graphWidth / 2, 0, data->graphWidth / 2, data->graphHeight);

	/*set the color of the points*/
	SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
	/*plot data points and connect them*/
	SDL_RenderDrawLines(ren, data->points, (data->graphWidth));

	data->updated = 0;
}