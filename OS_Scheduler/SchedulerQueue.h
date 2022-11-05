#pragma once

#include <queue>
#include <mutex>
#include <array>
#include "Process.h"

class SchedulerQueue 
{

public:

	enum QueueType		
	{
		RUN,
		IO
	};

	SchedulerQueue() {}
	SchedulerQueue(const SchedulerQueue& cpy) 
	{
		

		for (int i = 0; i<2; i++)
		{
			queues[i] = cpy.GetQueues()[i];

		}
	}
	~SchedulerQueue() {}
	
	/*
	* Checks the status of the run queue and handles accordingly
	*/
	void Update(std::mutex* _mtx);

	/*
	* Adds a process to a queue either , Run or IO
	*
	* @param Process the process to add to queue
	* @param QueueType the queue to add process to
	*/
	void AddProcess(Process* p, QueueType qType);

	/*
	* Gets the Queue type from the process
	* 
	* @param QueueType the queuetype of the process
	*/
	std::queue<Process*> GetQueue(QueueType qType) const;

	std::array<std::queue<Process*>, 2> GetQueues() const;
	
	
private:
	std::array<std::queue<Process*>, 2> queues{ std::queue<Process*>(), std::queue<Process*>()};
	
};

