#pragma once

#include <vector>
#include <memory>

class Process
{
public:

    enum Status 
    {
        READY,
        RUNNING,
        IO,
        DONE
    };

    Process(std::vector<int> jobList) : status(READY), jobs(jobList) {} //contructer
    ~Process(){}
    /*
    * Gets what status the process is currently in 
    */
    Status GetStatus() const;

    /*
    * Changes the status of the process to its  proper status
    * 
    * @param Status the status of the process
    */
    void SetStatus(Status stat);

    /*
    * Gets list of jobs
    */
    std::vector<int> GetJobs() const;

    /*
    * Run arbitrary code for a set duration
    */
    void Run();

private:
    int burst_time = 0;
    int completion_time = 0;
    int turnaround_time = 0;
    int waiting_time = 0;
    int response_time = 0;
    int jobIndex = 0;
    
    std::vector<int> jobs;

    Status status;

};

