#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Romano.h"

int transforma_romano(const char* num_romano){
	int decimal=0, i=0;
	int flag=0;

	while(num_romano[i]){
		if(num_romano[i]=='I'){ 
			if(flag==0) decimal++; //Se nao preceder nenhuma letra
			if(num_romano[i+1]=='V') flag=1; //Se preceder V
			else if(num_romano[i+1]=='X') flag=2; //Se preceder X
		}

		if(num_romano[i]=='V'){
			if(flag==1) decimal+=3;
			else decimal+=5;
			if(num_romano[i+1]=='I') flag=0;
		}

		if(num_romano[i]=='X'){
			if(flag==2) decimal+=8;
			else if(num_romano[i+1]=='L') flag=3;
			else if(num_romano[i+1]=='V') flag=2;
			else decimal+=10;
		}

		i++;
	}
	return decimal;
}