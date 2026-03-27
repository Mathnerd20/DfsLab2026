#include<stdio.h>

void enQueue(int [], int*, int);
int deQueue(int [], int*);
void push(int [], int [], int*);
void pop(int [], int [], int*);
void display(int [], int *);

int main(){
	int q1[100];
	int q2[100];
	int r = 0;
	printf("Enter choice:\n");
	printf("Enter 1 to push into stack\n");
	printf("Enter 2 to pop from stack\n");
	printf("Enter 3 to display\n");
	printf("Enter 0 to exit\n");
	int choice;
	do{
		scanf("%d", &choice);
		switch(choice){
			case 1:
				push(q1, q2, &r);
				break;
			case 2:
				pop(q1, q2, &r);
				break;
			case 3:
				display(q1, &r);
				break;
		}
	}while(choice);
}

void enQueue(int q[], int *r, int val){
	q[(*r)++] = val;
}

int deQueue(int q[], int *r){
	int val = q[0];
	for(int i = 1; i < *r; i++)
		q[i-1] = q[i];
	(*r)--;
	return val;
}

void push(int q1[], int q2[], int *r){
	if(*r == 100){
		printf("Full\n");
		return;
	}
	printf("Enter value:");
	int val;
	scanf("%d", &val);
	enQueue(q1, r, val);
}

void pop(int q1[], int q2[], int *r){
	if(*r == 0){
		printf("Empty\n");
		return;
	}
	int i = 0;
	int j = *r;
	while(i < *r-1)
		enQueue(q2, &i, deQueue(q1, &j));
	int val = deQueue(q1,&j);
	printf("Popped value: %d\n", val);
	(*r)--;	
	i = 0;
	j = *r;
	while(i < *r)
		enQueue(q1, &i, deQueue(q2, &j));
}

void display(int q[], int *r){
	for(int i = *r-1; i >= 0; i--){
		printf("%d ", q[i]);
	}
	printf("\n");
}
