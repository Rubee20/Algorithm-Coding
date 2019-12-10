#include <iostream>

using namespace std;

void max_seq_by_replace_k_0(int array[], int size, int k)
{
	int left = -1;
	int right = 0;

	int count = 0;
	int max_length_of_1 = 0;

	for (right=0; right<size; right++)
	{
		if (array[right] == 0)
			count ++;

		if(count > k)
		{
			while (k < count)
			{
				if (array[left] == 0)
					count = count -1;
				left++;
			}
		}

		if (max_length_of_1 < right - left +1)
			max_length_of_1 = right -left + 1;
	}

	cout << max_length_of_1 << endl;
}
int main()
{
	int array[] = {1, 1, 0, 1, 1, 0, 1, 1, 1};
	int size = sizeof(array)/sizeof(array[0]);
	int k = 1;

	max_seq_by_replace_k_0(array, size, k);
}