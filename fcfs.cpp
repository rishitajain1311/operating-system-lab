/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<string.h>
#include<vector>

using namespace std;

struct Process{
    string name;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
};

int main()
{
    int numProcess;
    cout<<"Enter the number of Process :"<<endl;
    cin>>numProcess;
    vector<Process> Processes(numProcess);
    for(int i =0; i<numProcess; i++){
        cout<<"Enter burst time for process"<<(i+1)<<":";
        cin>>Processes[i].burstTime;
        Processes[i].name = "p"+ to_string(i+1);
        Processes[i].waitingTime = 0;
        
        Processes[i].turnAroundTime = 0;
        }
        
        for(int i =1; i<numProcess; i++){
         Processes[i].waitingTime = Processes[i-1].waitingTime+Processes[i-1].burstTime;
         Processes[i].turnAroundTime = Processes[i].waitingTime+ Processes[i].burstTime;
         
        }
        
        double avgWaitingTime = 0, avgTurnArounfTime=0;
        for(const Process& process: Processes){
            avgWaitingTime += process.waitingTime;
            avgTurnArounfTime += process.turnAroundTime;
        }
        avgWaitingTime/= numProcess;
        avgTurnArounfTime /= numProcess;
        
        cout<<avgTurnArounfTime;
        cout<<avgWaitingTime;
        
        
    


    return 0;
}
