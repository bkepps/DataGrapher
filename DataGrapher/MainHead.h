#pragma once
#include <SDL.h>
#include <stdio.h>
#include <Windows.h>
#include <math.h>

typedef struct {
	Uint32 numOfPoints;
	Uint8 updated;			//BOOL true after points is filled
	Uint8 run;				//BOOL true while Gather thread running
	Uint16 graphHeight;
	Uint16 graphWidth;
	SDL_Point* points;		//data points ready to be graphed
	Uint16* dataRaw;		//unprocessed data
	HANDLE port;			//handle for serial port --note: HANDLE is 4 bytes in size
	Uint16 valueMax;		//largest possible value from ADC
} gather_data;
//data.c
 void data_Gather(gather_data* data);

 int data_Process(gather_data* data);
//graph.c
 void graph_Update(gather_data* data, SDL_Renderer* ren);
//init.c
 gather_data* init_gather_data();

 int init_port(gather_data* data);
