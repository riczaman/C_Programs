/* -------------------------------------------
Name: Ricky Zaman	
Student number: 121942171
Email: rzaman6@myseneca.ca
Section: SMM
Date: Dec.14/17
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"
#include "contacts.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5



//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n')
		; //empty statement intentional 
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
int getInt(void)
{
	int value;
	char NL = 'x';

	while (NL != '\n') {

		//printf("Enter an integer: ");
		scanf("%d%c", &value, &NL);

		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	} return value;
}

// getIntInRange:
int getIntInRange(int a, int b)
{
	int x = getInt();
	while (x<a || x>b) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", a, b);
		x = getInt();
	}
	return x;
}

// yes:
int yes(void)
{
	char a;
	char NL = 'x';



	scanf(" %c%c", &a, &NL);

	while (NL != '\n') {
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");

		scanf(" %c%c", &a, &NL);

	} if (a == 'y' || a == 'Y')
		return 1;
	else
		return 0;
}


// menu:
int menu(void)
{
	int value;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	value = getIntInRange(0, 6);
	printf("\n");
	return value;
}

// ContactManagerSystem:
void ContactManagerSystem(void)
{  //intialized the struct array as per the assignment notes
	 struct Contact contact[MAXCONTACTS]= { { { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
	{
		{ "Maggie", "R.", "Greene" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9051112222", "9052223333", "9053334444" } },
		{
			{ "Morgan", "A.", "Jones" },
			{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
			{ "7051112222", "7052223333", "7053334444" } },
			{
				{ "Sasha",{ '\0' }, "Williams" },
				{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
				{ "9052223333", "9052223333", "9054445555" } },
				
	};
	int x;
	int size=4; 
	int logic = 0;
	do {
		// Print the option list

		x = menu();

		switch (x) {
			int check;
		case 0:	// Exit the program
			printf("Exit the program? (Y)es/(N)o: ");
			check = yes();
			printf("\n");

			if (check == 1) {
				printf("Contact Management System: terminated\n");

				logic = 1;
			}

			break;
		case 1:
			/*printf("\n<<< Feature 1 is unavailable >>>\n\n");
			pause();
			printf("\n");*/
			//Commented out assignment 2 and just called the functions now
			displayContacts(contact, size);
			break;
		case 2:
			/*printf("\n<<< Feature 2 is unavailable >>>\n\n");
			pause();
			printf("\n");*/
			addContact(contact, &size);
			break;
		case 3:
			/*printf("\n<<< Feature 3 is unavailable >>>\n\n");
			pause();
			printf("\n");*/
			updateContact(contact, &size);
			break;
		case 4:
			/*printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();
			printf("\n");*/
			deleteContact(contact, &size);
			break;
		case 5:
			/*printf("\n<<< Feature 5 is unavailable >>>\n\n");
			pause();
			printf("\n");*/
			searchContacts(contact, &size);
			break;
		case 6:
			//printf("\n<<< Feature 6 is unavailable >>>\n\n");
			//pause();
			//printf("\n");
			sortContacts(contact, &size);
			break;

		default:
			printf("\nERROR: Incorrect Option: Try Again\n\n");
			pause();
			printf("\n");
		}
	}

	while (logic == 0);
}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[11])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);

		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex: used to go through the arrays and find a matching cell number and then return the index value
int findContactIndex(const struct Contact contact[], int *size, const char cellNum[])
{
	int i;
	int value;
	int sizze;
	sizze = *size;
	for (i = 0; i < sizze; i++) {
		value=strcmp(contact[i].numbers.cell, cellNum);
		if (value == 0) {
			value = i; 
			return value; 
		}
	}
	return -1;
}


// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");

}

// displayContactFooter
void displayContactFooter(int a)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", a);
}

// displayContact:
void displayContact(const struct Contact *contact)
{
	//getContact(&contact);
	if (contact->name.middleInitial[1]!='\0') {
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	}
	else if(contact->name.middleInitial[1] == '\0'){
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	}
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	if (contact->address.apartmentNumber != 0) {
		printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber, contact->address.street,
			contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
	}
	else if (contact->address.apartmentNumber == 0) {
		printf("       %d %s, %s, %s\n", contact->address.streetNumber, contact->address.street,
			contact->address.city, contact->address.postalCode);
	}
	
}

// displayContacts: iterate through the arrays and display only those that have a valid cellphone number
void displayContacts(const struct Contact contact[], int size)
{
	int i;
	int valid=0;
	displayContactHeader();
	for (i = 0; i < MAXCONTACTS; i++) {
		if (contact[i].numbers.cell[1] != '\0') {
			displayContact(&contact[i]);
			valid = valid + 1; 
		}
	}

	displayContactFooter(valid);
	
	pause();
	printf("\n");
}

// searchContacts:
void searchContacts(const struct Contact contact[], int *size)
{
	int check;
	char tel[11];
	int sizze;
	sizze = *size;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(tel);
	printf("\n");
	check= findContactIndex(contact, &sizze, tel); 
	if (check == -1) {
		printf("*** Contact NOT FOUND ***<\n");
		pause();
	}
	else {
		displayContact(&contact[check]);
		printf("\n");
		pause();
		printf("\n");
	}
		
}

// addContact:
void addContact(struct Contact contact[], int *size)
{
	int i; 
	
	
	/*if (*size>MAXCONTACTS)
		printf("*** ERROR: The contact list is full! ***\n");*/ //This didn't work 
	if (*size != MAXCONTACTS) {
		//printf("%d", *size);
		for (i = 0; i < MAXCONTACTS; i++) {

			//alpha = strlen(contact[i].numbers.cell); //Tried using strlen but it would not add the new 
			//contact to the appropriate spot which was occupied by the null terminator of the deleted array
			//printf("\n%d\n", alpha);
			if ((contact[i].numbers.cell[1] == '\0')) {
				getContact(&contact[i]);
				*size = *size + 1;
				printf("--- New contact added! ---\n");
				pause();
				printf("\n");
			}
		}
	}
	else
	{
		printf("*** ERROR: The contact list is full! ***\n");
		pause();
		printf("\n");
	}
}

// updateContact:
void updateContact(struct Contact contact[], int *size)
{
	char updatecontact[11]; 
	
	int check; 
	int b, c, d; 
	int sizze;
	sizze = *size;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(updatecontact);
	check= findContactIndex(contact, &sizze, updatecontact); 
	if (check == -1) {
		printf("*** Contact NOT FOUND ***\n");
		pause();
		printf("\n");
	}
	else {
		printf("\nContact found:\n");
		displayContact(&contact[check]); 
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		b= yes();
		if (b == 1) {
			getName(&contact[check].name);
		}
		printf("Do you want to update the address? (y or n): ");
		c = yes();
		if (c == 1) {
			getAddress(&contact[check].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		d = yes(); 
		if (d == 1) {
			getNumbers(&contact[check].numbers);
		}
		printf("--- Contact Updated! ---\n");
		pause();
		printf("\n");
	}

}

// deleteContact:
void deleteContact(struct Contact contact[], int *size)
{
	char num[11]; 
	int del; 
	int confirm;
	int sizze;
	sizze = *size;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(num);
	del = findContactIndex(contact, &sizze, num);
	//printf("%d", del); debugging
	//printf("%d", *size);
	if (del == -1) {
		printf("*** Contact NOT FOUND ***\n");
		pause();
	}
	else {
		printf("\n");
		printf("Contact found:\n");
		displayContact(&contact[del]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		confirm=yes();
		
	
		if (confirm == 1) {
			
		
			contact[del].numbers.cell[1] =  '\0' ;
			
		
			*size=*size-1;
			printf("--- Contact deleted! ---");
			printf("\n");
			pause();
			printf("\n");
		}
		else {
			pause();
			printf("\n");
		}
			
			
			
	}


}

// sortContacts: used an embedded loop to sort contacts based on size of the cell number
void sortContacts(struct Contact contact[], int *size)
{
	struct Contact temp[MAXCONTACTS];
	int i,j;
	for (i = 0; i < *size-1; i++) {
		for (j = 0; j < *size - i - 1; j++) {
			if (strcmp(contact[j].numbers.cell, contact[j + 1].numbers.cell) > 0) {
				temp[j] = contact[j];
				contact[j] = contact[j + 1];
				contact[j + 1] = temp[j];
			}
		}
	}
	printf("--- Contacts sorted! ---\n");
	pause();
	printf("\n");
	//printf("<<< Feature to sort is unavailable >>>");
}