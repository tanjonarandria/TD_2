/*
algorithme calcul de produit scalaire de 2 vecteurs
variable i,n,pscal:entier;
debut
               U:tableau entier[3];
               V:tableau entier[3];
               i<-0;
               faire 
               si (i==3) alors
                   fin;
               finsi
               afficher("Entrer n le nombre de composante des vecteurs u et v (entre 1 à 3));
                saisir(n);
                i++;
            tantque((n>3)||(n<1));
            afficher("Donner les coordonnées du vecteur v");
            pour(i<-0;i<n;i++)faire
                     afficher("V",i,"= ");
                     saisir(V[i]);
            finpour
            afficher("Donner les coordonnées du vecteur U");
              pour(i<-0;i<n;i++)faire
                     afficher("U",i,"= ");
                     saisir(U[i]);
             finpour
             pscal<-0;
             pour(i<-0;i<n;i++)faire
                     pscal<-U[i]*V[i]+pscal;
             finpour
             afficher("le produit scalaire de u et v est",pscal);
 fin        
                     
*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int i,n,pscal;
	int U[3];
    int V[3];
	i=0;
    do
{	
      if(i==3)
     {
	    exit(0);
	}
	printf(" Entrer n le nombre de composonte des 2 vecteurs u et v  (entre 1 a 3)  ");
	scanf("%d",&n);
	i++;
}
   while ((n>3)||(n<1));
   printf("Donner les coordonnées du vecteur v\n");
   for(i=0;i<n;i++)
   {
        printf("v%d = ",i);
        scanf("%d",&V[i]);
   }

  printf("Donner les coordonnées du vecteur u\n");
   for(i=0;i<n;i++)
   {
        printf("u%d = ",i);
        scanf("%d",&U[i]);
   } 
    pscal=0;
   for(i=0;i<n;i++)
   {
       pscal=U[i]*V[i]+pscal;
   }
   printf("le produit scalaire de u et v est %d",pscal);
   }

	    