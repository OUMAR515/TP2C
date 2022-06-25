#include<stdio.h>
#include<stdlib.h>
int pgcd(int m,int n)
{
    int r;
    if(m>n)
    {
        r=m%n;
        if(r==0)
        {
            return n; 
        }
        else
        {
         return pgcd(n,r);
        }

    }
    else
    {
        r=n%m;
        if(r==0)
        {
            return m;
        }
        else
        {
            return pgcd(m,r);
        }
    }
}
int main ()
{
    /*
    la partie de la fonction principale.
    Dans cette partie nous ferons
    appel à notre fonction PGCD.
    */
    int A,B;
    do
    {
        printf("Veuillez saisir un entier\n");
        scanf("%d\n",&A);
    } while (A<=0);
    do
    {
        printf("Veuillez saisir un autre entier\n");
        scanf("%d",&B);
    } while (B<=0);
     printf("PGCD(%d,%d)=%d\n",A,B,pgcd(A,B));
     return 0;
    
    


}