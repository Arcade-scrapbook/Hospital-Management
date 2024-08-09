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

    int main() {
        char input[MAX_SIZE];

        printf("\n1. Enter Data\n2. Patient List\n3. Patient list based on doctor\n4. Patient based on ammount\n5. Enter Q to return to Home Screen\n");
        fgets(input, sizeof(input), stdin);
        strtok(input, "\n"); // remove newline character

        if (strcmp(input, "Q") == 0) {
            printf("\n");
            return 1;
        }

        int t = atoi(input);
        if (t == 1)
            input();
        else if (t == 2)
            display();
        else if (t == 3) {
            printf("Please choose doctors name:\n1. Dr. Jagdish Patil\n2. Dr. Surbhi Anand\n3. Dr. Sanjay Sachdeva\n");
            fgets(input, sizeof(input), stdin);
            strtok(input, "\n"); // remove newline character
            display_doc(docname[atoi(input) - 1]);
        } else if (t == 4) {
            printf("Please enter amount to be filtered: ");
            fgets(input, sizeof(input), stdin);
            strtok(input, "\n"); // remove newline character
            display_amt(atof(input));
        } else
            main_paitent();

    
    return 1;
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

    
void display_amt(double a) {
    int c = 0;
    char input[MAX_SIZE];
    char *token;

    // Counting the number of patients
    for (int i = 0; i < strlen(nameb); i++) {
        if (nameb[i] == ':')
            c++;
    }

    // Counting the number of patients with the specified amount
    int t = 0;
    for (int i = 0; i < c; i++) {
        if (amtb[i] == a)
            t++;
    }

    // If no patients found with the specified amount
    if (t == 0) {
        println("No Data Found", 0);
        return;
    } else {
        max();
        top();
        // Printing information of patients with the specified amount
        token = strtok(nameb, ":");
        while (token != NULL) {
            if (amtb[c] == a) {
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

    void refresh() {
    int c = 0;
    int w = 0;
    char wd[MAX_SIZE];
    char *token;

    // Counting the number of patients
    for (int i = 0; i < strlen(nameb); i++) {
        if (nameb[i] == ':')
            c++;
    }

    // Allocating memory for arrays based on the number of patients
    char *name[c];
    char *doc[c];
    char *issue[c];
    double amt[c];

    // Tokenizing and populating arrays
    token = strtok(nameb, ":");
    while (token != NULL) {
        strcpy(wd, token);
        name[w] = wd;
        token = strtok(NULL, ":");
        strcpy(wd, token);
        doc[w] = wd;
        token = strtok(NULL, ":");
        strcpy(wd, token);
        issue[w] = wd;
        token = strtok(NULL, ":");
        strcpy(wd, token);
        amt[w] = atof(wd);
        token = strtok(NULL, ":");
        w++;
    }
}

    void max() {
    mp = 0;
    int i;
    
    // Finding the maximum length among columns, names, doctors, and issues
    char *col[] = { "Name", "Doctor", "Amount", "Issue" };
    int col_size = sizeof(col) / sizeof(col[0]);
    for (i = 0; i < col_size; i++) {
        int len = strlen(col[i]);
        if (len > mp)
            mp = len;
    }

    int c = 0;
    for (i = 0; i < strlen(nameb); i++) {
        if (nameb[i] == ':')
            c++;
    }

    char *name[c];
    char *doc[c];
    char *issue[c];

    // Tokenizing the strings and calculating maximum length
    char *token = strtok(nameb, ":");
    for (i = 0; i < c; i++) {
        name[i] = token;
        int len = strlen(token);
        if (len > mp)
            mp = len;
        token = strtok(NULL, ":");
    }

    token = strtok(docb, ":");
    for (i = 0; i < c; i++) {
        doc[i] = token;
        int len = strlen(token);
        if (len > mp)
            mp = len;
        token = strtok(NULL, ":");
    }

    token = strtok(issueb, ":");
    for (i = 0; i < c; i++) {
        issue[i] = token;
        int len = strlen(token);
        if (len > mp)
            mp = len;
        token = strtok(NULL, ":");
    }

    // printf("Maximum length: %d\n", mp);
}
}
