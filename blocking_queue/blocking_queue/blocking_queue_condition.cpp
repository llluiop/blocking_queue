#include "blocking_queue_condition.h"
#include <iostream>

blocking_queue_condition::blocking_queue_condition()
{

}

blocking_queue_condition::~blocking_queue_condition()
{

}

void blocking_queue_condition::put(int x)
{
	std::unique_lock<std::mutex> lck(m_);

	cv_.wait(lck, [&] {return !q_.full(); });


	q_.put(x);
	std::cout << "thread " << std::this_thread::get_id() << " put " << x << std::endl;

	lck.unlock();
	cv_.notify_one();
}

int blocking_queue_condition::take()
{
	std::unique_lock<std::mutex> lck(m_);

	cv_.wait(lck, [&] {return !q_.empty(); });


	int ret = q_.take();
	std::cout << "thread " << std::this_thread::get_id() << " take " << ret << std::endl;

	lck.unlock();
	cv_.notify_one();

	return ret;
}

bool blocking_queue_condition::empty()
{
	lock_guard<std::mutex> lck(m_);
	return q_.empty();
}

