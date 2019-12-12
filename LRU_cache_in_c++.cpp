#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

list <int> q;
unordered_map<int, list<int> :: iterator> map;
int size =3;

void lru(int k)
{
	if (map.find(k) == map.end())
	{
		if (q.size() == size)
		{
			int last = q.back();
			q.pop_back();

			map.erase(last);
		}
	} else 
		q.erase(map[k]);

	q.push_front(k);
	map[k] = q.begin();

	return;
}

void print_queue()
{
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop_front();
	}
}
int main()
{
	lru(1);
	lru(2);
	lru(3);
	lru(2);
	lru(4);
	lru(5);

	print_queue();
	return 0;
}
