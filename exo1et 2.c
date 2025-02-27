/*
    algorithme s max pos
    variable T:tableau entier;
                    n,i,max,pos;
     debut
            si(i==3)faire
               fin;
            finsi
            afficher("veuillez entrer la taille du tableau T(entre 1à 50 ");
            saisir(n);
            i++;
            tantque((n>100) || (n<2));
            pour(i<-0;i<n;i++)faire 
                    afficher("T[",i,"]= ");
                    saisir(T[i]);
            fin
            pour(i<-0;i<n;i++)faire
                    afficher("T[",i,"]="T[i]);
            finpour
           s<-0;
           pour(i<-0;i<n;i++)faire
                   s<-s+T[i];
            finpour
            afficher("la somme s=",s);
            max<-T[0];
            pos<-1;
            pour(i=1;i<n;i++)faire
                    si(max<T[i])alors
                      max<-T[i];
                      pos<-i+1;
                    finsi
            finpour
            afficher("le max=",max," se trouve au ",pos," position");
     fin     
*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	  int T[50];
	  int n,i,max,s,pos;
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
    while((n>100)|| (n<2));

	  for(i=0;i<n;i++)
	  {
	      printf(" T[%d]= ",i);
	      scanf("%d",&T[i]);
	  }
	  for(i=0;i<n;i++)
	  {
	       printf("T[%d]=%d\n",i,T[i]);
	  }
	  s=0;
	  for(i=0;i<n;i++)
	  { 
	     s=s+T[i];
	  }
	  printf("la somme s=%d\n",s);
      max=T[0];
      pos=1;
      for(i=1;i<n;i++)
      {
           if(max<T[i])
           { 
              max=T[i];
              pos=i+1;
           }  
      }
      
      printf("le max =%d se trouve au %d position ",max,pos);
      	  	
      return(0);
}

