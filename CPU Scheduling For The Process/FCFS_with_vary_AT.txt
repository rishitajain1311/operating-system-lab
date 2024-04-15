#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    string name;
    int burstTime;
    int arrivalTime;
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
        cout << "Enter arrival time for process " << (i + 1) << ": ";
        cin >> processes[i].arrivalTime;
        processes[i].name = "p" + to_string(i + 1);
    }
    
   
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });
    
    
    processes[0].waitingTime = 0; 
    processes[0].turnAroundTime = processes[0].burstTime;
    
    for(int i = 1; i < numProcess; i++) {
        int prevCompletionTime = processes[i - 1].arrivalTime + processes[i - 1].burstTime;
        processes[i].waitingTime = max(0, prevCompletionTime - processes[i].arrivalTime);
        processes[i].turnAroundTime = processes[i].waitingTime + processes[i].burstTime;
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
