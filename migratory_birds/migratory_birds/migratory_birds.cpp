#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct birds 
{
	int key;
	int value;

};


int main()
{

	int n;

	int arr[5]{ 0 };

	//map<int, int> arr;
	
	cin >> n;


	/**/
	for (int i = 0; i < n; i++) 
	{
		/** /


		birds tempBird;

		tempBird.key = temp;
		tempBird.value = 1;

		auto found = find_if(vectArr.begin(), vectArr.end(), [temp](const birds bird) { return bird.key == temp; });

		if (found != vectArr.end())
		{
			found->value++;
		}
		else 
		{
			vectArr.push_back(tempBird);
		}

		//arr[temp]++;
		/**/

		int temp;

		cin >> temp;

		arr[temp - 1]++;

	}
	
	//using type = decltype(arr)::value_type;
	//
	//auto result = max_element(arr.begin(), arr.end(), [](const type p1, const type p2) { return p1.second < p2.second; });
	//
	//cout << result->second;
	/** /
	vector<birds>::iterator result = max_element(vectArr.begin(), vectArr.end(), [](const birds p1, const birds p2) { return p1.value < p2.value; });

	cout << result->key;
	/**/

	int result = 0;
	int index = 0;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) 
	{
		if (result < arr[i]) 
		{
			result = arr[i];
			index = i + 1;
		}
	}

	cout << index;

	return 0;

}
