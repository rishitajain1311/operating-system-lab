#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id;
    int burst_time;
    int arrival_time;
};

bool compareJobs(const Job& a, const Job& b) {
    if (a.arrival_time != b.arrival_time)
        return a.arrival_time < b.arrival_time;
    return a.burst_time > b.burst_time;
}

class LIFScheduler {
private:
    vector<Job> joblist;

public:
    LIFScheduler(vector<Job>& jobs) {
        joblist = jobs;
    }

    void schedule() {
        sort(joblist.begin(), joblist.end(), compareJobs);
        int current_time = 0;
        cout << "jobschedule (LJF with arrival time):\n";
        cout << "Job ID \t Burst Time \t Arrival Time \t Completion Time\n";

        for (Job& job : joblist) {
            int completion_time = max(current_time, job.arrival_time) + job.burst_time;
            cout << job.id << "\t" << job.burst_time << "\t\t" << job.arrival_time << "\t\t" << completion_time << endl;
            current_time = completion_time;
        }
    }
};

int main() {
    vector<Job> jobs = {
        {1, 10, 0},
        {2, 5, 2},
        {3, 8, 3}
    };

    LIFScheduler scheduler(jobs);

    scheduler.schedule();

    return 0;
}