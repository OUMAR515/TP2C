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
    } while (p->noteAlgo<0 ||  p->noteAlgo>20);


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
void triNoteALgo(Eleve t[],int M)
{
    int i,j,imin;
      Eleve tampon;


        for(i=0;i<=M-2;i++)
        {
            imin=i;
           for(j=i+1;j<=M-1;j++)
           {
               if(t[imin].noteAlgo<t[j].noteAlgo)
               {
                  imin=j;
               }
           }
           tampon=t[i];
           t[i]=t[imin];
           t[imin]=tampon;


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
int indexDe(Eleve t[],int gauche,int droite,float NoteRecherchee)
{
    int milieu;
    if(gauche<=droite)
    {
        milieu=(gauche+droite)/2;
        if(t[milieu].noteAlgo==NoteRecherchee)
        {
            return milieu;
        }
        else if(t[milieu].noteAlgo<NoteRecherchee)
        {
            return  (indexDe (t,gauche,milieu-1,NoteRecherchee)+1);
        }
        else
        {
            return (indexDe (t,milieu+1,droite,NoteRecherchee)+1);
        }
    }
    else
    {
      return -1;
    }
}
int main()


{

     Eleve T[N];
     float Note;
     int g=0,d=N-1;
     printf("Remplissage du tableau d'Eleves\n");
     printf("\n\n");
     remplirTab(T,N);
     printf("\n\n");
     printf("Affichage du tableau d'Eleves\n");
     printf("\n\n");
     afficherTab(T,N);
     triNoteALgo(T,N);
     printf("_______________ saut de ligne _______________________*********\n");
     afficherTab(T,N);
     do
     {
         printf("Recherche d'une note dans le tableau Eleve\n");
         printf("Veuillez saisir une note valide\n");
         scanf("%f",&Note);
     } while (Note<0 || Note>20);
     printf("votre note saisie est a la position %d\n",indexDe(T,g,d,Note));

}
