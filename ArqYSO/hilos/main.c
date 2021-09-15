#include <pthread.h>
#include <stdio.h>

#define buf "abcde"
#define num_pthreads  3

void * new_thread(void * arg)
{
    int i;
    pthread_t tid = (pthread_t)arg;
    printf("Soy el thread numero %i\n", (int)pthread_self());

    for (i = 0; i < 5; i++)
    {

        printf("%c",buf[i]);
       sleep(3);

    }
//    pthread_join(tid,NULL); ///suspende la ejecucion del thread actual hasta que termine el thread tid
//    printf("Ahora que espere a %i voy a terminar\n", (int)tid);
//   if (pthread_detach(pthread_self()) != 0 ) ///reclama el espacio cuando el thread termina, si aun no termino devolvera un valor negativo
//    {
//        printf("Thread no pudo ser detached\n");
//    }
//    else
//        printf("Thread %i fue detached\n",pthread_self());

    //pthread_exit(NULL); ///finaliza a nivel thread (si es padre moriran los hijos)
    return(NULL);
}

////esta funcion es llamada por el thread numero 2
void *creadorDeHilos(void *arg)
{
    pthread_t tid = pthread_self(); ///le a signo a tid el thread 2
    pthread_t thread;
//    int thread_num =2;

///con thread2 creamos 3 hilos mas ( thread 2 es padre de 3 hilos)
    for (int i = 0; i < num_pthreads; i++)
    {
       pthread_create(&thread, NULL, new_thread, (void*)tid);

    }
//   if (pthread_detach(id) != 0 ) ///reclama el espacio cuando el thread termina, si aun no termino devolvera un valor negativo
//    {
//        printf("Thread no pudo ser detached\n");
//    }
//    else
//        printf("Thread 2 fue detached\n");

   new_thread((void*)pthread_self());

}

void* mostrar(void* arg)
{
    printf("soy el thread numero %i\n", pthread_self());
    //pthread_detach(pthread_self());
    //pthread_join(1,NULL);
    for (int i = 0; i < 5; i++)
    {
        printf("%c",buf[i]);
        //sleep(1);
    }
    pthread_exit(NULL);
}

////cada thread termina de eejecutar su porcion de codigo
///no va a liberar la memoria asignada hasta que el thread indicado termine

///thread 1
void main()
{
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;
 //   int id;
    pthread_attr_t attributes;
    pthread_attr_init(&attributes);
    pthread_attr_setdetachstate(&attributes,PTHREAD_CREATE_DETACHED); ///por defecto es JOINABLE

////pthread_create retorna negativo si no pudo crearlo, si no 0
    printf("soy el thread principal, el %i!\n", pthread_self());
    pthread_create(&thread2, &attributes, mostrar, NULL); ///si se crea el hilo me devuelve 0
    pthread_create(&thread3, NULL, mostrar, NULL); ///si se crea el hilo me devuelve 0
    pthread_create(&thread4,  NULL, mostrar, NULL); ///si se crea el hilo me devuelve 0
    //sleep(10); ///suspendes el thread quitandolo de ejecucion (procesador esta libre)
    //exit(1); ///es a nivel proceso
    pthread_exit(NULL); ///si sos el thread principal, espera a que los  demas terminen
















//        pthread_create(&thread2,NULL,mostrar,(void*)pthread_self());
//        pthread_create(&thread3,NULL,mostrar,(void*)thread2);
//        pthread_join(thread3,NULL);


  //  printf("Todos los threads moriran despues de mi por que soy el thread mayor\n");
    //sleep(10000);
    ///exit(0); ///a nivel proceso
    ///pthread_exit(NULL); /// espera a que todos los hilos terminen (hilo terminante) a nivel thread --- si es el retorno del main mata a nivel proceso, si es el retorno de una funcion mata a nivel thread ---
    ///si no especifico salida se hace kill del proceso por el simple retorno de la funcion (como exit)
}
