#include "Box.h"

using namespace box;


Box::Box()
{
	l = b = h = 0;
}

Box::Box(int l, int b, int h) 
{
	this->l = l;
	this->b = b;
	this->h = h;
}

Box::Box(const Box& box) 
{
	l = box.l;
	b = box.b;
	h = box.h;
}

int Box::getLength() 
{
	return l;
}

int Box::getBreadth() 
{
	return b;
}

int Box::getHeight() 
{
	return h;
}

long long Box::CalculateVolume() 
{
	return (long long)l * b * h;
}

bool Box::operator<(const Box& box) 
{
	if (l < box.l)
	{
		return true;
	}
	else if (b < box.b && l == box.l) 
	{
		return true;
	}
	else if (h < box.h && b == box.b && l == box.l) 
	{
		return true;
	}

	return false;
}





