/* ------------------------------------------------------------------
Name: Ricky Zaman	
Student number: 121942171
Email: rzaman6@myseneca.ca
Section: SMM
Date: Dec.14/17 
---------------------------------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------------------------------
Description: This header file modularizes general helper functions to
help reduce redundant coding for common repetative tasks.
---------------------------------------------------------------------*/


// Hint:  This header file now has functions with parameters referring to 
//        the struct Contact type so be sure to include the contacts.h header:
#include "contacts.h"

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function prototypes here...              |
// +-------------------------------------------------+

// Clear the standard input buffer
// clearKeyboard:
void clearKeyboard(void);

// pause:
void pause(void);

// getInt:
int getInt(void);

// getIntInRange:
int getIntInRange(int, int);

// yes:
int yes(void);

// menu:
int menu(void);

// ContactManagerSystem:
void ContactManagerSystem(void);


// Generic function to get a ten-digit phone number:
// getTenDigitPhone:
void getTenDigitPhone(char[11]);

// findContactIndex:
int findContactIndex(const struct Contact[], int *, const char[]);


// displayContactHeader:
void displayContactHeader(void);

// displayContactFooter:
void displayContactFooter(int);

// displayContact:
void displayContact(const struct Contact*);

// displayContacts:
void displayContacts(const struct Contact[], int);

// searchContacts:
void searchContacts(const struct Contact[], int *);

// addContact:
void addContact(struct Contact[], int *);

// updateContact:
void updateContact(struct Contact[], int *);

// deleteContact:
void deleteContact(struct Contact[], int *);

// sortContacts:
void sortContacts(struct Contact[], int *);