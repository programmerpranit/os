#include <iostream>
using namespace std;

int main(){

    // Current Time
    int t = 0;
    int wt[20];

    // number of processes
    int n;
    cout<<"Enter No Of Process"<<endl;
    cin>>n;

    // array of brust time
    int bt[20];
    for(int i=0; i<n; i++){
        cout<<"Brust Time of Process P"<<i+1<<" =  ";
        cin>>bt[i];
    }

    int quantom;
    cout<<"Enter Time Quantom ";
    cin>>quantom;

    int bt_cpy[20];
    for(int i=0; i<n; i++){
        bt_cpy[i] = bt[i];
    }

    while(true){

        // check if all processes are done or not
        bool done = true;

        for(int i=0; i<n; i++){
            // if brust time is greater then 0 then only procced further
            if(bt_cpy[i]>0){
                // it means all processes are not done yet
                done = false;

                // compare time quantom and perform operations accordingly
                if(bt_cpy[i]>quantom){
                    bt_cpy[i] -= quantom;
                    t += quantom;
                }
                else {
                    t += bt_cpy[i];
                    wt[i] = t - bt[i];
                    bt_cpy[i] = 0;
                }
                
            }

            
        }

        if (done == true) break;
    }

    int total_wt = 0;
    int total_tat = 0;

    for(int i=0; i<n; i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + bt[i] + wt[i];
    }


    cout << "Average waiting time = "
        << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n;
    

    return 0;
}