#include<stdio.h>

int front=-1, rear=-1;
int a[20];

void add_proc(int time){
    if((front==0 && rear==max-1) || front==rear+1)
	{
		printf("queue is full\n");
	}
	else 
	{
		if(front==-1)
		{
			front=0;
		}
		rear=(rear+1)%max;
		queue[rear]=time;
	}
}

void rem_proc()
