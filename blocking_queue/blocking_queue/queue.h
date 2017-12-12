#pragma once
class queue
{
public:
	queue()
	{

	}

	~queue()
	{

	}

public:
	bool full()
	{
		if (count == 2)
			return true;
		
		return false;
	}
	bool empty()
	{
		if (count == 0)
			return true;

		return false;
	}

	void put(int x)
	{
		value[count++] = x;
	}

	int take()
	{
		return value[--count];
	}

private:
	int value[2];
	int count = 0;
};