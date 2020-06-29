// gathers one array of data from a serial port
#include "MainHead.h"

void Gather(gather_data* data) {
	Uint32 pointCurrent = 0;
	Uint8 Status;
	char* file_rBuf = malloc(sizeof(char));
	char* dataBuf = malloc(sizeof(char) * 10);
	Uint8 end = 0;			//BOOL
	DWORD NoBytesRead;						// Bytes read by ReadFile()
	char  TempChar;							// Temperory Character
	int i = 0;

	

	for (pointCurrent = 0; pointCurrent < data->numOfPoints;) {
		i = 0;
		end = 0;
		/*step through chars and append to data_rBuf until a return char is found. return char is last char in string*/
		do {
			ReadFile(data->port, file_rBuf, sizeof(TempChar), &NoBytesRead, NULL);		//returns 0 when no chars left to read, will store one more point, we'll ignore it later
			if (*file_rBuf == '\r')
				end = 1;
			dataBuf[i++] = *file_rBuf;
		} while (!end);
		/*convert data_buf to int. atoi ignores \r at end of string*/

		data->points[pointCurrent].y = atoi(dataBuf);
		data->points[pointCurrent].x = ++pointCurrent;
		if (!NoBytesRead)
			--pointCurrent;
	}
	data->updated = 1;
	data->run = 0;



	//free(dataBuf);
	free(file_rBuf);
}