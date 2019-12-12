#include <iostream>

using namespace std;

int find_max_difference_bwt_max_min(int array[], int size)
{
	int max_difference = INT_MIN;
	int max_number = array[size-1];

	int i;
	for (i = size-1; i>=0; i--)
	{
		//cout << "Rubee ";
		if (max_number < array[i])
		{
			cout << "Rubee " << endl;
			max_number = array[i];

			//out << "Rubee " << max_number << endl;
		}

		if (max_difference < max_number - array[i])
		{
			cout << "Rubee 1 " << max_difference << endl;
			max_difference = max_number - array[i];
		}
	}

	return max_difference;
}
int main()
{
	int array[] = {2, 7, 1, 5, 9, 3, 5};
	//int array[] = {9, 1 };

	int size = sizeof(array)/sizeof(array[0]);

	cout << find_max_difference_bwt_max_min(array, size);
}