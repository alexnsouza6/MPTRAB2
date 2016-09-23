#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Romano.h"

int transforma_romano(const char* num_romano){
	int decimal=0, i=0;
	int flag;
	int checador;

	if(num_romano[0]=='I') flag=0;
	if(num_romano[0]=='V') flag=2;
	if(num_romano[0]=='X') flag=3;
	if(num_romano[0]=='L') flag=4;
	if(num_romano[0]=='C') flag=5;
	if(num_romano[0]=='D') flag=6;
	if(num_romano[0]=='M') flag=7;
	
	checador=valida_num_romano(num_romano);
	if(checador==-1) return -1;

	else{
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
			if(flag==3) decimal+=10;
			else if(flag==2) decimal+=8;
			if(num_romano[i+1]=='I') flag=0;
			if(num_romano[i+1]=='L') flag=3;
			if(num_romano[i+1]=='V') flag=2;
			if(num_romano[i+1]=='C') flag=4;
		}

		if(num_romano[i]=='L'){
			if(flag==4) decimal+=50;
			else if(flag==3) decimal+=30;
			if(num_romano[i+1]=='X') flag=3;
			if(num_romano[i+1]=='I') flag=0;
			if(num_romano[i+1]=='V') flag=2;
		}

		if(num_romano[i]=='C'){
			if(flag==5) decimal+=100;
			else if(flag==4) decimal+=80;
			if(num_romano[i+1]=='X') flag=3;
			if(num_romano[i+1]=='I') flag=0;
			if(num_romano[i+1]=='V') flag=2;
			if(num_romano[i+1]=='L') flag=4;
			if(num_romano[i+1]=='D') flag=5;
			if(num_romano[i+1]=='M') flag=6;
		}

		if(num_romano[i]=='D'){
			if(flag==6) decimal+=500;
			else if(flag==5) decimal+=300;
			if(num_romano[i+1]=='X') flag=3;
			if(num_romano[i+1]=='I') flag=0;
			if(num_romano[i+1]=='V') flag=2;
			if(num_romano[i+1]=='L') flag=4;
			if(num_romano[i+1]=='C') flag=5;
		}

		if(num_romano[i]=='M'){
			if(flag==7) decimal+=1000;
			else if(flag==6) decimal+=800;
			if(num_romano[i+1]=='X') flag=3;
			if(num_romano[i+1]=='I') flag=0;
			if(num_romano[i+1]=='V') flag=2;
			if(num_romano[i+1]=='L') flag=4;
			if(num_romano[i+1]=='C') flag=5;
			if(num_romano[i+1]=='D') flag=6;
		}

		i++;
	}
	return decimal;
	}
}

int valida_num_romano(const char* num_romano){
	int i;
	int contador=0;
	int contadorc=0;
	int contadorm=0;
	int contadorx=0;


		while(num_romano[i]){
			if(num_romano[i]=='I'){
				if(num_romano[i]==num_romano[i+1]) contador++;
				if(contador==3) return -1;
			}

			if(num_romano[i]=='V'){
				if(num_romano[i+1] == 'V') return -1;
				if(num_romano[i+1] == 'D') return -1;
				if(num_romano[i+1] == 'C') return -1;
				if(num_romano[i+1] == 'L') return -1;
				if(num_romano[i+1] == 'M') return -1;
				if(num_romano[i+1] == 'X') return -1;
			}

			if(num_romano[i]=='X'){
				if(num_romano[i]==num_romano[i+1]) contadorx++;
				if(contadorx==3) return -1;
				if(num_romano[i+1] == 'M') return -1;
				if(num_romano[i+1] == 'D') return -1;
			}

			if(num_romano[i]=='L'){
				if(num_romano[i+1] == 'M') return -1;
				if(num_romano[i+1] == 'D') return -1;
				if(num_romano[i+1] == 'L') return -1;		
			}

			if(num_romano[i]=='C'){
				if(num_romano[i]==num_romano[i+1]) contadorc++;
				if(contadorc==3) return -1;
			}
		

			if(num_romano[i]=='D')
				if(num_romano[i+1] == 'M') return -1;

			if(num_romano[i]=='M'){
				if(num_romano[i]==num_romano[i+1]) contadorm++;
				if(contadorm==3) return -1;
			}
			i++;
		}
	return 0;
}
