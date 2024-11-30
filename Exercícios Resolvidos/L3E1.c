#include <stdio.h>

void calculaPontoMedio(int p1X,int p1Y,int p2X,int p2Y,int *abscissa, int *ordenada);

int main(){
	
	int p1X, p1Y, p2X, p2Y;
	int abscissa,ordenada;
	
	scanf("%d %d %d %d", &p1X,&p1Y,&p2X,&p2Y);
	
	calculaPontoMedio(p1X,p1Y,p2X,p2Y,&abscissa,&ordenada);
	
	printf("%d %d",abscissa,ordenada);
	
	return 0;
}

void calculaPontoMedio(int p1X,int p1Y,int p2X,int p2Y,int *abscissa, int *ordenada){
	*abscissa = (p1X + p2X) / 2;
	*ordenada = (p1Y + p2Y) / 2;
}