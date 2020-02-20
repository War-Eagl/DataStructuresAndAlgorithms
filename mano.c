#include<stdio.h>
char a[20];
int top=-1;
int prec(char a);
int isOp(char b);
void push(char i){
    if(top==19){
        printf("Stack is full");
    }
    top=top+1;
    a[top]=i;
 
}
int pop(){
    if(top==-1){
        printf("Stack is empty");
        return 0;
    }
    top=top-1;
    return a[top+1];
}

void main(){
   char p;
   char exp[]="a+c^d^e";
   int i =0;
   do{
       
       if(isOp(exp[i]))
       {
           if(top==-1)
           {
               push(exp[i]);
            }
           else
           {
           while(prec(a[top])>=prec(exp[i]))
           {
               if((exp[i]=='^')&&(a[top]=='^'))
                   break;
               else
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


isOp(char b){
    return (b=='+')||(b=='-')||(b=='*')||(b=='/')||(b=='^');
} 

prec(char a){
    switch(a){
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



