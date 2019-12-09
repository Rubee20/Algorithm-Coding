#include <iostream>
#include <vector>

using namespace std;

void kadanes_algo(vector <int> vec1, int size)
{
	//cout << "Rubee" << endl;
	for (int i=0; i<size; i++)
	{
		//cout << vec1[i] << " ";
	}

	int max_so_far = 0;
	int max_end_here = 0;
	int start, end;

	for (int i=0; i<size; i++)
	{
		if (max_so_far < max_end_here + vec1[i])
		{
			max_so_far = max_end_here + vec1[i];
			end = i;
		}

		max_end_here = max_end_here + vec1[i];
		
		if (max_end_here < 0)
		{
			max_end_here = 0;
			start = i;
		}
	}

	cout << "max_end_here = " << max_so_far << endl;
	cout << "start = " << start << "end = " << end << endl;
}
int main()
{
	vector <int> vec1 = {-2, 1, -3, 4, -3, 2, 1, -5, 4};
	int size = vec1.size();

	kadanes_algo(vec1, size);
}