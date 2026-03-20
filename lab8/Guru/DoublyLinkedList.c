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
	node *top = NULL;
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
				addBeg(&top);
				break;
			case 2:
				addEnd(&top);
				break;
			case 3:
				addMid(&top);
				break;
			case 4:
				delBeg(&top);
				break;
			case 5:
				delEnd(&top);
				break;
			case 6:
				delMid(&top);
				break;
			case 7:
				display(&top);
				break;
		}
	}while(choice);
}

void addBeg(node **top){
	node *temp = (node *)malloc(sizeof(node));
	printf("Enter value for new element:");
	int val;
	scanf("%d", &val);
	temp->data = val;
	temp->left = NULL;
	temp->right = *top;
	if(*top != NULL)
		(*top)->left = temp;
	*top = temp;
}

void addEnd(node **top){
	node *temp = (node *)malloc(sizeof(node));
	printf("Enter value value of new element:");
	int val;
	scanf("%d", &val);
	temp->data = val;
	node *p = *top;
	if(p == NULL){
		temp->right = NULL;
		temp->left = NULL;
		*top = temp;
	}
	else{
		while(p->right != NULL)
			p = p->right;
		temp->right = NULL;
		temp->left = p;
		p->right = temp;
	}
}

void addMid(node **top){
	printf("Enter value(key) of the element after which you are adding an element:");
	int key;
	scanf("%d", &key);
	node *p = *top;
	while(p != NULL && p->data != key)
		p = p->right;
	if(p == NULL){
		printf("Key not found\n");
		return;
	}
	if(p == *top)
		addBeg(top);
	else if(p->right == NULL)
		addEnd(top);
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

void delBeg(node **top){
	if(*top == NULL){
		printf("List is empty\n");
		return;
	}
	node *temp = *top;
	if((*top)->right != NULL)
		(*top)->right->left = NULL;
	*top = (*top)->right;
	free(temp);
}

void delEnd(node **top){
	if(*top == NULL){
		printf("List is empty\n");
		return;
	}
	node *temp = *top;
	while(temp->right != NULL)
		temp = temp->right;
	if(temp->left != NULL)
		temp->left->right = NULL;
	else
		*top = NULL;
	free(temp);
}

void delMid(node **top){
	if(*top == NULL){
		printf("List is empty\n");
		return;
	}
	printf("Enter value(key) of element to be deleted:");
	int key;
	scanf("%d", &key);
	node *temp = *top;
	while(temp != NULL && temp->data != key)
		temp = temp->right;
	if(temp == NULL){
		printf("Key not found\n");
		return;
	}
	if(temp == *top)
		delBeg(top);
	else if(temp->right == NULL)
		delEnd(top);
	else{
		temp->left->right = temp->right;
		temp->right->left = temp->left;
		free(temp);
	}
}

void display(node **top){
	if(*top == NULL){
		printf("List is empty\n");
		return;
	}
	node *p = *top;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->right;
	}
	printf("\n");
}
