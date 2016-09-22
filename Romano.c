#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Romano.h"

int transforma_romano(const char* num_romano){
	int num_arabe=0, i=0;

	while(num_romano[i]){
		if(num_romano[i]=='I') num_arabe+=1;
		i++;
	}
	return num_arabe;
}