#pragma once
#include <SDL.h>
#include <stdio.h>
#include <Windows.h>

typedef struct {
	Uint32 numOfPoints;
	Uint8 updated;			//BOOL true after points is filled
	Uint8 run;				//BOOL true while Gather thread running
	Uint16 graphHeight;
	Uint16 graphWidth;
	SDL_Point* points;		
	HANDLE port;			//handle for serial port --note: HANDLE is 4 bytes in size
} gather_data;

 void Gather(gather_data* data);

 void GraphUpdate(gather_data* data, SDL_Renderer* ren);