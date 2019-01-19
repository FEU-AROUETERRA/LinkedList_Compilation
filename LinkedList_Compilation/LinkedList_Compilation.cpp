/*
[Group 2] LAB2V2
August Bryan N. Florese
Ian Pacelo
Rowell Ferrer
Bryan Alvarico

GITHUB Repository: https://github.com/FEU-AROUETERRA/LinkedList_Compilation/blob/master/LinkedList_Compilation/LinkedList_Compilation.cpp
*/


#include <iostream>
#include <string>
#include <stdlib.h>
#include "conio.h"

using namespace std;

struct Node {
	char data;
	Node *next;
	Node *previous;
};

//GLOBAL
Node *head = NULL;
Node *tail = NULL;
Node *node = NULL;
int List_Size = 0;
//Pre-definition
void Explode(string Line);
string Initialize();

void Add_Node(char letter, bool type) {
	if (type == true) { //Add to End
		node = new Node;
		node->next = NULL;
		node->previous = NULL;
		node->data = letter;
		if (head == NULL) {
			head = tail = node;
			List_Size++;
		}
		else if (node->previous == NULL && List_Size == 1) {
			node->previous = head;
			tail->next = node;
			tail = node;
			List_Size++; //Not sure if there's a better way to initialize the first previous node.
		}
		else {
			tail->next = node;
			node->previous = tail;
			tail = node;
			List_Size++;
		}
	}
}

#pragma region INITIALIZE
void Creation() {
	string Line;
	Line = Initialize();
	//Creates the nodes 
	Explode(Line);
}
string Initialize() {
	string Line = "";
	cout << "We will now create your linked list. \n";
	cout << "Now, enter characters delimited by spaces: "; cin.ignore(1000, '\n');
	getline(cin, Line);

	//cout << Line;
	return Line;
} //For c++11 use make_pair with pair<1,2>
void Explode(string Line) {
	int temp = Line.length();
	for (int i = 0; i <= Line.size() - 1; i++) {
		if (isspace(Line[i]) && temp <= 0 || temp <= 0) {
			//Do nothing!
		}
		else if (!isspace(Line[i])) {
			Add_Node(Line[i], true);
			temp--;
		}
	}

}
#pragma endregion

#pragma region DISPLAY-REGION
void Proper_Display() {
	node = head;
	cout << "{ ";
	while (node != NULL) {
		if (node == tail) {
			cout << node->data;
			node = node->next;
		}
		else {
			cout << node->data << ", ";
			node = node->next;
		}
	} cout << " } ";
	system("pause");
}
void Reverse_Display() {
	node = tail;
	cout << "{ ";
	while (node != NULL) {
		if (node == head) {
			cout << node->data;
			node = node->previous;
		}
		else {
			cout << node->data << ", ";
			node = node->previous;
		}
	} cout << " } ";
	system("pause");
}
void Display() {
	int choice;
	do {
		system("cls");
		cout << "[1] Display" << endl;
		cout << "[2] Reverse_Display" << endl;
		cout << "[0] Exit" << endl;
		cout << "Choice: ";
		cin >> choice;
		switch (choice) {
		case 1:Proper_Display();break;
		case 2:Reverse_Display();break;
		case 0: break;
		}

	} while (choice != 0);
}

#pragma endregion

#pragma region INSERT-REGION
void Insert_Beg() {
	char insert; //END
	cout << "Type the character to insert: ";
	cin.ignore(1000, '\n');
	cin >> insert;

	node = new Node;
	node->next = head;
	node->previous = NULL;
	node->data = insert;
	if (head == NULL) {
		head = tail = node;
		List_Size++;
	}
	else if (node->previous == NULL && List_Size == 1) {
		node->next = head;
		node->previous = NULL;
		head->previous = node;
		head = node;
		List_Size++;
	}
	else {
		node->next = head;
		node->previous = NULL;
		head->previous = node;
		head = node;
	}
}
void Insert_End() {
	char insert; //END
	cout << "Type the character to insert: ";
	cin.ignore(1000, '\n');
	cin >> insert;

	node = new Node;
	node->next = NULL;
	node->previous = tail;
	node->data = insert;
	if (head == NULL) {
		head = tail = node;
		List_Size++;
	}
	else if (node->previous == NULL && List_Size == 1) {
		node->previous = head;
		tail->next = node;
		tail = node;
		List_Size++;
	}
	else {
		tail->next = node;
		node->previous = tail;
		tail = node;
	}
}
void Insert_Specific(char data, int n)
{
	node = new Node();
	node->data = data;
	node->next = NULL;
	node->previous = NULL;
	if (n == List_Size) {
		tail->next = node;
		node->previous = tail;
		tail = node;
	}
	if (n > List_Size-1) {
		cout << "Out of bounds!" << endl;
		return;
	}
	if (n <= 1) {
		node->next = head;
		head = node;
		return;   
	}

	Node* node2 = head;
	Node* node3;
	for (int i = 0; i <= n - 2; i++) {
		node2 = node2->next;
	}

	node3 = node2->next;
	node3->previous = node;
	node->next = node2->next;
	node->previous = node2;
	node2->next = node;

}
void Insertion() {
	int choice;
	do {
		system("cls");
		cout << "[1] Insert@Beginning" << endl;
		cout << "[2] Insert@End" << endl;
		cout << "[3] Insert@Specific Position" << endl;
		cout << "[0] Exit" << endl;
		cout << "Choice: ";
		cin >> choice;
		char data; int n;
		switch (choice) {
		case 1:Insert_Beg();break;
		case 2:Insert_End();break;
		case 3:
			cout << "\n Enter element: ";
			cin >> data;
			cout << "\n Enter position: ";
			cin >> n;
			Insert_Specific(data, n);
		case 0: break;
		}
	} while (choice != 0);
}

#pragma endregion

#pragma region DELETION-REGION
void RemoveBEG(int choice)
{
	Node *ptr, *prev;
	ptr = NULL; prev = NULL;

	if (head == NULL)
	{
		cout << "\nList is empty \n";
	}
	else if (head == tail)
	{
		delete head;
	}
	else
	{
		node = head;
		head = head->next;
		head->previous = NULL;
		delete node;
	}

}
void RemoveEND(int choice)
{
	Node *ptr, *prev;
	ptr = NULL; prev = NULL;

	if (head == NULL)
	{
		cout << "\nList is empty \n";
	}
	else if (head == tail)
	{
		delete head;
	}
	else
	{
		node = tail;
		tail = node->previous;
		tail->next = NULL;
		delete node;
	}
}
void RemoveSpecific(int n)
{
	node = head;
	if (n == 0) {
		head = node->next; //head points to second node
		head->previous = NULL;
		delete node;
		return;
	}
	else if (n == List_Size || n > List_Size - 2 || n == List_Size-1) {
		node = tail;
		tail = node->previous;
		tail->next = NULL;
		delete node;
		return;
	}
	

	for (int i = 0; i <= n - 2; i++) {
		node = node->next; //temp1 points to (n-1)th node
	}
	//     1234@
		// -----
	Node* deletetarget = node->next;
	Node *keeptarget = deletetarget->next; //nth node
	keeptarget->previous = deletetarget->previous;
	node->next = keeptarget;
	//node->previous = deletetarget->previous;
	
	

	//Node *node2 = node->next; //nth node
	//node->next = node2->next; //(n+1)th Node
	//node->previous = node2;
	//node2->previous = node;
	delete deletetarget;

}
void Deletion() {
	int choice;
	do {
		system("cls");
		cout << "[1] Remove a character? @BEGINNING" << endl;
		cout << "[2] Remove a character? @END" << endl;
		cout << "[3] Remove a character? @Specific Position" << endl;
		cout << "[0] Exit" << endl;
		cout << "Choice: ";
		cin >> choice;
		int n;
		switch (choice) {
		case 1:RemoveBEG(choice);break;
		case 2:RemoveEND(choice);break;
		case 3:
			cout << "\n Enter position: ";
			cin >> n;
			RemoveSpecific(n);break;
		case 0: break;
		}

	} while (choice != 0);
}
#pragma endregion

#pragma region SEARCH-REGION
void Search() {
	char a;
	int numofsearch;
	int position;
	int searchposition[100];

	//SEARCH INITIALIZATION
	numofsearch = 0;
	position = 1;
	cout << "\nSearch for element: ";
	cin.ignore(1000, '\n');
	cin >> a;
	//ELEMENT POSITION DETECTOR
	node = head;
	while (node != NULL)
	{
		if (a == node->data)
		{
			searchposition[numofsearch] = position;
			numofsearch++;
		}
		node = node->next;
		position++;
	}

	//SEARCH RESULTS
	if (numofsearch != 0)
	{
		cout << "\n\nElement " << a << " is at position ";
		if (numofsearch == 1)
		{
			cout << searchposition[0] << ".";
		}
		else
		{
			for (int i = 0; i < numofsearch - 1; i++)
			{
				cout << searchposition[i] << ", ";
			}
			cout << "and " << searchposition[numofsearch - 1] << ".";
		}
	}
	else
	{
		cout << "\n\nThere is no element " << a << " on the list!";
	}
	system("pause>0");
}
#pragma endregion

void Menu() {
	int choice;
	do {
		system("cls");
		cout << "[1] Creation" << endl; //Done
		cout << "[2] Insertion" << endl;
		cout << "[3] Deletion" << endl; //Done?
		cout << "[4] Search" << endl; //Done
		cout << "[5] Display" << endl; //Done
		cout << "[0] Exit" << endl;
		cout << "\nCurrent Size: " << List_Size << endl;
		cout << "Choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			Creation();break;
		case 2:
			Insertion();break;
		case 3:
			Deletion();break;
		case 4:
			Search();break;
		case 5:
			Display();break;
		}
	} while (choice != 0);
	exit(1);
}

int main()
{
	while (true) {
		//Looping menu items
		Menu();
	}
	return 0;
}