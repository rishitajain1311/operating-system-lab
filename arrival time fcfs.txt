#include <iostream>
#include <string>
#include <vector>

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
    
    vector<Process> Processes(numProcess);
    
   
    for(int i = 0; i < numProcess; i++) {
        cout << "Enter burst time for process " << (i + 1) << ": ";
        cin >> Processes[i].burstTime;
        cout << "Enter arrival time for process " << (i + 1) << ": ";
        cin >> Processes[i].arrivalTime;
        Processes[i].name = "p" + to_string(i + 1);
        Processes[i].waitingTime = 0;
        Processes[i].turnAroundTime = 0;
    }
    
    
    sort(Processes.begin(), Processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });
    
    
    for(int i = 1; i < numProcess; i++) {
        int prevCompletionTime = Processes[i - 1].arrivalTime + Processes[i - 1].burstTime;
        Processes[i].waitingTime = max(0, prevCompletionTime - Processes[i].arrivalTime);
        Processes[i].turnAroundTime = Processes[i].waitingTime + Processes[i].burstTime;
    }
    
    
    double avgWaitingTime = 0, avgTurnAroundTime = 0;
    for(const Process& process: Processes) {
        avgWaitingTime += process.waitingTime;
        avgTurnAroundTime += process.turnAroundTime;
    }
    avgWaitingTime /= numProcess;
    avgTurnAroundTime /= numProcess;
    
    cout << "Average Turnaround Time: " << avgTurnAroundTime << endl;
    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    
    return 0;
}
