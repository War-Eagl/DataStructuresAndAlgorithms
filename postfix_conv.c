#include<stdio.h>
char a[20];
int top=-1;
int prec(char i);
int isOp(char i);
void main(){
   char exp[]="a+b+c";
   int i =0;
   do{
       if(isOp(exp[i])){
           while(prec(a[top])>=prec(exp[i])){
               printf("%c",pop());
           }
           push(exp[i]);
       }
       else{
           printf("%c",exp[i]);
       }
       i=i+1;
    }while(exp[i]!='\0');
    while(top!=-1)
    { printf("%d",pop());
    }
}


isOp(char i){
    return (i=='+')||(i=='-')||(i=='*')||(i=='/');
} 

prec(char i){
    switch(i){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
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
