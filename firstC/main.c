#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

int checkIfUserIsApprovedForLoan(int creditScore);
void calculatePayment(int creditScore, double downPayment, int month, double carPrice);
void save(char carMake[], char carModel[], char carColor[], double price, char *saveItem, int *userSession);
void displaySave(char *displayStore, int *userSession);
void signIn(char *password, char *name, int *);
void singUp(char *, char *);

struct Car
{
    char carMaker[50];
    char carModel[50];
    double price;
    char carColor[50];
    int uID;
};

int main()
{
    
    char storeSave[50];
    int userSession = 0;
    
    int carID = 0;
    struct Car car;
    struct Car cars[100];
    char userName[32];
    char password[32];
    
    
    singUp(&password, &userName);
    signIn(&password, &userName, &userSession);
    
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
        
//        printf("%-13s%-13s%-13s%s\n", "Maker", "Model", "Color", "price");
        fscanf(cfPtr, "%49s%49s%49s%lf", carMaker, carModel, carColor, &price);
//        printf("%-13s%-13s%-13s%7.2f\n", carMaker, carModel, carColor, price);
        strcpy(cars[0].carMaker, carMaker);
        strcpy(cars[0].carModel, carModel);
        strcpy(cars[0].carColor, carColor);
        cars[0].price = price;
        cars[0].uID = 1;
        
        int i = 2;
        while(!feof(cfPtr))
        {
                fscanf(cfPtr, "%49s%49s%49s%lf", carMaker, carModel, carColor, &price);
//              printf("%-13s%-13s%-13s%7.2f\n", carMaker, carModel, carColor, price);
                strcpy(cars[i-1].carMaker, carMaker);
                strcpy(cars[i-1].carModel, carModel);
                strcpy(cars[i-1].carColor, carColor);
                cars[i-1].price = price;
                cars[i-1].uID = i;
                ++i;
        }
        fclose(cfPtr);
    }

    printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
    for(int j = 0; j < 15; ++j)
    {
        printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
    }

    puts("Enter 1 for Makers, 2 for Models, 3 for colors, 4 for Prices Range, 5 for display the whole");
    int firstEnter;
    scanf("%d", &firstEnter);
    int thirdEnter = 0;
    if( firstEnter == 1)
    {
        puts("Enter 1 for Toyota, 2 for Subaru");
        int secondEnter = 0;
        scanf("%d", &secondEnter);
        if(secondEnter == 1)
        {
            printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
            for(int j = 0; j < 15; ++j)
            {
                //char carMake[50] = {};
                const char* str = "Toyota";
                //strcpy(cars[j].carMaker, carMake);
                if( strcmp("Toyota", cars[j].carMaker) == 0)
                {
                    printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                }
            }
            scanf("%d", &thirdEnter);
            printf("You have selected # %d.\n", thirdEnter);
            save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
        }
        else if (secondEnter == 2)
        {
            printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
            for(int j = 0; j < 15; ++j)
            {
                //char carMake[50] = {};
                const char* str = "Toyota";
                //strcpy(cars[j].carMaker, carMake);
                if( strcmp("Subaru", cars[j].carMaker) == 0)
                {
                    printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                }
            }
            scanf("%d", &thirdEnter);
            printf("You have selected # %d.\n", thirdEnter);
            save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
        }
    }

    
    puts("Please enter your credit Score");
    int creditScore;
    scanf("%d", &creditScore);

    
    if (checkIfUserIsApprovedForLoan(creditScore) == 1) {
        printf("Now we estimate your monthly payments on your new car.\n");
        puts("How much would you like to pay today");
        int downPayment;
        scanf("%d", &downPayment);
        puts("How long would you like to finance your new car?");
        int month;
        scanf("%d", &month);
        
        calculatePayment(creditScore, downPayment, month, cars[thirdEnter].price);
    } else {
        printf("Please pay with cash!!!!!!!!!!");
    }
    
}

////add car models to Inventory
//void printCarInfo(struct Car *carPtr) {
//    printf("Car ID  is: %d \n", carPtr->uID);
//    printf("Make    is: %s \n", carPtr->carMaker);
//    printf("Model   is: %s \n", carPtr->carModel);
//    printf("Color   is: %s \n", carPtr->carColor);
//    printf("Price   is: $ %lf \n", carPtr->price);
//    printf("\n");
//}

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
int checkIfUserIsApprovedForLoan(int creditScore) {
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
    return userApproved;
}

//saveFunction and displySave
void save(char carMake[], char carModel[], char carColor[], double price, char *saveItem, int *userSession) {
   
    char bufferPrice[32];
    gcvt(price,10,bufferPrice);
    
    if (*userSession == 1) {
        saveItem[0] = *carMake;
        saveItem[1] = *carModel;
        saveItem[2] = *carColor;
        saveItem[3] = bufferPrice;
        printf("Selected");
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


//singIn
void signIn(char *password, char *name, int *userSession) {
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
        *userSession = 1;
    } else {
        printf("wrong password or username \n");
        signIn(password, name, *userSession);
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
