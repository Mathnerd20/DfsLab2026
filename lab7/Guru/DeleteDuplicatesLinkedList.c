#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

void addEnd(struct node **, int);
void display(struct node **);
void delDupSorted(struct node **);
void delDupUnsorted(struct node **);

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
	printf("Enter 1 if elements entered are sorted, 2 if unsorted:");
	int choice;
	scanf("%d", &choice);
	printf("Initial linked list:\n");
	display(&head);
	switch(choice){
		case 1:
			delDupSorted(&head);
			break;
		case 2:
			delDupUnsorted(&head);
			break;
	}
	printf("Final linked list:\n");
	display(&head);
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

void delDupSorted(struct node **head){
	struct node *p = *head;
	while(p != NULL && p->next != NULL){
		if(p->data == p->next->data){
			struct node *temp = p->next;
			p->next = p->next->next;
			free(temp);
		}
		else
			p = p->next;
	}
}

void delDupUnsorted(struct node **head){
	struct node *p = *head;
	while(p != NULL && p->next != NULL){
		struct node *t = p;
		while(t->next != NULL){
			if(t->next->data == p->data){
				struct node *temp = t->next;
				t->next = t->next->next;
				free(temp);
			}
			else
				t = t->next;
		}
		p = p->next;
	}
}
