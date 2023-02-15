#include <stdio.h>
#include <stdlib.h>
struct node
  {
  int data;
  struct node *prev;
  struct node *next;
 };
  struct node *root=NULL; 
  struct node *ptr1=NULL;
  struct node *ptr=NULL;
  struct node *new=NULL;
  void insertion();
  void inorder(struct node*);
  void preorder(struct node*);
  void postorder(struct node*);
  void search(struct node*);
  void deletion(int);
  struct node* min_val_node(struct node*);
  
  void main() {
  int choice,value,x;
   do{
      printf("\n1.insertion\n2.inorder\n3.preorder\n4.postorder\n5.search\n6.deletion\n7.exit\nenter your choice:\n");
      scanf("%d",&choice);
      switch (choice)
      {
      case 1:
             printf("enter a value\n");
             scanf("%d",&value);
             insertion(value);
             break;
      case 2:
             inorder(root);
             break;
      case 3:
             preorder(root);
             break;
      case 4:       
             postorder(root);
             break;
      case 5:
             search(root);
             break;
      case 6:
             printf("enter a value\n");
             scanf("%d",&x);          
             deletion(x);
             break;
      case 7:
             exit(0);
             break;
      default:
      printf("enter a valid choice");
      }
     }
     while (choice!=7);
   }

     
void insertion(int value) {
	new = (struct node *)malloc(sizeof(struct node));
	if(new==NULL){
		printf("insufficent memory");
	}
	else { 
		new->next=new->prev=NULL;
		new->data=value;    
	        if(root==NULL){
		   root=new;
		}
		else{
			ptr=root;
			while(ptr!=NULL){
				if(value==ptr->data){
					printf("item present in the tree");
                                        break;                      
		   }
		   else if(value>ptr->data){
		     ptr1=ptr;
		     ptr=ptr->next;
		   }
			 else{
				   ptr1=ptr;
				   ptr=ptr->prev;
				}
			}
			if(value>ptr1->data){
				ptr1->next=new;
			}
			else{
				  ptr1->prev=new;
			}            
		}
	}
}
    
    void inorder(struct node *ptr)
  {
    if(ptr!=NULL)
   {
      inorder(ptr->prev);
       printf("%d ",ptr->data);
       inorder(ptr->next);
   }
  }   
    
     void preorder(struct node *ptr)
  {
    if(ptr!=NULL)
   {
       printf("%d ",ptr->data);
       preorder(ptr->prev);
       preorder(ptr->next);
   }
  }   
    
    void postorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->prev);
		postorder(ptr->next);
		printf("%d ",ptr->data);
	}
}
  void search(struct node *ptr){ 
    int data,flag=0;
    if(ptr==NULL){
		printf("\n tree empty");
	}
	else { 
	        printf("enter the element to find");
	        scanf("%d",&data);
		while(ptr!=NULL){
			if(data==ptr->data){
			printf("item present in the tree");
			ptr=NULL;
			 flag=1;                  
		   }
		   else if(data>ptr->data)
		          ptr=ptr->next;
		         
			 else
			      ptr=ptr->prev;
			}
			if(flag==0)
			printf("item not found");
     }
    } 
  
     
    void deletion( int x)
    {
    struct node *ptr=NULL;
     if(root==NULL)
     printf("tree is empty");
   else{
      struct node * parent=NULL;
       ptr=root;
       while(ptr!=NULL){
         if(ptr->data==x){  
       break;
     } 
     else{
        parent=ptr;
        if(x>ptr->data)
        ptr=ptr->next;
     else
            ptr=ptr->prev;
            }
         }
       if(ptr==NULL){
       printf("item not present in the tree");
       } 
           
    //case1       
     else{ 
        if(ptr->next==NULL && ptr->prev==NULL){
       if(parent==NULL)
        root=NULL;
        else if (parent->next==ptr)
          parent->next=NULL;
      else  
          parent->prev=NULL;
        free(ptr);
        }
        
      //case2   
     else if(ptr->next!=NULL && ptr->prev!=NULL){ 
         struct node *p=NULL;
	p=ptr->next;
	while(p->prev!=NULL)
	p=p->prev;
    int dat=p->data;
	deletion(dat); 
	ptr->data=dat;
	}     
     //case3
     else{
         if (parent==NULL){
    	if (ptr->next==NULL)
    	root=ptr->prev;
    	else
             root=ptr->next;
     }       
   else{
	if (parent->next==ptr){
    	if (ptr->next==NULL)
            parent->next=ptr->prev;
        else
           parent->next=ptr->next;
          }
	else{
	     if (ptr->prev==NULL)
	    	parent->prev= ptr->next;
		 else
               parent->prev=ptr->prev;
	     }
         free(ptr);
	   }
    }
  }
     printf("element deleted");
   }   
} 
     
     
     
     
     
     
     
     
     
     
        
      
