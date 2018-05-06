/*
Name: Ricky Zaman
Student number: 121942171
Email: rzaman6@myseneca.ca
Workshop: Workshop 5
Section:SMM
Date: October 13, 2017
*/

// Copy your source code from in_lab file to here
// Expand the option list to include option 3 & 4 after 
// option 2. as following
// "3. Update Employee Salary"
// "4. Remove Employee"

// Create two switch-cases for option 3 & 4 after case 2. 
// Implement "Update Salary" and "Remove Employee" 
// functionality as per instructions
// inside the relevant case statements

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* Define Number of Employees "SIZE" to be 4 this basically makes SIZE a constant
and if I need to change it I can do it here and it will apply it throughout the program*/

#define SIZE 4

// Declare Struct Employee 

struct Employee {
	int id;
	int age;
	double salary;
};


/* main program */
int main(void) {

	int option = 0;
	int numberofEmployees = 0;
	int checkID;
	int logic;
	int removeID;
	int logic2;
	printf("---=== EMPLOYEE DATA ===---\n\n");

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero
	//Had to use double brackets because of matrix
	struct Employee emp[SIZE] = { { 0 } };

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;
		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 

			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0 this is accounted for in the if statement
			int i;
			for (i = 0; i < numberofEmployees; i++) {
				if (emp[i].id > 0) {
					printf("%6d%9d%11.2lf", emp[i].id, emp[i].age, emp[i].salary);
					printf("\n");
				}
			}
			printf("\n");
			break;
		case 2:	// Adding Employee
				// @IN-LAB

			printf("Adding Employee\n");
			printf("===============\n");

			// Check for limits on the array and add employee 
			// data accordingly. 
			/*Used an if statement because we are in a do while loop so it will run
			as long as the while criteria is not met when case 2 is called until the
			struct array reaches a maximum which is defined by numberofemployees being
			less than size*/

			if (numberofEmployees < SIZE) {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[numberofEmployees].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[numberofEmployees].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[numberofEmployees].salary);
				printf("\n");


				numberofEmployees = numberofEmployees + 1;
			}
			else
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");

			break;
		case 3: 
		//created a new variable called checkID which will be used to compare to element in the struct array
			logic = 0;
			printf("Update Employee Salary\n");
			printf("======================\n");
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &checkID);
				/*if the if condition is met then we can enter a new salary also use logic so we can break out of the while 
				when we find the id that we want to change salary of*/
				int i; 
				for (i = 0; i <numberofEmployees; i++) {
					if (checkID == emp[i].id) {
						printf("The current salary is %.2lf\n", emp[i].salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &emp[i].salary);
						printf("\n");
						logic = 1;
					}

				}
			} while (logic == 0);

			break;
		case 4:
			logic2 = 0;
			printf("Remove Employee\n");
			printf("===============\n");
			//use the same do while loop from before but now use another variable j to do the actual removal 
			/*You can't actually remove the elements but what is done is we shift all the values after the value
			selected up by one to essentially replace it and then we decrease the employees by one to 
			open up a spot for another employee in the struct array*/
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &removeID);
				int i;
				for (i = 0; i <numberofEmployees; i++) {
					if (removeID == emp[i].id) {
						printf("Employee %d will be removed\n", emp[i].id);
						printf("\n");
						int j;
						for (j = i; j < numberofEmployees; j++) {
							emp[j].id = emp[j + 1].id;
							emp[j].age = emp[j + 1].age;
							emp[j].salary = emp[j + 1].salary;
						}

		
						numberofEmployees--;
						logic2 = 1;
					}

				}
			} while (logic2 == 0);

			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}
	}

	while (option != 0);


	return 0;
}








// PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 113
Enter Employee Age: 53
Enter Employee Salary: 120345.78

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 114
Enter Employee Age: 25
Enter Employee Salary: 46780

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
112       41   65000.00
113       53  120345.78
114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 112
The current salary is 65000.00
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
112       41   99999.99
113       53  120345.78
114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 112
Employee 112 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
113       53  120345.78
114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!
*/