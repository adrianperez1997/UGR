//tarea4.c
//Trabajo con llamadas al sistema del Subsistema de Procesos "POSIX 2.10 compliant"
//Prueba el programa tal y como está. Después, elimina los comentarios (1) y pruebalo de nuevo.

#include<sys/types.h>	//Primitive system data types for abstraction of implementation-dependent data types.
						//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<unistd.h>		//POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>


char buf[]="cualquier mensaje de salida\n";
int main(int argc, char *argv[])
{
int var=strtol(argv[1], NULL, 10);
pid_t pid;


if(write(STDOUT_FILENO,buf,sizeof(buf)+1) != sizeof(buf)+1) {
	perror("\nError en write");
	exit(-1);
}


if( (pid=fork())<0) {
	perror("\nError en el fork");
	exit(-1);
}
else if(pid==0) {  //proceso hijo ejecutando el programa
		if(var%2==0){
			printf("\nEl numero %d es par\n",var); 
		}
		else{printf("\nEl numero %d no es par\n",var);} 

} else{  //proceso padre ejecutando el programa
		if(var%4==0){
			printf("\nEl numero %d es divisible por 4\n",var); 
		}
		else{printf("\nEl numero %d no es divisible por 4\n",var);}
		

}

exit(0);

}
