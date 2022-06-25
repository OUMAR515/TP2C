#include<stdio.h>
#include<stdlib.h>
void remplirTableau( int t[],int M )
{
	int i;
    for( i=0;i<=M-1;i++)
    {
        printf("Elements?valeurs %d ",i+1);
        scanf("%d",&t[i]);
    }
}
void afficherTableau(int t[],int M)
{
	int i;
    for( i=0;i<=M-1;i++)
    {
        printf("%d\n",t[i]);
    }
}


int maximumTab(int t[],int M)
{
   int i,max;
   max=t[0];
   for(i=1;i<=M-1;i++)
   {
       if(t[i]>max)
       {
           max=t[i];
       }
   }
   return max;

}
int sommeElements(int t[],int M)
{
    int s=0,i;
    for(i=0;i<=M-1;i++)
    {
        s=s+t[i];
    }
    return s;
}
int moyenneElements(int t[],int M)
{

    return (sommeElements(t,M)/M);
}
void inverserTableau(int t[],int M)
{
    int i,tampon;
    for(i=0;i<=M/2;i++)
    {
        tampon=t[i];
        t[i]=t[M-1-i];
        t[M-1-i]=tampon;
    }
}

int main()
{
    int tab[100],N;
    printf("Remplissage tableau\n");
    do
    {
        printf("Entrer la taille de votre ta tableau\n (taille>0)\n");
        scanf("%d",&N);
    } while (N<=0 || N>=100);
    remplirTableau(tab,N);
    printf("Affichage tableau\n");
    afficherTableau(tab,N);
    printf("le grand element de votre  tableau est:%d\n",maximumTab(tab,N));
    printf("la somme des elements de votre tableau est:%d\n",sommeElements(tab,N));
    printf("la moyenne  des elements de votre tableau est:%d\n",moyenneElements(tab,N));
    printf("Voici votre tableau apres inversion de ses elements\n");
    inverserTableau(tab,N);
    afficherTableau(tab,N);
    return 0;
}
