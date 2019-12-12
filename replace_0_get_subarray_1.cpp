#include <iostream>

using namespace std;

/*
int find_index_of_0(int array[], int size)
{
	int max_count = 0;
	int index;
	int prev_0 = -1;
	int prev_prev_0 = -1;

	for (int i=0; i<size; i++)
	{
		if (array[i] == 0)
		{
			if (i - prev_prev_0 > max_count)
			{
				index = prev_0;
				max_count = i - prev_prev_0;
			}

			prev_prev_0 = prev_0;
			prev_0 = i;
		}

	}

	return index;

} */

int find_index_of_0(int array[], int size)
{
	int left = -1;
	int right = -1;
    int old_index = -1, new_index = -1;
    int max_length = -1;

	for (int i=0; i<size; i++)
	{
		if (array[i] == 0)
		{ 
			//cout << left << " " << right << " " << max_length << endl;
			if (max_length < left + right + 1)
			{
				old_index = new_index;
				max_length = left + right +1;
			}

			left = right;
			right = 0;
			new_index = i;
		}
		else 
		{
			right++;
		}
	}

	if (max_length < left + right + 1)
	{
		old_index = new_index;
		max_length = left + right +1;
	}

	return old_index;
}
int main()
{
	//int array[] = {0, 0, 1, 0, 1, 1, 0, 0 , 1, 1,};
	int array[] = {0, 0, 0, 1, 0};
	int size = sizeof(array)/sizeof(array[0]);

	int index = find_index_of_0(array, size);

	cout << index;
}