#include <iostream>
using namespace std;

// Enter your code for reversed_binary_value<bool...>()
int binary(int);
template <typename... args>
int binary(int, bool, args...);

//
//template <bool... args>
//void func_binary();


template <bool... args>
int reversed_binary_value()
{
	int result = binary(0, 0, args...);

	return result;
}


int binary(int mult)
{
	return 0;
}

template <typename... args>
int binary(int mult, bool n, args... arg)
{
	int multi = mult * 2;

	if (multi <= 0)
	{
		multi = 1;
	}

	int result = 0;

	result = binary(multi, arg...);

	return mult * n + result;

}

	
template <int n, bool...digits>
struct CheckValues {
	static void check(int x, int y)
	{
		CheckValues<n - 1, 0, digits...>::check(x, y);
		CheckValues<n - 1, 1, digits...>::check(x, y);

	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
	
	static void check(int x, int y)
	{
		int z = reversed_binary_value<digits...>();
		std::cout << (z + 64 * y == x);
		return;
	}
};






int main()
{

	//int result = reversed_binary_value<0, 0, 0, 1>();

	//std::cout << result << std::endl;

	int t = 0;

	std::cin >> t;
	
	for (int i = 0; i != t; ++i) {
		int x, y;
		cin >> x >> y;
		CheckValues<6>::check(x, y);
		cout << "\n";
	}
}


/** /

template <bool... args>
void func_binary()
{
	int result = binary(0, 0, args...);

	std::cout << "Result " << result ;
}


void recursive_loop(int n)
{
	if (n == 0)
	{
		return;
	}

	std::cout << "REC " << n << std::endl;

	recursive_loop(n - 1);

	std::cout << "UN REC " << n << std::endl;
}

int recursive_return(int n)
{
	int i = 0;

	if (n != 0)
	{
		i = recursive_return(n - 1);
	}

	//std::cout << i << std::endl;
	return (n % 2 != 0) ? n * 2 + i : 0 + i;
}


/**/