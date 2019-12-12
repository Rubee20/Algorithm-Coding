#include <iostream>

using namespace std;

int find_max_difference_bwt_max_min(int array[], int size)
{
	int max_difference = INT_MIN;
	int max_number = array[size-1];

	int i;
	for (i = size-1; i>=0; i--)
	{
		if (max_number < array[i])
		{
			max_number = array[i];

		}

		if (max_difference < max_number - array[i])
		{
			max_difference = max_number - array[i];
		}
	}

	return max_difference;
}
int main()
{
	int array[] = {2, 7, 1, 5, 9, 3, 5};

	int size = sizeof(array)/sizeof(array[0]);

	cout << find_max_difference_bwt_max_min(array, size);
}
