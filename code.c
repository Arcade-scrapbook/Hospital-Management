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
