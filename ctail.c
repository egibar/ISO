/*
** Authors: Julen Fraile, Gorka Bravo and Asier Eguibar.
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argv, char* argc[]) {
	FILE *fp;
	int n = 10;
	int length;
	char error[] = "ERROR : ";
	char error1[] = "no arguments.";
	char error2[] = "ctail: no se puede abrir ";
	char error3[] = " para lectura: No existe el archivo o el directorio.\n";
	char buff;
	char c[] = ">>";
	
	if(argv == 1) 
	{
		printf("%s %s",error,error1);
		return 0;
	}
	int b, i = 1;
	b = atoi(argc[1]);
	if(b != 0) {
		n = b;
		i = 2;
	}
	for(i;i < argv;i++)
	{		
		fp = fopen(argc[i],"r");
		if(fp == NULL)
		{
			printf("%s %s %s",error2,argc[i],error2);
		}else{
			printf("%s %s %s\n",c,argc[i],c);
			
			fseek(fp,-n,SEEK_END);

			do {
      			buff = fgetc(fp);
      			putchar(buff);
   			} while (buff != EOF);
			fclose(fp);
			printf("\n");
		}
	}
	return 0;
}
