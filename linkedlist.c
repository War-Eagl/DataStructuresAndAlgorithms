#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **head_ref, int data){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=*head_ref;
    *head_ref=new;
}

void insert(struct node **prev, int data){
    if(prev==NULL)
    {
        printf("Cannot insert after this node");
        return;
    }
    
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=*prev;
    *prev=new;
}

void append(struct node **head_ref, int data){
    struct node *new= (struct node*)malloc(sizeof(struct node));
    struct node *n=*head_ref;
    
    new->data=data;
    new->next=NULL;
    while(n!=NULL){
        n=n->next;
    }
    n->next=new;
}

void delete(struct node **head_ref, int position){
    if(head_ref==NULL){
        return;
    }
    
    struct node *temp=*head_ref;
    
    if(position==0){
        *head_ref=temp->next;
        free(temp);
        return;
    }
    
    for(int i=0; temp!=NULL && i<position-1; i++){
        temp=temp->next;
    }
    
    if(temp==NULL || temp->next==NULL)
        return;
    
    struct node *next= temp->next->next;
    free(temp->next);
    temp->next=next;
}

void printlist(struct node **head_ref){
    struct node *temp=*head_ref;
    
    do{
        printf("%d->",temp->data);
        temp=temp->next;
    }while(temp !=NULL);
}

int count(struct node **head_ref){
    int i=0;
    struct node *temp=*head_ref;
    
    do{
        i=i+1;
        temp=temp->next;
    }while(temp!=NULL);
    return i;
}

int *getnth(struct node **head_ref,int n){
    struct node *temp=*head_ref;
    if(n==-1)
        return (int*)*head_ref;
    for(int i=-1;i<=n-2;i++){
        temp=temp->next;
    }
    return (int*)temp->next;
}

void main(){
    struct node* head = NULL; 
  
    
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 8); 
    push(&head, 5);
    push(&head, 2);
    puts("Created Linked List: "); 
    printlist(&head); 
    delete(&head, 4); 
    puts("\nLinked List after Deletion at position 4: "); 
    printlist(&head);
    //printf("\n%d",count(&head));
    for(int i=-1;i<=3;i++){
    printf("\n%d",*getnth(&head,i));
    }
    
    insert(*getnth(&head,4),3);
}
