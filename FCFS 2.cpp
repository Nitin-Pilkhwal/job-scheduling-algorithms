/// FCFS with arrival time
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Process{
    int pid;
    int bt;
    int at;
    Process(int id,int a,int b){
        pid = id;
        at = a;
        bt = b;
    }
} typedef process;

bool cmp(process& a,process&b){
    return a.at < b.at;
}

void calCompletionTime(vector<process>& p,int completionTime[]){
    int currTime = 0;
    for(int i=0;i<p.size();i++){
        int bt = p[i].bt;
        int id = p[i].pid;
        currTime += bt;
        completionTime[id] = currTime;
    }
}

void calTurnAroungTime(int completionTime[],int turnAroungTime[],vector<process>& p){
    for(int i=0;i<p.size();i++){
        int at = p[i].at;
        int id = p[i].pid;
        turnAroungTime[id] = completionTime[id] - at;
    }
}

void calWaitingTime(int turnAroungTime[],int waitingTime[],vector<process>& p){
    for(int i=0;i<p.size();i++){
        int bt = p[i].bt;
        int id = p[i].pid;
        waitingTime[id] = turnAroungTime[id] - bt;
    }
}



int main()
{
    int n = 6;
    int processes[n] = {1,2,3,4,5,6};
    int burstTime[n] = {9,3,2,4,3,2};
    int arrTime[n] = {0,1,1,1,2,3};
    vector<process> p;
    
    // Inserting processID, arrTime and burstTime
    for(int i=0;i<n;i++){
        process p1 =  Process(processes[i]-1,arrTime[i],burstTime[i]);
        p.push_back(p1);
    }
    // Sorting wrt arrTime
    sort(p.begin(),p.end(),cmp);
    
    /// calculate completionTime
    int completionTime[n];
    calCompletionTime(p,completionTime);
    
    // calculate turnAroung time
    int turnAroungTime[n];
    calTurnAroungTime(completionTime,turnAroungTime,p);
    
    // calculate waiting time
    int waitingTime[n];
    calWaitingTime(turnAroungTime,waitingTime,p);
    
    
    // calculate average waiting time
    int wt = 0;
    int tat = 0;
    cout<<"waiting Time  Turn aroung time"<<endl;
    for(int i=0;i<n;i++){
        cout<<waitingTime[i]<<"       "<<turnAroungTime[i]<<endl;
        wt += waitingTime[i];
        tat += turnAroungTime[i];
    }
    cout<<"average waiting time "<<(float)wt/6.0<<endl;
    cout<<"average turnAroung time "<<(float)tat/6.0<<endl;

    return 0;
}