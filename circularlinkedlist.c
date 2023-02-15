#include <stdio.h>
#include <stdlib.h>
int f=-1, r=-1,item,size,a[30];
void insertion();
void deletion();
void display();
void main(){  
 int choice;
 printf("enter the size of queue:");
 scanf("%d",&size);

    do{

    printf("\n1.Insertion\n2.deletion\n3.display\n");
    scanf("%d",&choice);
    switch (choice){    
     case 1:
     insertion();
     break;
     case 2:
     deletion();
     break;
     case 3:
     display();
     break;
     default:
     printf("enter a valid choice");
     }
   } 
   while(choice != 4);
 }
 

     void insertion()
     {
         if(f==(r+1)%size)

         {
         printf("queue is full");
     }
   else
     { 
         printf("enter the data to be inserted:");
         scanf("%d",&item);
    
     if(f== -1&&r== -1)
     {
      f=r=0;
      a[r]=item;
     }
     else
     {
     r=(r+1)%size;
     a[r]=item;
     }
    }
 }
 
 void deletion()
{ 
   if(f==-1)
   {
       printf("queue is empty");
   }
   else if(f==r)
   {
       printf("deleted valuve %d",a[f]);
    f=r=-1;
   }
    else
    { 
         printf("\ndeleted valuve %d",a[f]);
         f=(f+1)%size;
    }
}
void display(){
int temp;
temp=f;
if(f==-1&&r==-1)
{
    printf("queue is empty");
}
else
   {
    printf("elements are:\n");
      while(temp>-1)
      {
          printf("%d", a[temp]);
          if(temp==r)
          break;
          temp=(temp+1)%size;
      }
   }

}
