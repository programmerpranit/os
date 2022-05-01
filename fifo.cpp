#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main(){

    int n = 10;
    int pages[n] = {5,8,6,2,3,2,2,1,2,3};

    unordered_set<int> s;

    queue<int> index;

    int capacity = 3;

    int page_fault = 0;

    for (int i = 0; i<n; i++){

        // there is space in set and 
        if(s.size()<capacity && s.find(pages[i])==s.end()){
            s.insert(pages[i]);
            index.push(pages[i]);
            page_fault++;
        }
        //  there is no space in set
        // page fault
        else if(s.find(pages[i])==s.end()){
            
            int first = index.front();
            s.erase(first);
            s.insert(pages[i]);
            index.pop();
            index.push(pages[i]);
            page_fault++;
            
        }

    }

    cout<<"Total Page Faults = "<<page_fault;


    return 0;

}