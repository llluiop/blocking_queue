#pragma once

#include <mutex>
#include "queue.h"
using namespace std;

class blocking_queue
{
public:
	blocking_queue();
	~blocking_queue();


public:
	void put(int x);
	int take();

private:
	queue q_;
	mutex m_;
};