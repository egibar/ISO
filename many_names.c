/*
	Authors: Julen Fraile, Asier Eguibar and Gorka Bravo.
*/
#include <unistd.h>
#include <errno.h>

int main (int argv,char* argc[]) {
	
	if(argv == 1) 
	{
		write(2,"ERROR: No arguments.\n",21);
		return 1;
	}
	int i,aux;
	for(i=2;i < argv;i++)
	{
		if((aux = link(argc[1],argc[i])) ==-1)
			perror("ERROR:");
	}
	return 0;
}
