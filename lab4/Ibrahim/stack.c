#include<stdio.h>

#define MAXSIZE 100

typedef struct STACK{
    int top;
    int data[MAXSIZE];
}stack;

int pop(stack *s){

    if(s->top == -1){
        printf("The stack is empty");
        return -1;
    }
    else{
        int x = s->data[s->top];
        s->top--;
        return x;
    }
}

void push(stack *s,int n){
    if(s->top == MAXSIZE-1){
        printf("The stack is full");
        return;
    }
    else{
        s->top++;
        s->data[s->top] = n;
    }
}

void display(stack *s){

    stack *temp = s;
    for(int i = temp->top;i >= 0;i--){
        printf("%d ",temp->data[i]);
    }
    printf("\n");
    return;
}

int main(){

    stack s;
    s.top = -1;
    int n;
    int option = 0;
    while(option != 4){
        printf("Enter the option\n");
        printf("1.)push\n2.)pop\n3.)display\n4.)exit\n");
        scanf("%d",&option);

        switch(option){
            case 1:
                printf("Enter the Elemnet you want to enter: ");
                scanf("%d",&n);
                push(&s,n);
                break;
            case 2:
                n = pop(&s);
                printf("Enter element you popped is %d\n",n);
                break;
            case 3:
                printf("The elements in the stacks are : ");
                display(&s);
                break;
            case 4:
                printf("Thank You");
                break;
            default:
                printf("option does not exist\n");
                break;
        }
    }

    return 0;
}