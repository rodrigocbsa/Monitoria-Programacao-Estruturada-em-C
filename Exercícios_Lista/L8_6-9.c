#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Lista 8 - Monitor Rodrigo B. Arruda
@2024
*/

/* QUESTAO NUMERO 6 */
typedef enum {comercial = 1, residencial, movel} TiposTelefone; // Considere os enums como "structs fixas" (imutaveis). Escrevi de uma forma diferente aqui, mas pode ser de outras formas... tem de sal e tem de doce. Explico mais adiante esse typedef.
// Automaticamente os proximos enumerados receberao 2 e 3. Sem o numero 1, inicia-se sozinho no zero como nos vetores!
typedef struct{
	int ddd, *numero; // Cuidado com a escolha de tipos para identificar seus atributos: se colocar apenas inteiro, pode ser que estrapole o tamanho numerico que eh possivel armazenar um inteiro aqui em "numero". Tambem poderia ser um array de caracteres ou outra coisa, depende do seu programa... Qual eh a melhor opcao? Aquela que melhor simplificar o seu programa
	TiposTelefone tipo; // Aqui eh o NOME do atributo da minha struct "TTelefone" que se chama "tipo". Esse meu atributo eh um enumeravel "TiposTelefone". Eu poderia ter chamado o atributo de "batata", se quisesse... nao confunda isso.
	//TiposTelefone batata;
} TTelefone;

typedef struct{
	char *nome;
	char sigla_estado[1]; /*(apenas para fins comparativos, explicacao na main)*/
	TTelefone telefone;
} TContato;
//$6_END


/* QUESTAO NUMERO 7 */
typedef enum { verde, amarelo, azul, branco } Setor;
typedef enum { F1 = 1, F2, F3, F4, F5, F6, F7, F8, F9, F10 } Fileira;
typedef enum { A = 'A', B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y } Coluna; // Aqui fica como na tabela ASCII
typedef struct{
	Fileira fileira;
	Coluna coluna;
	Setor setor;
} TPosicaoCadeira;
//$7_END


/* QUESTAO NUMERO 8 */
typedef struct{
	int ordenada;
	int abscissa;
} TPonto; // Dai fica facil alterar o seu codigo ja feito: apague todos os parametros na funcao e coloque apenas esse tipo, assim como no retorno da funcao. Simples!!
//$8_END


/* QUESTAO NUMERO 9 */
////é de fato a mesma coisa do anterior. Fica como treino para voces. Valeu!
//$9_END


int main(){
	
	/* ALGUNS COMENTARIOS PARA A QUESTAO NUMERO 6 */
	TTelefone meu_telefone; // Eu prefiro colocar "typedef ..." la em cima por causa disso. Eu nao preciso ficar sempre colocando "enum" toda vez antes das minhas declaracoes.
	// Ex.: se eu tivesse declarado a minha struct la em cima como "struct TTelefone{};" aqui eu teria que por:
	//// struct TTelefone meu_telefone;
	// Enfim, eh apenas uma preferencia para nao precisar ficar me preocupando com os tipos, pois ja vai direto com typedef. Assim como nos enums. Ok?
	
	//meu_telefone.tipo = batata; Eu nao posso fazer isso pois nao tem o item "batata" no meu enumeravel. Mas posso fazer com movel, residencial ou comercial.
	meu_telefone.tipo = movel;
	printf("%d",meu_telefone.tipo); // "3"
	meu_telefone.ddd = 22;
	meu_telefone.numero = malloc(sizeof(int)); // lembre-se que sao aplicadas as mesmissimas regras com ponteiros.
	*meu_telefone.numero = 991019898;
	printf("\n(%d) %d",meu_telefone.ddd,*meu_telefone.numero);
	
	TContato minha_pessoa;
	minha_pessoa.telefone = meu_telefone;
	printf("\n%d",*minha_pessoa.telefone.numero);
	
	
	/* OBSERVACAO IMPORTANTE */
	//minha_pessoa.nome = "Rodrigo";  /*nao eh possivel fazer isso em C (aceita que doi menos).*/
	minha_pessoa.nome = malloc(sizeof(char));
	strcpy(minha_pessoa.nome,"Rodrigo"); /* Biblioteca string.h */
	printf("\n%s",minha_pessoa.nome); // obs: Nao se coloca ponteiro para imprimir conteudos string.
	
	free(meu_telefone.numero);
	free(minha_pessoa.nome);
	
	
	/*(Extra)*/
	strcpy(minha_pessoa.sigla_estado,"RJ"); // Perceba a diferença para o anterior: um nome voce nao sabe quantos caracteres vai ter, por isso o uso de ponteiros foi justificado. Aqui, o meu estado tera apenas duas siglas, entao eu nao uso malloc e atribuo com o strcpy tambem. O nome no anterior tambem poderia ter sido implementado sem ponteiro, assim como nesse, por exemplo "nome[80]". Porem dai voce estaria falando que os seus nomes tem um limite maximo de caracteres (80) e nao pode passar disso! Mais uma vez, vai depender do seu programa.
	printf("\n%s",minha_pessoa.sigla_estado);
	//$6_END
	
	
	
	
	
	return 0;
}