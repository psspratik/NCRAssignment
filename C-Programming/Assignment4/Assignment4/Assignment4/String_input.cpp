#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

char *inputString(FILE* fp, size_t size){
	//The size is extended by the input with the value of the provisional
	char *str;
	int ch;
	size_t len = 0;
	str =(char*)realloc(NULL, sizeof(char)*size);//size is start size
	if (!str)return str;
	while (EOF != (ch = fgetc(fp)) && ch != '\n'){
		str[len++] = ch;
		if (len == size){
			str = (char*)realloc(str, sizeof(char)*(size += 16));
			if (!str)return str;
		}
	}
	str[len++] = '\0';
	str =(char*)realloc(str, sizeof(char)*len);
	return str;
}