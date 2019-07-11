#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
	/*
	 * Write your code here.
	 */
	string time = s;

	stringstream stream;

	string front;
	
	stream << time.front();
	stream >> front;

	int h = stoi(front);
		
	stream.clear();
	stream.str(string());

	stream << time[(time.find(time.front()) + 1)];
	stream >> front;

	int hh = stoi(front);

	size_t found = time.find("M");
	
	if (found != string::npos) 
	{
		if (time[found - 1] == 'P')
		{
			h += 1;
			hh += 2;

			if ((h - 1) == 1 && (hh - 2) == 2) 
			{
				h -= 1;
				hh -= 2;
			}

			stream.clear();
			stream.str(string());

			stream << h << hh;
			front = stream.str();

			time.replace(time.begin(), time.begin() + 2, front);

		}
		else if (time[found - 1] == 'A')
		{
			if (h == 1 && hh >= 2)
			{
				h = 0;
				hh -= 2;

				stream.clear();
				stream.str(string());

				stream << h << hh;
				front = stream.str();

				time.replace(time.begin(), time.begin() + 2, front);
			}
		}

	}

	time.pop_back();
	time.pop_back();

	return time;


}


int getTotalX(vector<int> a, vector<int> b) {

	vector<int> factors;
	vector<int> gcd;

	if ((int)a.size() > 1)
	{
		for (int i = *max_element(a.begin(), a.end()); i <= *min_element(b.begin(), b.end()); i++)
		{
			bool isDivideEvenly = true;


			for (int x = 0; x < (int)a.size(); x++) 
			{
				if ((i % a[x] != 0))
				{
					isDivideEvenly = false;
				}
			}

			if (isDivideEvenly)
			{
				factors.push_back(i);
			}
		}
	}
	else
	{
		if (!a.empty())
		{
			factors.push_back(a[0]);
		}
	}
	
	for (int i = *max_element(b.begin(), b.end()); i >= 1; i--)
	{
		for (int x = 0; x < (int)b.size(); x++)
		{
			if ((b[x] % i) == 0) 
			{
				gcd.push_back(i);
			}
		}
	}
			
	/** /
	for (int i = 0; i < (int)factors.size(); i++)
	{
		for (int x = 0; x < (int)gcd.size(); x++)
		{
			cout << "GCD " << gcd[x] << endl;

			if ((gcd[x] % factors[i]) != 0)
			{
				gcd.erase(gcd.begin() + x);
			}
		}
	}
	/**/


	for (int i = 0; i < (int)gcd.size(); i++)
	{
		for (int x = 0; x < (int)factors.size(); x++)
		{
			if ((gcd[i] % factors[x]) == 0) 
			{
				gcd.erase(gcd.begin() + i);
			}
		}
	}


	return gcd.empty() ? 0 : (int)gcd.size();

}

int main()
{

	vector<int> a { 3, 4 };
	vector<int> b { 24, 48 };		

	int result = getTotalX(a, b);

	cout << result << endl;


	/** /
	string s;
	getline(cin, s);

	string result = timeConversion(s);

	cout << result << "\n";
	/**/



	return 0;
}
