#include<stdio.h>
#include<stdlib.h>
int fibo_itera(int n)
{
    int t[n+1],i;
    if(n==1 || n==2)
    {
        return 1;
    }
    else
    {
        t[1]=1;
        t[2]=1;
        for(i=3;i<=n;i++)
        {
            t[i]=t[i-1]+t[i-2];
        }
        return (t[n]);
    }
}
int fibo_recursiv(int n)
{
    if(n==1 || n==2)
    {
        return 1;
    }
    else
    {
        return (fibo_recursiv(n-1)+fibo_recursiv(n-2));
    }
}
int main()
{
    int N;
    do
    {
     printf("Veuillez entrer un numero de mois\n");
     scanf("%d",&N);
    } while (N<=0);
    printf("\n\n");
    printf("Avec la fonction iterative\n");
    printf("Au bout de %d mois, Macoumba aura %d pigeons\n",N,fibo_itera(N));
    printf("\n\n");
    printf("Avec la fonction recursive\n");
    printf("Au bout de %d mois, Macoumba aura %d pigeons\n",N,fibo_recursiv(N));
    return 0;
    
}