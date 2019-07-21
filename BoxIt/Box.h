#pragma once

#include <iostream>
#include <string>


namespace box 
{
	
	using namespace std;

	class Box
	{
		int l;
		int b;
		int h;


		public:
			Box();
			Box(int, int, int);
			Box(const Box&);
			int getLength();
			int getBreadth();
			int getHeight();
			long long CalculateVolume();
			bool operator < (const Box&);
			friend ostream& operator << (ostream& os, const Box& box) 
			{
				os << box.l << " " << box.b << " " << box.h;
				return os;
			};
	};


}

