#include "io.h"
#include <stdio.h>

void read_file(const char* file_name, char* content_buffer, size_t size){
	FILE *fptr = fopen(file_name, "rb");

	if (fptr == NULL){
		perror("Error opening the file");
		return;
	}

	size_t bytes_read = fread(content_buffer, 1, size -1, fptr);
	content_buffer[bytes_read] = '\0';

	fclose(fptr);
}
