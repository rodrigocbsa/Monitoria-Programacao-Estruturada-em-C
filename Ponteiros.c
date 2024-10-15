#include <stdio.h>

int main(){
	// Como os ponteiros funcionam?
	
	
	
	int * ptr, Nptr;
	// Qual a diferença entre essas duas variáveis declaradas?
	// É importante notar que Nptr será, para o compilador, apenas um INTEIRO.
	// Mas ptr terá um ponteiro de um inteiro.
	
	// Portanto se eu quisesse que Nptr tivesse um ponteiro, na verdade, eu teria que fazer assim na declaração:	
	int *ptr1, *Nptr1;
	
	
	// Chegamos à devida conclusão que, dessa forma, o ponteiro não faz parte do TIPO, mas sim da VARIÁVEL.
	// Se ponteiros fizessem parte do tipo, Nptr também teria um ponteiro, no primeiro caso.
	
	// Então, ponteiros são características/atributos especiais das variáveis e podemos (ou não) utilizá-las. Perceba:
	
	/* Se fizermos
		int *pX = &x;
	você poderia dizer que "estamos atribuindo em *pX o valor do endereço de x".
	Mas, em verdade, nós estamos "atribuindo em pX o valor do endereço de x". Não em ponteiro de pX. Percebeu a diferença?
	
	Portanto, o valor de pX é o endereço de x. E o *pX é a derreferência. Veja:
	*/
	int x = 10;
	int *pX = &x; // Equivale a "pX = &x" fora da declaração.
	printf("\npX = %d",pX); // Imprimirá o endereço de memória de x.
	printf("\n*pX = %d",*pX); // Imprimirá a derreferência de pX (subir na escada), que é 10.
	// Portanto isso confirma a teoria em dizer que o ponteiro é uma característica/atributo especial da variável que, caso utilizado, ele cumprirá o seu papel de derreferenciar a variável.
	
	
	
	
	int z = 7; // Pense numa escada na qual o primeiro degrau é o nó raíz ...
	int *pZ = &z; // ... e descer nesta escada significa referenciar cada vez mais.
	int **ppZ = &pZ;
	int ***pppZ = &ppZ;
	int ****ppppZ = &pppZ; // E SUBIR na escada significa DERREFERENCIAR.
	// ... ao infinito e além ...
	
	/*
	Então, o que os ponteiros fazem é unicamente DERREFERENCIAR endereços.
	Você pode estar se perguntando onde que está o ponteiro (*) nas atribuições...
	*/
	
	
	
	// ... por exemplo, você diria o seguinte:
	//"em int **ppZ = &pZ, não deveria ser, na verdade, int **ppZ = &*pZ ???"
	/* E a resposta é: NÃO!*/
	
	// Ora, se os ponteiros DERREFERENCIAM, significa que se eu atribuísse um ponteiro, eu estaria derreferenciando aquela variável para o compilador, ou seja, subindo na escada.
	// E, dessa forma, atribuindo algo que não é equivalente a um ponteiro duplo, nesse caso.
	// Faça o teste e perceba o erro do compilador: ele subiu na escada e foi para o tipo anterior!!!! :-)
	
	
	
	
	printf("\n\n***pppZ = %d",***pppZ);
	printf("\n&***pppZ = %d",&***pppZ);
	printf("\n&z = %d",&z);
	
	
	
	printf("\n\n&****ppppZ = %d",&****ppppZ);
	printf("\n&z = %d",&z);
	
	
	// Perceba, então, que cada ponteiro é uma referência para uma variável.
	// E essa variável terá um endereço e um valor, como de costume.
	
	// Se você estiver lidando com ponteiros, necessariamente, estará lidando com referências.
	// Isto é: para cada ponteiro, +1 endereço.	
	
	
	
	
	
}