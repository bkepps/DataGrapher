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