#include <stdio.h>
#include "file.h"

// saving contacts

void saveContactsToFile(AddressBook *addressBook)
{
    int i;
    FILE *fptr =fopen("contacts.txt", "w");

    if(fptr == NULL)
    {
        perror("Error");
        return;
    }

    fprintf(fptr, "%d\n", addressBook->contactCount);

    for(i=0;i <addressBook->contactCount;i++)
    {
        fprintf(fptr, "%s,%s,%s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    fclose(fptr);
    printf("Contacts saved successfully\n");
}

// to load contacts from the file
void loadContFile(AddressBook *addressBook)
{
    int i;

    FILE *fptr = fopen("contacts.txt", "r");

    if(fptr == NULL)
    {
        addressBook->contactCount = 0;
        return;
    }

    if(fscanf(fptr, "%d\n", &addressBook->contactCount) != 1)
    {
        addressBook->contactCount = 0;
        fclose(fptr);
        return;
    }

    if(addressBook->contactCount> MAX_CONTACTS)
    {
        addressBook->contactCount = MAX_CONTACTS;
    }

    for(i =0;i <addressBook->contactCount;i++)
    {
        if(fscanf(fptr, "%[^,],%[^,],%[^\n]\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email) != 3)
        {
            addressBook->contactCount = i;
            break;
        }
    }
    fclose(fptr);
    if(addressBook->contactCount > 0)
    {
        printf("%d contacts loaded\n",
        addressBook->contactCount);
    }
}

