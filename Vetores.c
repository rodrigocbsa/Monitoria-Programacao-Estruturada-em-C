#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void teste(int v[SIZE]){ // ou "teste(int *v){...}"
	for(int i = 0; i < SIZE; i++){
		printf("%d",v[i]);
	}
}

int main(){
	int *v = malloc(sizeof(int[SIZE]));
	for(int i = 0; i < SIZE; i++){
		v[i] = i;
	}
	//teste(&v);
	teste(v); // Em C, os vetores são automaticamente passados por referência.
	/* Isto é, manipulá-los dentro da função também irá alterar fora dela.*/
}