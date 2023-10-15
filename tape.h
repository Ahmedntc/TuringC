#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{
  char s;
  struct Node *next;
  struct Node *prev;
} Node;


void add_node(Node *init, char msg) {
  Node* no = (Node *)malloc(sizeof(Node));
  if (no == NULL) {
    return;
  }
  no->next = NULL;
  if(msg != '\n'){
    Node *aux = init;
    no->s = msg;
    while (aux->next != NULL) {
      aux = aux->next;
    }
    aux->next = no;
    no->prev = aux;
  }
}

Node* init_tape(char sigma){
    Node* no = (Node*) malloc(sizeof(Node));
    if (no == NULL) {
        return NULL;
    }
    no->s = sigma;
    no->next = NULL;
    no->prev = NULL;
    return no;
}
