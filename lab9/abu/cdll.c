#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#define WIDTH 60
#define HEIGHT 30

typedef struct node{
    int data;
    struct node *prev, *next;
}NODE;

NODE* pGuru = NULL;

void draw_heart(float scale) {
    for (int y = HEIGHT / 2; y > -HEIGHT / 2; y--) {
        for (int x = -WIDTH / 2; x < WIDTH / 2; x++) {
            float xf = x / (float)(WIDTH / 2) / scale;
            float yf = y / (float)(HEIGHT / 2) / scale;

            float equation = pow(xf*xf + yf*yf - 1, 3) - xf*xf*yf*yf*yf;

            if (equation <= 0)
                printf("❤");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void heart_animation() {
    float t = 0;

    while (1) {
        float scale = 0.8 + 0.2 * sin(t); // pulsing effect

        printf("\033[H\033[J"); // clear screen
        draw_heart(scale);

        usleep(50000); // control speed
        t += 0.1;
    }
}

int checkEmpty(){
    return (pGuru == NULL);
}

void addBegin(int x){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    if(temp == NULL){
        printf("Memory Allocation failed\n");
        return;
    }
    temp->data = x;
    if(checkEmpty()){
        temp->prev = temp;
        temp->next = temp;
        pGuru = temp;
    }else{
        temp->prev = pGuru->prev;
        temp->next = pGuru;
        pGuru->prev->next = temp;
        pGuru->prev = temp;
        pGuru = temp;
    }
    printf("Added %d in the beginning\n", pGuru->data);
}

void display(){
    if(checkEmpty()){
        printf("List empty\n");
        return;
    }
    NODE* pCur = pGuru;
    int count = 0;
    printf("The Great Doubly linked list:\n");
    printf("|-> ");
    do{
        printf("%d <-> ", pCur->data);
        pCur = pCur->next;
        count++;
    }while(pCur != pGuru);
    printf("|\n");
    printf("|___");
    for(int i = 0; i < count; i++){
        printf("______");
    }
    printf("|\n");
}

void addLoc(int y, int key){
    if(checkEmpty()){
        printf("List empty\n");
        return;
    }
    NODE* pCur = pGuru;
    do{
        pCur = pCur->next;
    }while(pCur != pGuru && pCur->data != key);

    if(pCur == pGuru){
        printf("Key doesn't exist\n");
        return;
    }
    NODE* pNew = (NODE*)malloc(sizeof(NODE));
    if(pNew == NULL){
        printf("Memory Allocation failed\n");
        return;
    }
    pNew->data = y;
    pNew->prev = pCur;
    pNew->next = pCur->next;
    pCur->next->prev = pNew;
    pCur->next = pNew;
    printf("Added %d after %d\n", pNew->data, key);
}

void addEnd(int z){
    if(checkEmpty()){
        printf("List empty\n");
        return;
    }
    NODE* pCur = pGuru;
    NODE* pNew = (NODE*)malloc(sizeof(NODE));
    if(pNew == NULL){
        printf("Memory Allocation failed\n");
        return;
    }
    do{
        pCur = pCur->next;
    }while(pCur->next != pGuru);
    pNew->data = z;
    pNew->prev = pCur;
    pNew->next = pCur->next;
    pCur->next->prev = pNew;
    pCur->next = pNew;
    printf("Added %d in the end\n", pNew->data);
}

int delBeg(){
    if(checkEmpty()){
        return -1;
    }
    NODE* pCur = pGuru;
    int x = pCur->data;
    pCur->next->prev = pCur->prev;
    pCur->prev->next = pCur->next;
    pGuru = pCur->next;
    free(pCur);
    return x;
}

int delLoc(int o){
    if(checkEmpty()){
        return -1;
    }
    NODE* pCur = pGuru;
    do{
        pCur = pCur->next;
    }while(pCur->next != pGuru && pCur->data != o);
    if(pCur == NULL){
        return -2;
    }
    int x = pCur->data;
    pCur->prev->next = pCur->next;
    pCur->next->prev = pCur->prev;
    free(pCur);
    return x;
}

int delEnd(){
    if(checkEmpty()){
        return -1;
    }
    NODE* pCur = pGuru->prev;
    int x = pCur->data;
    pCur->prev->next = pCur->next;
    pCur->next->prev = pCur->prev;
    free(pCur);
    return x;
}

int main(){
    printf("Welcome dear users to my program!!!!!\n");
    printf("Instructions\nPress:\n"
           "1 - check empty\n"
           "2 - add beginning\n"
           "3 - add at a particular location\n"
           "4 - add ending\n"
           "5 - delete beginning\n"
           "6 - delete at a particular location\n"
           "7 - delete ending\n"
           "8 - to display\n"
           "-1 - quit\n");
    int n;
    do{
        int k;
        printf("Enter command no.:\n");
        scanf("%d", &n);
        switch(n){
                case 1:
                    if(checkEmpty())
                        printf("List is Empty\n");
                    else
                        printf("List is Not Empty\n");
                    break;   
                case 2:{
                    int x;
                    printf("Enter number to add at beginning:\n");
                    scanf("%d", &x);
                    addBegin(x);
                    break;
                }
                case 3:{
                    int y, key;
                    printf("Enter new data and key element:\n");
                    scanf("%d %d", &y, &key);
                    addLoc(y, key);
                    break;
                }
                case 4:{
                    int z;
                    printf("Enter number to add at end:\n");
                    scanf("%d", &z);
                    addEnd(z);
                    break;
                }
                case 5:
                    k = delBeg();
                    if(k != -1){
                        printf("Deleted %d at the beginning\n", k);
                    }else{
                        printf("List Empty\n");
                    }
                    break;
                case 6:{
                    int o;
                    printf("Enter element you want to delete\n");
                    scanf("%d", &o);
                    k = delLoc(o);
                    if(k != -1 && k != -2){
                        printf("Deleted %d somewhere in the ll\n", k);
                    }else if(k == -1){
                        printf("List Empty\n");
                    }else{
                        printf("Key doesn't exist\n");
                    }
                    break;
                }
                case 7:
                    k = delEnd();
                    if(k != -1){
                        printf("Deleted %d at the ending\n", k);
                    }else{
                        printf("List Empty\n");
                    }
                    break;
                case 8:
                    display();
                    break;
                case -1:
                    printf("I LOVE U ANCHIT!!!!!\n");
                    heart_animation();
                    break;
                default:
                    printf("Invalid command no.\n");
        }
    }while(n != -1);
    return 0;
}