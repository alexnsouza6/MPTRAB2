#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Romano.h"

int main(int argc, char **argv) {
	int i;
	char c[30];

	printf("Digite o numero em romano: \n");
	scanf("%s", c);

	for(i=0;i<strlen(c);i++) c[i]=toupper(c[i]);
	
	c[strlen(c)] = '\0';
	i=transforma_romano(c);

	return 0;

}

