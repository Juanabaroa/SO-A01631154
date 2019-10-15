#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
int main(void) {
    int pid;
    pid = fork();
    if(pid==0){
        //Key debe de ser igual para que los bloques compartan memoria, de lo contrario crea 2 bloques diferentes
        int key = 27;
        //sí no existe el bloque de memoria, lo crea, si existe te devuelve el id
        //100bytes, ICPC_CREAT nos devuelve el ID, y el 0666 le da permiso de lectura
        int shmid=shmget(key,100,IPC_CREAT|0666);
        //0 sí quiero para escribir y leer, cualquier número diferente a 0 es para sólo lectura+
        //message es una variable que es compartida por ambos procesos.
        char * message = (char *) shmat(shmid,NULL,0);
        //sobreescribe a message con la cadena que le pasas
        sprintf(message, "Hola mundo");
            while(message[0]=='H'){
                sleep(1);
            }
        printf("El mensaje final es: %s\n",message);
    } else {
        int key = 27;
        //sí no existe el bloque de memoria, lo crea, si existe te devuelve el id
        //100bytes, ICPC_CREAT nos devuelve el ID, y el 0666 le da permiso de lectura
        int shmid=shmget(key,100,IPC_CREAT|0666);
        //0 sí quiero para escribir y leer, cualquier número diferente a 0 es para sólo lectura
        char * message = (char *) shmat(shmid,NULL,0);
        sleep(1);
        printf("El mensaje es: %s\n", message);
        message[0]='*';
    }
 }