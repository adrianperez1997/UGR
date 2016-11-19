#include<sys/types.h>
#include<unistd.h>		//POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>

int main(int argc, char *argv[]){           
  int nprocs = 5;
  pid_t childpid[nprocs];
  pid_t aux[nprocs];
  int contador = 5;

for (int i=0; i < nprocs; i++){ 
           
	if ((childpid[i]= fork()) == -1) { 
		fprintf(stderr, "Could not create child %d: %s\n",i,strerror(errno));
		exit(-1);
	}
	if (!childpid[i]){
		printf("\nSoy el hijo %d \n", getpid());
		childpid[i]=getpid();
		exit(0);
	}
}

      
for(int i=0; i<nprocs; i+=2){
aux[i]=childpid[i];
wait(&childpid[i]);
printf("Acaba de finalizar mi hijo con %d\n", aux[i]);
contador--;
printf("Sólo me quedan %d hijos vivos.\n", contador);
  }

for(int i=1; i<nprocs; i+=2){
aux[i]=childpid[i];
wait(&childpid[i]);
printf("Acaba de finalizar mi hijo con %d\n", aux[i]);
contador--;
printf("Sólo me quedan %d hijos vivos.\n", contador);
  }

}
