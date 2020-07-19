// gathers one array of data from a serial port
#include "MainHead.h"

void data_Gather(data* grphInfo) {
	SDL_LockMutex(grphInfo->Mutex);
	char file_rBuf;
	char dataBuf[10];
	Uint8 end = 0;			//BOOL
	DWORD NumBytesRead;						// Bytes read by ReadFile()
	Uint16 i = 0;
	Uint16 j;
	int math;
	DWORD error;

	for (j = 0; j < grphInfo->numOfPoints; j++) {
		i = 0;
		end = 0;
		/*step through chars and append to data_rBuf until a return char is found. return char is last char in string*/
		do {
			math = ReadFile(grphInfo->port, &file_rBuf, sizeof(char), &NumBytesRead, NULL);		//returns 0 when no chars left to read, will store one more point, we'll ignore it later
			if (!math) {
				error = GetLastError();
				SDL_UnlockMutex(grphInfo->Mutex);
				return;
			}
			if (file_rBuf == '\n')
				end = 1;
			if (i == 10)				//prevent writing past bounds of dataBuf if no \r is reached -- this seems to occur if port is used too soon after initialization, it reads garbage until actual data is recieved
				break;
			dataBuf[i] = file_rBuf;
			i++;
		} while (!end);
		/*convert data_buf to int. atoi ignores \r at end of string*/
		//data->points[pointCurrent].y = data->graphHeight - (atoi(dataBuf) * ((float) data->graphHeight / (float) data->valueMax));
		//data->points[pointCurrent].x = pointCurrent;
		grphInfo->points[j].y = grphInfo->graphHeight - BitsNBobs_mapTo(atoi(dataBuf), 0, grphInfo->valueMax, 0, grphInfo->graphHeight);
		grphInfo->points[j].x = j;
		if (!NumBytesRead || i == 10)
			j--;
	}
	SDL_UnlockMutex(grphInfo->Mutex);
}