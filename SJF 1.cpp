/// Shortest job first non-preemptive

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process{
    int pid;
    int bt;
    Process(int id,int a){
        pid = id;
        bt = a;
    }
} typedef process;

void calTurnAroungTime(int waitingTime[],int turnAroungTime[],vector<process>& p){
    for(int i=0;i<p.size();i++){
        int id = p[i].pid;
        turnAroungTime[id] = waitingTime[id] + p[i].bt;
    }
}

void calWaitingTime(int waitingTime[],vector<process>& p){
    waitingTime[p[0].pid] = 0;
    for(int i=1;i<p.size();i++){
        waitingTime[p[i].pid] = waitingTime[p[i-1].pid] + p[i].bt;
    }
}

bool cmp(process& a,process&b){
    return a.bt < b.bt;
}
int main()
{
    int n = 5;
    int processes[n] = {1,2,3,4,5};
    int burstTime[n] = {7,3,2,10,8};
    vector<process> p;
    
    // Inserting processID, arrTime and burstTime
    for(int i=0;i<n;i++){
        process p1 =  Process(processes[i]-1,burstTime[i]);
        p.push_back(p1);
    }
    
    // Sorting wrt burstTime
    sort(p.begin(),p.end(),cmp);
    
    // calculate waiting time
    int waitingTime[n];
    calWaitingTime(waitingTime,p);
    
    // calculate turnAroung time
    int turnAroungTime[n];
    calTurnAroungTime(waitingTime,turnAroungTime,p);
    
    // calculate average waiting time
    int wt = 0;
    int tat = 0;
    cout<<"waiting Time  Turn aroung time"<<endl;
    for(int i=0;i<n;i++){
        cout<<waitingTime[i]<<"                  "<<turnAroungTime[i]<<endl;
        wt += waitingTime[i];
        tat += turnAroungTime[i];
    }
    cout<<"average waiting time "<<(float)wt/5.0<<endl;
    cout<<"average turnAroung time "<<(float)tat/5.0<<endl;
    return 0;
}