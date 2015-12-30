/*
 Authors : Julen Fraile, Asier Egibar and Gorka Bravo
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "is_executable3.c"
#include "is_executable4.c"


int main(int argc,char* argv[]) {
	DIR *dir;
	char to_print[512];

	struct dirent *sarrera;

	if(argc == 2)
	{
		if((dir = opendir(argv[1])) == NULL)
		{
			perror("ERROR");
			return 1;
		} else {
			while((sarrera = readdir(dir)) != NULL) 
			{
				if(is_executable3(sarrera->d_name)==1)
				{
					write(1,sarrera->d_name, strlen(sarrera->d_name));
					write(1,"3\n",1);
				}
				if(is_executable4(sarrera->d_name)==1)
				{
					write(1,sarrera->d_name, strlen(sarrera->d_name));
					write(1,"4\n",1);
				}

			}
			closedir(dir);	
		}
		
		return 0;
	} else {
		printf("Incorrect number of arguments.\n");
		return 1;
	}

}
