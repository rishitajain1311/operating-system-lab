#include <iostream>
#include <string>
#include <vector>
#include <queue>

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
    int timeQuantum;
    
    cout << "Enter the number of Processes: ";
    cin >> numProcess;
    
    cout << "Enter the time quantum: ";
    cin >> timeQuantum;
    
    vector<Process> processes(numProcess);
    queue<int> readyQueue;
    
   
    for(int i = 0; i < numProcess; i++) {
        cout << "Enter burst time for process " << (i + 1) << ": ";
        cin >> processes[i].burstTime;
        cout << "Enter arrival time for process " << (i + 1) << ": ";
        cin >> processes[i].arrivalTime;
        processes[i].name = "p" + to_string(i + 1);
    }
    
    int currentTime = 0;
    int nextProcessIndex = 0;
    while (!readyQueue.empty() || nextProcessIndex < numProcess) {
        
        while (nextProcessIndex < numProcess && processes[nextProcessIndex].arrivalTime <= currentTime) {
            readyQueue.push(nextProcessIndex++);
        }
        
        if (readyQueue.empty()) {
           
            currentTime = processes[nextProcessIndex].arrivalTime;
            continue;
        }
        
        int processIndex = readyQueue.front();
        readyQueue.pop();
        
       
        int executionTime = min(timeQuantum, processes[processIndex].burstTime);
        processes[processIndex].burstTime -= executionTime;
        currentTime += executionTime;
        
        
        for (int i = 0; i < numProcess; i++) {
            if (i != processIndex && processes[i].arrivalTime <= currentTime && processes[i].burstTime > 0) {
                processes[i].waitingTime += executionTime;
            }
        }
        
        
        if (processes[processIndex].burstTime > 0) {
            readyQueue.push(processIndex);
        } else {
            
            processes[processIndex].turnAroundTime = currentTime;
        }
    }
    
   
    double avgWaitingTime = 0;
    for(const Process& process: processes) {
        avgWaitingTime += process.waitingTime;
    }
    avgWaitingTime /= numProcess;
    
    
    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    
    return 0;
}
