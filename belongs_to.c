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
#include <grp.h>
#define error(a){perror(a);return 1;};
int main (int argc, char** argv){

	struct passwd *pwd;
	struct group *grou;

	if(argc != 3)
	{
		printf("Bad arguments. \n");
		return 1;
	} 

	if((pwd = getpwnam(argv[1])) == NULL) error("error");

	grou = getgrgid(pwd->pw_gid);
	if(grou->gr_name == argv[2]){
		printf("true \n");
	}	else printf("false \n");
return 0;
}
