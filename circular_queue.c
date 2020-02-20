#include <stdio.h>

int start=-1, end=-1;
int a[5];

void enqueue(int x){
    if(size()==4){
        printf("Queue is full");
    }
    a[end]=x;
    end=end+1;
    return;
}

int dequeue(){
    if(size()==0){
        printf("Queue is empty");
        return;
    }
    start=start+1;
    return a[start-1];
}

int size(){
    if (end>=start)
        return (end-start+1);
    else if(start>end)
        return (20-start+end+1);
}

void display(){
    for(int i=start+1;i<=end; i++)
    {
        printf("%d",a[i]);
    }
    return;
}


void main()
{
    int k;
    int temp;
    while(1){
    printf("press 1,2,3 for enqueue, dequeue, display respectively");
    scanf("%d",&k);
    switch(k){
        case 1:
            scanf("%d",&temp);
            enqueue(temp);break;
        case 2: printf("%d",dequeue());break;
        case 3: display();break;
    }
        
    }
    
}
