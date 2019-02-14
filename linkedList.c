#include "linkedList.h"

node* createVehicle(char* newVehicle, int mileage, int date){

  node* carPtr;
  carPtr = malloc(sizeof(node));
  carPtr->vehicle = malloc(sizeof(newVehicle) + 1);

  strcpy(carPtr->vehicle, newVehicle);
  carPtr->mileage = mileage;
  carPtr->date = date;
  carPtr->next = NULL;
  return carPtr;
}

list* makeList(){
  list* carList = malloc(sizeof(list));
  carList->head= NULL;
  carList->count = 0;
  return carList;
}

node* find(list* carList, char* vehicle){
  node* tempNode;
  tempNode = carList->head;

  if(strcmp(tempNode->vehicle, vehicle) == 0){
    return tempNode;
  }
  while(tempNode != NULL){
    if(strcmp(tempNode->vehicle, vehicle) == 0){
      return tempNode;
    }
    tempNode = tempNode->next;
  }
  return tempNode;
}

void insertEnd(list* carList, char* newVehicle, int mileage, int date){
  if (carList == NULL || newVehicle == NULL){
    printf("There is no list available\n");
    return;
  }
  node* newNode = createVehicle(newVehicle, mileage, date);
  node* curNode = carList->head;

  if (carList->head == NULL){
    carList->head = newNode;
    printf("%s, %d, %d\n", carList->head->vehicle, carList->head->mileage, carList->head->date);
    return;
  }

  while (curNode != NULL){
    if (curNode->next == NULL){
      curNode->next = newNode;
      return;
    }
  }
}

float transaction(int mileageDiff){
  float charge = 0;

  if(mileageDiff <= 100){
    charge = 40;
    return charge;
  }
  else if(mileageDiff > 100){
    mileageDiff -= 100;
    charge = 40 + (mileageDiff * 0.15);
    return charge;
  }
  return charge;

}
void sendToFile(list* newCar, list* rentedCar, list* repairCar){

  FILE *filePtr;
  node* tempNode;
  filePtr = fopen("vehicleList.db", "r");

  if(newCar != NULL){
    tempNode = newCar->head;
    printf("%s %d %d\n", tempNode->vehicle, tempNode->mileage, tempNode->date);
    fprintf(filePtr, "%s\n", "Available:");
    fprintf(filePtr, "%s\n%d\n%d", tempNode->vehicle, tempNode->mileage, tempNode->date);
    /*fwrite(tempNode->vehicle, 1, sizeof(node), filePtr);*/
  }
/*
  if(rentedCar != NULL){
    tempNode = rentedCar->head;
    while(rentedCar){
      fprintf(filePtr, "%s\n%s\n%d\n%d", "Rented:", tempNode->vehicle, tempNode->mileage, tempNode->date);

      tempNode = tempNode->next;
    }
  }
  if(repairCar != NULL){
    tempNode = repairCar->head;
    while(repairCar){
      fprintf(filePtr, "%s\n%s\n%d\n%d", "Repairing:", tempNode->vehicle, tempNode->mileage, tempNode->date);
      tempNode = tempNode->next;
    }
  }*/
  fclose(filePtr);
}

void insertVehicle(list* carList, char* newVehicle, int mileage, int date){

  if (carList == NULL || newVehicle == NULL){
    printf("There is no list available\n");
    return;
  }
  node* newNode = createVehicle(newVehicle, mileage, date);
  node* curNode = carList->head;
  /*FILE *filePtr;
  filePtr = fopen("vehicleMileage.bin", w);
  */
  /*CASE 1*/
  if (carList->head == NULL){
    carList->head = newNode;
    return;
  }
  /*CASE 2*/
  if (mileage <= carList->head->mileage || date < carList->head->date)
  {
    newNode->next = carList->head;
    carList->head = newNode;
    return;
  }
  /*CASE 3*/
  while (curNode->mileage < mileage || curNode->date < date){
    if (curNode->next == NULL){
      curNode->next = newNode;
      return;
    }
    if (curNode->next->mileage == mileage){
      newNode->next = curNode->next;
      curNode->next = newNode;
      return;
    }
    if (curNode->next->mileage > mileage || curNode->next->date > date){
      newNode->next = curNode->next;
      curNode->next = newNode;
      return;
    }
    else {
      curNode = curNode->next;
    }
  }
  return;
}

void deleteVehicle(list* carList, char* vehicle){
  node* tempPtr;
  node* oldPtr;
  if (carList == NULL || carList->head == NULL){
    printf("There is no list available\n");
    return;
  }
  tempPtr = carList->head;

  if (strcmp(tempPtr->vehicle, vehicle) == 0){
    tempPtr = tempPtr->next;
    free(carList->head);
    carList->head = tempPtr;
    return;
  }
  while (strcmp(tempPtr->vehicle, vehicle) > 0 || strcmp(tempPtr->vehicle, vehicle) < 0 ){
    if(strcmp(tempPtr->next->vehicle, vehicle) == 0){
      oldPtr = tempPtr->next;
      tempPtr->next = oldPtr->next;
      free(oldPtr);
      return;
    }
    tempPtr = tempPtr->next;
  }
  return;
}

void printList(list* carList){
  if (carList == NULL){
    printf("There is no list available\n");
    return;
  }
  node* tempList;
  tempList = carList->head;
  while (tempList){
    if (tempList->date == 0){
      printf("Vehicle: %s Mileage: %d\n", tempList->vehicle, tempList->mileage);
    }
    else if (tempList->date > 0){
      printf("Vehicle: %s Mileage: %d Date: %d\n", tempList->vehicle, tempList->mileage, tempList->date);
    }
    tempList = tempList->next;
  }
}
