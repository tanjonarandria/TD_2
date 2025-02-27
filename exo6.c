/* algorithme element B a la fin de A
    variable i,N,M,M1,n,j:entier;
                   A:tableau entier[150];
                   B:tableau entier[50];
    debut
          faire 
          i++;
          si(i>3)alors
             fin;
          finsi
          afficher("entrer la taille N du tableau B");
          saisir(N);
          afficher("entrer la taille du tableau A (entre 1 à 100)");
          saisir(M);
          si (N>M)alors
            afficher("verifier que N soit inférieur à M");
           si(M>100)alors
               afficher("M est inférieur à 100");
           finsi
          tantque((N>M)||(A>100));
          afficher("Donner des valeur dans le tableau B");
          pour(j<-0;j<N;j++)
                afficher("        B[",j,"]= " );
                saisir(B[j]);
          finpour
          afficher("les valeurs dans le tableau B sont ");
           pour(j<-0;j<N;j++)faire
                afficher("        B[",j,"]=",B[j]);
           finpour
           afficher("Donner maintenant des valeurs dans le tableau A");
           pour(i=0;i<M;i++)faire
                   afficher("A[",i,"]= ");
                   saisir(A[j]);
           finpour
           
     pour (i<-M,j<-0;i<M+N,j<N;i++,j++)faire
             A[i]<-B[j];
     finpour   
     afficher("finalement,on a");
     pour(i<-0;i<N+M;i++)faire
           afficher(A[i]);
     finpour
 fin*/
     
   
       
       
          
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{  
      int i,N,M,M1,n,j;
      int A[100];
      int B[50];
      do
      {
        i++;
        if(i>3)
        {
            exit (0);
        }
        printf("entrer la taille N du tableau B ");
        scanf("%d",&N);
        printf("entrer la taille M du tableau A (entre 1 à 100) ");
        scanf("%d",&M);
        if(N>M)
        {
             printf("verifier que N soit inférieur à  M \n"); 
        }
        if (M>100)
        {
            printf("M est inférieur à 100\n");
        }
 
  
     } 
        while((N>M) || (M>100) ); 
      printf("Donner des valeur dans le tableau B\n");
      for(j=0;j<N;j++)
      {
          printf("\t          B[%d]= ",j);
          scanf("%d",&B[j]);
      }
      printf("\nles valeurs dans le tableau B sont\n");
      for (j=0;j<N;j++)
      {
            printf("\t  B[%d] =%d \n",i,B[i]);
      }
      printf("Donner maintenant des valeurs dans le tableau A \n");
      for (i=0;i<M;i++)
      {
            printf(" A[%d]= ",i);
            scanf("%d",&A[i]);
      }
      for (i=M,j=0;i<M+N,j<N;i++,j++)
      {  
             A[i]=B[j];
      }
      printf("finalement,on a \n");
      for(i=0;i<M+N;i++)
      {
          printf("  %d ",A[i]);
      }
      return(0);
      
}
 
 