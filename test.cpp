#include<iostream>
using namespace std;
struct Node {
	int d;
	struct Node* next;
	struct Node* prev;
};
struct Node* head;
struct Node* tail;
int k = 3;
void insertToLinkedList(int d)
{
	struct Node* n = new Node();
	n->d = d;
	if (head == NULL)
	{
		head = n;
		tail = n;
		head->next = NULL;
		head->prev = NULL;
	}
	else
	{
		tail->next = n;
		n->prev = tail;
		tail = n;
		tail->next = NULL;
	}

}


void printing()
{
	struct Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->d << " ";
		temp = temp->next;

	}
	cout << endl;

	temp = tail;

}

void makeskiplist()
{
	struct Node* temp = tail;
	int i = 0;
	struct Node* temp2;
	struct Node* temp3;
    int j=0;
    while(j<6/k){
        temp3=temp;
	for (int i = 0; i < k; i++)
	{
	    if(temp->prev!=NULL){
		temp2 = temp->prev;
		temp->prev = NULL;
		free(temp->prev);
		temp = temp2;
	    }
	}
	j++;
	temp3->prev = temp2;
    }

}
void deleteElement(int d)
{
	struct Node* temp = head, * temp5 = head;
	while (temp != NULL && temp->d != d) { temp = temp->next; }
	if (temp == head)
	{
		temp = temp->next;
		while (temp->prev == NULL) { temp = temp->next; }

		temp->prev = head->next;
		head = head->next;
		temp5->next = NULL;
		free(temp5);
	}
	else if (temp == tail)
	{
		struct Node* temp2 = temp->prev; struct Node* temp3 = temp->prev;
		while (temp2->next != temp) { temp2 = temp2->next; }
		tail = temp2;
		tail->next = NULL;
		tail->prev = temp3;
		free(temp);
	}

	else if (temp->prev == NULL)
	{
		struct Node* temp2 = temp;
		while (temp2->prev == NULL) { temp2 = temp2->next; }
		temp2 = temp2->prev;
		while (temp2->next != temp) { temp2 = temp2->next; }
		temp2->next = temp->next;
		free(temp);

	}

	else if (temp->next != NULL && temp->prev != NULL)
	{
		temp->next->prev = temp->prev;
		struct Node* temp3 = temp->prev;
		while (temp3->next != temp) { temp3 = temp3->next; }
		temp3->next = temp->next;
		struct Node* temp2 = temp->next->next;
		while (temp2->prev == NULL)
		{
			temp2 = temp2->next;
		}
		temp2->prev = temp->next;
		free(temp);
	}
	else
	{
		cout << "ELEMENT NOT FOUND" << endl;
	}
}

void insertBeginning(int d)
{
	struct Node* n = new Node();
	n->d = d;
	struct Node* temp = head->next;
	int i = 0;
	while (temp->prev == NULL) { i++; temp = temp->next; }
	if (i == k - 1)
	{
		n->next = head;
		head->prev = n;
		head = n;
		head->prev = NULL;
		free(head->prev);
	}
	else
	{
		n->next = head;
		struct Node* temp2 = head->next;
		while (temp2->prev == NULL) { temp2 = temp2->next; }
		temp2->prev = n;
		head = n;
		head->prev = NULL;
		free(head->prev);
	}

}
void backward()
{
	struct Node* temp = tail;
	while (temp != NULL)
	{
		cout << temp->d << " "; temp = temp->prev;
	}
	cout << endl;
}
void addEnd(int d)
{

	struct Node* temp = tail->prev; int i = 0;
	struct Node* n = new Node();
	n->d = d;

	while (temp->next != NULL)
	{
		i++; temp = temp->next;
	}

	if (i == k)
	{
		tail->next = n;
		tail = n;
		tail->next = NULL;
		tail->prev = temp;

	}
	else
	{
		tail->next = n;
		struct Node* temp2 = tail->prev; tail->prev = NULL;
		n->prev = temp2;
		free(tail->prev);
		tail = n;


	}

}
void additionwhichmakesperfects(int d) {
	
	struct Node* temp = head;
	int i = 0;
	struct Node* temp2;
	while (temp!=NULL) {
		if (temp->prev != NULL)
		{
			if (i == k)
			{
				i = 0;
			}
			else
			{
				temp2 = temp;
				break;
			}
		}
		i++;
		temp = temp->next;

	}
	if (temp == NULL) {
		addEnd(d);
	}
	else {
		struct Node* n = new Node();
		n->d = d;
		struct Node* temp3;
		temp2 = temp2->prev;
		temp3 = temp2->next;
		temp2->next = n;
		n->next = temp3;

	}
}
int main()
{
    int n;
    for(int i=0; i<k; i++){
        cin >> n;
        insertToLinkedList(n);
    }
	makeskiplist();
	for(int i=k; i<10000; i++){
	    cin >> n;
	    addEnd(n);
	}
}
