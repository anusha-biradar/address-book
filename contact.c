#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"

// for printing lines

void printLine()
{
    printf("------------------------------------------------------------\n");
}

// for case insensitive search
int ignoreCase(char *name, char *search)
{
    int i, j;

    for(i=0;name[i]!= '\0'; i++)
    {
        j=0;

        while(search[j]!= '\0' && name[i + j]!='\0' && tolower(name[i + j])== tolower(search[j]))
        {
            j++;
        }

        if(search[j]=='\0')
        {
            return 1;
        }
    }
    return 0;
}

// list contacts
void listContacts(AddressBook *addressBook)
{
    int i;
    if(addressBook->contactCount== 0)
    {
        printf("No contacts found\n");
        return;
    }

    printf("\n--- Contact List ---\n");

    for(i =0;i<addressBook->contactCount; i++)
    {
        printf("%d. Name: %s | Phone: %s | Email: %s\n", i,addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
}

// creating contacts

void createContact(AddressBook *addressBook)
{
    char create_name[30];
    char create_phonenumber[20];
    char create_email[50];

    int len;
    int i;

    printLine();

    printf("                    ENTERED INTO CREATE CONTACT\n");
    printLine();

    if (addressBook->contactCount >=MAX_CONTACTS)
    {
        printf("Address book is full\n");
        return;
    }
    printf("Enter the name: ");
    scanf(" %[^\n]", create_name);

    for(i=0;create_name[i]!='\0';i++)
    {
        if(isdigit(create_name[i]))
        {
            printf("Invalid name\n");
            return;
        }
    }

    printf("Enter phone number: ");
    scanf("%s", create_phonenumber);

    len =strlen(create_phonenumber);

    if(len!= 10)
    {
        printf("Invalid phone number\n");
        return;
    }

    for(i=0;create_phonenumber[i]!='\0'; i++)
    {
        if (!isdigit(create_phonenumber[i]))
        {
            printf("Invalid phone number\n");
            return;
        }
    }

    printf("Enter the email: ");
    scanf("%s", create_email);

    if(strchr(create_email, '@')==NULL||strchr(create_email, '.') == NULL)
    {
        printf("Invalid email\n");
        return;
    }

    for(i = 0;i <addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].name, create_name)==0)
        {
            printf("Name already exists\n");
            return;
        }

        if(strcmp(addressBook->contacts[i].phone,create_phonenumber) == 0)
        {
            printf("Phone number already exists\n");
            return;
        }
        if(strcmp(addressBook->contacts[i].email,create_email)==0)
        {
            printf("Email already exists\n");
            return;
        }
    }

    strcpy(addressBook->contacts[addressBook->contactCount].name,create_name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,create_phonenumber);
    strcpy(addressBook->contacts[addressBook->contactCount].email,create_email);
    addressBook->contactCount++;

    printLine();
    printf("Contact successfully added\n");
    printLine();
}

// search contacts

void searchContact(AddressBook *addressBook)
{
    int option;
    int found;
    int i;

    char search_name[30];
    char search_phonenumber[20];
    char search_email[50];

    do
    {
        printLine();
        printf("                    ENTERED INTO SEARCH CONTACT\n");
        printLine();

        printf("Search By:\n");

        printf("1. Name\n");
        printf("2. Phonenumber\n");
        printf("3. Email\n");
        printf("4. Exit\n");

        printLine();

        printf("Enter your choice: ");
        scanf("%d", &option);


        switch(option)
        {
            case 1:
                found = 0;

                printf("Enter the name you want to search: ");
                scanf(" %[^\n]", search_name);

                printLine();

                for(i = 0; i < addressBook->contactCount; i++)
                {
                    if(ignoreCase(addressBook->contacts[i].name,
                                           search_name))
                    {
                        printf("Name       : %s\n",
                               addressBook->contacts[i].name);

                        printf("Phonenumber: %s\n",
                               addressBook->contacts[i].phone);

                        printf("Email      : %s\n",
                               addressBook->contacts[i].email);

                        printLine();

                        found = 1;
                    }
                }


                if(found == 0)
                {
                    printf("Name is not found\n");
                }

                break;


            case 2:

                found = 0;

                printf("Enter the phonenumber: ");
                scanf("%s", search_phonenumber);

                printLine();


                for(i=0;i<addressBook->contactCount;i++)
                {
                    if(strcmp(addressBook->contacts[i].phone,
                              search_phonenumber) == 0)
                    {
                        printf("Name       : %s\n",
                               addressBook->contacts[i].name);

                        printf("Phonenumber: %s\n",
                               addressBook->contacts[i].phone);

                        printf("Email      : %s\n",
                               addressBook->contacts[i].email);

                        printLine();

                        found = 1;

                        break;
                    }
                }

                if(found == 0)
                {
                    printf("Phonenumber is not found\n");
                }

                break;


            case 3:

                found = 0;

                printf("Enter email: ");
                scanf("%s", search_email);

                printLine();

                for(i = 0; i < addressBook->contactCount; i++)
                {
                    if(strcmp(addressBook->contacts[i].email,
                              search_email) == 0)
                    {
                        printf("Name       : %s\n", addressBook->contacts[i].name);
                        printf("Phonenumber: %s\n", addressBook->contacts[i].phone);
                        printf("Email      : %s\n", addressBook->contacts[i].email);
                        printLine();

                        found = 1;

                        break;
                    }
                }


                if(found ==0)
                {
                    printf("Email is not found\n");
                }

                break;


            case 4:

                break;


            default:

                printf("Enter valid option\n");
        }

    }while(option != 4);
}

// edit contacts

void editContact(AddressBook *addressBook)
{
    int choice;
    int ind;
    int i;

    char new_name[30];
    char new_phonenumber[20];
    char new_email[50];

    printLine();
    printf("                    ENTERED INTO EDIT CONTACT\n");
    printLine();

    if (addressBook->contactCount == 0)
    {
        printf("No contacts to edit\n");
        return;
    }

    listContacts(addressBook);

    printf("Choose field to edit:\n");

    printf("1. Name\n");
    printf("2. Phone number\n");
    printf("3. Email\n");
    printf("4. Exit\n");

    printLine();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice== 4)
    {
        return;
    }

    printf("Enter index to edit: ");
    scanf("%d", &ind);

    if(ind< 0||ind >=addressBook->contactCount)
    {
        printf("Invalid index\n");
        return;
    }

    switch(choice)
    {
        case 1:

            printf("Enter new name: ");
            scanf(" %[^\n]", new_name);

            for(i = 0; new_name[i] != '\0'; i++)
            {
                if(isdigit(new_name[i]))
                {
                    printf("Invalid name\n");
                    return;
                }
            }

            strcpy(addressBook->contacts[ind].name,
                   new_name);
            printf("Name updated successfully!\n");
            break;

        case 2:

            printf("Enter new phone number: ");
            scanf("%s", new_phonenumber);

            if(strlen(new_phonenumber) != 11)
            {
                printf("Invalid phone number\n");
                return;
            }
            for(i= 0; i< 10;i++)
            {
                if(!isdigit(new_phonenumber[i]))
                {
                    printf("Invalid phone number\n");
                    return;
                }
            }
            strcpy(addressBook->contacts[ind].phone,
                   new_phonenumber);
            printf("Phone updated successfully!\n");
            break;


        case 3:

            printf("Enter new email: ");
            scanf("%s", new_email);

            if(strchr(new_email, '@') == NULL ||
                strchr(new_email, '.') == NULL)
            {
                printf("Invalid email format\n");
                return;
            }

            strcpy(addressBook->contacts[ind].email,
                   new_email);
            printf("Email updated successfully!\n");
            break;

        default:

            printf("Invalid choice\n");
    }
}

//delete contact
void deleteContact(AddressBook *addressBook)
{
    char ch;
    int del_ind;
    int i;

    printLine();
    printf("                    ENTERED INTO DELETE CONTACT\n");

    printLine();

    if(addressBook->contactCount == 0)
    {
        printf("No contacts to delete\n");
        return;
    }
    printf("Do you want to delete (y/n): ");
    scanf(" %c", &ch);


    if(ch== 'y'||ch =='Y')
    {
        listContacts(addressBook);
        printf("Enter which index to delete: ");
        scanf("%d", &del_ind);

        if(del_ind < 0 ||del_ind >= addressBook->contactCount)
        {
            printf("Invalid index\n");
            return;
        }


        for(i=del_ind;i<addressBook->contactCount - 1; i++)
        {
            addressBook->contacts[i]= addressBook->contacts[i + 1];
        }
        addressBook->contactCount--;
        saveContactsToFile(addressBook);
        printLine();

        printf("Contact deleted successfully\n");
        printLine();
    }
    else
    {
        printf("Deletion cancelled\n");
    }
}




