#include <thread>
#include <iostream>
#include <functional>
#include <mutex>
#include "SchedulerQueue.h"

void SchedulerQueue::Update(std::mutex* _mtx)
{
	std::unique_lock<std::mutex> lock(*_mtx);
	//TODO: implement update

	if (!queues[RUN].empty())
	{
		switch (queues[RUN].front()->GetStatus())
		{
		case Process::READY:
		{
			std::thread t1([&]() {
				queues[RUN].front()->Run();
				Update(_mtx);
				});
				break;
		}
		case Process::IO:
			queues[IO].emplace(queues[RUN].front());
			queues[RUN].pop();
			break;
		case Process::DONE:
			queues[RUN].pop();
		}
	}
	
	
	if (!queues[IO].empty())
	{

		switch (queues[IO].front()->GetStatus())
		{
		case Process::READY:
		{
			std::thread t2([&]() {
				queues[IO].front()->Run();
				Update(_mtx);
				});
			break;
		}
		case Process::RUNNING:
			queues[RUN].emplace(queues[IO].front());
			queues[IO].pop();
			break;
		}
	}
	
	lock.unlock();
}

void SchedulerQueue::AddProcess(Process* p, QueueType qType)
{
	queues[qType].push(p);
}

std::queue<Process*> SchedulerQueue::GetQueue(SchedulerQueue::QueueType qType) const
{
	return queues[qType];
}


std::array<std::queue<Process*>, 2> SchedulerQueue::GetQueues() const
{
	return 	queues;
}

