/*
 Authors : Julen Fraile, Asier Egibar and Gorka Bravo
*/
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc,char* argv[]) {
	int f;
	if(argc != 3)
	{
		printf("Bad arguments.\n");
		exit(0);
	} else {
		
		mode_t mask = (mode_t)argv[1]; 
		if((f = chmod(argv[2],mask)) == -1)
		{
			perror("ERROR");
			return 1;
		}
	}
	return 0;
}
