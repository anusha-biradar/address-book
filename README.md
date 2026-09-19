# Address Book

A menu-driven contact management program written in C.

## What this project does

The program allows users to manage contact information from the terminal.

Contacts can be added, searched, edited, deleted and displayed. The program also uses file handling to save contact information so it can be loaded again later.

## Features

* Add new contacts
* Search contacts by name, phone number or email
* Edit existing contacts
* Delete contacts
* Display all saved contacts
* Validate contact information
* Save and load contacts using files
* Menu-driven interface

## Concepts Used

* C programming
* Structures
* Arrays
* Pointers
* Functions
* Strings
* File handling
* Input validation
* Modular programming

## Project Structure

```text
address-book/
│
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
└── README.md
```

### File Description

| File        | Purpose                                                                             |
| ----------- | ----------------------------------------------------------------------------------- |
| `main.c`    | Handles the main menu and program flow                                              |
| `contact.c` | Contains functions for adding, searching, editing, deleting and displaying contacts |
| `contact.h` | Contains contact structures and function declarations                               |
| `file.c`    | Handles saving and loading contact information                                      |
| `file.h`    | Contains file-handling declarations                                                 |

## How it works

The program uses a menu-driven approach. The user selects an operation such as adding a contact, searching for a contact or editing an existing contact.

Contact details are stored using structures, while file handling is used to save the information so that it can be accessed again when the program is run.

## How to Compile

Compile the project using:

```bash
gcc main.c contact.c file.c -o addressbook
```

Then run:

```bash
./addressbook
```

## What I Learned

This project helped me strengthen my C programming fundamentals and understand how different concepts such as structures, pointers, functions and file handling can be combined to build a complete application.

It also helped me understand how to organize a C project into multiple source and header files.
