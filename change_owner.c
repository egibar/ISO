/*
 Authors : Julen Fraile, Asier Egibar and Gorka Bravo
*/
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <sys/stat.h>

int main (int argc,char* argv[]) {
	struct group *group;
	struct passwd *name;

	if(argc != 3)
	{
		printf("Bad argument.\n");
		exit(0);
	} else { 
		name = getpwnam(argv[2]);
		group = getgrnam(argv[2]);

		
		mode_t oldMask = umask((mode_t) 0);
		if(oldMask > (mode_t)022)
		{
			printf("permissions ERROR\n");	
			return 1;
		 } else if(chown(argv[1],name->pw_uid,group->gr_gid) == -1) {
			perror("chown ERROR");	
			return 2;	
		}
	}
	return 0;
}
