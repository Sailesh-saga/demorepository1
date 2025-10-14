/*//Implementation of stacks using Arrays
#include<stdio.h>
int stack[10000],size,top=-1;
void push(int val)
{
	//Overflown condition --> If the stack is already full
	if(top==size-1)
	{
		printf("Stack is overflown. No more insertions possible\n");
		return;
	}
	else
	{
		top++;
		stack[top]=val;//Or you can use stack[++top]=val (first increment and then the val is placed)	
	}
}
void display()
{
	if(top==-1)
	{
		printf("Stack is Underflow / Empty\n");
		return;
	}
	int i;
	for(i=top;i>=0;i--) printf("%d ",stack[i]);
	printf("\n");
}
void pop()
{
	if(top==-1)
	{
		printf("Stack is Underflown / Empty\n");
	}
	else
	{
		printf("Deleting: %d\n",stack[top]);
		top--;
	}
}
void peek()
{
	if(top==-1)
	{
		printf("Stack is Underflown / Empty\n");
		return;
	}
	else
	{
		printf("The element which is at the top of the stack : %d",stack[top]);
	}
	printf("\n");
}
int main()
{
	printf("Enter the max numbers of elements stack can hold: ");
	scanf("%d",&size);
	int ch;
	while(1)
	{
		printf("Enter\n1. Push\n2. Pop\n3. Display\n4. Peek\nAny other to exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			//Implement Push() ---> Adding a new element to the stack
			int e;
			printf("Enter an element to push into the stack: ");
			scanf("%d",&e);
			push(e);	//Function Call
		}
		else if(ch==2)
		{
			pop();
		}
		else if(ch==3)
		{
			display();
		}
		else if(ch==4)
		{
			peek();	
		}
		else
		{
			printf("Thank you!\n");
			break;
		}
	}
}*/
//coversion of postflix (reverse polish notation)
//Queues
#include<stdio.h>
int queue[1001];
int front=-1;
int rear=-1;
void ENQ(int val){
	if(rear>=1001) return;
	if(front==-1) front=0;
	queue[++rear]=val;
}
void DEQ(){
	if(front>=1001) return;
	front++;
}
void peek() {
	if(front==-1 || front>=1001) printf("It is empty\n");
	else printf("%d \n", queue[front]);
}
void DISPLAY(){
	int i;
	if(rear==-1)printf("EMPTY\n");
	for(i=front;i<=rear;i++){
		printf("%d ",queue[i]);
	}printf("\n");
}
void get_rear()
{
	if(front==-1 || front>=1001) printf("It is empty\n");
	else printf("%d\n", queue[rear]);
}
void is_full() {
	if(rear >= 1001) printf("It is Full\n");
}

int main(){
	while(1){
		printf("Q OPERATIONS\n\n");
		printf("1.ENQ\n\n");
		printf("2.DEQ\n\n");
		printf("3.DISPLAY\n\n");
		printf("4. PEEK\n\n");
		printf("5. REAR\n\n");
		printf("CHOOSE AN OPTION:\n");
		int option;
		scanf("%d",&option);
		if(option==1){
			int n;
			printf("enter value\n\n");
			scanf("%d",&n);
			ENQ(n);
		}
		else if(option==2){
			DEQ();
		}
		else if(option==3){
			DISPLAY();
		}
		else if(option==4)
		{
			peek();
		}
		else if(option == 5) {
			get_rear();
		}
		else {
			return 0;
		}
	}	
}



























