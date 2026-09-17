# Bank Management System

A simple, console-based banking application written in C. This project allows users to manage bank accounts, perform financial transactions, and persist records locally using binary file operations.

## Features

- **Open Account**: Create a new account with built-in alphabetic name validation.
- **Deposit & Withdraw**: Safely add or withdraw money with real-time balance checks.
- **Money Transfer**: Transfer funds between two valid accounts.
- **View & Delete**: Inspect existing account balances or remove an account from the system.
- **Data Persistence**: Automatically loads data on startup and saves changes to a binary file (`accounts.dat`), keeping data intact across restarts.

## How to Build and Run

### 1. Compile the Project
Open your terminal in the project directory and run:

```bash
gcc main.c account.c -o bank_app