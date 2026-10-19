#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void append(struct Node **pList, int data) {
  struct Node *newNode = malloc(sizeof(*newNode));
  if (newNode == NULL) {
    perror("Malloc failed.");
    exit(EXIT_FAILURE);
  }

  newNode->data = data;
  newNode->next = NULL;

  if (*pList == NULL) {
    *pList = newNode;
  } else {
    struct Node *current = *pList;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}

void printList(struct Node *list) {
  printf("The list is: ");
  struct Node *current = list;
  while (current != NULL) {
    printf("%d, ", current->data);
    current = current->next;
  }
  printf("\n");
}

void freeList(struct Node **pList) {
  struct Node *current = *pList;
  while (current != NULL) {
    struct Node *next = current->next;
    free(current);
    current = next;
  }
  *pList = NULL;
}

int main() {
  printf("C Linked List Demo\n");

  struct Node *head = NULL;

  append(&head, 10);
  append(&head, 20);
  append(&head, 30);
  append(&head, 40);

  printList(head);

  freeList(&head);
}
