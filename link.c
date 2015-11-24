
#include <stdio.h>
#include <stdlib.h>

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
int getSingleNum();
void printList();
void search();

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
	printf("%s\n", "What would you like to do?");
	printf("%s\n", "1. Add a number to the list");
	printf("%s\n", "2. Print the list");
	printf("%s\n", "3. Search the list");
	printf("%s\n", "5. exit");

	return;
}

int getSingleNum() {
	// flush stdin
	int c;
	while((c = getchar()) != '\n' && c != EOF);
	// get the num
	int tmp = getchar();
	tmp -= '0';
	// flush stdin again
	while((c = getchar()) != '\n' && c != EOF);
	// check input
	if (tmp < 0 || tmp > 9) {
		printf("\n%s\n", "Please enter a number");
		return getSingleNum();
	}
	return tmp;
}

void userChoice() {
	int input = getSingleNum();
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
	scanf("%d", new->val);
	new->next = NULL;

	// Insert new node
	if (head != NULL) {new->next = head;}
	head = new;

	printf("\n%s\n", "done!");
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
	return;
}

void exitProgram () {
	printf("%s\n", "See you later!");
	exit(0);
}
