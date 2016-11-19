// *****************************************************************************
//
// Prácticas de SCD. Práctica 1.
// Plantilla de código para el ejercicio del productor-consumidor con
// buffer intermedio.
//
// *****************************************************************************

#include <iostream>
#include <cassert>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // necesario para {\ttbf usleep()}
#include <stdlib.h> // necesario para {\ttbf random()}, {\ttbf srandom()}
#include <time.h>   // necesario para {\ttbf time()}

using namespace std ;

// ---------------------------------------------------------------------
// constantes configurables:

const unsigned
  num_items  = 40 ,    // numero total de items que se producen o consumen
  tam_vector = 10 ;    // tamaño del vector, debe ser menor que el número de items
   
unsigned buffer[tam_vector];
unsigned primeraLibre=0;

sem_t puedeProducir, puedeConsumir, mutex;

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

// ---------------------------------------------------------------------
// función que simula la producción de un dato

unsigned producir_dato()
{
  static int contador = 0 ;
  contador = contador + 1 ;
  retraso_aleatorio( 0.1, 0.5 );
  cout << "Productor : dato producido: " << contador << endl << flush ;
  return contador ;
}
// ---------------------------------------------------------------------
// función que simula la consumición de un dato

void consumir_dato( int dato )
{
   retraso_aleatorio( 0.1, 1.5 );
   cout << "Consumidor:                              dato consumido: " << dato << endl << flush ;
}
// ---------------------------------------------------------------------
// función que ejecuta la hebra del productor

void * funcion_productor( void * )
{
  for( unsigned i = 0 ; i < num_items ; i++ )
  {
    int dato = producir_dato() ;

    sem_wait(&puedeProducir);
    sem_wait(&mutex);

    buffer[primeraLibre]=dato;
    primeraLibre++;    
    cout << "Productor : dato insertado: " << dato << endl << flush ;

    sem_post(&mutex);
    sem_post(&puedeConsumir);
  }
  return NULL ;
}
// ---------------------------------------------------------------------
// función que ejecuta la hebra del consumidor

void * funcion_consumidor( void * )
{
  for( unsigned i = 0 ; i < num_items ; i++ )
  {
    int dato ;

    sem_wait(&puedeConsumir);
    sem_wait(&mutex);

    dato=buffer[primeraLibre-1];
    primeraLibre--;
    cout << "Consumidor:                              dato extraído : " << dato << endl << flush ;

    sem_post(&mutex);
    sem_post(&puedeProducir);

    
    consumir_dato( dato ) ;
  }
  return NULL ;
}
//----------------------------------------------------------------------

int main()
{

   sem_init(&puedeProducir,0,tam_vector);
   sem_init(&puedeConsumir,0,0);
   sem_init(&mutex,0,1);

   pthread_t hebraProductora, hebraConsumidora;
   pthread_create(&hebraProductora,NULL,funcion_productor,NULL);
   pthread_create(&hebraConsumidora,NULL,funcion_consumidor,NULL);  

   pthread_join(hebraProductora,NULL);
   pthread_join(hebraConsumidora,NULL);

   sem_destroy(&puedeProducir);
   sem_destroy(&puedeConsumir);
   sem_destroy(&mutex);

   return 0 ;
}
