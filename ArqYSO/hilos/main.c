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
       //sleep(1);

    }
//    pthread_join(tid,NULL); ///suspende la ejecucion del thread actual hasta que termine el thread tid
//    printf("Ahora que espere a %i voy a terminar\n", (int)tid);
//   if (pthread_detach(pthread_self()) != 0 ) ///reclama el espacio cuando el thread termina, si aun no termino devolvera un valor negativo
//    {
//        printf("Thread no pudo ser detached\n");
//    }
//    else
//        printf("Thread %i fue detached\n",pthread_self());

    pthread_exit(NULL); ///finaliza a nivel thread (si es padre moriran los hijos)
    return(NULL);
}

////esta funcion es llamada por el thread numero 2
void *creadorDeHilos(void *arg)
{
    pthread_t tid = pthread_self();
    pthread_t id = tid;
    pthread_t thread;
//    int thread_num =2;

///con thread2 creamos 3 hilos mas ( thread 2 es padre de 3 hilos)
    for (int i = 0; i < num_pthreads; i++)
    {
       pthread_create(&thread, NULL, new_thread, (void*)id);

    }
//   if (pthread_detach(id) != 0 ) ///reclama el espacio cuando el thread termina, si aun no termino devolvera un valor negativo
//    {
//        printf("Thread no pudo ser detached\n");
//    }
//    else
//        printf("Thread 2 fue detached\n");

   //  new_thread((void*)pthread_self());

}

void* mostrar(void* arg)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%c",buf[i]);
    }
    pthread_join((pthread_t)arg,NULL);
}


void main()
{
    pthread_t thread2;
    pthread_t thread3;
    int id;
//    pthread_attr_t attributes;
//     pthread_attr_setdetachstate(&attributes,PTHREAD_CREATE_DETACHED); ///por defecto es JOINABLE

//    if (pthread_create(&thread, NULL, creadorDeHilos, (void*)pthread_self())) ///si se crea el hilo me devuelve 0
//    {
//        fprintf(stderr, "error creando un nuevo thread \n");
//        exit(1);
//    }

        pthread_create(&thread2,NULL,mostrar,(void*)pthread_self());
        pthread_create(&thread3,NULL,mostrar,(void*)thread2);
//        pthread_join(thread3,NULL);

    pthread_exit(NULL);
    printf("Todos los threads moriran despues de mi por que soy el thread mayor\n");
    //sleep(10000);
    ///exit(0); ///a nivel proceso
    ///pthread_exit(NULL); /// espera a que todos los hilos terminen (hilo terminante) a nivel thread --- si es el retorno del main mata a nivel proceso, si es el retorno de una funcion mata a nivel thread ---
    ///si no especifico salida se hace kill del proceso por el simple retorno de la funcion (como exit)
}
