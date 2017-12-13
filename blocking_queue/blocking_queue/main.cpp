#include "blocking_queue_cruise.h"
#include <thread>
#include <vector>

using namespace std;

int main()
{
	blocking_queue_cruise queue;
	std::vector<std::thread> put_threads_;
	std::vector<std::thread> take_threads_;
	//vector<std::thread> vec;

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

	auto b = queue.empty();

	return getchar();
}