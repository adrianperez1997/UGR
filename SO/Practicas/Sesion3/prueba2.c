//tarea4.c
//Trabajo con llamadas al sistema del Subsistema de Procesos "POSIX 2.10 compliant"
//Prueba el programa tal y como está. Después, elimina los comentarios (1) y pruebalo de nuevo.

#include<sys/types.h>	//Primitive system data types for abstraction of implementation-dependent data types.
						//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<unistd.h>		//POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
int estado;
int nprocs=strtol(argv[1], NULL, 10);
pid_t pid;
int childpid;

/*
Jerarquía de procesos tipo 1
*
for (int i=1; i < nprocs; i++) {
printf("\npid= %d, pid del padre= %d\n", getpid(),getppid());           
  if ((childpid= fork()) == -1) { 
    fprintf(stderr, "Could not create child %d: %s\n",i,strerror(errno));
    exit(-1);
  }       
  if (childpid)   
    break;
} 
/*
Jerarquía de procesos tipo 2
*/
for (int i=1; i < nprocs; i++) {
printf("\npid= %d, pid del padre= %d\n", getpid(),getppid());            
  if ((childpid= fork()) == -1) { 
    fprintf(stderr, "Could not create child %d: %s\n",i,strerror(errno));
    exit(-1);
  }       
  if (!childpid)   
    break;
}

wait(&estado);
exit(0);
}
