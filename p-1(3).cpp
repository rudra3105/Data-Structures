//Practical - 1(3)


#include<stdio.h>
int main(){
   int element[10],i,j,temp;
   printf("enter 10 integer numbers:");
   for(i=0;i<10;i++){
      scanf("%d",&element[i]);
   }
   for(i=0;i<10-1;i++){
      for(j=i+1;j<10;j++){
         if(element[i]>element[j]){
            temp=element[i]; //swapping element[i] with element[j]
            element[i]=element[j];
            element[j]=temp;
         }
      }
   }
   printf("Elements are now in ascending order:");
   for(i=0;i<10;i++)
      printf("%d\n",element[i]);
   return 0;
}

