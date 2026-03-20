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
        newnode->left = NULL;
        newnode->right = NULL;
        head = newnode;
        return;
    }
    head->left = newnode;
    newnode->left = NULL;
    newnode->right = head;
    head = newnode;
    return;
}

void addEnd(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if(head == NULL){
        newnode->left = NULL;
        newnode->right = NULL;
        head = newnode;
        return;
    }
    else{
        struct node *temp = head;
        while(temp->right != NULL){
            temp = temp->right;

        }
        temp->right = newnode;
        newnode->left = temp;
        newnode->right = NULL;
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
        if(temp == NULL){
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
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->right;
    }
    printf("\n");
    return;
}
void deleteBeg(){
    if(head == NULL){
        printf("Linked List is Empty\n");
        return;
    }
    else if(head ->right == NULL){
        struct node *temp = head;
        head = NULL;
        free(temp);
        return;
    }
    struct node *temp = head;
    head = head->right;
    head->left = NULL;
    free(temp);
    return;
}

void deleteEnd(){
    if(head == NULL){
        printf("Linked List is Empty\n");
        return;
    }
    else if(head ->right == NULL){
        struct node *temp = head;
        head = NULL;
        free(temp);
        return;
    }

    struct node *temp = head;
    while(temp->right != NULL){
        temp = temp->right;
    }
    temp->left->right = NULL;
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
            if(temp == NULL){
                printf("Position Does Not exist\n");
                return;
            }
        }
        if(temp->right == NULL){
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