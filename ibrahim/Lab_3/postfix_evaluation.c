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

int char_to_int(char c){
    return c-'0';
}

int main(){

    stack s;
    s.top = -1;

    char postfix[100];
    printf("Enter the postfix string : ");
    scanf("%s",&postfix);
    int j = 0;
    int ans;
    while(postfix[j] != '\0'){
        if(postfix[j] == '+' ||postfix[j] == '*' || postfix[j] == '/' ||postfix[j] == '-'){
            char opt = postfix[j];
            int b = pop(&s);
            int a = pop(&s);
            if(opt == '+'){
                ans = a+b;
                push(&s,ans);
            }
            else if(opt == '-'){
                ans = a-b;
                push(&s,ans);
            }
            else if(opt == '*'){
                ans = a*b;
                push(&s,ans);
            }
            else if(opt == '/'){
                ans = a/b;
                push(&s,ans);
            } 
            
        }
        else{
            int n = char_to_int(postfix[j]);
            push(&s,n);
        }

        j++;
    }

    printf("the evaluation is %d\n",pop(&s));

    return 0;
}