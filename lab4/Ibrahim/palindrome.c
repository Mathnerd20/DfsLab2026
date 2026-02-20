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


int main(){

    stack s;
    s.top = -1;

    char string[100];
    printf("Enter the string you want to check: ");
    scanf("%s",&string);

    char reverse[100];
    int i = 0;
    while(string[i] != '\0'){
        push(&s,string[i]);
        i++;
    }
    char c = 'i';
    i = 0;
    while(c != '\0'){
        c = pop(&s);
        reverse[i] = c;
        i++;
    }

    int palindrome = 1;
    i = 0;
    while(string[i] != '\0'){
        if(string[i] != reverse[i]){
            palindrome = 0;
        }
        i++;
    }

    if(palindrome){
        printf("The string is a palindrome");
    }
    else{
        printf("The string is not a palindrome");
    }
    


    return 0;
}