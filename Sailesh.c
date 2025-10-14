/*Usage of Malloc:
#include<stdio.h>
#include<stdlib.h>
int *send_array(int A[],int n)
{
	int *B=(int *)malloc(sizeof(int)*n);//Since malloc gives you a void return so we just give it a data type as int * infront
	printf("Memory Allocated in Heap: %d\n",B);
	int i;
	for(i=0;i<n;i++)
	{
		B[i]=A[i]*A[i];
	}
	return B;
}
int main()
{
	int A[]={10,20,30,40,50};
	int *B=send_array(A,5);
	printf("Memory Stayed Intact: %d\n",B);
	int i;
	for(i=0;i<5;i++) printf("%d ",B[i]);
}*/


/*#include<stdio.h>
#include<stdlib.h> //for Dynamic Memory Allocation 
struct node
{
	int data; //Is used to store the data
	struct node *next;	//Store the address of next node
};
int main()
{
	
	struct node *n1=(struct node *)malloc(sizeof(struct node));
	n1->data=10;
	n1->next=NULL;
	struct node *n2=(struct node *)malloc(sizeof(struct node));
	n2->data=20;
	n2->next=NULL;
	struct node *n3=(struct node *)malloc(sizeof(struct node));
	n3->data=30;
	n3->next=NULL;
	//Connection forming
	n1->next=n2;
	n2->next=n3;
	printf("Node-1 Value:%d\n",n1->data);
	printf("Node-2 Value:%d\n",n1->next->data);
	printf("Node-3 Value:%d\n",n1->next->next->data);
}*/
/*#include<stdio.h>
#include<stdlib.h>
struct node
{	
	char data;
	struct node *next;
};
int main()
{
	struct node *n1=(struct node *)malloc(sizeof(struct node));
	n1->data='a';
	n1->next=NULL;
	struct node *n2=(struct node *)malloc(sizeof(struct node));
	n2->data='b';
	n2->next=NULL;
	struct node *n3=(struct node *)malloc(sizeof(struct node));
	n3->data='c';
	n3->next=NULL;
	struct node *n4=(struct node *)malloc(sizeof(struct node));
	n4->data='d';
	n4->next=NULL;
	struct node *n5=(struct node *)malloc(sizeof(struct node));
	n5->data='e';
	n5->next=NULL;
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	printf("Node-1 value :%c\n",n1->data);
	printf("Node-2 value :%c\n",n1->next->data);
	printf("Node-3 value :%c\n",n1->next->next->data);
	printf("Node-4 value :%c\n",n1->next->next->next->data);
	printf("Node-5 value :%c\n",n1->next->next->next->next->data);
}*/
/*#include<stdio.h>
#include<stdlib.h>
struct node
{	
	char data;
	struct node *next;
};
int main()
{
	struct node *n1=(struct node *)malloc(sizeof(struct node));
	n1->data='a';
	n1->next=NULL;
	struct node *n2=(struct node *)malloc(sizeof(struct node));
	n2->data='b';
	n2->next=NULL;
	struct node *n3=(struct node *)malloc(sizeof(struct node));
	n3->data='c';
	n3->next=NULL;
	struct node *n4=(struct node *)malloc(sizeof(struct node));
	n4->data='d';
	n4->next=NULL;
	struct node *n5=(struct node *)malloc(sizeof(struct node));
	n5->data='e';
	n5->next=NULL;
		n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	//Traversing through a linked list
	// Running a loop on a linked list
	struct node *temp=n1;//taking a temp variable to run a loop
	while(temp!=NULL)
	{
		printf("%c",temp->data);
		temp=temp->next;
	}
}*/
/*#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;	
};
//Global variable
struct node *head=NULL;
struct node *create_new_node(int value)
{
	struct node *new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=value;
	new_node->next=NULL;
}
void insert_at_head(int value)
{
	struct node *newnode=create_new_node(value);
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->next=head;//store address of current head in newnode's next
		head=newnode;//make newnode as your head
	}
}
void insert_at_tail(int value)
{
	struct node *newnode=create_new_node(value);
	if(head==NULL)//This is a possibility if there are no nodes 
	{
		head=newnode;
	}
	else
	{
		struct node *temp=head;//Here node is set to the first node 
		while(temp->next!=NULL)//This goes till we get to the node which has next node as NULL
		{
			temp=temp->next;//it moves through every node until it gets to the node which has NULL as the next address
		}
		temp->next=newnode;//After finding the node with NULL then new node is attached to the temp node
	}
}
void display()
{
	struct node *temp= head;
	if(temp==NULL)
	{
		printf("No node to Display\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
void deletion_at_head()
{
	struct node *temp=head;
	if(head==NULL)
	{
		printf("No nodes exist\n");
	}
	else
	{
		printf("%d is removed\n",head->data);
		head=head->next;
		free(temp);
	}
}
void deletion_at_tail()
{
	if(head==NULL)
	{
		printf("No nodes exist\n");
	}
	else if(head->next==NULL)
	{
		head=NULL;
	}
	else
	{
		struct node *temp=head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		printf("%d is deleted\n",temp->data);
		temp->next=NULL;
	}
}
void search_element(int key)
{
	struct node *temp=head;
	int c=0;
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			c++;
		}
		temp=temp->next;
	}
	if(c>0)
	{
		printf("Found!\n");
	}
	else
	{
		printf("Not found!\n");
	}
	
}
void count_of_nodes()
{
	struct node *temp=head;
	int c=0;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	printf("%d number of nodes are present\n",c);
}
void insert_position(int value,int pos)
{
	struct node *temp=head;
	struct node *newnode=create_new_node(value);
	int i=0;
	if(head==NULL||pos==0)
	{
		newnode->next=head;
		head=newnode;
	}
	else
	{
	
	while(i<pos-1 && temp->next!=NULL)
	{
		temp=temp->next;
		i++;
	}
	newnode->next=temp->next;
	temp->next=newnode;
	}	
}
void delete_by_position(int pos)
{
	struct node *temp=head;
	int i=0;
	while(i<pos-1)
	{
		temp=temp->next;
		i++;
	}
	temp->next=temp->next->next;
}
int main()
{
	int ch;
	while(1)
	{
		printf("Enter\n1. Insert at head\n2. Insert at tail\n3.Deletion at head\n4. Deletion at tail\n5.search an element\n6.node count\n7.Display\n8.Insert at a position\nAny other to exit:");
		scanf("%d",&ch);
		if(ch==1)
		{
			int val;
			printf("Enter the value to be inserted:");
			scanf("%d",&val);
			insert_at_head(val);
		}
		else if(ch==2)
		{
				int val;
			printf("Enter the value to be inserted:");
			scanf("%d",&val);
			insert_at_tail(val);
		}
		else if(ch==3)
		{
			deletion_at_head();
		}
		else if(ch==4)
		{
			deletion_at_tail();
		}
		else if(ch==5)
		{
			int key;
			printf("Enter the number:");
			scanf("%d",&key);
			search_element(key);
		}	
		else if(ch==6)
		{
			
			count_of_nodes();
			
		}
		else if(ch==7)
		{
			display();
		}
		else if(ch==8)
		{
			int value,pos;
			printf("Enter the position:");
			scanf("%d %d",&value,&pos);
			insert_position(value,pos);
		}
		else if(ch==9)
		{
			int pos;
			printf("Enter the position:");
			scanf("%d",&pos);
			delete_by_position(pos);
		}
		else
		{
			printf("Thank you!\n");
			break;
		}
	}
}*/
//Sparse Matrix form in singly linked list
/*#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	int row;
	int col;
	struct node *next;
};
struct node *head=NULL;
struct node *create_newnode(int value,int r,int c)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->row=r;
	newnode->col=c;
	newnode->next=NULL;
	return newnode;
}
void display()
{
	if(head==NULL)
	{
		printf("No Nodes to be displayed!\n");
	}
	else
	{
		struct node *temp=head;
		while(temp!=NULL)
		{
			printf("Row:%d\tColumn:%d\tData:%d\n",temp->row,temp->col,temp->data);
			temp=temp->next;
		}
	}
}
void insert_at_tail(int data,int row,int col)
{
	struct node *newnode=create_newnode(data,row,col);
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		struct node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void construct_sparse_matrix_from_ll(int m,int n)
{
	struct node *temp=head;
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			//Checking if a non - zero element is there at (i,j)
			if(temp->row==i && temp->col==j)
			{
				printf("%d ",temp->data);
				temp=temp->next;
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
	
}
int main()
{
	//Sparse Matrix
	int m,n;
	printf("Enter the dimensions of matrix:");
	scanf("%d %d",&m,&n);
	int non_zeroes,i;
	printf("Enter how many non - zeroes are there in the sparse matrix:");
	scanf("%d",&non_zeroes);
	for(i=0;i<non_zeroes;i++)
	{
		int r,c;
		printf("Enter the row and column coordinates of non-zero element %d :",i+1);
		scanf("%d %d",&r,&c);
		int value;
		printf("Enter the value of %d non zero element:",i+1);
		scanf("%d",&value);
		insert_at_tail(value,r,c);
	}
	display();
	construct_sparse_matrix_from_ll(m,n);
}*/
/*#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;	
};
typedef struct node node;
//Two global variables, one for maintaining head
// another for maintaining tail
node *head=NULL;
node *tail=NULL;
node* create_a_new_node(int value)
{
	node *newnode=(node *)malloc(sizeof(node));
	newnode->prev=NULL;
	newnode->data=value;
	newnode->next=NULL;
	return newnode;
}
void display_from_head()
{
	node *temp=head;
	if(head==NULL)
	{
		printf("No Nodes to be displayed!\n");
		return ;
	}
	else
	{
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
}
void display_from_tail()
{
	node *temp=tail;
	if(tail==NULL)
	{
		printf("No Nodes to be displayed!\n");
		return ;
	}
	else
	{
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->prev;
	}
	printf("\n");
	}
}
void insert_at_head(int value)
{
	node *newnode=create_a_new_node(value);
	if(head==NULL && tail==NULL)
	{
		head=newnode;
		tail=newnode;
	}
	else
	{
		head->prev=newnode;
		newnode->next=head;
		head=newnode;
	}
}
void insert_at_tail(int value)
{
	node *newnode=create_a_new_node(value);
	if(tail==NULL)
	{
		head=newnode;
		tail=newnode;
	}
	else
	{
		tail->next=newnode;
		newnode->prev=tail;
		tail=newnode;
	}
}
void delete_at_head()
{
	if(head==NULL)
	{
		printf("No nodes to be deleted!\n");
		return ;
	}
	else if(head==tail)
	{
		head=NULL;
		tail=NULL;
	}
	else
	{
		node *delnode=head;
		head->next->prev=NULL;
		head=head->next;
		free(delnode);
	}
}
void delete_at_tail()
{
	if(tail==NULL)
	{
		printf("No nodes to be deleted!\n");
		return;
	}
	else if(head==tail)
	{
		tail=NULL;
		head=NULL;
	}
	else
	{
		node *delnode=tail;
		tail->prev->next=NULL;
		tail=tail->prev;
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("Enter\n1.Insert at head\n2.Insert at tail\n3.Display from head\n4.Display from tail\n5.Delete at head\n6.Delete at tail\nAny other to exit:");
		scanf("%d",&ch);
		if(ch==1)
		{
			int value;
			printf("Enter the value to be inserted:");
			scanf("%d",&value);
			insert_at_head(value);
		}
		else if(ch==2)
		{
			int value;
			printf("Enter the value to be inserted:");
			scanf("%d",&value);
			insert_at_tail(value);
		}
		else if(ch==3)
		{
			display_from_head();
		}
		else if(ch==4)
		{
			display_from_tail();
		}
		else if(ch==5)
		{
			delete_at_head();
		}
		else if(ch==6)
		{
			delete_at_tail();
		}
		else
		{
			printf("Thank you\n");
			break;
		}
	}
}*/
//Quick Sort
/*#include<stdio.h>
void print_array(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int partition(int *arr,int l,int r)
{
	//Selecting first element of the array as pivot
	int pivot=arr[l];
	int temp[r-l+1];
	int j=0,i;
	for(i=l+1;i<=r;i++)
	{
		if(arr[i]<=pivot)
		{
			temp[j++]=arr[i];
		}
	}
	int pivot_index=l+j;//To find out the position of pivot in original array
	temp[j++]=pivot;
	//Bringing elements greater than pivot 
	for(i=l+1;i<=r;i++)
	{
		if(arr[i]>pivot)
		{
			temp[j++]=arr[i];
		}
	}
	j=0;
	for(i=l;i<=r;i++)
	{
		arr[i]=temp[j++];
	}
	return pivot_index;
}
void quick_sort(int *arr,int l,int r)
{
	if(l<r)
	{
		int p=partition(arr,l,r);
		quick_sort(arr,l,p-1);
		quick_sort(arr,p+1,r);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Before Sorting: ");
	print_array(arr,n);
	quick_sort(arr,0,n-1);
	printf("After Sorting:");
	print_array(arr,n);
}
//Polynomials
#include<stdio.h>
#include<math.h>
struct node
{
	int coeff;
	int expo;
	struct node *next;
};
struct node* create_polynomials()
{
	int n;
	printf("Enter the no of terms in the polynomial:");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		int coeff,expo;
		struct node *head=NULL;
		printf("Enter coefficient & exponent of term %d:",i+1);
		scanf("%d%d",&coeff,&expo);
		struct node *head=polynomials(head,coeff,expo);
	}
	return head;
}
struct node* polynomials(struct node* head,int value,int expo)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->coeff=value;
	newnode->expo=expo;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		struct node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;// attach the new node to last node
	}
}
void display()
{
	struct node *temp=head;
	if(temp==NULL)
	{
		printf("No node to display");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%dx^%d",temp->coeff,temp->expo);
			temp=temp->next;
		}
	}
}
int main()
{
	struct node *poly1=create_polynomials();
	display(poly1);
	struct node *poly2=create_polynomials();
	display(poly2);
}
//Circular linked list
/*#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *createanewnode(int val)
{
	node *newnode=(node *)malloc(sizeof(node));
	newnode->data=val;
	newnode->next=NULL;
	return newnode;
}
node *head = NULL;
void insertathead(int val)
{
	node *newnode=createanewnode(val);
	if(head==NULL)
	{
		head=newnode;
		head->next=head;
	}
	node *temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	temp->next=newnode; // connecting last node with to be head node
	newnode->next=head; // connecting new node with old head node
	head=newnode;	// making newnode as head node
}
void display()
{
	if(head==NULL)
	{
		printf("Linked List is Empty\n");
		return ;
	}
	node *temp=head;
	do{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=head);
}
void display2(int val)
{
	node *temp=head;
	for(int i=0;i<val;i++)
	{
		display();
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("Enter\n1. Insert at head\n2. Delete at tail\n3. Display\n4. Display2\nAny other option:\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			//Insert at head
			int val;
			printf("Enter a value for the node to be inserted:");
			scanf("%d",&val);
			insertathead(val);//implement the function
		}
		else if(ch==2)
		{
			//Delete at tail
			
		}
		else if(ch==3)
		{
			//Display
			display();
		}
		else if(ch==4)
		{
			int n;
			scanf("%d",&n);
			display2(n);
		}
		else 
		{
			printf("Thank you!");
			break;
		}
	}
}*/

