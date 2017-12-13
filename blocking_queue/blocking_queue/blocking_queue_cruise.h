#pragma once

#include <mutex>
#include "queue.h"
using namespace std;

class blocking_queue_cruise
{
public:
	blocking_queue_cruise();
	~blocking_queue_cruise();


public:
	void put(int x);
	int take();

	bool empty();

private:
	queue q_;
	mutex m_;
};