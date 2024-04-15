#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    string name;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
};

int main() {
    int numProcess;
    cout << "Enter the number of Processes: ";
    cin >> numProcess;
    
    vector<Process> processes(numProcess);
    
    
    for(int i = 0; i < numProcess; i++) {
        cout << "Enter burst time for process " << (i + 1) << ": ";
        cin >> processes[i].burstTime;
        processes[i].name = "p" + to_string(i + 1);
    }
    
    
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.burstTime < b.burstTime;
    });
    
    
    int currentTime = 0;
    for(int i = 0; i < numProcess; i++) {
        processes[i].waitingTime = currentTime;
        processes[i].turnAroundTime = processes[i].waitingTime + processes[i].burstTime;
        currentTime += processes[i].burstTime;
    }
    
    
    double avgWaitingTime = 0, avgTurnAroundTime = 0;
    for(const Process& process: processes) {
        avgWaitingTime += process.waitingTime;
        avgTurnAroundTime += process.turnAroundTime;
    }
    avgWaitingTime /= numProcess;
    avgTurnAroundTime /= numProcess;
    
   
    cout << "Average Turnaround Time: " << avgTurnAroundTime << endl;
    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    
    return 0;
}
