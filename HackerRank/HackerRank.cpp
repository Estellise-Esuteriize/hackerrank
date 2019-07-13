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

int getGcd(int a, int b)
{

	int temp = 0;

	while (b > 0) 
	{
		temp = b;

		b = a % b;

		a = temp;
	
	}

	return a;


}

int getLcm(int a, int b)
{
	return (a * b) / getGcd(a, b);
}


int getTotalX(vector<int> a, vector<int> b) {

	int count = 0;


	int lcm = a[0];
	int gcd = b[0];

	for (int i = 1; i < (int)a.size(); i++)
	{
		lcm = getLcm(lcm, a[i]);
	}

	for (int i = 0; i < (int)b.size(); i++) 
	{
		gcd = getGcd(gcd, b[i]);
	}

	for (int i = lcm; i <= gcd; i+=lcm) 
	{
		if ((gcd % i) == 0) 
		{
			count++;
		}
	}

	return count;

}

vector<int> breakingRecords(vector<int> scores) {

	int min = scores[0];
	int max = scores[0];

	vector<int> beats{ 0, 0 };

	for (int i = 0; i < (int)scores.size(); i++) 
	{
		if (scores[i] < min)
		{
			min = scores[i];
			beats[1]++;
		}
		else if (scores[i] > max) 
		{
			max = scores[i];
			beats[0]++;
		}

	}

	return beats;


}



int main()
{

	vector<int> a { 1 };
	vector<int> b { 72, 48 };		

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
