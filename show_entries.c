/*
Authors : Gonzalo Montero, Eneko Pinzolas and Gorka Bravo
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>

#define error(a){perror(a);return 1;};

int main (int argc, char* argv[]) {

	struct stat st;
	DIR *dir;
	struct dirent *entry;
	struct passwd *pwd;

	if(argc != 4)
	{
		printf("Bad arguments. \n");
		return 1;
	} 
	if((dir = opendir(argv[1])) == NULL)
	{
		error("Directory error: ");
	}
	while((entry = readdir(dir)) != NULL) 
	{
		stat(entry->d_name, &st);

		if(st.st_mode & 0777 == atoi(argv[3])) {
			pwd = getpwuid(st.st_uid);

			if (pwd->pw_name == argv[2]){

				write(1,entry->d_name, strlen(entry->d_name));
				write(1, "\n", 1);			

			}

		}
	}
	return 0;
}
