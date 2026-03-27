#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *right;
    struct node *left;
};

struct node *head = NULL;

void addBegin(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if(head == NULL){
        newnode->left = newnode;
        newnode->right = newnode;
        head = newnode;
        return;
    }
    newnode->left = head->left;
    newnode->right = head;
    head->left->right = newnode;
    head->left = newnode;
    head = newnode;
    return;
}

void addEnd(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if(head == NULL){
        newnode->left = newnode;
        newnode->right = newnode;
        head = newnode;
        return;
    }
    else{
        newnode->left = head->left;
        newnode->right = head;
        head->left->right = newnode;
        head->left = newnode;
        return;
    }
}
void addAt(int pos,int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if(pos == 1){
        addBegin(data);
        return;
    }
    struct node *temp = head;
    for(int i = 1; i < pos ; i++){
        temp = temp->right;
        if(temp == head){
                printf("Position Does Not exist\n");
                return;
        }
    }
    newnode->left = temp->left;
    newnode->right = temp;
    temp->left->right = newnode;
    temp->left = newnode;
    return;
}

void display(){
    struct node *temp = head;
    if(head == NULL){
        printf("Linked List is Empty\n");
        return;
    }
    do{
        printf("%d ",temp->data);
        temp = temp->right;
    }while(temp != head);
    printf("\n");
    return;
}
void deleteBeg(){
    if(head == NULL){
        printf("Linked List is Empty\n");
        return;
    }
    else if(head ->right == head){
        struct node *temp = head;
        head = NULL;
        free(temp);
        return;
    }
    struct node *temp = head;
    head->right->left = head->left;
    head->left->right = head->right;
    head = head->right;
    free(temp);
    return;
}

void deleteEnd(){
    if(head == NULL){
        printf("Linked List is Empty\n");
        return;
    }
    else if(head ->right == head){
        struct node *temp = head;
        head = NULL;
        free(temp);
        return;
    }

    struct node *temp = head->left;
    temp->left->right = head;
    head->left = temp->left;
    free(temp);
    
}
void deleteAt(int pos){
    if(head == NULL){
        printf("Linked List is Empty\n");
        return;
    }
    else if(pos == 1){
        deleteBeg();
    }
    else{
        struct node *temp = head;
        for(int i = 1; i < pos ; i++){
            temp = temp->right;
            if(temp == head){
                printf("Position Does Not exist\n");
                return;
            }
        }
        if(temp->right == head){
            deleteEnd();
        }
        else{
            temp->left->right = temp->right;
            temp->right->left = temp->left;
            free(temp);
        }
    }
    return;
}

int main(){
    int option = 0;
    int data,pos;
    while(option != 8){
        printf("Choose from below options:\n1.)add at begin\n2.)add at end\n3.)add at position\n4.)delete from begin\n5.)delete from end\n6.)delete from position\n7.)display\n8.)Exit\n");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter the element you want to add: ");
                scanf("%d",&data);
                addBegin(data);
                break;
            case 2:
                printf("Enter the element you want to add: ");
                scanf("%d",&data);
                addEnd(data);
                break;
            case 3:
                printf("Enter the element you want to add: ");
                scanf("%d",&data);
                printf("Enter the position at which you want to add: ");
                scanf("%d",&pos);
                addAt(pos,data);
                break;
            case 4:
                deleteBeg();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter the position from which you want to delete the element: ");
                scanf("%d",&pos);
                deleteAt(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Thank You!\n");
                break;
            default:
                printf("invalid option\n");
                break;
        }
    }
    return 0;
}