#include <stdio.h>

#include "contact.h"
#include "file.h"


int main()
{
    int choice;
    AddressBook addressBook;
    addressBook.contactCount = 0;
    loadContFile(&addressBook);

    do
    {
        printLine();
        printf("                    ADDRESS BOOK MENU\n");
        printLine();


        printf("1. Create contact\n");
        printf("2. Edit contact\n");
        printf("3. Delete contact\n");
        printf("4. Search contact\n");
        printf("5. List contact\n");
        printf("6. Save contacts\n");
        printf("7. Exit\n");

        printLine();
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createContact(&addressBook);
                break;

            case 2:
                editContact(&addressBook);
                break;

            case 3:
                deleteContact(&addressBook);
                break;

            case 4:
                searchContact(&addressBook);
                break;

            case 5:
                listContacts(&addressBook);
                break;

            case 6:
                saveContactsToFile(&addressBook);
                break;

            case 7:
                printLine();
                printf("                    EXITING ADDRESS BOOK\n");
                printLine();
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 7);
    return 0;
}
