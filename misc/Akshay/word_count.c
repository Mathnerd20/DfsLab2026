#include "stackLinked.h"
#define IN 1
#define OUT 0

int main() {
  FILE *f1;
  f1 = fopen("text_file.txt", "r");
  FILE *f2;
  f2 = fopen("word_freq.txt", "w");
  int a;
  struct node *top = NULL;
  while ((a = getc(f1)) != EOF) {
    int i = 0;
    char c[100];
    for (int d = 0; d < 100; d++) {
      c[d] = '\0';
    }
    while (a != ' ' && a != '\n' && a != EOF) {
      /*if(a == '.' || a == '\'' || a == '"')
      {
        break;
      }*/
      c[i] = a;
      i++;
      a = getc(f1);
    }
    c[i + 1] = '\0';
    struct node *temp = top;
    while (temp != NULL && strcmp(temp->word, c) != 0) {
      temp = temp->next;
    }
    if (temp != NULL) {
      temp->freq++;
    } else {
      push(&top, c);
      top->freq = 1;
    }
  }
  fputs("Words \t Count \n", f2);
  while (top != NULL) {
    fputs(top->word, f2);
    fprintf(f2, "\t %d \n", top->freq);
    top = top->next;
  }
  fclose(f1);
  fclose(f2);
}
