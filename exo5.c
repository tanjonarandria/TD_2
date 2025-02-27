/*algorithme tableau inverse
   variable i,n,j,t:entier;
                  T:tableau entier[100];
   debut
       i<-0;
            faire
                si(i==3)alors
                    fin;
                finsi
            afficher("veuillez entrer la taille du tableau T(entre 1 à 100");
            saisir(n);
            i++; 
           tantque((n>100)(n<2));  
           pour(i<-0;i<-n;i++)faire
                   afficher("T[",i,"]= );
                   saisir(T[i]);
           finpour
           si(n%2==0)alors
             pour(i<-0,j<-n-1;i<=n/2,j<=n/2;i++,j++)faire
             t<-T[i];
             T[i]<-T[j];
             T[j]=t;
             finpour
           si(n%2!=0)alors
             pour(i<-0,j<-n-1;i<n/2,j<n/2;i++,j++)faire
             t<-T[i];
             T[i]<-T[j];
             T[j]<-t;
             finpour
             pour(i<-0;i<n;i++)faire
                    afficher("T[",i,"]=T[i]);
             finpour
   fin 
*/
            
          
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{ 
	int i,n,j,t;
	int T[100];
    i=0;
    do 
    {
     	
     	if(i==3)
     	{
     	    exit (0);
     	}
         printf("veuillez entrer la taille du tableau T(entre 1 à  100) ");
         scanf("%d",&n);
         i++;
    }
    while((n>100)|| (n<2));
	for (i=0;i<n;i++)
	{
	     printf("T[%d]= ",i);
	     scanf("%d",&T[i]);
	}
	if(n%2==0)
	{
	   for(i=0,j=n-1;i<=n/2,j>=n/2;i++,j--)
  	{
	    t=T[i];
	    T[i]=T[j];
	    T[j]=t;
   	}
	}
	else if (n%2!=0)
	{
	     for(i=0,j=n-1;i<n/2,j>n/2;i++,j--)
  	{
	    t=T[i];
	    T[i]=T[j];
	    T[j]=t;
   	}
	}
	
			for(i=0;i<n;i++)
	{
	     printf("T[%d]=%d\n",i,T[i]);
	}
   }
   

