#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void addBeg(struct node **);
void addAtLoc(struct node **);
void addEnd(struct node **);
void delBeg(struct node **);
void delAtLoc(struct node **);
void delEnd(struct node **);
void search(struct node **);
void display(struct node **);

// HAS SOME ERRORS PLEASE CHECK !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int main(){
	struct node *head;
	head = NULL;
	printf("Enter what to do to the linked list\n");
	printf("Enter 1 to add an element to the beginnig\n");
	printf("Enter 2 to add an element to a specific location\n");
	printf("Enter 3 to add an elements to the end\n");
	printf("Enter 4 to delete the first element\n");
	printf("Enter 5 to delete an element at a specific location\n");
	printf("Enter 6 to delete the last element\n");
	printf("Enter 7 to find the location of an element\n");
	printf("Enter 8 to display all elements\n");
	printf("Enter 0 to exit\n");
	int choice;
	do{
		scanf("%d", &choice);
		switch(choice){
			case 1:
				addBeg(&head);
				break;
			case 2:
				addAtLoc(&head);
				break;
			case 3:
				addEnd(&head);
				break;
			case 4:
				delBeg(&head);
				break;
			case 5:
				delAtLoc(&head);
				break;
			case 6:
				delEnd(&head);
				break;
			case 7:
				search(&head);
				break;
			case 8:
				display(&head);		
				break;
		}
	}while(choice);
}

void addBeg(struct node **head){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter value to be added:");
	int val;
	scanf("%d", &val);
	temp->data = val;
	temp->next = *head;
	*head = temp;
}

void addAtLoc(struct node **head){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter value to be added:");
	int val;
	scanf("%d", &val);
	temp->data = val;
	printf("Enter location:");
	int loc;
	scanf("%d", &loc);
	struct node *t;
	t = *head;
	int len = 0;
	while(t != NULL){
		len++;
		t = t->next;
	}
	if(loc > len+1){
		printf("Location does not exist");
		return;
	}
	struct node *p;
	p = *head;
	if(p == NULL){
		*head = temp;
		(*head)->next = NULL;
	}
	else{
		for(int i = 1; i < loc-1; i++)
			p = p->next;
		temp->next = p->next;
		p->next = temp;
	}
}

void addEnd(struct node **head){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter value to be added:");
	int val;
	scanf("%d", &val);
	temp->data = val;
	struct node *p;
	p = *head;
	if(p == NULL){
		*head = temp;
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

void delBeg(struct node **head){
	if(*head == NULL){
		printf("List empty");
		return;
	}
	struct node *temp;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}

void delAtLoc(struct node **head){
	if(*head == NULL){
		printf("List empty");
		return;
	}
	struct node *temp;
	struct node *p;
	p = *head;
	printf("Enter location:");
	int loc;
	scanf("%d", &loc);
	struct node *t;
	t = *head;
	int len = 0;
	while(t != NULL){
		len++;
		t = t->next;
	}
	if(loc > len+1){
		printf("Location does not exist");
		return;
	}
	for(int i = 1; i < loc-1; i++)
		p = p->next;
	temp = p->next;		
	p->next = temp->next;
	free(temp);
}

void delEnd(struct node **head){
	if(*head == NULL){
		printf("List empty");
		return;
	}
	struct node *p;
	p = *head;
	if(p->next == NULL){
		*head = NULL;
		free(p);
	}
	else{
		struct node *temp;
		while(p->next->next != NULL)
			p = p->next;
		temp = p->next;
		p->next = NULL;
		free(temp);
	}
}

void search(struct node **head){
	if(*head == NULL){
		printf("List empty");
		return;
	}
	printf("Enter key:");
	int key;
	scanf("%d", &key);
	struct node *p;
	p = *head;
	int loc = 1;
	while(p->data != key){
		p = p->next;
		loc++;
	}
	printf("Location of required element is %d", loc);
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
}
