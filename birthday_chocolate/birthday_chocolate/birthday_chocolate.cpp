#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 
using namespace std;

int shareChocolateBar(vector<int>, int, int);


int main()
{
	string stream;

	int n = 0;
	vector<int> s;
	int d = 0;
	int m = 0;

	cin >> stream;

	stream.erase(remove_if(stream.begin(), stream.end(), [](char c) {return !isdigit(c); }), stream.end());

	n = stoi(stream);

	for (int i = 0; i < n + 2; i++){
		
		stream.clear();

		cin >> stream;

		stream.erase(remove_if(stream.begin(), stream.end(), [](char c) {return !isdigit(c); }));


		if (i < n)
		{
			s.push_back(stoi(stream));
		}
		else
		{
			if (i <= n)
			{
				d = stoi(stream);
			}
			else
			{
				m = stoi(stream);
			}
		}

	}	

	int result = shareChocolateBar(s, d, m);

	cout << "Result " << result;
	
}


int shareChocolateBar(vector<int> s, int d, int m)
{
	
	int result = 0;

	int sum = 0;

	int max = (int)s.size();


	for (int i = 0; i < max; i++) 
	{	
	
		sum = s[i];

		for (int x = 1; x < m; x++) 
		{
			if ((i + x) < max) 
			{
				sum += s[i + x];
			}
		}

		if (sum == d) 
		{
			result++;
		}
			
		sum = 0;
		
	}



	return result;
}
