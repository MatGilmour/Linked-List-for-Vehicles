#include "linkedList.h"

int main(){

  char vehicle[20];
  int mileage;
  int date;
  node* tempNode;
  list* newCar;
  list* repairCar;
  list* rentedCar;
  int mileageDiff = 0;
  float charge = 0;
  float sumCharge = 0;
  int question = 0;
  int choice = 0;
  int answer = 0;

  newCar = makeList();
  repairCar = makeList();
  rentedCar = makeList();

  printf("Which question would you like to do? (1. Linked List, 2. Postfix): ");
  scanf("%d", &question);

  if (question == 1){
  printf("***Renter's Incorporated***\n");
  printf("Choose a number to perform the action of choice: \n");
  printf("1. Add a new car to the available-for-rent list\n");
  printf("2. Add a returned car to the available-for-rent list\n");
  printf("3. Add a returned car to the repair list\n");
  printf("4. Transfer a car from the repair list to the available-for-rent list\n");
  printf("5. Rent the first available car\n");
  printf("6. Print all the lists\n");
  printf("7. Quit\n");
  printf("Choice: ");
  scanf("%d", &choice);

  while (1){
    switch (choice){
      case 1:
        printf("Please write the license plate: ");
        scanf("%s", vehicle);
        printf("Please write the mileage: ");
        scanf("%d", &mileage);
        date = 0;
        insertVehicle(newCar, vehicle, mileage, date);
        break;
      case 2:
        printf("Please input the license plate of the returned vehicle: ");
        scanf("%s", vehicle);
        printf("What is the new mileage? ");
        scanf("%d", &mileage);
        tempNode = find(rentedCar, vehicle);
        mileageDiff = mileage;
        mileageDiff = mileage - tempNode->mileage;
        charge = transaction(mileageDiff);
        sumCharge += charge;
        printf("Price of rental for today is %.02f\n", charge);
        date = 0;
        deleteVehicle(rentedCar, vehicle);
        insertVehicle(newCar, vehicle, mileage, date);
        break;
      case 3:
        printf("Please input the license plate of the returned vehicle: ");
        scanf("%s", vehicle);
        printf("What is the new mileage? ");
        scanf("%d", &mileage);
        tempNode = find(rentedCar, vehicle);
        mileageDiff = mileage;
        mileageDiff = mileage - tempNode->mileage;
        charge = transaction(mileageDiff);
        sumCharge += charge;
        printf("Price of rental for today is %.02f\n", charge);
        date = 0;
        deleteVehicle(rentedCar, vehicle);
        insertVehicle(repairCar, vehicle, mileage, date);
        break;
      case 4:
        printf("Please input a license plate for your repaired vehicle: ");
        scanf("%s", vehicle);
        tempNode = find(repairCar, vehicle);
        mileage = tempNode->mileage;
        date = 0;
        deleteVehicle(repairCar, vehicle);
        insertVehicle(newCar, vehicle, mileage, date);
        break;
      case 5:
        printf("please write the return date for your vehicle (yymmdd): ");
        scanf("%d", &date);
        strcpy(vehicle, newCar->head->vehicle);
        mileage = newCar->head->mileage;
        newCar->head->date = date;
        deleteVehicle(newCar, vehicle);
        insertVehicle(rentedCar, vehicle, mileage, date);
        break;
      case 6:
        printf("Here's the list of available cars for rent: \n");
        printList(newCar);
        printf("Here's the list of rented cars: \n");
        printList(rentedCar);
        printf("Here's the list of cars being repaired: \n");
        printList(repairCar);
        break;
      case 7:
        sendToFile(newCar, rentedCar, repairCar);
        printf("Total ammount due is %0.2f\n", sumCharge);
        exit(0);
      default:
        printf("***please input a number between 1 and 7***\n");
    }
    printf("Please pick a new number: ");
    scanf("%d", &choice);
  }
  }
  else if (question == 2){
    char postFix[MAX];
    printf("Create a postfix equation to be evaluated: ");
    scanf("%s", postFix);
    answer = evaluatePostfix(postFix);
    printf("%d is the postfix notation for the equation %s\n", answer, postFix);
  }
  return 0;
}
