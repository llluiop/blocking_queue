#pragma once

#include <mutex>
#include <condition_variable>
#include "queue.h"
using namespace std;

class blocking_queue_condition
{
public:
	blocking_queue_condition();
	~blocking_queue_condition();


public:
	void put(int x);
	int take();

	bool empty();

private:
	queue q_;
	mutex m_;
	condition_variable cv_;
};
