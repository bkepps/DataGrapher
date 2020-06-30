// gathers one array of data from a serial port
#include "MainHead.h"

void Gather(gather_data* data) {
	Uint32 pointCurrent = 0;
	char file_rBuf;
	char dataBuf[10];
	Uint8 end = 0;			//BOOL
	DWORD NoBytesRead;						// Bytes read by ReadFile()
	int i = 0;

	

	for (pointCurrent = 0; pointCurrent < data->numOfPoints;) {
		i = 0;
		end = 0;
		/*step through chars and append to data_rBuf until a return char is found. return char is last char in string*/
		do {
			ReadFile(data->port, &file_rBuf, sizeof(char), &NoBytesRead, NULL);		//returns 0 when no chars left to read, will store one more point, we'll ignore it later
			if (file_rBuf == '\r')
				end = 1;
			if (i == 10)				//prevent writing past bounds of dataBuf if no \r is reached -- this seems to occur if port is used too soon after initialization, it reads garbage until actual data is recieved
				break;
			dataBuf[i] = file_rBuf;
			i++;
		} while (!end);
		/*convert data_buf to int. atoi ignores \r at end of string*/

		data->points[pointCurrent].y = data->graphHeight - atoi(dataBuf);
		data->points[pointCurrent].x = pointCurrent++;
		if (!NoBytesRead)
			--pointCurrent;
	}
	data->updated = 1;
	data->run = 0;



	//free(dataBuf);
	//free(file_rBuf);
}