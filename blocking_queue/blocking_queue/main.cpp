#include "blocking_queue_cruise.h"
#include "blocking_queue_condition.h"
#include <thread>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	//blocking_queue_cruise queue;
	blocking_queue_condition queue;
	std::vector<std::thread> put_threads_;
	std::vector<std::thread> take_threads_;


	for (int i = 0; i < 10; i++)
	{
		put_threads_.push_back(std::thread([i, &queue] {
			queue.put(i);
			queue.put(i);
			queue.put(i);
			queue.put(i);
			queue.put(i);
			queue.put(i);



		}));
	}

	for (int i = 0; i < 10; i++)
	{
		take_threads_.push_back(std::thread([i, &queue] {


			queue.take();
			queue.take();
			queue.take();
			queue.take();
			queue.take();
			queue.take();


		}));
	}

	for (auto& v : put_threads_)
	{
		v.join();
	}

	for (auto& v : take_threads_)
	{
		v.join();
	}

	cout << queue.empty() << endl;

	return getchar();
}