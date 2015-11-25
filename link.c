
#include <stdio.h>
#include <stdlib.h>

#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define RESET "\033[0m"

// node declaration
typedef struct node {
	int val;
	struct node* next;
}node;

// head as global
node* head = NULL;

// function prototypes
void printMenu();
void userChoice();
void addItem();
void exitProgram();
int getNum();
void printList();
void search();
void delete();

// main3
int main(int argc, char* argv[])
{
    printf("\n%s\n", "Welcome to linked lists!");

    node* head = NULL;

    while (1) {
    	printMenu();
    	userChoice();
    }
         
	return 1;
}

void printMenu() {
	// print out the menu
	printf("\n");
	printf(KYEL "%s\n", "What would you like to do?");
	printf("%s\n", "1. Add a number to the list");
	printf("%s\n", "2. Print the list");
	printf("%s\n", "3. Search the list");
	printf("%s\n", "4. Delete a node");
	printf("%s\n", "5. exit" RESET);

	return;
}

int getNum() {
	int temp;
  	printf (KBLU "Input your number: " RESET);
  	while (scanf("%d", &temp) != 1) {
    	while (getchar() != '\n');
    	printf ("Try again: ");
  	}
	return temp;
}

void userChoice() {
	int input = getNum();
	printf("\n");
	
	// check input
	switch(input) {

		case 1:
			addItem();
			break;

		case 2:
			printList();
			break;

		case 5:
			exitProgram();
			break;

		case 3:
		 	search();
		 	break;

		case 4:
			delete();
			break;

		default: 
			printf("%s\n", "Try Again");
			
	}
}

void addItem() {
	// Make new node
	node* new = malloc(sizeof(node));
	if (new == NULL) {
		printf("%s\n", "Outta memory!");
		return;
	}
	printf("%s\n", "Enter a number to add to list:");
	new->val = getNum();
	new->next = NULL;

	// Insert new node
	if (head != NULL) {new->next = head;}
	head = new;

	printf("%s\n", "done!");
}

void printList() {
	int nodeCount = 0;
	node* crawler = head;

	// check list is empty
	if (head == NULL){
		printf("%s\n", "The list is empty!");
		return;
	}
	// Print the list
	printf("%s", "Your list looks like this:\n\nHEAD\n->\n");
	while (crawler != NULL) {
		printf("%d\n", crawler->val);
		printf("%s\n", "->");
		nodeCount++;
		crawler = crawler->next;
	} 
	printf("%s\n\n", "NULL");
	printf("%s%d%s\n", "There are ", nodeCount, " active nodes.");
}

void search() {
	// Allows user to searh for a nuber in the list
	// alerts the user to the first match in the list
	printf("What number are you looking for?\n");
	int target = getNum();
	node* crawler = head;
	int nodeCount = 0;

	if (head == NULL) { printf("The list is empty! No number!\n"); }
	else {	
		while (crawler != NULL) {
			nodeCount++;
			if (crawler->val == target) {
				printf("%s%d\n", "Your number was found at node ", nodeCount);
				return;
			}
			else { crawler = crawler->next; }
		}
		printf("Number not found.\n");
		return;
	}
}

void delete() {
	return;
}


void exitProgram () {
	printf("%s\n", "See you later!");
	exit(0);
}
