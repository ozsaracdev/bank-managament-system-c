#include <stdio.h>
#include <stdlib.h>
#include "account.h"

int main()
{
    struct AccountInfo bank[100];
    int customerCount = 0;
    int selection;

    while(1)
    {
        system("cls");

        printf("******* BANKING SYSTEM *******\n");
        printf("1 - Open a new account\n");
        printf("2 - View balance\n");
        printf("3 - Deposit money\n");
        printf("4 - Withdraw money\n");
        printf("5 - Money transfer\n");
        printf("0 - Exit\n");
        printf("Please make a selection:");
        scanf("%d",&selection);

        cleanBuffer();

        if(selection==0)
        {
            printf("Logging out...");
            break;
        }

        switch(selection)
        {
            case 1:
                openAccount(bank, &customerCount);
                break;

            case 2:
                viewBalance(bank , customerCount);
                break;

            case 3:
                deposeMoney(bank , customerCount);
                break;

            case 4:
                withdrawMoney(bank, customerCount);
                break;

            case 5:
                moneyTransfer(bank,customerCount);
                break;
                
            default:
                printf("Invalid selection. Please try again.");
                break;
        }

        printf("\n");
        system("pause");
    }
    return 0;
}

