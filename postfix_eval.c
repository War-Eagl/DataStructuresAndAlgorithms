#include<stdio.h>

int a[20];
int top=-1;

void main(){
    char exp[]="73-24*+;
    int i=0;
    
    do{
        if(!((exp[i]=='+')||(exp[i]=='-')||(exp[i]=='*')||(exp[i]=='/')))
            push(exp[i]-'0');
        else{
            int a=pop();
            int b=pop();
            switch(exp[i]){
                case '+':
                    push(a+b);
                    break;
                case '-':
                    push(a-b);
                    break;
                case '*':
                    push(a*b);
                    break;
                case '/':
                    push(a/b);
                    break;
                
            }
        }
        i=i+1;
    }while(exp[i]!='\0');
        
        printf("%d",a[top]);
}

void push(int b){
    top=top+1;
    a[top]=b;
}

int pop(){
    top=top-1;
    return a[top+1];
}

