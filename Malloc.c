#include <stdio.h>
#include <stdlib.h>

int main(){
	int *y;
	
	//y = malloc(sizeof(int));
	
	*y = 10; // O compilador não apresentará erros. Pois não há erros sintáticos. Isso é possível.
	
	printf("y = %d",*y); // Mas não vai funcionar, pois para y não foi separado um espaço na memória de modo que consiga receber um VALOR diretamente apontado pelo ponteiro. O programa chegará aqui e encerrará sem continuar.
	
	// Portanto, podemos concluir que a função de memory allocation (malloc), ou alocação de memória em português, serve para atribuirmos um valor diretamente a um ponteiro, sem utilizar endereços de memória de outras variáveis.
	
	
	/* Agora, DESCOMENTE a linha 7 e execute o programa! */
	int x = 10;
	y = &x;
	*y = 20; // Isso sim funciona sem o malloc, pois na verdade y é um endereço.
	printf("\ny = %d = x = %d",*y,x); // E, portanto, *y é a derreferência, que recebe 20, por sua vez, alterando x.
	// Perceba que tanto o valor 10 quanto o valor 20 só existem em um ÚNICO lugar na memória do computador: em x.
	
	
	
	// CUIDADO: perceba que na linha 18, quem recebe o endereço é y (E NÃO PONTEIRO DE y!!!). Caso necessário, leia o arquivo Ponteiros.c para entender como ponteiros funcionam. Em resumo: quem recebe o valor do endereço é sempre a variável, sendo que o ponteiro apenas derreferencia ela.
}
