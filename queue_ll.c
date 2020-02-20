gcc #include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
}*head=NULL,*temp,*y;

void insertion(int a)
{
	struct node* newnode=(struct node*) malloc(sizeof(struct node));
    newnode->data=a;
    newnode->next=NULL;
    if(head==NULL)
    {
    	struct node* temp=head;
        head=newnode;
        newnode->next=temp;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}

}

void deletion()
{
	temp=head;
	head=temp->next;
	printf("the element deleted is %d",temp->data);
	temp=NULL;
}

void display()
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL");

}

int main()
{
	int b,c,d;
	do

	{
		printf("\nchoose one of the below\n");
		printf(" 1.insertion\n 2.deletion\n 3.display\n 4.exit\n ");
		scanf("%d",&b);


		if(b==1)
		{
			printf("enter the element to be inserted ");
			scanf("%d",&c);
			insertion(c);
		}

        if(b==2)
		{
			deletion();
		}

        if(b==3)
		{
			display();
		}

	}while(b!=4);

	return 0;
}
