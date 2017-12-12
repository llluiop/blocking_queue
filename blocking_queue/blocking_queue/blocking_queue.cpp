// blocking_queue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "blocking_queue.h"
#include <thread>
#include <iostream>
using namespace std;


blocking_queue::blocking_queue()
{
}

blocking_queue::~blocking_queue()
{
}

void blocking_queue::put(int x)
{
	while (true)
	{
		{
			lock_guard<std::mutex> lck(m_);
			if (!q_.full())
			{
				q_.put(x);
				cout << "thread " << std::this_thread::get_id() << " put " << x << endl;
				return;
			}
		}

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

}

int blocking_queue::take()
{
	while (true)
	{
		{
			lock_guard<std::mutex> lck(m_);
			if (!q_.empty())
			{
				auto x = q_.take();
				cout << "thread " << std::this_thread::get_id() << " take " << x << endl;
				return x;
			}
		}

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
