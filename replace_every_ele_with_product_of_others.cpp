#include <iostream>

using namespace std;

void replace_every_ele_with_product (int array[], int size)
{
	int temp = 1;

	cout << size << endl;

	int *product = new int [sizeof(int) * size];

	int i;
	for (i = 0; i<size; i++)
	{
		product[i] = temp;

		cout << "Rubee " << product[i] << endl;
		temp *= array[i];
	}

	temp = 1;

	for (i = size-1; i>=0; i--)
	{
		product[i] *= temp;
		temp *= array[i];
	}

	for (int i = 0; i<size; i++)
	{
		cout << product[i] << " ";
	}
}
int main()
{
	int array[] = {5, 3, 4, 2, 6, 8};
	int size = sizeof(array)/sizeof(array[0]);

	replace_every_ele_with_product(array, size);

	return 0;
}