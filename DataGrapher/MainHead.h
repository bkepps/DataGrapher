#pragma once
#include <SDL.h>
#include <SDL_quit.h>
#include <SDL_render.h>
#include <stdio.h>
#include <Windows.h>
#include <math.h>

/*
struct that stores one set of points and related data
*/
typedef struct {
	Uint32 numOfPoints;
	Uint16 graphHeight;
	Uint16 graphWidth;
	SDL_Point* points;		//data points ready to be graphed
	Uint16 valueMax;		//largest possible value from ADC
	SDL_mutex* Mutex;
} data_processed;

typedef struct {
	Uint32 numOfPoints;
	HANDLE port;
	SDL_mutex* Mutex;
	Uint16* rawData;
} data_raw;

/*
struct with all key elements of a slide selector
*/
typedef struct {
	Uint8 position;
	Uint8 numOfPositions;
	Uint16 spaceBetweenPositions;
	SDL_Rect slideRailRectangle;			//
	SDL_Rect sliderArrowRectangle;			//
	Uint8 move;								//BOOL
} Slider;

/*
contains all textures required
*/
typedef struct {
	SDL_Texture* sliderArrow;
	SDL_Texture* sliderRail;
} Textures;

//data.c
 void data_Gather(data_raw* data);

 int data_Process(data_raw* rawData, data_processed* processedData);

//graph.c
 void graph_Update(data_processed* data, SDL_Renderer* ren);

//init.c
 data_raw* init_data_raw(data_processed* processed_data);

 data_processed* init_data_processed();

 Slider* init_slider(Uint8 initPosition, Uint8 numOfPositions, Uint32 height, Uint32 upperLeftX, Uint32 upperLeftY);

 Textures* init_Textures(char* basePath, SDL_Renderer* ren);

 //Slider.c
 /*call to move slider, not necessarilly with mouse, it just needs a point*/
 int Slider_MoveWithMouse(SDL_Point, Slider*);

 int Slider_Render(SDL_Renderer*, Textures*, Slider*);
/*update position of slider on screen, for x or y give NULL if no update is desired*/
 Uint8 Slider_UpdatePosition(Uint32 upperLeftX, Uint32 upperLeftY, Slider* slide);
