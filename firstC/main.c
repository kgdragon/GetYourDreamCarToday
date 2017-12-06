#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

void singUp(char *, char *);
void signIn(char *password, char *name, int *);
typedef struct Car CAR;
void save(char carMake[], char carModel[], char carColor[], double price, char *saveItem, int *userSession);
int checkIfUserIsApprovedForLoan(int creditScore);
void calculatePayment(CAR *cars, int *j, int *creditScore, int *downPayment, int *month, double *monthlyPayment, double *catchInterst);
void receipt(CAR *cars, int *j, int *creditScore, int *downPayment, int *month, double *monthlyPayment, double *catchInterst);

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
    
    
    int browsOrSignIn;
    printf("\n press 1 if you want to brows the car without signup/in, or press 2 to sign up\n");
    scanf("%d", &browsOrSignIn);
    
    if (browsOrSignIn == 1)
    {
        FILE *cfPtr;//create a pointer variable of type FILE called cfPtr
        
        //open the file called CarInventory.txt in read mode
        //fopen opens file. Exit program if unable to create file
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
            fscanf(cfPtr, "%49s%49s%49s%lf", carMaker, carModel, carColor, &price);
            strcpy(cars[0].carMaker, carMaker);
            strcpy(cars[0].carModel, carModel);
            strcpy(cars[0].carColor, carColor);
            cars[0].price = price;
            cars[0].uID = 1;
            int i = 2;
            while(!feof(cfPtr))//while not end of file
            {
                fscanf(cfPtr, "%49s%49s%49s%lf", carMaker, carModel, carColor, &price); //Read Formatted Data and stores them according to the parameter format into the locations pointed by the additional arguments
                strcpy(cars[i-1].carMaker, carMaker); // copies the string to the another character array named cars[i-1].carMaker.
                strcpy(cars[i-1].carModel, carModel);
                strcpy(cars[i-1].carColor, carColor);
                cars[i-1].price = price;
                cars[i-1].uID = i;
                ++i;
            }
            fclose(cfPtr);
        }
        
        puts("Enter 1 for Makers, 2 for colors, 3 for Prices Range, 4 for display the inventory");
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
                    const char* str = "Toyota";
                    if( strcmp("Toyota", cars[j].carMaker) == 0)
                    {
                        printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                    }
                }
                puts("Please pick a car by entering uID");
                scanf("%d", &thirdEnter);
                printf("You have selected # %d.\n", thirdEnter);
                save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
            }
            else if (secondEnter == 2)
            {
                printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
                for(int j = 0; j < 15; ++j)
                {
                    if( strcmp("Subaru", cars[j].carMaker) == 0)
                    {
                        printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                    }
                }
                puts("Please pick a car by entering uID");
                scanf("%d", &thirdEnter);
                printf("You have selected # %d.\n", thirdEnter);
                save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
            }
        }
        else if (firstEnter == 2)//2 for colors
        {
            puts("Enter 1 for White, 2 for Silver, 3 for Black, 4 for Blue, 5 for Red");
            int secondEnter = 0;
            scanf("%d", &secondEnter);
            if(secondEnter == 1)//Enter 1 for White
            {
                printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
                for(int j = 0; j < 15; ++j)
                {
                    if( strcmp("White", cars[j].carColor) == 0)
                    {
                        printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                    }
                }
                puts("Please pick a car by entering uID");
                scanf("%d", &thirdEnter);
                printf("You have selected # %d.\n", thirdEnter);
                save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
            }
            else if (secondEnter == 2)//2 for Silver
            {
                printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
                for(int j = 0; j < 15; ++j)
                {
                    if( strcmp("Silver", cars[j].carColor) == 0)
                    {
                        printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                    }
                }
                puts("Please pick a car by entering uID");
                scanf("%d", &thirdEnter);
                printf("You have selected # %d.\n", thirdEnter);
                save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
            }
            else if (secondEnter == 3)//3 for Black
            {
                printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
                for(int j = 0; j < 15; ++j)
                {
                    if( strcmp("Black", cars[j].carColor) == 0)
                    {
                        printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                    }
                }
                puts("Please pick a car by entering uID");
                scanf("%d", &thirdEnter);
                printf("You have selected # %d.\n", thirdEnter);
                save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
            }
            else if (secondEnter == 4)//4 for Blue
            {
                printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
                for(int j = 0; j < 15; ++j)
                {
                    if( strcmp("Blue", cars[j].carColor) == 0)
                    {
                        printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                    }
                }
                puts("Please pick a car by entering uID");
                scanf("%d", &thirdEnter);
                printf("You have selected # %d.\n", thirdEnter);
                save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
            }
            else//5 for Red
            {
                printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
                for(int j = 0; j < 15; ++j)
                {
                    if( strcmp("Red", cars[j].carColor) == 0)
                    {
                        printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                    }
                }
                puts("Please pick a car by entering uID");
                scanf("%d", &thirdEnter);
                printf("You have selected # %d.\n", thirdEnter);
                save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
            }
        }
        else if (firstEnter == 3)//3 for Prices Range
        {
            puts("Please Enter your price range, for example, enter 33000 means under 33000");
            double secondEnter = 0;
            scanf("%lf", &secondEnter);
            if(secondEnter > 18000)
            {
                printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
                for(int j = 0; j < 15; ++j)
                {
                    if( cars[j].price <= secondEnter)
                    {
                        printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                    }
                }
                puts("Please pick a car by entering uID");
                scanf("%d", &thirdEnter);
                printf("You have selected # %d.\n", thirdEnter);
                save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
            }
            else
            {
                printf("We don't have any cars priced under %.2f", secondEnter);
                main();
            }
            
        }
        else//4 for display the car inventory
        {
            printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
            for(int j = 0; j < 15; ++j)
            {
                printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
            }
            puts("Please pick a car by entering uID");
            scanf("%d", &thirdEnter);
            printf("You have selected # %d.\n", thirdEnter);
            save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
        }
        
        main();
        puts("Please enter your credit Score");
        int creditScore;
        scanf("%d", &creditScore);
        
        
        int downPayment;
        int month;
        double monthlyPayment = 0;
        double catchInterst = 0;
        if (checkIfUserIsApprovedForLoan(creditScore) == 1) {
            printf("Now we estimate your monthly payments on your new car.\n");
            puts("How much would you like to pay today");
            scanf("%d", &downPayment);
            puts("How long would you like to finance your new car?");
            scanf("%d", &month);
            
            calculatePayment(cars, &thirdEnter, &creditScore, &downPayment, &month, &monthlyPayment, &catchInterst);
        }
        else
        {
            printf("Please pay with cash!!!!!!!!!!");
        }
        receipt(cars, &thirdEnter, &creditScore, &downPayment, &month, &monthlyPayment, &catchInterst);
        
        
    }
    else
    {
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
        
            fscanf(cfPtr, "%49s%49s%49s%lf", carMaker, carModel, carColor, &price);
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
        
        puts("Enter 1 for Makers, 2 for colors, 3 for Prices Range, 4 for display the whole");
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
                    const char* str = "Toyota";
                    if( strcmp("Toyota", cars[j].carMaker) == 0)
                    {
                        printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                    }
                }
                puts("Please pick a car by entering uID");
                scanf("%d", &thirdEnter);
                printf("You have selected # %d.\n", thirdEnter);
                save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
            }
            else if (secondEnter == 2)
            {
                printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
                for(int j = 0; j < 15; ++j)
                {
                    if( strcmp("Subaru", cars[j].carMaker) == 0)
                    {
                        printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                    }
                }
                puts("Please pick a car by entering uID");
                scanf("%d", &thirdEnter);
                printf("You have selected # %d.\n", thirdEnter);
                save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
            }
        }
        else if (firstEnter == 2)//2 for colors
        {
            puts("Enter 1 for White, 2 for Silver, 3 for Black, 4 for Blue, 5 for Red");
            int secondEnter = 0;
            scanf("%d", &secondEnter);
            if(secondEnter == 1)//Enter 1 for White
            {
                printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
                for(int j = 0; j < 15; ++j)
                {
                    if( strcmp("White", cars[j].carColor) == 0)
                    {
                        printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                    }
                }
                puts("Please pick a car by entering uID");
                scanf("%d", &thirdEnter);
                printf("You have selected # %d.\n", thirdEnter);
                save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
            }
            else if (secondEnter == 2)//2 for Silver
            {
                printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
                for(int j = 0; j < 15; ++j)
                {
                    if( strcmp("Silver", cars[j].carColor) == 0)
                    {
                        printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                    }
                }
                puts("Please pick a car by entering uID");
                scanf("%d", &thirdEnter);
                printf("You have selected # %d.\n", thirdEnter);
                save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
            }
            else if (secondEnter == 3)//3 for Black
            {
                printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
                for(int j = 0; j < 15; ++j)
                {
                    if( strcmp("Black", cars[j].carColor) == 0)
                    {
                        printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                    }
                }
                puts("Please pick a car by entering uID");
                scanf("%d", &thirdEnter);
                printf("You have selected # %d.\n", thirdEnter);
                save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
            }
            else if (secondEnter == 4)//4 for Blue
            {
                printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
                for(int j = 0; j < 15; ++j)
                {
                    if( strcmp("Blue", cars[j].carColor) == 0)
                    {
                        printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                    }
                }
                puts("Please pick a car by entering uID");
                scanf("%d", &thirdEnter);
                printf("You have selected # %d.\n", thirdEnter);
                save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
            }
            else//5 for Red
            {
                printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
                for(int j = 0; j < 15; ++j)
                {
                    if( strcmp("Red", cars[j].carColor) == 0)
                    {
                        printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                    }
                }
                puts("Please pick a car by entering uID");
                scanf("%d", &thirdEnter);
                printf("You have selected # %d.\n", thirdEnter);
                save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
            }
        }
        else if (firstEnter == 3)//3 for Prices Range
        {
            puts("Please Enter your price range, for example, enter 33000 means under 33000");
            double secondEnter = 0;
            scanf("%lf", &secondEnter);
            if(secondEnter > 18000)
            {
                printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
                for(int j = 0; j < 15; ++j)
                {
                    if( cars[j].price <= secondEnter)
                    {
                        printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
                    }
                }
                puts("Please pick a car by entering uID");
                scanf("%d", &thirdEnter);
                printf("You have selected # %d.\n", thirdEnter);
                save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
            }
            else
            {
                printf("We don't have any cars priced under %.2f", secondEnter);
                main();
            }
        }
        else//4 for display the car inventory
        {
            printf("%-13s%-13s%-13s%-13s%-13s\n", "Maker", "Model", "Color", "price", "uID");
            for(int j = 0; j < 15; ++j)
            {
                printf("%-13s%-13s%-13s%7.2f%7d \n", cars[j].carMaker, cars[j].carModel, cars[j].carColor, cars[j].price, cars[j].uID);
            }
            puts("Please pick a car by entering uID");
            scanf("%d", &thirdEnter);
            printf("You have selected # %d.\n", thirdEnter);
            save(cars[thirdEnter].carMaker, cars[thirdEnter].carModel, cars[thirdEnter].carColor, cars[thirdEnter].price, &storeSave, &userSession);
        }
        
        puts("Please enter your credit Score");
        int creditScore;
        scanf("%d", &creditScore);
        int downPayment;
        int month;
        double monthlyPayment = 0;
        double catchInterst = 0;
        if (checkIfUserIsApprovedForLoan(creditScore) == 1)
        {
            printf("Now we estimate your monthly payments on your new car.\n");
            puts("How much would you like to pay today");
            scanf("%d", &downPayment);
            puts("How long would you like to finance your new car?");
            scanf("%d", &month);
            calculatePayment(cars, &thirdEnter, &creditScore, &downPayment, &month, &monthlyPayment, &catchInterst);
        }
        else
        {
            printf("Please pay with cash!!!!!!!!!!");
        }
        receipt(cars, &thirdEnter, &creditScore, &downPayment, &month, &monthlyPayment, &catchInterst);
    }
}

//calculate car paymentvi
void calculatePayment(CAR* cars, int *j, int *creditScore, int *downPayment, int *month, double *monthlyPayment, double *catchInterst)
{
    double interest = 0;
    double principle = 0;
    int arrayCredit[4] = {550, 650, 750, 850};
    
    if (*creditScore >= arrayCredit[3]) {
        interest = 3.89;
    } else if (*creditScore < arrayCredit[3] && *creditScore >= arrayCredit[2]) {
        interest = 4.89;
    } else if (*creditScore < arrayCredit[2] && *creditScore >= arrayCredit[1]) {
        interest = 5.89;
    } else if (*creditScore < arrayCredit[1] && *creditScore >= arrayCredit[0]) {
        interest = 6.89;
    }
    *catchInterst = interest;
    interest = (interest/100)/12;
    principle = cars[*j].price - (*downPayment);
    double getInterst = (1 + interest);
    *monthlyPayment = ((interest + (interest/(pow((1 + interest),(*month-1))))) * principle);
    printf("Your interest rate is %0.2lf percents\n", *catchInterst);
    printf("Your monthly payment is %0.2lf dollars\n", *monthlyPayment);
    puts("A receipt has generated.");
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
    }
    else
    {
        printf("user is not signed in, can't save");
    }
}

//Generate a receipt
void receipt(CAR *cars, int *j, int *creditScore, int *downPayment, int *month, double *monthlyPayment, double *catchInterst)
{
    FILE *cfPtr;
    if ((cfPtr = fopen("/Users/yanpengli/Google Drive/2017 Fall/--CS 49C/Hw/Project/receipt.txt", "w")) == NULL)
    {
        cfPtr = fopen("/Users/yanpengli/Google Drive/2017 Fall/--CS 49C/Hw/Project/receipt.txt", "w+");
        fputs(cars[*j].carMaker, cfPtr);
        fputs("   ", cfPtr);
        fputs(cars[*j].carModel, cfPtr);
        fputs("   ", cfPtr);
        fputs(cars[*j].carColor, cfPtr);
        fputs("   ", cfPtr);
        fprintf(cfPtr, "%.2f", cars[*j].price);
        fputs("   ", cfPtr);
        fprintf(cfPtr, "%d", cars[*j].uID);
        fputs(".\n", cfPtr);
        fputs("creditScore:", cfPtr);
        fprintf(cfPtr, "%d", *creditScore);
        fputs(", downPayment:", cfPtr);
        fprintf(cfPtr, "%d", *downPayment);
        fputs(", months:", cfPtr);
        fprintf(cfPtr, "%d", *month);
        fputs(", Monthly Payment:", cfPtr);
        fprintf(cfPtr, "%.2f", *monthlyPayment);
        fputs(", Auto Loan Rates:", cfPtr);
        fprintf(cfPtr, "%.2f", *catchInterst);
        fclose(cfPtr);
    }
    else
    {
        cfPtr = fopen("/Users/yanpengli/Google Drive/2017 Fall/--CS 49C/Hw/Project/receipt.txt", "w+");
        fputs(cars[*j].carMaker, cfPtr);
        fputs("   ", cfPtr);
        fputs(cars[*j].carModel, cfPtr);
        fputs("   ", cfPtr);
        fputs(cars[*j].carColor, cfPtr);
        fputs("   ", cfPtr);
        fprintf(cfPtr, "%.2f", cars[*j].price);
        fputs("   ", cfPtr);
        fprintf(cfPtr, "%d", cars[*j].uID);
        fputs(".\n", cfPtr);
        fputs("creditScore:", cfPtr);
        fprintf(cfPtr, "%d", *creditScore);
        fputs(", downPayment:", cfPtr);
        fprintf(cfPtr, "%d", *downPayment);
        fputs(", months:", cfPtr);
        fprintf(cfPtr, "%d", *month);
        fputs(", Monthly Payment:", cfPtr);
        fprintf(cfPtr, "%.2f", *monthlyPayment);
        fputs(", Auto Loan Rates:", cfPtr);
        fprintf(cfPtr, "%.2f", *catchInterst);
        fclose(cfPtr);
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
