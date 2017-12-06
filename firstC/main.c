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
void signIn(char *password, char *name);
void signUp(char *, char *);
void addCar(struct CarInventory *car);
void calculatePayment(int creditScore, double downPayment, int month, double carPrice);

int main() {
    
    int carID = 0;
    //username and password max size is 24
    char userName[24];
    char password[24];
    
    signUp(&password, &userName);
    
    
    signIn(&password, &userName);
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

//Sign In
void signIn(char *password, char *name) {
    printf("\n===================================\n");
    printf("Please Sign In!\n");
    char name1[24];
    char pass1[24];
    printf("Username: \n");
    scanf("%s", name1);
    printf("Password: \n");
    scanf("%s", pass1);
    
    
    if ((strcmp(name1,name)==0) && strcmp(password, pass1)==0) {
        printf("Welcome: %s\n", name);
    } else {
        printf("Wrong password or username! \n");
        signIn(password, name);
    }
    
}

//Sign Up
void signUp(char *password, char *name) {
    
    printf("Please enter username: \n");
    scanf("%s", name);
    //Declare variables
    int i, trackDigits = 0, trackUpper = 0, trackLower = 0;
    int count, trackCount=0;
    /*loop until user enters a valid password */
    while(1)
    {
        count = 0;
        trackDigits = 0;
        trackUpper = 0;
        trackLower = 0;
        trackCount = 0;
        //Getting the password entered by the user
        printf("\nEnter your password: \n");
        scanf("%s", password);
        /*Checking the length of the string is valid or not, if not, display error message*/
        //Must be certain length (between 5 and 24)
        if(strlen(password)<5){
            printf("This password is too short.");
            count++;
        }
        else if(strlen(password)>24){
            printf("\n This password is too long.");
            count++;
        }
        
        //Checking whteher the password contains at least one digit or not
        for(i=0; i<strlen(password); i++){
            if(isdigit(password[i])){
                trackDigits++;
            }
        }
        if(trackDigits<1){
            printf("\nThis password needs at least one digit.");
            count++;
        }
        //Checking whether the password contains at least one uppercase letter or not
        for(i=0; i<strlen(password);i++){
            if(isupper(password[i])){
                trackUpper++;
            }
        }
        if(trackUpper<1){
            printf("\nThis password needs an uppercase character.");
            count++;
        }
        //Checking whether the password contains at least one lowercase letter or not
        for(i=0; i <strlen(password); i++){
            if(islower(password[i])){
                trackLower++;
            }
        }
        if(trackLower < 1){
            printf("\nThis password needs a lowercase character.");
            count++;
        }
        //Checks whether the password contains punctuation or not
        for(i=0;i<strlen(password);i++){
            if(ispunct(password[i])){
                trackCount++;
            }
        }
        if(trackCount<1){
            printf("\nThis password needs at least one punctation character as well.");
            count++;
        }
        
        if(count==0){
            printf("\nThe entered password is valid.");
            break;
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
