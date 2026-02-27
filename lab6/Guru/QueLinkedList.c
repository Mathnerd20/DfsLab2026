#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void enQueue(struct node **);
void deQueue(struct node **);
void display(struct node **);

int main(){
	struct node *rear;
	rear = NULL;
	printf("Enter 1 to add an element to the queue\n");
	printf("Enter 2 to extract an element from the queue\n");
	printf("Enter 3 to display elements of the queue\n");
	printf("Enter 0 to exit\n");
	int choice;
	do{
		scanf("%d", &choice);
		switch(choice){
			case 1:
				enQueue(&rear);
				break;
			case 2:
				deQueue(&rear);
				break;
			case 3:
				display(&rear);
				break;
		}
	}while(choice);
}

void enQueue(struct node **rear){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter value to be added:");
	int val;
	scanf("%d", &val);
	temp->data = val;
	if(*rear == NULL){
		*rear = temp;
		(*rear)->next = *rear;
	}
	else{
		temp->next = (*rear)->next;
		(*rear)->next = temp;
		*rear = temp;
	}
	
}

void deQueue(struct node **rear){
	struct node *temp;
	if(*rear == NULL){
		printf("Queue is empty");
		return;
	}
	if((*rear)->next == *rear){
		temp = *rear;
		*rear = NULL;
	}
	else{
		temp = (*rear)->next;
		(*rear)->next = temp->next;
	}
	printf("Extracted elements is %d", temp->data);
	free(temp);
}

void display(struct node **rear){
	struct node *p;
	if(*rear == NULL){
		printf("Queue is empty");
		return;
	}
	p = *rear;
	do{
		p = p->next;
		printf("%d ", p->data);
	}while(p != *rear);
}
