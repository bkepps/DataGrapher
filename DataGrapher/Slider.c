#include "MainHead.h"

int Slider_MoveWithMouse(SDL_Point mousePos, Slider* slide) {
	int randcalc;

	randcalc = (mousePos.y - slide->slideRailRectangle.y) / slide->spaceBetweenPositions;
	if (randcalc >= 0 && randcalc < slide->numOfPositions) {
		slide->position = randcalc;
	}
	else if (randcalc >= slide->numOfPositions) {
		slide->position = slide->numOfPositions - 1;
	}
	else if (randcalc < 0) {
		slide->position = 0;
	}
	/* set position of arrow on slider */
	slide->sliderArrowRectangle.y = 50 + (slide->spaceBetweenPositions * slide->position) - (.5 * slide->sliderArrowRectangle.h);
	return 0;
}

int Slider_Render(SDL_Renderer *ren, Textures* textures, Slider* slide) {

	SDL_RenderCopy(ren, textures->sliderRail, NULL, &(slide->slideRailRectangle));
	SDL_RenderCopy(ren, textures->sliderArrow, NULL, &(slide->sliderArrowRectangle));

	return 0;
}