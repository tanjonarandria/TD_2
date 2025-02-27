/*
    algorithme s max pos
    variable T:tableau entier;
                    n,i,max,pos,posmin,min;
     debut
            si(i==3)faire
               fin;
            finsi
            afficher("veuillez entrer la taille du tableau T(entre 1à 100 ");
            saisir(n);
            i++;
            tantque((n>100) || (n<2));
            pour(i<-0;i<n;i++)faire 
                    afficher("T[",i,"]= ");
                    saisir(T[i]);
            fin
            pour(i<-0;i<n;i++)faire
                    afficher("T[",i,"]=",T[i]);
            finpour
            max<-T[0];
            min<-T[0];
            pos=1;
            posmin=1;
            pour(i=1;i<n;i++)faire
                    si(max<T[i])alors
                        max<-T[i];
                        pos<-i+1;
                    finsi
                    si(min>T[i])alors
                        min<-T[i];
                        posmin=i+1;
                    finsi 
            finpour
            afficher("le max=",max," se trouve au ",pos," position");
            afficher("le min =",min," se trouve au ",posmin,"position");
     fin   
  */ 
         
  #include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	  int T[50];
	  int n,i,max,pos,posmin,min;
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
	  min=T[0];
      max=T[0];
      pos=1;
      posmin=1;
      for(i=1;i<n;i++)
      {
          if(max<T[i])
           { 
              max=T[i];
              pos=i+1;
           }  
         if (min>T[i])
         {
              min=T[i];
              posmin=i+1;
         }
     }
      printf("le max =%d se trouve au %d position\n ",max,pos);
      printf("le min =%d se trouve au %d position",min,posmin);	  	
      return(0);
}

