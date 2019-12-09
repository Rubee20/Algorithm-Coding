#include <iostream>
#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

void zerosubsumproblem(int array[], int size)
{
	unordered_map <int, int> set;
	int i, sum=0;

	set.insert(pair<int, int> (0, -1));

	for(i=0; i<size; i++)
	{
		sum +=array[i];
		if(set.find(sum) != set.end())
		{
			//return true;
			auto it = set.find(sum);
			while(it != set.end() && it->first == sum) {
				cout << it->second+1 << ".." << i << endl;
				it++;
			}
		}
		else
			set.insert(pair<int, int>(sum, i));
	}

}

int main()
{
	int array[] = {4, 2, -3, -1, 0, 4};
	int size = sizeof(array)/sizeof(array[0]);

	zerosubsumproblem(array, size);
	//zerosubsumproblem(array, size) ? cout << "True" :
	//								 cout << "False";

	return 0;
}
