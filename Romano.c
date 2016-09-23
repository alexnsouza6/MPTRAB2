#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Romano.h"

int transforma_romano(const char* num_romano){
	int decimal=0, i=0;
	int flag=0;

	if(num_romano[0]=='I') flag=0;
	if(num_romano[0]=='V') flag=2;
	if(num_romano[0]=='X') flag=3;
	if(num_romano[0]=='L') flag=4;
	if(num_romano[0]=='C') flag=5;


	while(num_romano[i]){
		if(num_romano[i]=='I'){ 
			if(flag==0) decimal++; //Se nao preceder nenhuma letra
			if(num_romano[i+1]=='V') flag=1; //Se preceder V
			else if(num_romano[i+1]=='X') flag=2; //Se preceder X
		}

		if(num_romano[i]=='V'){
			if(flag==1) decimal+=3;
			else if(flag==2) decimal+=5;
			if(num_romano[i+1]=='I') flag=0;
		}

		if(num_romano[i]=='X'){
			if(flag==2) decimal+=8;
			else if(flag==3) decimal+=10;
			if(num_romano[i+1]=='I') flag=0;
			if(num_romano[i+1]=='L') flag=3;
			if(num_romano[i+1]=='V') flag=2;
		}

		i++;
	}
	return decimal;
}