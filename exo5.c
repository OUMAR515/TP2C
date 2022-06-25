#include<stdio.h>
#include<stdlib.h>
 int carreRec(int n)
 {
     if(n==0)
     {
         return 0;
     }
     else
     {
         return(carreRec(n-1)+2*n-1);
     }
 }
 int main()
 {
     int A;
     do
     {
         printf("Entrer un entier positif\n");
         scanf("%d",&A);
     }
     while(A<0);
     printf("le carre de %d est %d\n",A,carreRec(A));
     return 0;
 }


 