#include "MainHead.h"

void GraphUpdate(gather_data* data, SDL_Renderer* ren) {
	int j;

	SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
	/*creates horizontal lines about 50mV apart*/
	for (j = data->graphHeight; j >= 0; j -= 10.23) {
		SDL_RenderDrawLine(ren, 0, j, (data->numOfPoints), j);
	}
	/*creates darker horizontal line every 1V with 10-bit 0-5V adc*/
	for (j = data->graphHeight; j >= 0; j -= 204.6) {
		SDL_RenderDrawLine(ren, 0, j, (data->numOfPoints), j);
	}

	/*creates vertical lines 12 points apart*/
	for (j = 0; j <= (data->numOfPoints); j += 12) {
		SDL_RenderDrawLine(ren, j, 0, j, data->graphHeight);
	}
	/*creates darker vertical lines every 60 points*/
	SDL_SetRenderDrawColor(ren, 150, 150, 150, 255);
	for (j = 0; j <= (data->numOfPoints); j += 60) {
		SDL_RenderDrawLine(ren, j, 0, j, data->graphHeight);
	}


	/*set the color of the points*/
	SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
	/*plot data points and connect them*/
	SDL_RenderDrawLines(ren, data->points, (data->numOfPoints));

	data->updated = 0;
}