#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 500

typedef struct details{
    char name[50];
    char cont[20];
    char email[50];
}c;
c phone[500]; 
int num= 0;  


void addContact() {
    if (num < MAX) {
        printf("Enter name: ");
        scanf(" %[^\n]s", phone[num].name);  
        printf("Enter phone number: ");
        scanf(" %s", &phone[num].cont);
        printf("Enter email: ");
        scanf(" %s", phone[num].email);
        num++;
        printf("Contact added\n");
    } else {
        printf("Phonebook is full.\n");
    }
}


void searchContact(char *name) {
    int found = 0,i;
    for ( i = 0; i < num; i++) {
        if (strcmp(phone[i].name, name) == 0) {
            printf("Name: %s, Phone: %s, Email: %s\n", phone[i].name, phone[i].cont, phone[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact by name
void deleteContact(char *name) {
    int found = 0,i,j;
    for ( i = 0; i < num; i++) {
        if (strcmp(phone[i].name, name) == 0) {
            for ( j = i; j < num - 1; j++) {
                strcpy(phone[j].name, phone[j + 1].name);
                strcpy(phone[j].cont, phone[j + 1].cont);
                strcpy(phone[j].email, phone[j + 1].email);
            }
            num--;
            found = 1;
            printf("Contact deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to display all contacts
void displayContacts() {
    if (num == 0) {
        printf("Phonebook is empty.\n");
    } else {
        printf("Contact details:\n");
        int i;
        for ( i = 0; i < num; i++) {
            printf("Name: %s, Phone Number: %s, Email: %s\n", phone[i].name, phone[i].cont, phone[i].email);
        }
    }
}

// Main function to run the phonebook application
int main() {
    int choice;
    char name[50];

    while (1) {
        printf("\nPhonebook Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                printf("Enter name to search: ");
                scanf(" %[^\n]s", name);
                searchContact(name);
                break;
            case 3:
                printf("Enter name to delete: ");
                scanf(" %[^\n]s", name);
                deleteContact(name);
                break;
            case 4:
                displayContacts();
                break;
            case 5:
                printf("Exited Phonebook.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

