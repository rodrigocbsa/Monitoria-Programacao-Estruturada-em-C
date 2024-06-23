#include <stdio.h>
#include <stdlib.h>

/*
Exercício 1 - Lista 5

@Monitor: Rodrigo CBSA
2024

	Escreva duas funções para inverter um vetor,
	substituindo as posições dos seus elementos.
	O primeiro elemento do vetor será deslocado para o último
	índice do vetor, o segundo elemento do vetor será deslocado
	para o penúltimo índice do vetor, e assim por diante.
	
	Escreva uma função recebendo um arranjo e outra recebendo um ponteiro.
	Em seguida, chame estes módulos a partir de um módulo main para testar seu programa.
*/

int* inverte_sem_ponteiro(int vetor[],int tam); //Aqui eu mostro como retornar um array. Mas a ideia da questão é ver que tanto com ponteiro como sem ponteiro o vetor terá o mesmo comportamento.
void inverte_com_ponteiro(int* vetor, int tam);

int main(){
	
	int tam;
	do{
		printf("Forneca um valor valido para o tamanho do vetor: ");	
		scanf("%d",&tam);
	}while(tam<=0);
	
	int vetor[tam];
	int *invertido;
	
	
	printf("O seu vetor:\n");
	int i;
	for(i = 0; i < tam; i++){
		vetor[i] = i; // Preenche os valores do vetor automaticamente
		printf("%d ", vetor[i]);
	}
	
	
	
	invertido = inverte_sem_ponteiro(vetor,tam);
	printf("\nO seu vetor invertido sem ponteiro fica: \n");
	for(i = 0; i < tam; i++){
		printf("%d ",invertido[i]);
	}
	
	for(i = 0; i < tam; i++){
		vetor[i] = i; // "Resetar" o vetor
	}
	
	inverte_com_ponteiro(vetor,tam);
	printf("\nO seu vetor invertido com ponteiro fica: \n");
	for(i = 0; i < tam; i++){
		printf("%d ",vetor[i]);
	}
	
	free(invertido); // Pq invertido é uma referencia para aux que por sua vez utilizou o malloc
	
	return 0;
}

int* inverte_sem_ponteiro(int vetor[],int tam){
	int i,j = 0;
	int *aux = malloc(sizeof(int[tam]));
	// Não é possível, em C, retornar um array sem usar endereços de memória.
	// Então por isso estamos criando um malloc dentro da função para retornar um array.
	// Há funções como memcpy e strcpy para atribuir um array a um outro array, mas não é o propósito aqui.
	// Com Structs (vocês ainda verão), aí fica tranquilo atribuir um array a um outro array, pois você fará isso com structs (structA = structB)...
	// ... sendo que as structs conterão os arrays.
	
	for(i = 0; i < tam; i++){
		aux[i] = vetor[tam - 1 - i];
	}
	
	return aux;
}
void inverte_com_ponteiro(int* vetor, int tam){
	int i,j = 0,aux[tam];
	
	for(i = 0; i < tam; i++){
		aux[i] = vetor[tam - 1 - i];
	}
	for(i = 0; i < tam; i++){
		vetor[i] = aux[i];
	}
}