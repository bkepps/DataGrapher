#include "MainHead.h"

gather_data* init_gather_data() {
	gather_data* data = malloc(sizeof(gather_data));
	data->graphHeight = 400;
	data->graphWidth = 500;
	data->numOfPoints = data->graphWidth + 20;
	data->dataRaw = malloc(sizeof(Uint16) * data->numOfPoints);
	data->points = malloc(sizeof(SDL_Point) * data->graphWidth);
	data->updated = 0;
	data->run = 0;
	data->valueMax = 1023;

	return data;
}

int init_port(gather_data* data) {
	/*open serial port*/
	data->port = CreateFile(L"COM4",                  // Name of the Port to be Opened
		GENERIC_READ,							// Read Access
		0,                            // No Sharing, ports cant be shared
		NULL,                         // No Security
		OPEN_EXISTING,                // Open existing port only
		0,                            // Non Overlapped I/O
		NULL);                        // Null for Comm Devices

	if (data->port == INVALID_HANDLE_VALUE)
		return 1;
	DCB dcbSerialParams = { 0 };                         // Initializing DCB structure
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	GetCommState(data->port, &dcbSerialParams);      //retreives  the current settings

	dcbSerialParams.BaudRate = CBR_256000;      // Setting BaudRate = 9600
	dcbSerialParams.ByteSize = 8;             // Setting ByteSize = 8
	dcbSerialParams.StopBits = ONESTOPBIT;    // Setting StopBits = 1
	dcbSerialParams.Parity = NOPARITY;        // Setting Parity = None 

	SetCommState(data->port, &dcbSerialParams);  //Configuring the port according to settings in DCB 

	COMMTIMEOUTS timeouts = { 0 };
	timeouts.ReadIntervalTimeout = 50;
	timeouts.ReadTotalTimeoutConstant = 50;
	timeouts.ReadTotalTimeoutMultiplier = 10;
	timeouts.WriteTotalTimeoutConstant = 50;
	timeouts.WriteTotalTimeoutMultiplier = 10;

	if (SetCommTimeouts(data->port, &timeouts) == FALSE)
		return 4;
	return 0;
}

Slider* init_slider(Uint8 initPosition, Uint8 numOfPositions, Uint32 height, Uint32 upperLeftX, Uint32 upperLeftY) {
	Slider* slider = malloc(sizeof(Slider));
	slider->move = 0;
	slider->position = initPosition;
	slider->numOfPositions = numOfPositions;
	slider->spaceBetweenPositions = height / (slider->numOfPositions - 1);

	slider->slideRailRectangle.x = upperLeftX;
	slider->slideRailRectangle.y = upperLeftY;
	slider->slideRailRectangle.h = height;
	slider->slideRailRectangle.w = 8;

	slider->sliderArrowRectangle.h = 15;
	slider->sliderArrowRectangle.w = 20;
	slider->sliderArrowRectangle.x = slider->slideRailRectangle.x - (int)(slider->sliderArrowRectangle.w / 2);
	slider->sliderArrowRectangle.y = slider->slideRailRectangle.y + (slider->spaceBetweenPositions * slider->position) - (int)(slider->sliderArrowRectangle.h / 2);
	return slider;
}

Textures* init_Textures(char* basePath, SDL_Renderer *ren) {
	Textures* textures = malloc(sizeof(Textures));

	const char* returnedFilePath = BitsNBobs_append(basePath, "Resources\\SliderArrow.bmp");			//load arrow for sliders to texture
	SDL_Surface* sliderArrowsurf = SDL_LoadBMP(returnedFilePath);
	free(returnedFilePath);
	textures->sliderArrow = SDL_CreateTextureFromSurface(ren, sliderArrowsurf);
	SDL_FreeSurface(sliderArrowsurf);

	returnedFilePath = BitsNBobs_append(basePath, "Resources\\SliderRail.bmp");				//load rail arrow slides on
	SDL_Surface* sliderRailsurf = SDL_LoadBMP(returnedFilePath);
	free((void*)returnedFilePath);
	textures->sliderRail = SDL_CreateTextureFromSurface(ren, sliderRailsurf);
	SDL_FreeSurface(sliderRailsurf);

	return textures;
}