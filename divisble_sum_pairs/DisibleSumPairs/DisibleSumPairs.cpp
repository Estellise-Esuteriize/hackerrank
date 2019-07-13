#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
   
	vector<int> arr;
	
	int n = 0;
	int k = 0;

	int sum = 0;

	int result = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++) 
	{
		int temp = 0;

		cin >> temp;

		arr.push_back(temp);
	}

	for (int i = 0; i < (int)arr.size(); i++)
	{
		sum = arr[i];

		for (int x = (i + 1); x < (int)arr.size(); x++) 
		{
			if ((sum + arr[x]) % k == 0)
			{
				result++;
			}
		}

	}

	cout << result;

	return 0;
}

