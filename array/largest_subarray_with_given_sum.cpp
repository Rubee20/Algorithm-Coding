#include <iostream>
#include <unordered_map>

using namespace std;

void largest_subarray_with_given_sum(int array[], int size, int S)
{
    cout << "Rubee" << endl;
    /*
    int i, j, max_length = -1;
    for(i=0; i<size; i++)
    {
        int sum = 0;
        for(j=i+1; j<size; j++)
        {
            sum += array[j];
            if (sum == S & max_length < j-i)
            {
                max_length = j-i;
            }
        }
    }

    cout << max_length;
    */

    unordered_map <int, int> map;
    int sum = 0, max_length = 0;

    for(int i=0; i<size; i++)
    {
        sum += array[i];
        
        if (sum == S)
            max_length = i+1;

        if(map.find(sum) == map.end())
        {
            map[sum] = i;
            cout << "Rubee " << sum << "  "<< i << endl;
        }

        if(map.find(sum-S) != map.end() & max_length < i-map[sum-S])
        {
            //cout << "Rubee " << sum << "  "<< i << endl;
            max_length = i-map[sum-S];
        }

        //cout << sum << "  "<< map[sum] << endl;
    }

    cout << max_length;
    
}
int main()
{
    //int array[] = {10, 5, 2, 7, 1, 9};
    //int array[] = {-5, 8, -14, 2, 4, 12};
    int array[] = {5, 6, -5, 5, 3, 5, 3, -2, 0};

    int size = sizeof(array)/sizeof(array[0]);
    int sum = 15;
    largest_subarray_with_given_sum(array, size, sum);
    return 0;
}