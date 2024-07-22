/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;


void calWaitingTime(int process[], int burstTime[],int n,int w[]){
    w[0] = 0;
    for(int i=1;i<n;i++){
        w[i] = w[i-1] + burstTime[i-1];
    }
}
void calTurnAroungTime(int process[],int burstTime[], int n,int tat[],int w[]){
    for(int i=0;i<n;i++){
        tat[i] = burstTime[i] + w[i];
    }
    
}
int main()
{
    int n = 4;
    int process[4] = {1,2,3,4};
    int burstTime[4] = {21, 3, 6, 2};
    
    // calculate waiting time
    int waitingTime[4];
    calWaitingTime(process,burstTime,4,waitingTime);
    
    // calculate turnAroung time
    int turnAroungTime[4];
    calTurnAroungTime(process,burstTime,4,turnAroungTime,waitingTime);
    
    // calculate average waiting time
    int wt = 0;
    int tat = 0;
    cout<<"waiting Time  Turn aroung time"<<endl;
    for(int i=0;i<n;i++){
        cout<<waitingTime[i]<<"       "<<turnAroungTime[i]<<endl;
        wt += waitingTime[i];
        tat += turnAroungTime[i];
    }
    cout<<"average waiting time "<<(float)wt/4.0<<endl;
    cout<<"average turnAroung time "<<(float)tat/4.0<<endl;

    return 0;
}