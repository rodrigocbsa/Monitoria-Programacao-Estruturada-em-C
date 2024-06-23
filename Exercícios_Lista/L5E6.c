/*
Questão 6 da Lista 5
Monitor Rodrigo CBSA
@2024
*/

#include <stdio.h>

int oposto(int numero); //Calcula o oposto de um número, apenas com ++ ou -- (isto é, inverte o sinal)
//int modulo(int numero); //Mesma lógica do anterior
int subtracao(int numero1,int numero2);
//int adicao(int numero1,int numero2); //Lógica similar à anterior
int multiplicacao(int numero1,int numero2);
//int divisao(int numero1,int numero2); //Deve ser a msm coisa do anterior, só que invertido né
int resto(int numero1,int numero2);


/*
(EXTRA)

NOTE: (IMPORTANTE)
x = 10 e z = 0
z = x++; // z = 10 e x = 11
z = ++x; // x = 12 e z = 12

*/

int main(){
	
	int numero1, numero2;
	printf("Insira dois numeros inteiros separados por espaco: ");
	scanf("%d %d",&numero1,&numero2);
	
	printf("\n\nO oposto deles: %d %d",oposto(numero1),oposto(numero2));
	printf("\nA subtracao deles: %d",subtracao(numero1,numero2));
	printf("\nA multiplicacao deles: %d",multiplicacao(numero1,numero2));
}

int oposto(int numero){
	/*
	Se precisamos calcular o oposto de um número e só podendo utilizar os operadores ++ e --, pense:
	
	Caso 1: se for positivo (>0), precisamos decrementar (--) em mesma quantidade do valor absoluto do número
	Caso 2: se for negativo (<0), precisamos incrementar (++) em mesma quantidade do valor absoluto do número
	ah, e se for 0, obviamente, é o próprio 0.
	
	
	Deve haver mais de uma forma de se resolver isso, mas eu pensei numa variável independente que se inicie em 0 e que:
	++ se numero for negativo;
	-- se numero for positivo;
	até "numero" estiver zerado.
	
	
	Então vamos lá
	*/
	int oposto = 0;
	
	
	if(numero == 0) return numero;
	
	else if(numero < 0)
		while(oposto, numero != 0, numero++) oposto++;
	// IMPORTANTE: a declaração da primeira variável dentro do escopo do loop só é permitido em C++ (não em C)
	else
		while(oposto, numero != 0, numero--) oposto--;
	// IMPORTANTE 2: nesse caso as expressões do while são separadas por "," e não ";"
	// poderia fazer com do while (adiante)
		                                                   
	return oposto;
}
	

int subtracao(int numero1,int numero2){
	/* um pouco mais de cautela
	
	
	Caso: 1 - 1 = 0
	Caso: -1 - 1 = -2
	Caso: 1 - -1 = 2
	Caso: 0 - 1 = 1
	
	
	
	*/
	
	int resultado;
	
	if(numero1 == 0) return numero2;
	else if(numero2 == 0) return numero1;
	
	if(numero1 > 0 && numero2 > 0){
		do{
			numero1--; //Perceba que é uma lógica muito similar ao primeiro: vou decrementar numero1 até que satisfaça a operação (numero2 = 0)
			numero2--;
		}while(numero2 != 0);
		
		return numero1;
	}
	else{
		
	}
	// O resto deve ser similar tbm
}


int multiplicacao(int numero1, int numero2){
	// Na matemática, o ato de multiplicar é somar um número x vezes
	// 2 x 4 = 2 + 2 + 2 + 2
	
	// Se um deles for negativo, o resultado é negativo. Se ambos forem negativos, o resultado dará positivo.
	// Precisa verificar e retirar o sinal, jogando apenas ao final da função.
	
	
	if(numero1 == 0 || numero2 == 0) return 0;
	else if(numero1 == 1) return numero2;
	else if(numero2 == 1) return numero1;
	
	int repeticoes,valor,resultado = 0;
	for(repeticoes = numero2; repeticoes != 0; repeticoes--){
		for(valor = numero1; valor != 0; valor--){
			resultado++;
		}
	}
	
	// Jogar o sinal aqui, caso seja necessário...
	
	return resultado;
}

int resto(int numero1,int numero2){
	//Fica de desafio
}