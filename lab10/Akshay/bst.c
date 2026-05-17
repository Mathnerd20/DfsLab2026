#include <stdio.h>
#include <stdlib.h>
struct bst {
  int info;
  struct bst *right;
  struct bst *left;
};
typedef struct bst node;

node *add(node *p, int k);
node *delete(node *p, int a);
void display(node *p);
node *getnode();

int main() {
  node *top = NULL;
  int t = 9;
  while (t != -1) {
    printf("Enter option: ");
    scanf("%d", &t);
    int k;
    switch (t) {
    case 1:
      printf("Enter value to be added: ");
      scanf("%d", &k);
      top = add(top, k);
      break;
    case 2:
      printf("Enter element to be deleted: ");
      scanf("%d", &k);
      delete(top, k);
      break;
    case 3:
      display(top);
      printf("\n");
      break;
    }
  }
}

node *add(node *p, int k) {
  if (p == NULL) {
    p = getnode();
    p->info = k;
    p->right = NULL;
    p->left = NULL;
  } else if (p->info < k) {
    p->right = add(p->right, k);
  } else {
    p->left = add(p->left, k);
  }
  return p;
}

node *getnode() {
  node *new;
  new = (node *)malloc(sizeof(node *));
  return new;
}
void display(node *p) {
  if (p == NULL) {
    return;
  }
  display(p->left);
  printf("%d ", p->info);
  display(p->right);
}

node *delete(node *top, int a) {
  if (top == NULL) {
    return top;
  } else if (top->info < a) {
    top->right = delete(top->right, a);
  } else if (top->info > a) {
    top->left = delete(top->left, a);
  } else {
    if (top->left == NULL & top->right == NULL) {
      free(top);
      top = NULL;
    } else if (top->left == NULL) {
      node *temp = top;
      top = top->right;
      free(temp);
    } else if (top->right == NULL) {
      node *temp = top;
      top = top->left;
      free(temp);
    } else {
      node *temp = top->right;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      top->info = temp->info;
      top->right = delete(top->right, temp->info);
    }
  }
  return top;
}
