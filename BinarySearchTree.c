#include <stdio.h>

typedef struct node{
  struct node* left, *right;
  int data;
}node;

void createNode() 
