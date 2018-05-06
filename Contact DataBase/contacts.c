/* -------------------------------------------
Name: Ricky Zaman
Student number: 121942171
Email: rzaman6@myseneca.ca
Section: SMM
Date: Dec. 14/17
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name *name)
{
	int a;
	// Contact Name Input:

	printf("Please enter the contact's first name: ");
	scanf("%[^\n]", name->firstName);

	//store the answer of y or n in a variable known as a
	printf("Do you want to enter a middle initial(s)? (y or n): ");

	/*have to include a space after " because then scanf will ignore the first space in the previous
	printf statement and then look for its character*/
	//scanf(" %c", &a); no need for this because yes() will store what I need
	a = yes();
	//if this condition is true then we will ask for the contacts middle name and then store it
	/*also we must use the %s format specifier because we are dealing with strings not a single character
	the if condition includes || just incase the user inputs y or Y also use single quotes because its just
	one character*/
	//This will check the value of the yes() and proceed accordingly 
	if (a == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %s", name->middleInitial);
	
	}

	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]", name->lastName);

}

// getAddress:
void getAddress(struct Address *address)
{
	int a;
	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	//scanf("%d", &address->streetNumber); no need because it will be stored in getInt()

	printf("Please enter the contact's street name: ");
	scanf("%[^\n]", address->street);


	printf("Do you want to enter an apartment number? (y or n): ");
	a = yes();
	//scanf(" %c", &a); no need because yes() will store
	if (a == 1) {
		printf("Please enter the contact's apartment number: ");

		scanf("%d", &address->apartmentNumber);
	}
	else {
		address->apartmentNumber = 0;
	}
	/*Had to use %8[^\n] because there is a space inbetween the postal code if I did not do this
	then only the first half of the postal code before the space would be stored*/
	printf("Please enter the contact's postal code: ");
	scanf(" %8[^\n]", address->postalCode);
	//printf("%s", address->postalCode); used for debugging to check if it was being saved properly 

	printf("Please enter the contact's city: ");
	scanf(" %[^\n]", address->city);

}

// getNumbers:
void getNumbers(struct Numbers *numbers)
{
	int a;
	/*printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &a);
	if (a == 'y' || a == 'Y') {*/
	//Commented out because it is cell phone number is mandatory now
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);
	
	//scanf("%s", numbers->cell);


	printf("Do you want to enter a home phone number? (y or n): ");
	a = yes();
	//scanf(" %c", &a); no need because yes() will store it now 

	if (a == 1) {
		
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
		//scanf("%s", numbers->home);
	}else {
		*numbers->home = '\0';
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	a = yes();
	//scanf(" %c", &a); no need because yes() will store it now
	if (a == 1) {
		
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
		//scanf("%s", numbers->business);
	}
	else {
		*numbers->business = '\0';
	}
}
// getContact:
void getContact(struct Contact *contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}

