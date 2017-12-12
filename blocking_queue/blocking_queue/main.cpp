#include "blocking_queue.h"
#include <thread>


int main()
{
	blocking_queue queue;

	for (int i = 0; i < 10; i++)
	{
		thread t([i, &queue] {
			queue.put(i);
			queue.take();

		});

		t.detach();
	}
	return getchar();
}