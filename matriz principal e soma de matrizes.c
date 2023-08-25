#include <stdio.h>
#include <time.h>
#include <stdlib.h>



//Aluno: Isaias Fabricio da Costa Silva
int main()
{
 int n = 3;
 int l, c, matriz1 [n] [n], matriz2 [n] [n], matriz3[n] [n];

srand(time(NULL));


for ( l = 0; l < n; l++) {
    for ( c = 0; c < n; c++) {
        matriz1 [l] [c] = rand() % 100;
        matriz2 [l] [c] = rand() % 100;
        matriz3 [l] [c] = matriz1 [l] [c] + matriz2 [l] [c];
    }

}


printf("A diagonal primária da matriz gerada é:\n\n");
for ( l = 0; l < n; l++) {
    for ( c = 0; c < n; c++) {
        if (l == c)
            printf("%d", matriz1 [l] [c]); 
        else 
            printf("  ");
        }
        printf("\n");
        

        
}
printf("\nO resultado da soma da matriz1 e matriz2 gerada aleatoriamente no computador é:\n\n");

   for(l = 0; l < n; l++){
        for(c = 0; c < n; c++){
            matriz3[l][c] = matriz1[l][c] + matriz2[l][c];
        }
    }

    for(l = 0; l < n; l++){
        for(c = 0; c < n; c++)
            printf("%2d ", matriz3[l][c]);
        printf("\n");
    }
 
    return 0;  
 
 


}

