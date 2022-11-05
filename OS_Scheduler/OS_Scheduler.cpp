#include <iostream>
#include <algorithm> 
#include <iomanip> 
#include <vector>

#include "Process.h"
#include "SchedulerQueue.h"

using namespace std;

int main() {
    std::vector<int> CPU_1{ 5, 27, 3, 31, 5, 43, 4, 18, 6, 22, 4, 26, 3, 24, 4 };
    std::vector<int> CPU_2{ 4, 48, 5, 44, 7, 42, 12, 37, 9, 76, 4, 41, 9, 31, 7, 43, 8 };
    std::vector<int> CPU_3{ 8, 33, 12, 41, 18, 65, 14, 21, 4, 61, 15, 18, 14, 26, 5, 31, 6 };
    std::vector<int> CPU_4{ 3, 35, 4, 41, 5, 45, 3, 51, 4, 61, 5, 54, 6, 82, 5, 77, 3 };
    std::vector<int> CPU_5{ 16, 24, 17, 21, 5, 36, 16, 26, 7, 31, 13, 28, 11, 21, 6, 13, 3, 11, 4 };
    std::vector<int> CPU_6{ 11, 22, 4, 8, 5, 10, 6, 12, 7, 14, 9, 18, 12, 24, 15, 30, 8 };
    std::vector<int> CPU_7{ 14, 46, 17, 41, 11, 42, 15, 21, 4, 32, 7, 19, 16, 33, 10 };
    std::vector<int> CPU_8{ 4, 14, 5, 33, 6, 51, 14, 73, 16, 87, 6 };

    SchedulerQueue scheduler = SchedulerQueue();

    Process p1 = Process(CPU_1);
    Process p2 = Process(CPU_2);
    Process p3 = Process(CPU_3);
    Process p4 = Process(CPU_4);
    Process p5 = Process(CPU_5);
    Process p6 = Process(CPU_6);
    Process p7 = Process(CPU_7);
    Process p8 = Process(CPU_8);


    scheduler.AddProcess(&p1, SchedulerQueue::RUN);
    scheduler.AddProcess(&p2, SchedulerQueue::RUN);
    scheduler.AddProcess(&p3, SchedulerQueue::RUN);
    scheduler.AddProcess(&p4, SchedulerQueue::RUN);
    scheduler.AddProcess(&p5, SchedulerQueue::RUN);
    scheduler.AddProcess(&p6, SchedulerQueue::RUN);
    scheduler.AddProcess(&p7, SchedulerQueue::RUN);
    scheduler.AddProcess(&p8, SchedulerQueue::RUN);

    std::mutex mtx;
    scheduler.Update(&mtx);
    
   
    while (scheduler.GetQueue(SchedulerQueue::IO).empty() && scheduler.GetQueue(SchedulerQueue::RUN).empty())
    {


    }
    cout << "done, dummy" << endl;

    float avg_turnaround_time;
    float avg_waiting_time;
    float avg_response_time;
    float cpu_utilisation;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    float throughput;
}




/*


BT - Burst time of the process
ST - Start time of the process
CT - Completion time of the process
TAT - Turnaround time of the process
WT - Waiting time of the process
RT - Response time of the process

Formulas used:

TAT = CT - RT
WT = TAT - BT
RT = ST - AT

*/