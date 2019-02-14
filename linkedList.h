/**********************************

***********************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 20

typedef struct node{
  char *vehicle;
  int mileage;
  int date;
  struct node* next;
  struct node* prev;
} node;

typedef struct list{
  node* head;
  int count;
}list;

typedef struct stack{
  int* hold;
  unsigned length;
  int top;
}stack;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

node* createVehicle(char* newVehicle, int mileage, int date);

list* makeList();

node* find(list* carList, char* vehicle);

float transaction(int mileageDiff);

void sendToFile(list* newCar, list* rentedCar, list* repairCar);

void insertEnd(list* carList, char* newVehicle, int mileage, int date);

void insertVehicle(list* carList, char* newVehicle, int mileage, int date);

void deleteVehicle(list* carList, char* vehicle);

void printList(list* carList);

int isEmpty(stack* stack);

stack* createStack(unsigned length);

void push(stack* stack, char elem);

char pop(stack* stack);

int evaluatePostfix(char *postFix);

#endif
