#include <iostream>
#include <string>
#include <vector>

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

    vector<Process> Processes(numProcess);

    
    for (int i = 0; i < numProcess; i++) {
        cout << "Enter burst time for process " << (i + 1) << ": ";
        cin >> Processes[i].burstTime;
        Processes[i].name = "p" + to_string(i + 1);
        Processes[i].waitingTime = 0;
        Processes[i].turnAroundTime = 0;
    }

    
    Processes[0].waitingTime = 0;
    Processes[0].turnAroundTime = Processes[0].burstTime;
    for (int i = 1; i < numProcess; i++) {
        Processes[i].waitingTime = Processes[i - 1].waitingTime + Processes[i - 1].burstTime;
        Processes[i].turnAroundTime = Processes[i].waitingTime + Processes[i].burstTime;
    }

    
    double totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (const Process& process : Processes) {
        totalWaitingTime += process.waitingTime;
        totalTurnaroundTime += process.turnAroundTime;
    }
    double avgWaitingTime = totalWaitingTime / numProcess;
    double avgTurnaroundTime = totalTurnaroundTime / numProcess;

   
    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;

    return 0;
}
