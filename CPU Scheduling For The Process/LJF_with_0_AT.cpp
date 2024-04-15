
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id;
    int burst_time;
};

bool compareJobs(Job& a, Job& b) {
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
        cout << "jobschedule (lif):" << endl;
        cout << "Job ID \t burst time \t completion Time\n";

        for (Job& job : joblist) {
            int completion_time = current_time + job.burst_time;
            cout << job.id << "\t" << job.burst_time << "\t\t" << completion_time << endl;
            current_time = completion_time;
        }
    }
};

int main() {
    vector<Job> jobs = {
        {1, 10},
        {2, 5},
        {3, 8}
    };

    LIFScheduler scheduler(jobs);

    scheduler.schedule();

    return 0;
}