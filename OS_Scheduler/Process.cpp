#include "Process.h"
#include <vector>
#include <stdio.h>
#include "SchedulerQueue.h"

Process::Status Process::GetStatus() const
{
	return status;
}

void Process::SetStatus(Status stat)
{
	status = stat;
}

std::vector<int> Process::GetJobs() const
{
	return jobs;
}

void Process::Run()
{
	unsigned int duration = jobs[jobIndex];

	// Determine status based on the jobIndex parity
	if (jobIndex % 2 == 0)
	{
		status = RUNNING;
	}
	else
	{
		status = IO;
	}

	printf("Job at status %d for duration %d starting \n", status, duration);

	for (unsigned int i = 0; i < duration; i++)
	{
		switch (status)
		{
		case RUNNING:
			burst_time++;
		case IO:
			completion_time++;
			break;
		}
	}

	printf("Job at status %d for duration %d ending \n", status, duration);

	if (jobIndex == jobs.size() - 1)
	{
		status = DONE;
	}
	else if (jobIndex % 2 == 0)
	{
		status = IO;
	}
	else
	{
		status = RUNNING;
	}

	jobIndex++;
}