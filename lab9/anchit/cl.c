# include <stdio.h>
# include <stdlib.h>

struct NODE
{
    int item;
    struct NODE *prev;
    struct NODE *next;
};
typedef struct NODE nd;

nd *head = NULL;

void first (int t)
{
    nd *tmp;
    tmp = (nd*)malloc(sizeof(nd));

    if (head == NULL)
    {
        tmp->prev = tmp;
        tmp->next = tmp;
        tmp->item = t;
        head = tmp;
    }
    
    else
    {
        tmp->prev = head->prev;
        tmp->next = head;
        head->prev->next = tmp;
        head->prev = tmp;
        tmp->item = t;
        head = tmp;
    }
}

void middle (int t , int key)
{
    nd *add;
    add = (nd*)malloc(sizeof(nd));

    if (head->item == key)
    {
        add->item = t;
        add->prev = head->prev;
        add->next = head;
        head->prev->next = add;
        head->prev = add;
        head = add;
    }
    
    else
    {
        nd *tmp ; tmp = head->next;
        while (tmp->item != key && tmp != head) tmp = tmp->next;

        add->item = t;
        add->prev = tmp;
        add->next = tmp->next;
        tmp->next->prev = add;
        tmp->next = add;
    }
}

void last (int t)
{
    nd *add;
    add = (nd*)malloc(sizeof(nd));

    add->next = head;
    add->prev = head->prev;
    head->prev->next = add;
    head->prev = add;
    add->item = t;
}

void delete_first ()
{
    nd *tmp;
    tmp = head;
    printf("The deleted item is : %d\n", tmp->item);

    head->next->prev = head->prev;
    head->prev->next = head->next;
    head = head->next;
    free(tmp);
}

void delete_middle (int key)
{
    nd *tmp;
    if (head->item == key)
    {
        head->next->prev = head->prev;
        head->prev->next = head->next;
        tmp = head;
        head = head->next;
        free(tmp);
    }
    
    else
    {
        tmp = head->next;
        while (tmp->item != key && tmp != head) tmp = tmp->next;

        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        free(tmp);
    }
}

void delete_last ()
{
    nd *tmp;
    tmp = head->prev;
    printf("Deleted item is %d\n", tmp->item);

    tmp->prev->next = head;
    head->prev = tmp->prev;
    free(tmp);
}

void display ()
{
    nd *tmp;
    tmp = head;

    do
    {
        printf("%d ", tmp->item);
        tmp = tmp->next;

    } while (tmp != head);

    printf("\n");
}

int main ()
{
    int n;

    do
    {
        printf("Enter 1 to add item in front\n2 to add at particular location\n3 to add item at last\n4 to delete 1st node\n5 to delete middle node\n6 to delete end node\n7 to display (0 to exit then programm) : ");
        scanf("%d", &n);

        switch(n)
        {
            case 1:
                int t;
                printf("Enter the item u want to add : ");
                scanf("%d", &t);

                first (t);
                break;

            case 2:
                int keya;
                printf("Enter the key of the node after which u want to add node : ");
                scanf("%d", &keya);

                int a;
                printf("Enter the item u want to add : ");
                scanf("%d", &a);

                middle (a , keya);
                break;
            
            case 3:
                int b;
                printf("Enter the item u want to add : ");
                scanf("%d", &b);

                last (b);
                break;

            case 4:
                delete_first ();
                break;

            case 5:
                int keyd;
                printf("Please enter the item of the node u want to delete : ");
                scanf("%d", &keyd);

                delete_middle (keyd);
                break;

            case 6:
                delete_last ();
                break;

            case 7:
                display ();
                break;
        }
    }while (n != 0);
}


