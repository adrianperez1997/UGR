
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main(int argc, char *argv[]){
   if(argc<3){
      printf("El programa necesita dos parametros: extremo inferior y extremo superior.");
      exit(-1);
   }
   int   min=atoi(argv[1]),
         mid=(atoi(argv[2])+atoi(argv[1]))/2,
         max=atoi(argv[2]);

   char  minarg[10],
         midarg1[10],
	 midarg2[10],
         maxarg[10];
        

   sprintf(minarg, "%d", min);
   sprintf(midarg1, "%d", mid);
   sprintf(midarg2, "%d", mid+1);
   sprintf(maxarg, "%d", max);

   /////////////////////////////////////////////////

   //Cauces
   int fd1[2], fd2[2], fd;
   char buffer[25];
   memset(buffer,0,strlen(buffer));
   pid_t pid1, pid2;
  
   pipe(fd1); // pipe esclavo1
   pipe(fd2); // pipe esclavo2

   /////////////////////////////////////////////////

   //ESCLAVOS
   if ((pid1= fork())<0) {
      perror("\Error en fork");
      exit(-1);
   }
   if ((pid2= fork())<0) {
      perror("\Error en fork");
      exit(-1);
   }

   if(!pid1){   //ESCLAVO1

      //Cerrar el descriptor de lectura de cauce en el proceso hijo
      close(fd1[0]);

      //dup2(): Duplicar el descriptor de escritura en cauce en el descriptor
      //correspondiente a la salida estda r (stdout), cerrado previamente en
      //la misma operación
      dup2(fd1[1], STDOUT_FILENO);	//Sustituimos salida estandar por el descriptor de escritura del esclavo1
      execlp("./esclavo","./esclavo",minarg,midarg1,NULL); //ejecutamos programa esclavo
      perror("fallo en execlp");
      exit(EXIT_FAILURE);
   }

    if(!pid2){   //ESCLAVO2

      //Cerrar el descriptor de lectura de cauce en el proceso hijo
      close(fd2[0]);
      dup2(fd2[1],STDOUT_FILENO);	//busca en la tabla de descriptores de archivos la primera que sea null y mete ahi lo que le pasamos(fd[1]) y esto tambien lo mete en la posicion de la tabla STDOUT_FILENO. Esto sirve para que a la vez que muestra por la salida estandar lo que tenga que mostrar, tambien se le pase al cauce(que es lo que hay en fd[1])
     
      execlp("./esclavo","./esclavo", midarg2, maxarg,NULL);
      perror("fallo en execlp");
      exit(EXIT_FAILURE);
      }
   



   //Cerramos descriptor de escritura en cauce del padre
   close(fd1[1]);
   close(fd2[1]);

   //LEEMOS DESDE EL CAUCE
   int primo1,primo2;
   memset(buffer,0,strlen(buffer));
   primo1=read(fd1[0],buffer,sizeof(buffer));
   while(primo1!=0){

      if(write(STDOUT_FILENO,buffer,strlen(buffer))==-1){
	   perror("Error en la escritura del esclavo1.\n");
	   exit(EXIT_FAILURE);
      }
   memset(buffer,0,strlen(buffer));
      primo1=read(fd1[0],buffer,sizeof(buffer));
   }
   memset(buffer,0,strlen(buffer));
   primo2=read(fd2[0],buffer,sizeof(buffer));
   while(primo2!=0){
     
      if(write(STDOUT_FILENO,buffer,strlen(buffer))==-1){
	   perror("Error en la escritura del esclavo2.\n");
	   exit(EXIT_FAILURE);
      }
   memset(buffer,0,strlen(buffer));
primo2=read(fd2[0],buffer,sizeof(buffer));
   }

   return 0;
}

