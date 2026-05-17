#include <stdio.h>
#include <string.h>

struct heapItem {
    char info[100];
    int priority;
};
typedef struct heapItem item;
//This is a max heap

//functions
void swapInfo(item *a, item *b){
    char k[100];
    strcpy(k,a->info);
    strcpy(a->info, b->info);
    strcpy(b->info, k);
    int t = a->priority;
    a->priority = b->priority;
    b->priority = t;
}

void heapifyup(item heap[], int i) {
    int p = (i - 1) / 2;

    if(p < 0)
    {
        return;
    }

    if(heap[p].priority < heap[i].priority)
    {
        /*char k[100];
        strcpy(k,heap[p].info);
        strcpy(heap[p].info, heap[i].info);
        strcpy(heap[i].info,k);
        int a = heap[p].priority;
        heap[p].priority = heap[i].priority;
        heap[i].priority = a;
        heapifyup(heap, p);
        */
        swapInfo(&heap[p], &heap[i]);
        heapifyup(heap, p);
    }
}

void heapifydown(item heap[], int i, int size) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;
    if(l < size)
    {
       if(heap[l].priority >  heap[r].priority)
       {
           max = l;
       }
       else
       {
           max = r;
       }
    }
    if(heap[max].priority > heap[i].priority)
    {
        /*char k[100];
        strcpy(k,heap[i].info);
        strcpy(heap[i].info, heap[max].info);
        strcpy(heap[max].info,k);
        int a = heap[i].priority;
        heap[i].priority = heap[max].priority;
        heap[max].priority = a;
        heapifydown(heap, max, size);
        */
        swapInfo(&heap[i], &heap[max]);
        heapifydown(heap, max, size);
    }
}
void add(item heap[], int *size) {

    printf("Enter name : ");
    scanf("%s", heap[*size].info);

    printf("Enter priority: ");
    scanf("%d", &heap[*size].priority);

    heapifyup(heap, *size);

    (*size)++;
}

void delete(item heap[], int *size) {
    printf("Deleted: %s\n", heap[0].info);
    heap[0] = heap[*size - 1];
    heapifydown(heap, 0, *size);
    (*size)--;
}

void display(item heap[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s ", heap[i].info);
        printf("\n%d \n", heap[i].priority);
    }
}


int main() {
    item heap[100];
    int size = 0;
    int t = 0;
    while (t != -1) {
        printf("Enter option: ");
        scanf("%d", &t);
        switch (t) {
            case 1:
                add(heap, &size);
                break;
            case 2:
                delete(heap, &size);
                break;
            case 3:
                display(heap, size);
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}
