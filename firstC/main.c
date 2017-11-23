
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include<stdlib.h>
#include <unistd.h>
#include <math.h>

int checkIfUserIsApprovedForLoan(int iD);

struct CarInventory {
    char carMake[50];
    char carModel[50];
    double price;
    int uID;
    
};

void addCar(struct CarInventory *car);
void calculatePayment(int creditScore, double downPayment, int month, double carPrice);

int main() {
    
    int carID = 0;
   
    struct CarInventory car;
    
    strcpy(car.carMake, "Toyota");
    strcpy(car.carModel, "Camry");
    car.price = 23000;
    car.uID = 1;
    
    addCar(&car);
    
}

//add car models to Inventory
void addCar(struct CarInventory *car) {
    
    printf("Car ID  is: %d \n", car->uID);
    printf("Make    is: %s \n", car->carMake);
    printf("Model   is: %s \n", car->carModel);
    printf("Price   is: $ %lf \n", car->price);
    
    
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
int checkIfUserIsApprovedForLoan(int iD) {
    int userApproved = 0;
    int creditScore = 0;
    int arrayCredit[4] = {550, 650, 750, 850};
    
    printf("Please enter your credit score to see if you are approved for the loan\n");
    scanf("%d", &creditScore);
    
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

    return userApproved;
}
