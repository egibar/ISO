/* parent.c */
/*
Authors: Julen Fraile, Gorka Bravo and Asier Egibar
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[])	
{
   int childid, clockid,clockid2, id, aux;
   long t;
   int i=atoi(argv[1]), contless=0, contmax=0, cont=0;
     t = time(0);
   while (i!=0){
   
   if ((clockid = fork()) == 0) execlp("./clock", "clock", argv[2], NULL);
   
   if ((clockid2 = fork()) == 0) execlp("./clock", "clock", argv[3], NULL);
   
   if ((childid = fork()) == 0) execvp(argv[4], &(argv[4]));

 
   
  id = wait(NULL);
      if (id==childid){
		  contless++;
		  kill(clockid, SIGKILL);
		  wait(NULL);
     		  kill(clockid2, SIGKILL);
      		  wait(NULL);	
                  }
         if (id==clockid2){ /* error */
                  printf("ERROR: Max_time less than Min_time\n");
		  exit(1);
                  }
	 else {
		id = wait(NULL); 
			if  (id==childid) {
				cont++;
				kill(clockid2, SIGKILL);
				wait(NULL);
                  		}
         		if (id==clockid2){ 
				contmax++;
				kill(childid, SIGKILL);
  			        wait(NULL);
                  		}
}
i--;
}
t = time(0) - t;
printf("--Total time: %ld\n", t);
printf("Less than min time: %d\n", contless);
printf("More than max time: %d\n", contmax);
printf("Between time interval: %d\n", cont);
}
