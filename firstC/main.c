
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include<stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
int checkIfUserIsApprovedForLoan(int iD);

struct CarInventory {
    char carMake[50];
    char carModel[50];
    double price;
    int uID;
    
};
void save(char carMake[], char carModel[], char carColor[], int price, char *saveItem, int *userSession);
void displaySave(char *displayStore, int *userSession);
void signIn(char *password, char *name);
void singUp(char *, char *);
void addCar(struct CarInventory *car);
void calculatePayment(int creditScore, double downPayment, int month, double carPrice);

int main() {
    
    int carID = 0;
    char userName[32];
    char password[32];
    
    singUp(&password, &userName);

    
    signIn(&password, &userName);
    struct CarInventory car;
    
    strcpy(car.carMake, "Toyota");
    strcpy(car.carModel, "Camry");
    car.price = 23000;
    car.uID = 1;
    
    addCar(&car);
    
    
    
   
    
    
}

//saveFunction and displySave
void save(char carMake[], char carModel[], char carColor[], int price, char *saveItem, int *userSession) {
    
    if (*userSession == 1) {
        saveItem[0] = *carMake;
        saveItem[1] = *carModel;
        saveItem[2] = *carColor;
        saveItem[3] = *carModel;
    } else {
        printf("user is not signed in, can't save");
    }
}

//display saved value
void displaySave(char *displayStore, int *userSession) {
    if (*userSession == 1) {
        printf("%s\n", displayStore);
    } else {
        printf("user is not signed in, can't display\n");
    }
}

//add car models to Inventory
void addCar(struct CarInventory *car) {
    
    printf("Car ID  is: %d \n", car->uID);
    printf("Make    is: %s \n", car->carMake);
    printf("Model   is: %s \n", car->carModel);
    printf("Price   is: $ %lf \n", car->price);
    
    

}

//singIn
void signIn(char *password, char *name) {
    printf("===================================\n");
    printf("Please Sign In!\n");
    char name1[32];
    char pass1[32];
    printf("Username: \n");
    scanf("%s", name1);
    printf("Password \n");
    scanf("%s", pass1);
    
    
    if ((strcmp(name1,name)==0) && strcmp(password,pass1)==0) {
        printf("Welcome: %s\n", name);
    } else {
        printf("wrong password or username \n");
        signIn(password, name);
    }
    
}

//SignUp
void singUp(char *password, char *name) {
    int len;
    int trackUpper=0;
    int trackLower=0;
    printf("Please enter user name \n");
    scanf("%s", name);
    printf("Please enter password need at least one letter \n" );
    scanf("%s", password);
    len = strlen(password);
 
    
    while (!(trackLower == 1 && trackUpper == 1)) {
        for (int i=0; i < len; i++) {
            if (isupper(password[i])) {
                trackUpper = 1;
       
            }
            if (islower(password[i])) {
                trackLower = 1;
               
            }
            
        }
        if (trackLower == 1 && trackUpper == 1) {
            printf("password and username created successsfuly \n" );
        } else {
            printf("Please make sure password has at least one letter \n");
            trackLower = 0;
            trackUpper = 0;
            scanf("%s", password);
        }
       
    }
    
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
