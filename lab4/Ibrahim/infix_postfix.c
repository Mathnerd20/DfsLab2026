#include<stdio.h>

#define MAXSIZE 100

typedef struct STACK{
    int top;
    char data[MAXSIZE];
}stack;

char pop(stack *s){

    if(s->top == -1){
        return '\0';
    }
    else{
        char x = s->data[s->top];
        s->top--;
        return x;
    }
}

void push(stack *s,char n){
    if(s->top == MAXSIZE-1){
        printf("The stack is full");
    }
    else{
        s->top++;
        s->data[s->top] = n;
    }
    return;
}

char get(stack *s){
    int t = s->top;
    if(t == -1){
        return '\0';
    }
    return s->data[s->top];
}

int main(){

    stack s;
    s.top = -1;

    char infix[100];
    printf("enter the infix string : ");
    scanf("%s",infix);

    char postfix[100];
    int j = 0;
    char c;
    int i = 0;
    while(infix[i] != '\0'){

        if(infix[i] <= 'z' && infix[i] >= 'a'){
            postfix[j] = infix[i];
            j++;
        }
        else if(infix[i] == '('){
            push(&s,infix[i]);
        }
        else{
            if(infix[i] == ')'){
                c = pop(&s);
                while(c != '('){
                    postfix[j] = c;
                    j++;
                    c = pop(&s);
                }
            }
            else{
                if(infix[i] == '+' || infix[i] == '-'){
                    while(get(&s) != '(' || get(&s) != '\0'){
                        c = pop(&s);
                        postfix[j] = c;
                        j++;
                    }
                    push(&s,infix[i]);
                }
                else{
                    while(get(&s) != '(' || get(&s) != '\0' || get(&s) != '+' || get(&s) != '-'){
                        c = pop(&s);
                        postfix[j] = c;
                        j++;
                    }
                    push(&s,infix[i]);
                }
            }
        }
        i++;
    }
    c = pop(&s);
    while(c != '\0'){
        postfix[j] = c;
        j++;
        c = pop(&s);
    }
    postfix[j] = '\0';
    
    printf("%s",postfix);

    return 0;
}
