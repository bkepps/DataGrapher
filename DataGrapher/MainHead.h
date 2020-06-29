#pragma once
#include <SDL.h>
#include <stdio.h>
#include <Windows.h>

typedef struct {
	Uint32 numOfPoints;
	Uint8 updated;			//BOOL true after points is filled
	Uint8 run;				//BOOL true while Gather thread running
	SDL_Point* points;		
	HANDLE port;
} gather_data;

 void Gather(gather_data* data);