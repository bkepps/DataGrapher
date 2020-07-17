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
	Uint8 updated;			//BOOL true after points is filled
	Uint8 run;				//BOOL true after Gather thread has run
	Uint16 graphHeight;
	Uint16 graphWidth;
	SDL_Point* points;		//data points ready to be graphed
	Uint16* dataRaw;		//unprocessed data
	HANDLE port;			//handle for serial port --note: HANDLE is 4 bytes in size
	Uint16 valueMax;		//largest possible value from ADC
	SDL_mutex* dataMutex;
} gather_data;

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
 void data_Gather(gather_data* data);

 int data_Process(gather_data* data);

//graph.c
 void graph_Update(gather_data* data, SDL_Renderer* ren);

//init.c
 gather_data* init_gather_data();

 int init_port(gather_data* data);

 Slider* init_slider(Uint8 position, Uint8 numOfPositions, int height, int upperLeftX, int upperLeftY);

 Textures* init_Textures(char* basePath, SDL_Renderer* ren);

 //Slider.c
 /*call to move slider, not necessarilly with mouse, it just needs a point*/
 int Slider_MoveWithMouse(SDL_Point, Slider*);

 int Slider_Render(SDL_Renderer*, Textures*, Slider*);
/*update position of slider on screen, for x or y give NULL if no update is desired*/
 Uint8 Slider_UpdatePosition(Uint32 upperLeftX, Uint32 upperLeftY, Slider* slide);
