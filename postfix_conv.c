#include<stdio.h>
char a[20];
int top=-1;
int prec(char i);
int isOp(char i);
void main(){
   char p;
   char exp[]="a+b*c^(d/e)";
   int i =0;
   do{
       
       if(isOp(exp[i])){
           if(top==-1){
               push(exp[i]);
               }
           else{
           while(prec(a[top])>=prec(exp[i])){
               printf("%c",pop());
           }
           push(exp[i]);
           
       }
    }
       else{
           printf("%c",exp[i]);
       }
       i=i+1;
    }while(exp[i]!='\0');
    while(top!=-1)
    { printf("%c",pop());
    }
}


isOp(char i){
    return (i=='+')||(i=='-')||(i=='*')||(i=='/')||(i=='^')||(i=='(')||(i==')');
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
        case '(':
            return 4;
        default:
            return -1;
    }
}

void push(char i){
    if(top==19){
        printf("Stack is full");
        return;
    }
    top=top+1;
    a[top]=i;
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
