#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

void addEnd(struct node **, int);
void display(struct node **);
struct node * merge(struct node *, struct node *);

int main(){
	struct node *head1, *head2;
	head1 = NULL;
	head2 = NULL;
	printf("Enter elements in ascending order for first linked list\n Enter choice(enter '1' to enter elements, enter '0' to stop entering):");
	int inp;
	scanf("%d", &inp);
	while(inp){
		printf("Enter value of element:");
		int val;
		scanf("%d", &val);
		addEnd(&head1, val);
		printf("Enter choice:");
		scanf("%d", &inp);
	}
	printf("Enter elements in ascending order for second linked list\n Enter choice(enter '1' to enter elements, enter '0' to stop entering):");
	scanf("%d", &inp);
	while(inp){
		printf("Enter value of element:");
		int val;
		scanf("%d", &val);
		addEnd(&head2, val);
		printf("Enter choice:");
		scanf("%d", &inp);
	}
	struct node *mergeHead = merge(head1, head2);
	printf("Merged linked list:\n");
	display(&mergeHead);
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

struct node * merge(struct node *head1, struct node *head2){
	struct node *mergeHead;
	if(head1 == NULL || head2 == NULL){
		if(head2 != NULL)
			return head1;
		if(head1 != NULL)
			return head2;
		printf("Both lists empty");
		return NULL;
	}
	if(head1->data < head2->data){
		mergeHead = head1;
		head1 = head1->next;
	}
	else{
		mergeHead = head2;
		head2 = head2->next;
	}
	struct node *p = mergeHead;
	while(head1 != NULL && head2 != NULL){
		if(head1->data < head2->data){
			p->next = head1;
			head1 = head1->next;
		}
		else{
			p->next = head2;
			head2 = head2->next;
		}
		p = p->next;
	}
	if(head1 != NULL)
		p->next = head1;
	if(head2 != NULL)
		p->next = head2;
	return mergeHead;
}
