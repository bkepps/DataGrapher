// gathers one array of data from a serial port
#include "MainHead.h"

void data_Gather(gather_data* data) {
	Uint32 pointCurrent = 0;
	char file_rBuf;
	char dataBuf[10];
	Uint8 end = 0;			//BOOL
	DWORD NumBytesRead;						// Bytes read by ReadFile()
	int i = 0;
	int math;

	

	for (pointCurrent = 0; pointCurrent < data->numOfPoints;) {
		i = 0;
		end = 0;
		/*step through chars and append to data_rBuf until a return char is found. return char is last char in string*/
		do {
			ReadFile(data->port, &file_rBuf, sizeof(char), &NumBytesRead, NULL);		//returns 0 when no chars left to read, will store one more point, we'll ignore it later
			if (file_rBuf == '\n')
				end = 1;
			if (i == 10)				//prevent writing past bounds of dataBuf if no \r is reached -- this seems to occur if port is used too soon after initialization, it reads garbage until actual data is recieved
				break;
			dataBuf[i] = file_rBuf;
			i++;
		} while (!end);
		/*convert data_buf to int. atoi ignores \r at end of string*/
		math = 
		data->points[pointCurrent].y = data->graphHeight - (atoi(dataBuf) * ((float) data->graphHeight / (float) data->valueMax));
		data->points[pointCurrent].x = pointCurrent++;
		if (!NumBytesRead || i == 10)
			--pointCurrent;
	}
	data->updated = 1;
	data->run = 0;



	//free(dataBuf);
	//free(file_rBuf);
}

int data_Process(gather_data* data) {
	
	return 0;
}