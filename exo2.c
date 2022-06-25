#include<stdio.h>
#include<stdlib.h>
#define N 2
  typedef struct
    {


      char code [100];
      char nom[100];
      char prenom[100];
      float noteAlgo;

    }Eleve;
void saisirEleve( Eleve *p)
{
    printf("Veuillez saisir le nom de l'eleve\n");
    fflush(stdin);
    gets(p->nom);
    printf("veuillez saisir le prenom de l'eleve\n");
    fflush(stdin);
    gets(p->prenom);
    printf("veuillez saisir le code de l'eleve\n");
    scanf("%s",&p->code);

  do
    {
        printf("Donner sa note\n");
        scanf("%f",&p->noteAlgo);
    } while (p->noteAlgo<0   ||  p->noteAlgo>20);


}
void afficherEleve( Eleve E)
{
    printf("Nom:%s\nPrenom:%s\nCode:%s\nNote_En_Algo:%f\n",E.nom,E.prenom,E.code,E.noteAlgo);
}
void remplirTab( Eleve t[],int M)
{
    int i;

    for(i=0;i<=M-1;i++)
    {
        printf("Veuillez saisir les informations de l'Etudiant%d\n",i+1);
        saisirEleve(&t[i]);

    }
}
void afficherTab( Eleve t[],int M)
{
    int i;
    for(i=0;i<=M-1;i++)
    {
        afficherEleve(t[i]);
        printf("\n\n");
    }

}
float moyenneclasse( Eleve t[],int M)
{
    int i,moy,s=0;
    for(i=0;i<=M-1;i++)
    {
        s=s+t[i].noteAlgo;

    }
    moy=s/M;
    return moy;

}
void statistiquesClasse( Eleve t[], int M,float *pg,float *pp,float *notemoy)
{
    int i;
    *notemoy=moyenneclasse(t,M);
    *pg=t[0].noteAlgo;
    for(i=0;i<=M-1;i++)
    {
        if(*pg<t[i].noteAlgo)
        {
            *pg=t[i].noteAlgo;
        }
    }
    *pp=t[0].noteAlgo;
    for(i=0;i<=M-1;i++)
    {
        if(*pp>t[i].noteAlgo)
        {
            *pp=t[i].noteAlgo;
        }
    }
    printf("la note moyenne de la classe est: %f\n",*notemoy);
    printf("La plus grande note de la classe est: %f\n",*pg);
    printf("La plus petite note de la classe est : %f\n",*pp);

}

int main()


{
    int i;
    float max,min,moyenne;

     Eleve T[N];
     printf("Remplissage du tableau d'Eleves\n");
     printf("\n\n");
     remplirTab(T,N);
     printf("\n\n");
     printf("Affichage du tableau d'Eleves\n");
     printf("\n\n");
     afficherTab(T,N);
     printf("\n\n");
     statistiquesClasse(T,N,&max,&min,&moyenne);
     printf("\n\n");
     return 0;



}
