#include <iostream>

using namespace std;

struct Node {
	int data;
	bool flag;
	Node* next;
};

Node* newnode(int data)
{
	Node* tmp = (struct Node*) malloc(sizeof(Node));
	tmp->data = data;
	tmp->next = NULL;
	tmp->flag = 0;
	return tmp;
}

bool loop(Node* head)
{
	Node* curr = head;
	Node* prev;
	while(curr != NULL)
	{
		if(curr->flag == 1)
		{
			prev->next = NULL;
			return 1;
		}
		else
		{
			curr->flag = 1;
			prev = curr;
			curr = curr->next;
		}
	}

	return 0;
}
void print(Node* head)
{
	Node* curr = head;
	while(curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
}

int main()
{
	Node* head = newnode(1);
	head->next = newnode(2);
	head->next->next = newnode(3);
	head->next->next->next = newnode(4);
	head->next->next->next->next = head->next;

	bool x = loop(head);
	cout << endl << "Found loop = " << x << endl;

	print (head);
	return 0;
}
