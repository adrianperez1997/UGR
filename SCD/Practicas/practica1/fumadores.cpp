// *****************************************************************************
//
// Prácticas de SCD. Práctica 1.
// Plantilla de código para el ejercicio de los fumadores
//
// *****************************************************************************

#include <iostream>
#include <cassert>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>      // incluye "time(....)"
#include <unistd.h>    // incluye "usleep(...)"
#include <stdlib.h>    // incluye "rand(...)" y "srand"

using namespace std ;

sem_t puedeFumar[3], estanquero;
unsigned int producido;
// ---------------------------------------------------------------------
// introduce un retraso aleatorio de duración comprendida entre
// 'smin' y 'smax' (dados en segundos)

void retraso_aleatorio( const float smin, const float smax )
{
  static bool primera = true ;
  if ( primera )        // si es la primera vez:
  {  srand(time(NULL)); //   inicializar la semilla del generador
     primera = false ;  //   no repetir la inicialización
  }
  // calcular un número de segundos aleatorio, entre {\ttbf smin} y {\ttbf smax}
  const float tsec = smin+(smax-smin)*((float)random()/(float)RAND_MAX);
  // dormir la hebra (los segundos se pasan a microsegundos, multiplicándos por 1 millón)
  usleep( (useconds_t) (tsec*1000000.0)  );
}

// ----------------------------------------------------------------------------
// función que simula la acción de fumar, como un retardo aleatorio de la hebra.
// recibe como parámetro el numero de fumador
// el tiempo que tarda en fumar está entre dos y ocho décimas de segundo.

void fumar( int num_fumador )
{
   cout << "Fumador número " << num_fumador << ": comienza a fumar." << endl << flush ;
   retraso_aleatorio( 0.2, 0.8 );
   cout << "Fumador número " << num_fumador << ": termina de fumar." << endl << flush ;
}

// ----------------------------------------------------------------------------
void* funcion_fumador(void * numFumador_void){
  long long int numFumador = (long long)numFumador_void;

  while(true){
    sem_wait(&puedeFumar[numFumador]);
    sem_post(&estanquero);
    fumar(numFumador);
    
  }
}
// ----------------------------------------------------------------------------
void* funcion_estanquero(void * p){
  int aleatorio;

  while(true){
    sem_wait(&estanquero);
    producido = rand()%3;
    sem_post(&puedeFumar[producido]);
  }
}
int main()
{

  srand( time(NULL) ); // inicializa semilla aleatoria para selección aleatoria de fumador

  int fumadores = 3;
  pthread_t hebra_fumador[fumadores];
  pthread_t hebra_estanquero;

  sem_init( &puedeFumar[0], 0, 0 ); // inicialmente no puede fumar
  sem_init( &puedeFumar[1], 0, 0 ); // inicialmente no puede fumar
  sem_init( &puedeFumar[2], 0, 0 ); // inicialmente no puede fumar
  sem_init( &estanquero, 0, 1 );   // inicialmente puede producir tres ingredientes

  pthread_create( &hebra_estanquero, NULL, funcion_estanquero, NULL );
  pthread_create( &hebra_fumador[0], NULL, funcion_fumador, (void*)0);
  pthread_create( &hebra_fumador[1], NULL, funcion_fumador, (void*)1);
  pthread_create( &hebra_fumador[2], NULL, funcion_fumador, (void*)2);

  for(int i = 0; i < fumadores; i++){
    pthread_join( hebra_fumador[i], NULL ) ;
}
  pthread_join( hebra_estanquero,   NULL ) ;

  for(int i = 0; i < fumadores; i++){
    sem_destroy( &puedeFumar[i] );
}
  sem_destroy(&estanquero);

  return 0 ;
}
