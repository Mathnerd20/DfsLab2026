#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

void addEnd(struct node **, int);
void display(struct node **);
void displayHighest(struct node **);

int main(){
	struct node *head;
	head = NULL;
	printf("Enter elements in linked list\n Enter choice(enter '1' to enter elements, enter '0' to stop entering):");
	int inp;
	scanf("%d", &inp);
	while(inp){
		printf("Enter value of element:");
		int val;
		scanf("%d", &val);
		addEnd(&head, val);
		printf("Enter choice:");
		scanf("%d", &inp);
	}
	printf("Initial linked list:\n");
	display(&head);
	printf("Highest element in linked list:\n");
	displayHighest(&head);
}

void addEnd(struct node **head, int val){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = val;
	struct node *p;
	p = *head;
	if(p == NULL){
		*head = temp;
		(*head)->next = NULL;
	}
	else{
		if(p->next != NULL){
			while(p->next != NULL)
				p = p->next;
		}
		temp->next = NULL;	
		p->next = temp;
	}
}

void display(struct node **head){
	if(*head == NULL){
		printf("List empty");
		return;
	}
	struct node *p;
	p = *head;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void displayHighest(struct node **head){
	struct node *p;
	p = *head;
	if(p == NULL){
		printf("Empty list");
		return;
	}
	int max = p->data;
	while(p->next != NULL){
		p = p->next;
		if(p->data > max)
			max = p->data;
	}
	printf("%d\n", max);
}
