#include<stdio.h>
int a[20];
int top=-1; 
void main()
{
    int k;
    while(1){
        printf("1 for push 2 for pop 3 for display");
        scanf("%d",&k);
        switch(k){
            case 1:push();break;
            case 2:printf("%d",pop());break;
            case 3:display();break;
        }
    }
}

void push(){
    if(top==19){
        printf("Stack is full");
        return;
    }
    top=top+1;
    scanf("%d",&a[top]);
    return;
}

int pop(){
    if(top==-1){
        printf("Stack is empty");
        return;
    }
    top=top-1;
    return a[top+1];
}

void display(){
    for(int i=0;i<=top;i++){
        printf("%d",a[i]);
    }
    printf("\n");
}
    
            
