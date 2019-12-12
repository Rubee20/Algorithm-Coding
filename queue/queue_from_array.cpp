#include <iostream>

using namespace std;

int front = 0;
int rear = 0;
int array[4];
int size =  4;

void enqueue(int key)
{
	if (rear == size)
	{
		cout << "Queue is full" << endl;
		return;
	}

	array[rear] = key;
	rear++;
	return;
}

void dequeue()
{
	if (front == rear)
	{
		cout << "Queue is empty" << endl;
		return;
	}

	for(int i=0; i<rear; i++)
	{
		array[i] = array[i+1];
	}
	rear = rear-1;
}
void print()
{
	for (int i = front; i < rear; i++)
	{
		cout << array[i] << " ";
	}
}
int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(3);

	dequeue();
	dequeue();



	print();
	return 0;
}