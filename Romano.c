/**
	\mainpage
	\author Alex Nascimento Souza 15/0115474
	\date Realease: 23/09/2016
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Romano.h"

/** \brief Função que converte o número romano em número árabe (decimal) */
int transforma_romano(const char* num_romano){
	
	/**
	\details A função recebe o string correspondente ao numero romano e realiza a conversão
	\param checador é a flag responsável pela validação do numero romano inserido
	\param decimal é o resultado da conversão
	\param flag é responsável pela orientação quanto ao próximo algarismo. EX: num_romano[0]=='I', se num_romano[1]=='V, então flag=2
	\return O número em arábico, resultado da conversão (variável decimal)
	*/

	int decimal=0, i=0;
	int flag;
	int checador;
	

	checador=valida_num_romano(num_romano);

	if(checador==0){ //Checador e responsavel por analisar se o numero romano e valido. Em  caso de 0, o processo de conversao e autorizado
	
	/*Verifica qual a primeira letra da string */
	if(num_romano[0]=='I') flag=0;
	if(num_romano[0]=='V') flag=2;
	if(num_romano[0]=='X') flag=3;
	if(num_romano[0]=='L') flag=4;
	if(num_romano[0]=='C') flag=5;
	if(num_romano[0]=='D') flag=6;
	if(num_romano[0]=='M') flag=7;

	/*Processo de conversao*/
	while(num_romano[i]){
		if(num_romano[i]=='I'){ 
			if(flag==0) decimal++; //Se nao preceder nenhuma letra
			if(num_romano[i+1]=='V') flag=1; //Se preceder V
			else if(num_romano[i+1]=='X') flag=2; //Se preceder X
		}

		if(num_romano[i]=='V'){
			if(flag==1) decimal+=3; //Se V proceder um I
			else if(flag==2) decimal+=5;
			if(num_romano[i+1]=='I') flag=0; //Se preceder I
		}

		if(num_romano[i]=='X'){
			if(flag==3) decimal+=10;
			else if(flag==2) decimal+=8; //Se X proceder um I
			if(num_romano[i+1]=='I') flag=0; //Se preceder I
			if(num_romano[i+1]=='L') flag=3; //Se preceder L
			if(num_romano[i+1]=='V') flag=2; //Se preceder V
			if(num_romano[i+1]=='C') flag=4; //Se preceder C
		}

		if(num_romano[i]=='L'){
			if(flag==4) decimal+=50;
			else if(flag==3) decimal+=30; //Se L proceder um X 
			if(num_romano[i+1]=='X') flag=3; //Se preceder X
			if(num_romano[i+1]=='I') flag=0; //Se preceder I
			if(num_romano[i+1]=='V') flag=2; //Se preceder V
		}

		if(num_romano[i]=='C'){
			if(flag==5) decimal+=100;
			else if(flag==4) decimal+=80; //Se C proceder um X
			if(num_romano[i+1]=='X') flag=3; //Se preceder X
			if(num_romano[i+1]=='I') flag=0; //Se preceder I
			if(num_romano[i+1]=='V') flag=2; //Se preceder V
			if(num_romano[i+1]=='L') flag=4; //Se preceder L
			if(num_romano[i+1]=='D') flag=5; //Se preceder D
			if(num_romano[i+1]=='M') flag=6; //Se preceder M
		}

		if(num_romano[i]=='D'){
			if(flag==6) decimal+=500;
			else if(flag==5) decimal+=300; //Se D proceder um C
			if(num_romano[i+1]=='X') flag=3; //Se preceder X
			if(num_romano[i+1]=='I') flag=0; //Se preceder I
			if(num_romano[i+1]=='V') flag=2; //Se preceder V
			if(num_romano[i+1]=='L') flag=4; //Se preceder L
			if(num_romano[i+1]=='C') flag=5; //Se preceder C
		}

		if(num_romano[i]=='M'){
			if(flag==7) decimal+=1000;
			else if(flag==6) decimal+=800; //Se M proceder um C
			if(num_romano[i+1]=='X') flag=3; //Se preceder X
			if(num_romano[i+1]=='I') flag=0; //Se preceder I
			if(num_romano[i+1]=='V') flag=2; //Se preceder V
			if(num_romano[i+1]=='L') flag=4; //Se preceder L
			if(num_romano[i+1]=='C') flag=5; //Se preceder C
			if(num_romano[i+1]=='D') flag=6; //Se preceder D
		}

		i++;
	}
	return decimal;
	}
	else return -1;
}

/** \brief Função que verifica a validade do número romano inserido pelo usuário*/
int valida_num_romano(const char* num_romano){

	/**
	\details A função recebe o string correspondente ao numero romano e realiza a verificação
	\param contador Os contadores são responsáveis pela verificação do numero romano inserido
	\return 0 caso o número em questão realmente exista ou -1 caso contrário.
	*/



	int i=0;
	int contador=0;
	int contadorc=0;
	int contadorm=0;
	int contadorx=0;


		while(num_romano[i]){
			if(num_romano[i]=='I'){
				if(num_romano[i+1] == 'C') return -1; //Para caso a string seja "IC"
				if(num_romano[i+1] == 'L') return -1; //Para caso a string seja "IL"
				if(num_romano[i+1] == 'D') return -1; //Para caso a string seja "ID"
				if(num_romano[i+1] == 'M') return -1; //Para caso a string seja "IM"
				if(num_romano[i]==num_romano[i+1]) contador++;
				if(contador==3) return -1; //Para caso a string seja "IIII" ou variacoes, como "VIIII" para representar 9.
			}

			if(num_romano[i]=='V'){
				if(num_romano[i+1] == 'V') return -1; //Para caso a string seja "VV"
				if(num_romano[i+1] == 'D') return -1; //Para caso a string seja "VD"
				if(num_romano[i+1] == 'C') return -1; //Para caso a string seja "VC"
				if(num_romano[i+1] == 'L') return -1; //Para caso a string seja "VL"
				if(num_romano[i+1] == 'M') return -1; //Para caso a string seja "VM"
				if(num_romano[i+1] == 'X') return -1; //Para caso a string seja "VX"
			}

			if(num_romano[i]=='X'){
				if(num_romano[i]==num_romano[i+1]) contadorx++; 
				if(contadorx==3) return -1; //Para caso a string seja "XXXX" ou variacoes, como "XXXXI" para representar 41.
				if(num_romano[i+1] == 'M') return -1; //Para caso a string seja "XM"
				if(num_romano[i+1] == 'D') return -1; //Para caso a string seja "XD"
			}

			if(num_romano[i]=='L'){
				if(num_romano[i+1] == 'M') return -1; //Para caso a string seja "LM"
				if(num_romano[i+1] == 'D') return -1; //Para caso a string seja "LD"
				if(num_romano[i+1] == 'L') return -1; //Para caso a string seja "LL"		
			}

			if(num_romano[i]=='C'){ 
				if(num_romano[i]==num_romano[i+1]) contadorc++;
				if(contadorc==3) return -1; //Para caso a string seja "CCCC" ou variacoes, como "CCCCI" para representar 401.
			}
		

			if(num_romano[i]=='D')
				if(num_romano[i+1] == 'M') return -1; //Para caso a string seja "DM"

			if(num_romano[i]=='M'){
				if(num_romano[i]==num_romano[i+1]) contadorm++;
				if(contadorm==3) return -1; //Para caso a string seja "MMMMM" ou variacoes, como "MMMMM" para representar 401.
			}
			i++;
		}
	return 0;
}
