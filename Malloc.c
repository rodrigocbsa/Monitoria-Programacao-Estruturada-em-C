#include <stdio.h>
#include <stdlib.h>


/* Leia como um livro. */


int main(){
	int *y;
	
	y = malloc(sizeof(int));
	
	*y = 10; // O compilador não apresentará erros. Pois isso é possível de ser feito. Mas está errado considerando o contexto.
	printf("y = %d", *y); // Não vai funcionar... pois para y não foi separado um espaço na memória de modo que ela consiga receber um valor DIRETAMENTE que será apontado pelo ponteiro. O programa chegará aqui e encerrará sem continuar. Faça o teste!!
	// Portanto, podemos concluir que, com a função de memory allocation (malloc), ou de alocação de memória, em português, conseguimos atribuir um valor diretamente a uma variável com ponteiro sem utilizar endereços de outras variáveis... ou seja... o malloc estabelecerá o seu endereço. Observe a seguir como a atribuição poderia ser feita sem malloc:
	

	
	int x = 10;
	int *z = &x;
	*z = 20; // Isso sim funciona sem o malloc, pois na verdade "z" é um endereço...
	printf("\ny = %d = x = %d",*z,x); // portanto, "*z" é a derreferência, que recebeu 20 e que, por sua vez, alterou "x". Sacou?
	// Perceba, então, que tanto o valor 10 quanto o valor 20 só existiram em UM ÚNICO lugar na memória do computador: em "x".
	
	
	// CUIDADO: quem recebe o valor do endereço é sempre a variável, sendo que o ponteiro apenas derreferencia ela. Estude em Ponteiros.c
}
