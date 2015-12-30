/* who_wc_pipe.c */

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define error(a) {perror(a); exit(-1);};

main(int argc, char *argv[]) /* who | wc -l */
{
   int i = 0;
   int pfd[2];
   int pfd2[2];
   int id;

   if (pipe(pfd) == -1) error("pipe");
   printf("parent: pipe created, channels: READ=%d eta WRITE=%d\n", pfd[0], pfd[1]);

	if (pipe(pfd2) == -1) error("pipe2");
   printf("parent: pipe created, channels: READ=%d eta WRITE=%d\n", pfd2[0], pfd2[1]);


   switch (id = fork()) {
      case -1: error("fork");
      case 0:   /* 1st child: who */
         printf("1st child process created\n");
         if (close(1) == -1) error("close");
         if (dup(pfd[1]) != 1) error("dup");
         if ((close(pfd[0]) == -1) || (close(pfd[1]) == -1)) error("close");
         if ((close(pfd2[0]) == -1) || (close(pfd2[1]) == -1)) error("close");
         execlp("who", "who", NULL);
         error("execlp");
   }
   printf("parent: who(%d) process launched\n",id);

   switch (id = fork()) {
      case -1: error("fork");
      case 0:   /* 2nd child process: grep */
         printf("2nd child process created\n");
         if (close(0) == -1) error("close");
         if (dup(pfd[0]) != 0) error("dup");
		 if (close(1) == -1) error("close");
		 if (dup(pfd2[1]) != 1) error("dup");
         if ((close(pfd[0]) == -1) || (close(pfd[1]) == -1)) error("close");
         if ((close(pfd2[0]) == -1) || (close(pfd2[1]) == -1)) error("close");
         execlp("grep","grep","acaf", NULL);
         error("execlp");
   }
	
	switch (id = fork()) {
      case -1: error("fork");
      case 0:   /* 3rd child process: wc -l */
         printf("3rd child process created\n");
         if (close(0) == -1) error("close");
         if (dup(pfd2[0]) != 0) error("dup");
         if ((close(pfd[0]) == -1) || (close(pfd[1]) == -1)) error("close");
         if ((close(pfd2[0]) == -1) || (close(pfd2[1]) == -1)) error("close");
         execlp("wc","wc","-l",NULL);
         error("execlp");
   }

   printf("parent: wc(%d) process launched\n",id);

   if ((close(pfd[0]) == -1) || (close(pfd[1]) == -1)) error("close");
   if ((close(pfd2[0]) == -1) || (close(pfd2[1]) == -1)) error("close");

   while ((id = wait(NULL)) != -1)  
      printf("parent: %d process finished\n", id);

   exit(0);
}

/*Gorka Bravo eta Xabi Linazasoro*/
