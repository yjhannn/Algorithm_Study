#include <iostream>
#include <set>
using namespace std;

int main()
{
	int N, ret = 0;
	cin >> N;
	set<string> m;
	string str;

	while (N--)
	{
		cin >> str;

		if (str == "ENTER")
		{
			ret += m.size();
			m.clear();
			continue;
		}
		
		m.insert(str);
	}

	ret += m.size();
	cout << ret;
}