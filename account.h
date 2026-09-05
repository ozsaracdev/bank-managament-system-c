#ifndef ACCOUNT_H
#define ACCOUNT_H

struct AccountInfo{
    int accountNumber;
    char name[50];
    float balance;
};

void deposeMoney(struct AccountInfo bank[],int customerCount);
void viewBalance(struct AccountInfo bank[],int customerCount);
void openAccount(struct AccountInfo bank[],int *customerCount);
void withdrawMoney(struct AccountInfo bank[],int customerCount);
void moneyTransfer(struct AccountInfo bank[],int customerCount);
int findAccountIndex(const struct AccountInfo bank[],int customerCount,int accnum);
void cleanBuffer();
int isValidName(const char name[]);

#endif
