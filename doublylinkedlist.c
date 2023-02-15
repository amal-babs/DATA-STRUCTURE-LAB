#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;  
void insertion_beginning();  
void insertion_last();  
void insertion_specified();  
void deletion_beginning();  
void deletion_last();  
void deletion_specified();  
void display();  
void main ()  
{  
int choice =0;  
    while(choice != 9)  
    {    
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert a Value in a node\n4.Delete from Beginning\n5.Delete from last\n6.Delete the  value in node          \n7.Show\n8.Exit\n");  
        printf("\nEnter your choice?\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insertion_beginning();  
            break;  
            case 2:  
            insertion_last();  
            break;  
            case 3:  
            insertion_specified();  
            break;  
            case 4:  
            deletion_beginning();  
            break;  
            case 5:  
            deletion_last();  
            break;  
            case 6:  
            deletion_specified();  
            break;    
            case 7:  
            display();  
            break;  
            case 8:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
  
}  
void insertion_beginning()  
{  
   struct node *ptr;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
    printf("\nEnter Item value");  
    scanf("%d",&item);  
      
   if(head==NULL)  
   {  
       ptr->next = NULL;  
       ptr->prev=NULL;  
       ptr->data=item;  
       head=ptr;  
   }  
   else   
   {  
       ptr->data=item;  
       ptr->prev=NULL;  
       ptr->next = head;  
       head->prev=ptr;  
       head=ptr;  
   }  
   printf("\nNode inserted\n");  
}  
     
}  
void insertion_last()  
{  
   struct node *ptr,*temp;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
       printf("\nEnter value");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(head == NULL)  
       {  
           ptr->next = NULL;  
           ptr->prev = NULL;  
           head = ptr;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          ptr->next = NULL;  
          }  
             
       }  
     printf("\nnode inserted\n");  
    }  
void insertion_specified()  
{  
	int key;
   struct node *ptr,*ptr1;  
   struct node *new=NULL;
	new=(struct node*)malloc(sizeof(struct node));
	printf("\nenter the key value");
		scanf("%d",&key);
	printf("\nenter the data to be inserted");
		scanf("%d",&new->data);
	if(head==NULL)
		head=new;
	ptr=head;
	while(ptr->next!=NULL && ptr->data!=key)
		{
		ptr=ptr->next;
		}
	if(ptr->next==NULL)
		{
		ptr->next=new;
		ptr->prev=ptr;
		}
	else
	{
	ptr1=ptr->next;
	new->next=ptr1;
	new->prev=ptr;
	ptr->next=new;
	ptr1->prev=new;
	}
} 
  
void deletion_beginning()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("\nnode deleted\n");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
  
}  

void deletion_last()  
{  
    struct node *ptr; 
	ptr=head; 
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(ptr->next == NULL)  
    {  
        head = NULL;   
        free(ptr);   
        printf("\nnode deleted\n");  
    }  
    else   
    {  
        ptr = head;   
        while(ptr->next != NULL)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = NULL;   
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
}  

void deletion_specified()  
{  
    struct node *ptr;  
    int key;  
	ptr=head;
    printf("\nEnter the element to delete: ");  
    scanf("%d", &key);  
   if(ptr->data == key){
		deletion_beginning();
	}
    if(head == NULL)  
    {  
        printf("\nlist is empty\n");  
    }  
    else {
	ptr=head;
    while(ptr->next !=NULL && ptr->data !=key)
	{
	ptr=ptr->next;
	}
    if (ptr==NULL)
	printf("\nelement not found\n");
    else 
    {   
      ptr->prev->next=ptr->next;
	if(ptr->next!=NULL)
	ptr->next->prev=ptr->prev;
	else
	ptr->next=NULL;
	free(ptr);
	}
    }	
 }  

void display()  
{  
    struct node *ptr; 
	ptr = head;
	if(ptr==NULL)
	printf("linked list is empty");
	else
	
    	printf("\n printing values...\n");  
    
    while(ptr != NULL)  
    {  
        printf("%d\n",ptr->data);  
        ptr=ptr->next;  
    }  
}   
