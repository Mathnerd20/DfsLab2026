#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left, *right;
} node;

void addBeg(node **);
void addEnd(node **);
void addMid(node **);
void delBeg(node **);
void delEnd(node **);
void delMid(node **);
void display(node **);

int main(){
	node *rear = NULL;
	int choice;
	printf("Enter 1 to add an element to the beginning\n");
	printf("Enter 2 to add an element to the end\n");
	printf("Enter 3 to add an element after a certain element \n");
	printf("Enter 4 to delete an element at the beginning\n");
	printf("Enter 5 to delete an element at the end\n");
	printf("Enter 6 to delete an element with certain data\n");
	printf("Enter 7 to display the list\n");
	printf("Enter 0 to exit\n");
	do{
		printf("Enter a choice:\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				addBeg(&rear);
				break;
			case 2:
				addEnd(&rear);
				break;
			case 3:
				addMid(&rear);
				break;
			case 4:
				delBeg(&rear);
				break;
			case 5:
				delEnd(&rear);
				break;
			case 6:
				delMid(&rear);
				break;
			case 7:
				display(&rear);
				break;
		}
	}while(choice);
}

void addBeg(node **rear){
	node *temp = (node *)malloc(sizeof(node));
	printf("Enter value for new element:");
	int val;
	scanf("%d", &val);
	temp->data = val;
	if(*rear == NULL){
		temp->right = temp;
		*rear = temp;
	}
	else{
		temp->right = (*rear)->right;
		temp->right->left = temp;
		(*rear)->right = temp;
	}
	temp->left = *rear;
}

void addEnd(node **rear){
	node *temp = (node *)malloc(sizeof(node));
	printf("Enter value value of new element:");
	int val;
	scanf("%d", &val);
	temp->data = val;
	if(*rear == NULL){
		temp->right = temp;
		temp->left = temp;
	}
        else{
		temp->right = (*rear)->right;
		(*rear)->right = temp;
		temp->right->left = temp;
		temp->left = *rear;
	}
	*rear = temp;
}

void addMid(node **rear){
	if(*rear == NULL){
		printf("List empty\n");
		return;
	}
	printf("Enter value(key) of the element after which you are adding an element:");
	int key;
	scanf("%d", &key);
	node *p = *rear;
	while(p->right != *rear && p->data != key)
		p = p->right;
	if(p == *rear && p->data != key){
		printf("Key not found\n");
		return;
	}
	if(p == *rear)
		addEnd(rear);
	else{
		node *temp = (node *)malloc(sizeof(node));
		printf("Enter value of new element:");
		int val;
		scanf("%d", &val);
		temp->data = val;
		temp->left = p;
		temp->right = p->right;
		temp->right->left = temp;
		p->right = temp;
	}
}

void delBeg(node **rear){
	if(*rear == NULL){
		printf("List is empty\n");
		return;
	}
	node *temp = (*rear)->right;
	if(temp == *rear)
		*rear = NULL;
	else{
		(*rear)->right = temp->right;	
		temp->right->left = *rear;
	}
	free(temp);
}

void delEnd(node **rear){
	if(*rear == NULL){
		printf("List is empty\n");
		return;
	}
	node *temp = *rear;
	if((*rear)->right == *rear)
		*rear == NULL;
	else{
		(*rear)->right->left = (*rear)->left;
		(*rear)->left->right = (*rear)->right;
		*rear = (*rear)->left;
	}
	free(temp);
}

void delMid(node **rear){
	if(*rear == NULL){
		printf("List is empty\n");
		return;
	}
	printf("Enter value(key) of element to be deleted:");
	int key;
	scanf("%d", &key);
	node *temp = *rear;
	while(temp->right != *rear  && temp->data != key)
		temp = temp->right;
	if(temp == *rear && temp->data != key){
		printf("Key not found\n");
		return;
	}
	if(temp == *rear)
		delEnd(rear);
	else if(temp->left == *rear)
		delEnd(rear);
	else{
		temp->left->right = temp->right;
		temp->right->left = temp->left;
		free(temp);
	}
}

void display(node **rear){
	if(*rear == NULL){
		printf("List is empty\n");
		return;
	}
	node *p = (*rear)->right;
	while(p != *rear){
		printf("%d ", p->data);
		p = p->right;
	}
	printf("%d", p->data);
	printf("\n");
}
