#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "art.c"

#define MAX_SIZE 100

char nameb[MAX_SIZE] = "";
char docb[MAX_SIZE] = "";
char issueb[MAX_SIZE] = "";
char amtb[MAX_SIZE] = "";
char* name[MAX_SIZE];
char* doc[MAX_SIZE];
char* issue[MAX_SIZE];
double amt[MAX_SIZE];
int mp = 0;
char* col[] = { "Name", "Doctor", "Amount", "Issue" };
char docname[][20] = { "Dr. Jagdish Patil", "Dr. Surbhi Anand", "Dr. Sanjay Sachdeva" };

void input();
void display();
void display_doc(char* d);
void display_amt(double a);
void refresh();
void max();
void top();
void line();
void display() {
    int c = 0;
    char input[MAX_SIZE];
    char *token;

    // Counting the number of patients
    for (int i = 0; i < strlen(nameb); i++) {
        if (nameb[i] == ':')
            c++;
    }

    // Checking if there are no patients
    if (c == 0) {
        println("No Data Found", 0);
        return;
    } else {
        max();
        top();
        // Tokenizing and printing each patient's information
        token = strtok(nameb, ":");
        for (int i = 0; i < c; i++) {
            printf("\n|%s\t\t%s\t\t%.2f\t\t%s|", token, strtok(NULL, ":"), amtb[i], strtok(NULL, ":"));
            token = strtok(NULL, ":");
        }
        line();
    }

    // Waiting for user input
    printf("\nPress Enter to continue...\n");
    fgets(input, sizeof(input), stdin);
}
 void input() {
    char n[MAX_SIZE], dn[MAX_SIZE], i[MAX_SIZE], a[MAX_SIZE], check_input[MAX_SIZE];
    int check = 0, choice;

    printf("Enter Name of Patient: ");
    fgets(n, sizeof(n), stdin);
    strtok(n, "\n"); // remove newline character

    printf("Please choose doctor's name:\n1. Dr. Jagdish Patil\n2. Dr. Surbhi Anand\n3. Dr. Sanjay Sachdeva\n");
    fgets(check_input, sizeof(check_input), stdin);
    choice = atoi(check_input);
    if (choice >= 1 && choice <= 3) {
        strcpy(dn, docname[choice - 1]);
    } else {
        printf("Invalid choice.\n");
        return;
    }

    printf("Enter Issue of The Patient: ");
    fgets(i, sizeof(i), stdin);
    strtok(i, "\n"); // remove newline character

    printf("Enter Fee charged: ");
    fgets(a, sizeof(a), stdin);
    strtok(a, "\n"); // remove newline character

    printf("Are you sure about the data enter\n1. Yes\n2. No: ");
    fgets(check_input, sizeof(check_input), stdin);
    choice = atoi(check_input);
    if (choice == 2) {
        input();
        return;
    }

    strcat(nameb, n);
    strcat(nameb, ":");
    strcat(docb, dn);
    strcat(docb, ":");
    strcat(issueb, i);
    strcat(issueb, ":");
    strcat(amtb, a);
    strcat(amtb, ":");

    printf("Data Entered Successfully\n");
    printf("Press Enter to continue or enter 'q' to quit: ");
    fgets(check_input, sizeof(check_input), stdin);
    if (tolower(check_input[0]) == 'q') {
        return;
    } else {
        input();
    }
}
void display_doc(char *d) {
    int c = 0;
    char input[MAX_SIZE];
    char *token;

    // Counting the number of patients
    for (int i = 0; i < strlen(nameb); i++) {
        if (nameb[i] == ':')
            c++;
    }

    // Counting the number of patients with the specified doctor's name
    int t = 0;
    for (int i = 0; i < c; i++) {
        if (strcasecmp(docb, d) == 0)
            t++;
    }

    // If no patients found with the specified doctor's name
    if (t == 0) {
        println("No Data Found", 0);
        return;
    } else {
        max();
        top();
        // Printing information of patients with the specified doctor's name
        token = strtok(nameb, ":");
        while (token != NULL) {
            if (strcasecmp(strtok(NULL, ":"), d) == 0) {
                printf("\n|%s\t\t%s\t\t%.2f\t\t%s|", token, strtok(NULL, ":"), amtb[c], strtok(NULL, ":"));
            }
            token = strtok(NULL, ":");
        }
        line();
    }
    
    // Waiting for user input
    printf("\nPress Enter to continue...\n");
    fgets(input, sizeof(input), stdin);
}

    
