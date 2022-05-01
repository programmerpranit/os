#include <iostream>
using namespace std;

int main(){
    // number of processes
    int n;
    cout<<"Enter No Of Process"<<endl;
    cin>>n;

    // array of processes
    // int p[20];
    // array of brust time
    int bt[20];
    for(int i=0; i<n; i++){
        cout<<"Brust Time of Process P"<<i+1<<" =  ";
        cin>>bt[i];
    }

    // Sorting According to brust time
    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i; j<n; j++){
            if(bt[min]>bt[j]){
                min = j;
            }
        }
        int temp = bt[min];
        bt[min] = bt[i];
        bt[i] = temp;
    }

    // array of waiting time
    int wt[20];
    wt[0] = 0; // waiting time of 1st process will be 0
    int totalWt = 0;
    for (int i = 1; i<n; i++){
        wt[i] = wt[i-1] + bt[i-1];
        totalWt += wt[i];
    }

    int tat[20];
    int totalTat = 0;

    for(int i = 0; i < n; i++){
        tat[i] = bt[i] + wt[i];
        totalTat += tat[i];
    }


    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++) {
        // tat[i] = bt[i] + wt[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d", i, bt[i], wt[i], tat[i]);
    }

    float avgwt = (float)totalWt / n;
    float avgtat = (float)totalTat / n;


    cout<<"\nAverage Waiting Time is "<<avgwt<<endl;
    cout<<"Average Turn Around Time is "<<avgtat<<endl;


    return 0;
}