/*
	Author: Julen Fraile Asier Eguibar and Gorka Bravo.
*/
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

int main(int argc,char* argv[]) {
	DIR *dir;
	char to_print[512];

	struct dirent *sarrera;

	if(argc == 1)
	{
		if((dir = opendir("/")) == NULL)
		{
			perror("ERROR");
			return 1;
		} else {
			while((sarrera = readdir(dir)) != NULL) 
			{
				write(1,sarrera->d_name, strlen(sarrera->d_name));
				write(1,"\n",1);

				sprintf(to_print,"%ld",sarrera->d_ino);
				write(1,to_print,strlen(to_print));
				write(1,"\n",1);
			}
			closedir(dir);	
		}
		return 0;
	}
	if(argc == 2)
	{
		if((dir = opendir(argv[1])) == NULL)
		{
			perror("ERROR");
			return 1;
		} else {
			while((sarrera = readdir(dir)) != NULL) 
			{
				write(1,sarrera->d_name, strlen(sarrera->d_name));
				write(1,"\n",1);

				sprintf(to_print,"%ld",sarrera->d_ino);
				write(1,to_print,strlen(to_print));
				write(1,"\n",1);
			}
			closedir(dir);	
		}
		
		return 0;
	} else {
		write(2,"Too many arguments.\n",20);
		return 1;
	}

}
