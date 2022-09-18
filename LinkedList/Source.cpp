#include <iostream>
#include <chrono>
using namespace std;

//struct Node{
//	int data;
//	Node* next;
//};
struct Node {
	int data; 
	Node* prev;
	Node* next;
};
void printLL(Node* n) {
	while (n != NULL) {
		cout << n->data << endl;
		n = n->next;
	}
}
Node* GetNewNode(int x);
void Insert(int x);
void Print();
void InsertAtN(int value, int pos);
void InsertEnd(int value);
void DeleteN(int pos);
void ReverseIteration();
void PrintRecursion(Node* n);
void ReverseRecursion(Node* n);
void InsertAtHead(int x);
Node* head;
int main(){
	head = NULL;
	Insert(10);
	Insert(22);
	Insert(37);
	Print();
	InsertEnd(3333);
	Print();
	ReverseIteration();
	Print();
	PrintRecursion(head);
	ReverseRecursion(head);
	Print();


	/*cout << "How many numbers?" << endl;
	int n, x;
	cin >> n;
	for (size_t i{}; i < n; i++) {
		cout << "Enter the number: ";
		cin >> x;
		Insert(x);
		Print();
	}*/


	//Node* A{ NULL };
	//Node* temp = (Node*)malloc(sizeof(Node));    //C 
	//Node* second = new Node();   //C++
	//Node* third = new Node();   //C++

	//temp->data = 2;
	//temp->link = second;
	//A = temp;
	//
	//second->data = 23;
	//second->link = third;
	//
	//third->data = 11;
	//third->link = NULL;
	//printLL(A);
	//delete third;
	//delete second;
	//delete A;
}

void Insert(int x) {
	Node* temp = new Node();
	temp->data = x;
	temp->next = head;
	head = temp;
}
void Print() {
	Node* temp = head;
	cout << "List is: ";
	while (temp != NULL) {
		cout << temp->data <<" ";
		temp = temp->next;
	}
	cout << endl;
}
void InsertAtN(int value, int pos) {
	Node* temp1 = new Node();
	temp1->data = value;
	temp1->next = NULL;
	if (pos == 1) {
		temp1->next = head;
		head = temp1;
		return;
	}
	Node* temp2 = head;
	for (size_t i{}; i < pos - 2; i++) {
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}
void InsertEnd(int value) {
	Node* InsertNode = new Node();
	InsertNode->data = value;
	InsertNode->next = NULL;

	Node* EndOfList = head;
	while (EndOfList->next != NULL) {
		EndOfList = EndOfList->next;
	}
	EndOfList->next = InsertNode;
}
void DeleteN(int pos) {
	Node* temp1 = head;
	if (pos == 1) {
		head = temp1->next;
		delete temp1;
	}
	for (int i{}; i < pos - 2; i++) {
		temp1 = temp1->next;  //(n-1)th Node
	}
	Node* temp2 = temp1->next;   //nth Node
	temp1->next = temp2->next;	//(n+1)th node
	delete temp2;
}
void ReverseIteration() {
	Node* current, * next, * prev;
	current = head;
	prev = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}
void PrintRecursion(Node* n) {
	if (n == NULL) 
		return;
	PrintRecursion(n->next);
	cout << n->data << " ";
	
}
void ReverseRecursion(Node* n) {
	if (n->next == NULL) {
		head = n;
		return;
	}
	ReverseRecursion(n->next);
	Node* q = n->next;
	q->next = n;
	n->next = NULL;
}
Node* GetNewNode(int x) {
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
void InsertAtHead(int x){
	Node* newNode = GetNewNode(x);
	if (head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}