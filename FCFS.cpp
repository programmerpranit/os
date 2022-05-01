#include <bits/stdc++.h>
using namespace std;

int main() {

    // number of processes
    int n;
    cout<<"Enter No Of Process"<<endl;
    cin>>n;

    // array of processes
    int at[20];
    // array of brust time
    int bt[20];
    for(int i=0; i<n; i++){
        cout<<"Arrival Time of Process P"<<i+1<<" =  ";
        cin>>at[i];
        cout<<"Brust Time of Process P"<<i+1<<" =  ";
        cin>>bt[i];
    }

    for (int i =0; i<n; i++){
        int min = i;
        for(int j=i; j<n; j++){
            if(at[min]>at[j]){
                min = j;
            }
        }
        // swap
        int temp = at[i];
        at[i] = at[min];
        at[min] = temp;

        temp = bt[i];
        bt[i] = bt[min];
        bt[min] = temp;
    }

    int totalwt =0;


    for(int i=0; i<n; i++){
        totalwt += bt[i]; 
    }

    float avgwt = (float)totalwt/(float)n;

    cout<<"Average Waiting Time "<<avgwt;

    return 0;
}