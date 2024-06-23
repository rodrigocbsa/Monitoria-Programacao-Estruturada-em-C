#include <stdio.h>
#include <stdlib.h>

const int rows = 2;
const int cols = 7;

void f1(int m1[rows][cols]){
	printf("M1:\n");
	for(int row = 0; row < rows; row++){
		for(int col = 0; col < cols; col++){
			printf("%d\t",m1[row][col]);
		}
		printf("\n");
	}
}

void f2(int ***m2){
	printf("\n\nM2:\n");
	for(int row = 0; row < rows; row++){
		for(int col = 0; col < cols; col++){
			printf("%d\t",(*m2)[row][col]);
		}
		printf("\n");
	}
}

void f3(int **m3){
	printf("\n\nM3:\n");
	for(int row = 0; row < rows; row++){
		for(int col = 0; col < cols; col++){
			printf("%d\t",m3[row][col]);
		}
		printf("\n");
	}
}


int main(){
	// PRIMEIRA FORMA: matriz[linhas][colunas] = {...};
	int m1[rows][cols];
	for(int row = 0; row < rows; row++){
		for(int col = 0; col < cols; col++){
			m1[row][col] = 1;
		}
	}

	// SEGUNDA FORMA: **matriz = malloc(linhas * sizeof(tipo*)); ou malloc(sizeof(tipo*[linhas]);
	int **m2 = malloc(rows * sizeof(int*));
	for(int row = 0; row < rows; row++){
		m2[row] = malloc(cols * sizeof(int)); // ou matriz[linha] = malloc(sizeof(int[colunas]));
		for(int col = 0; col < cols; col++){
			m2[row][col] = 2;
		}
	}

	// TERCEIRA FORMA: *matriz[linhas];
	int *m3[rows];
	for(int row = 0; row < rows; row++){
		m3[row] = malloc(cols * sizeof(int)); // ou matriz[linha] = malloc(sizeof(int[colunas]));
		for(int col = 0; col < cols; col++){
			m3[row][col] = 3;
		}
	}


	f1(m1);
	f2(&m2); // Decidi passar por referência apenas para ilustrar o que aconteceria. Veja.
	f3(m3);

	// Não se esqueça que após instanciar uma matriz com malloc, é necessário fazer o free() na ordem certa: cada linha primeiro, matriz depois
	for(int row = 0; row < rows; row++){
		free(m2[row]);
	}
	free(m2);


	for(int row = 0; row < rows; row++){
		free(m3[row]);
	}
	free(m3);
}