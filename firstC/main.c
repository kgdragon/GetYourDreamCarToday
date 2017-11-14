
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include<stdlib.h>
#include <unistd.h>

int checkIfUserIsApprovedForLoan();
void delay(int numberOfSeconds);
int main() {
    
    checkIfUserIsApprovedForLoan();
}


//check if use is qualified to get loan
int checkIfUserIsApprovedForLoan() {
    int userApproved = 0;
    int creditScore = 0;
    int arrayCredit[4] = {550, 650, 750, 850};
    
    printf("Please enter your credit score to see if you are approved for the loan\n");
    scanf("%d", &creditScore);
    
   

        if (creditScore >= arrayCredit[3]) {
            printf("Fantastic, you have been approved for Execellent credit score");
        } else if (creditScore < arrayCredit[3] && creditScore >= arrayCredit[2]) {
            printf("Fantastic, you have been approved for Great credit score\n");
        } else if (creditScore < arrayCredit[2] && creditScore >= arrayCredit[1]) {
            printf("Fantastic, you have been approved for Average credit score\n");
        } else if (creditScore < arrayCredit[1] && creditScore >= arrayCredit[0]) {
            printf("Fantastic, you have been approved for Minimum credit score\n");
        } else if (creditScore < arrayCredit[0]) {
            printf("Sorry, You have not been approved for the loan\n");
        }

    return userApproved;
}
