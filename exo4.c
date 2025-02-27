/* algorithme TNeg et Tpos
    variables T:tableau entier[50];
                     TPOS:tableau entier[50];
                     TNEG:tableau entier[50];
                     i,n:entier;
   debut
           faire
                si(i==3)alors
                    fin;
                finsi
                afficher("veuillez entrer la taille du tableau T(entre 1 à 50");
                saisir(n);
                i++;
           tantque((n>50)||(n<2));
           pour(i<-0;i<n;i++)faire
                 afficher("T[",i,]= );
                  saisir(T[i]);
           finpour
           pour(i<-0;i<n;i++)faire
   
                si (T[i]>0)alors
                     TPOS[i]<-T[i];
                     afficher("TPOS[",i,"] =",TPOS[i]);
                finsi
                 si (T[i]<0)alors
                      TNEG[i]<-T[i];
                      afficher("TNEG[",i,"]=",TNEG[i]);
                 finsi
         finpour
  fin
*/ 
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int T[50];
	int TPOS[50];
	int TNEG[50];
	int i,n;
	     do 
    {
     	
     	if(i==3)
     	{
     	    exit (0);
     	}
         printf("veuillez entrer la taille du tableau T(entre 1 à  50) ");
         scanf("%d",&n);
         i++;
    }
    while((n>50)|| (n<2));
	
    for(i=0;i<n;i++)
    {
          printf(" T[%d] ",i);
          scanf("%d",&T[i]);
          
    }
    for(i=0;i<n;i++)
   {
         if(T[i]>0)
         { TPOS[i]=T[i];
            printf("TPOS[%d] = %d\n",i,TPOS[i]);           }
    }     
        
    for(i=0;i<n;i++)
         {
             if (T[i]<0)
          {   
                 TNEG[i]=T[i];
              printf("TNEG[%d]=%d\n",i,TNEG[i]);           }
    }           
return(0);
}

