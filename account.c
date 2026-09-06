#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "account.h"

void cleanBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int isValidName(const char name[])
{
    int len = strlen(name);
    if(len==0)
    {
        return 0;
    }
    for(int i=0;i<len;i++)
    {
        if (!isalpha((unsigned char)name[i]) && name[i] != ' ')
        {
            return 0;
        }
    }
    return 1;
}

void withdrawMoney(struct AccountInfo bank[],int customerCount)
{
    int accnum;
    float reducebalance;
    int index;

    if(customerCount == 0)
    {
        printf("No account registered yet");
        return;
    }

    viewBalance(bank , customerCount);

    while(1)
    {
        printf("Please enter the account number from which you wish to withdraw money:");
        scanf("%d",&accnum);
        cleanBuffer();

        index = findAccountIndex(bank,customerCount,accnum);


        if(index == -1)
        {
            printf("Invalid account number! Please try again\n");
            continue;
        }

        printf("Enter the amount you wish to withdraw:");
        scanf("%f",&reducebalance);
        cleanBuffer();

        if(reducebalance < 0)
        {
            printf("Invalid number!\n");
            continue;
        }

        float remainbalance = bank[index].balance - reducebalance;

        if(reducebalance>0 && remainbalance>=0)
        {
            bank[index].balance -= reducebalance;
            printf("Successful");
            break;
        }
        else
        {
            printf("Invalid number! Please try again\n");
        }
    }
}

void openAccount(struct AccountInfo bank[],int *customerCount)
{
    if(*customerCount >= 100)
    {
        printf("Customer limit reached.");
        return;
    }

    while(1)
    {
        printf("\nEnter your name:");
        if(fgets(bank[*customerCount].name, sizeof(bank[*customerCount].name), stdin) != NULL)
        {
            bank[*customerCount].name[strcspn(bank[*customerCount].name, "\n")] = '\0';
        }
        if(isValidName(bank[*customerCount].name)==1)
        {
            break;
        }
        else
        {
            printf("Invalid name ! Please enter the name again");
        }
    }
    bank[*customerCount].balance = 0.0;
    bank[*customerCount].accountNumber = 100 + *customerCount;

    printf("The account has been opened.\n");
    printf("Account Number:%d\n\n",bank[*customerCount].accountNumber);
    (*customerCount)++;
}

void viewBalance(struct AccountInfo bank[],int customerCount)
{
    if(customerCount == 0)
    {
        printf("No accounts registered yet");
        return;
    }
    
    for(int i=0; i<customerCount;i++)
    {
        printf("\nAccount Number:%d\t Name:%s\t Balance:%.2f\n\n",bank[i].accountNumber,bank[i].name,bank[i].balance);
    }
}

void deposeMoney(struct AccountInfo bank[],int customerCount)
{
    int accnum;
    float addbalance;
    int index;

    if(customerCount == 0)
    {
        printf("No accounts registered yet");
        return;
    }

    viewBalance(bank , customerCount);

    while(1)
    {
        printf("Please enter the account number to which you wish to deposit funds:");
        scanf("%d",&accnum);
        cleanBuffer();

        index=findAccountIndex(bank,customerCount,accnum);

        if(index == -1)
        {
            printf("Invalid account number! Please try again\n");
            continue;
        }

        printf("Enter the amount you wish to deposit:");
        scanf("%f",&addbalance);
        cleanBuffer();

        if(addbalance>0)
        {
            bank[index].balance += addbalance;
            printf("Successful");
            break;
        }
        else
        {
            printf("Invalid Number! Please try again\n");
        }
    }
}

int findAccountIndex(const struct AccountInfo bank[],int customerCount,int accnum)
{
    for(int i=0;i<customerCount;i++)
    {
        if(bank[i].accountNumber == accnum)
        {
            return i;
        }
    }
    return -1;
}

void moneyTransfer(struct AccountInfo bank[],int customerCount)
{
    int receiverIndex,senderIndex;
    int receiverNum,senderNum;
    float money;

    if(customerCount == 0)
    {
        printf("No accounts registered yet");
        return;
    }

    if(customerCount < 2)
    {
        printf("Two accounts are required for a money transfer!");
        return;
    }

    while(1)
    {
     viewBalance(bank , customerCount);

    printf("Enter the sender's account number:");
    scanf("%d",&senderNum);
    printf("Enter the receiver's account number:");
    scanf("%d",&receiverNum);

    cleanBuffer();
    
    senderIndex = findAccountIndex(bank,customerCount,senderNum);
    receiverIndex = findAccountIndex(bank,customerCount,receiverNum);

    if(senderIndex == -1 || receiverIndex == -1)
    {
        printf("Please enter a valid account number!\n");
        continue;
    }

    if(senderIndex == receiverIndex)
    {
        printf(":) Please try again");
        continue;
    }

    printf("Enter the amount:");
    scanf("%f",&money);
    
    if(money > bank[senderIndex].balance)
    {
        printf("Insufficient balance! Please try again\n");
        continue;
    }
    else if(money <= 0)
    {
        printf("Please enter a valid value! Please try again\n\n");
        continue;
    } 
    else
    { 
        bank[receiverIndex].balance += money;
        bank[senderIndex].balance -= money;
        printf("Successful\n");
        break;

    }  
    }  
}

void deleteAccount(struct AccountInfo bank[],int *customerCount)
{
    int accnum;
    int index;

    if(*customerCount == 0)
    {
        printf("No accounts registered yet");
        return;
    }
    while(1)
    {
        viewBalance(bank, *customerCount);

        printf("Please enter the account number you wish to delete:");
        scanf("%d",&accnum);

        cleanBuffer();

        index = findAccountIndex(bank,*customerCount,accnum);
    
        if(index == -1)
        {
            printf("Please enter a valid account number!\n");
            continue;
        }
        else
        {
            for(int i=index; i<*customerCount-1;i++)
            {
                bank[i] = bank[i+1];
            }
            (*customerCount)--;
            printf("Successful\n");
            break;
        }
    }
    
}
