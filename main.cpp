#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **charSquare(int n);
void drawCharSquare(char **square, int n);

int main(int argc, char **argv)
{
	int n=atoi(argv[1]);
	srand(argc==3? atoi(argv[2]): time(NULL));
	drawCharSquare(charSquare(n), n);
	printf("\n");
}

char **charSquare(int n)
{
	char **square=new char*[n];
	for (int i=0; i<n; i++)
		square[i]=new char[n];
		
	for (int j=0; j<n*n; j++)
		square[j/n][j%n]= 'a'+rand()%('z'-'a'); 

	return square;
}

void drawCharSquare(char **square, int n)
{
		for (int j=0; j<n*n; j++)
			(j%n==0&&j!=0)?printf("\n%c ", square[j/n][j%n]):
			printf("%c ", square[j/n][j%n]);

		for (int i=0; i<n; i++)
		{
			delete[] square[i];
		}
		delete[] square;
}