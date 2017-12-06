
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

void checkIfUserIsApprovedForLoan(int creditScore);
void calculatePayment(int creditScore, double downPayment, int month, double carPrice);
//void signIn(char *password, char *name);
//void singUp(char *, char *);
void insert(ListNodePtr *sPtr, struct Car *carPtr);
void printList(ListNodePtr currentPtr);
void printCarInfo(struct Car *carPtr);

struct Car
{
    char carMaker[50];
    char carModel[50];
    double price;
    char carColor[50];
    int uID;
};

struct listNode
{
    struct Car *carPtr;
    struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *sPtr, struct Car *carPtr)
{
    ListNodePtr newPtr = malloc(sizeof(ListNode));
    if(newPtr != NULL)
    {
        newPtr->carPtr = carPtr;
        newPtr->nextPtr = NULL;
        
        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;
        
        while(currentPtr != NULL && carPtr->price > currentPtr->carPtr->price)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        
        if(previousPtr == NULL)
        {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else
        {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
    {
        printf("this car not inserted. No memory available.\n");
    }
    
}

void printList(ListNodePtr currentPtr)
{
    while(currentPtr != NULL)
    {
        printCarInfo(currentPtr->carPtr);
        currentPtr = currentPtr->nextPtr;
    }
}

int main()
{
    int carID = 0;
    
    struct Car car;
    ListNodePtr startPtr = NULL;
    
    FILE *cfPtr;//cfptr = CarInventory.txt file pointer
    
    if ((cfPtr = fopen("/Users/yanpengli/Google Drive/2017 Fall/--CS 49C/Hw/Project/CarInventory.txt", "r")) == NULL)
    {
        puts("Files could not be opened");
    }
    else
    {
        char carMaker[50];
        char carModel[50];
        char carColor[50];
        double price;
        
        printf("%-13s%-13s%-13s%s\n", "Maker", "Model", "Color", "price");
        fscanf(cfPtr, "%49s%49s%49s%lf", carMaker, carModel, carColor, &price);
        strcpy(car.carMaker, carMaker);
        strcpy(car.carModel, carModel);
        strcpy(car.carColor, carColor);
        car.price = price;
        car.uID = 1;
        //addCar(&car);
        insert(&startPtr, &car);
        
        while(!feof(cfPtr))
        {
            //printf("%-13s%-13s%-13s%7.2f\n", carMaker, carModel, carColor, price);
            fscanf(cfPtr, "%49s%49s%49s%lf", carMaker, carModel, carColor, &price);
            strcpy(car.carMaker, carMaker);
            strcpy(car.carModel, carModel);
            strcpy(car.carColor, carColor);
            car.price = price;
            car.uID = 1;
            //addCar(&car);
            insert(&startPtr, &car);
        }
        fclose(cfPtr);
    }
    printList(startPtr);
    
    
    puts("Hello, I'm Virtual Assistant. Welcome to Stevens Creek Toyota&Subaru. May I have your name, please?");
    char customerName [30];
    scanf("%s", &customerName);
    printf("Good Choice, %s. Now we start checking and seeing if you is approved for Loan.\n", customerName);
    puts("Please enter your credit Score");
    int creditScore;
    scanf("%d", &creditScore);
    checkIfUserIsApprovedForLoan(creditScore);
    printf("%s, Now we estimate your monthly payments on your new car.\n", customerName);
    puts("How much would you like to pay today");
    int downPayment;
    scanf("%d", &downPayment);
    puts("How long would you like to finance your new car?");
    int month;
    scanf("%d", &month);
    calculatePayment(creditScore, downPayment, month, car.price);
}

//add car models to Inventory
void printCarInfo(struct Car *carPtr) {
    printf("Car ID  is: %d \n", carPtr->uID);
    printf("Make    is: %s \n", carPtr->carMaker);
    printf("Model   is: %s \n", carPtr->carModel);
    printf("Color   is: %s \n", carPtr->carColor);
    printf("Price   is: $ %lf \n", carPtr->price);
    printf("\n");
}

//calculate car payment
void calculatePayment(int creditScore, double downPayment, int month, double carPrice) {
    double interest=0;
    
    double monthlyPayment =0;
    int arrayCredit[4] = {550, 650, 750, 850};
    
    if (creditScore >= arrayCredit[3]) {
        interest = 1;
    } else if (creditScore < arrayCredit[3] && creditScore >= arrayCredit[2]) {
        interest = 3;
    } else if (creditScore < arrayCredit[2] && creditScore >= arrayCredit[1]) {
        interest = 5;
    } else if (creditScore < arrayCredit[1] && creditScore >= arrayCredit[0]) {
        interest = 10;
    }
    double catchInterst = interest;
    interest = (interest/100)/12;
    double principle = carPrice - downPayment;
    double getInterst = (1 + interest);
    monthlyPayment = ((interest * principle)) /(1 - pow((1+interest), -month));
    
    printf("Your interest rate is %0.2lf percents\n", catchInterst);
    printf("Your monthly payment is %0.2lf dollars\n", monthlyPayment);
}
//check if use is qualified to get loan
void checkIfUserIsApprovedForLoan(int creditScore) {
    int userApproved = 0;
    int arrayCredit[4] = {550, 650, 750, 850};
    
    printf("Checking..\n");
    usleep(1000000);
    printf("...\n");
    usleep(1000000);
    printf("....\n");
    usleep(1000000);
    printf(".....\n");
    usleep(1000000);
    
    if (creditScore >= arrayCredit[3]) {
        printf("Fantastic, you have been approved for Execellent credit score\n");
        userApproved = 1;
    } else if (creditScore < arrayCredit[3] && creditScore >= arrayCredit[2]) {
        printf("Fantastic, you have been approved for Great credit score\n");
        userApproved = 1;
    } else if (creditScore < arrayCredit[2] && creditScore >= arrayCredit[1]) {
        printf("Fantastic, you have been approved for Average credit score\n");
        userApproved = 1;
    } else if (creditScore < arrayCredit[1] && creditScore >= arrayCredit[0]) {
        printf("Fantastic, you have been approved for Minimum credit score\n");
        userApproved = 1;
    } else if (creditScore < arrayCredit[0]) {
        printf("Sorry, You have not been approved for the loan\n");
        userApproved = 0;
    }
}
