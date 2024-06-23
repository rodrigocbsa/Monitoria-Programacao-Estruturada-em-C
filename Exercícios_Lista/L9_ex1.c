#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* MONITOR RODRIGO B. ARRUDA @2024 - PROG ESTRT

LISTA 9 - EXERCÍCIO NÚMERO 1


#include <stdio.h>
#include <conio.h>

int main()
{
const int registros = 256;
struct TASCII
{
int codigo;
char caractere;
} ascii;
FILE * arquivo;
char c, nomeArquivo[80];
int i;
char opcao;
printf("*******************************n");
printf("*** Manipulacao de arquivos ***n");
printf("*******************************nn");
printf("Informe o nome (com caminho) do arquivo a ser usado: ");
gets(nomeArquivo);
arquivo = fopen(nomeArquivo, "wb+");
printf("nARMAZENANDO DADOS NO ARQUIVO...n");
for(i = 1; i < registros; i = i+1)
{
ascii.codigo = i-1;
ascii.caractere = (char)(i-1);
fwrite(&ascii, sizeof(struct TASCII), 1, arquivo);
}
//ADICIONANDO UM REGISTRO AO FINAL DO ARQUIVO
fseek(arquivo, (registros-1) * sizeof(struct TASCII), 0);
ascii.codigo = i-1;
ascii.caractere = (char)(i-1);
fwrite(&ascii, sizeof(struct TASCII), 1, arquivo);
printf("nLENDO DADOS DO ARQUIVO...n");
printf("Tabela ASCII:n");
rewind(arquivo);
while(1)
{
fread(&ascii, sizeof(struct TASCII), 1, arquivo);
if (feof(arquivo)) break;
//S encontramos o fim de arquivo aps tentarmos ler um
//registro e acabarmos lendo o fim de arquivo
printf("%dt%cn" , ascii.codigo, ascii.caractere);
}
fclose(arquivo);
printf("nDeseja apagar o arquivo?n");
printf("[S]imn");
printf("[N]aon");
printf("[S/N]: ");
scanf("n%c", &opcao);
if ((opcao == 'S') || (opcao == 's'))
remove(nomeArquivo);
getch();
}

1. Escreva um programa para fornecer como saída a quantidade de registros armazenados no arquivo criado pelo programa acima.
A única informção que você, programador, dispõe é a estrutura de cada registro, enquanto que a única informção que o
usuário do programa dispõe é o nome do arquivo.
Suponha total desconhecimento sobre quantos registros o programa acima inseriu: isso é tarefa do seu programa.
*/


struct TASCII
{
	int codigo;
	char caractere;
} ascii; // Requisito do programador

int main()
{
	int contador = 0;
	char nomeArquivo[80];

	printf("Insira o nome do arquivo gerado pelo programa anterior: ");
	gets(nomeArquivo); // Requisito do usuário

	FILE * arquivo;
	arquivo = fopen(nomeArquivo,"rb"); // Apenas leitura binária

	while(1)
	{
		fread(&ascii, sizeof(struct TASCII), 1, arquivo); // Lê cada conteúdo do tamanho da referida estrutura.
		if (feof(arquivo)) break;
		contador++;
	}

	printf("A quantidade de itens no arquivo: %d",contador); //EXATAMENTE COMO EM "const int registros = 256;" NO PROGRAMA DO PROFESSOR.

	return 0;
}