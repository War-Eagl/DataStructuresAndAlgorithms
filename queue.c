#include<stdio.h>
int start=20, end=20;
int a[20];
void main()
{
    int k;
    while(1){
    printf("press 1,2,3 for enqueue, dequeue, display respectively");
    scanf("%d",&k);
    switch(k){
        case 1: enqueue();break;
        case 2: printf("%d",dequeue());break;
        case 3: display();break;
    }
        
    }
    
}

void enqueue(){
    if(end==0){
        printf("Queue is full");
    }
    scanf("%d",&a[end]);
    end=end-1;
    return;
}
int dequeue(){
    if(start==end){
        printf("Queue is empty");
        return;
    }
    start=start-1;
    return a[start+1];
}

void display(){
    for(int i=end+1;i<=start; i++)
    {
        printf("%d",a[i]);
    }
    return;
}
