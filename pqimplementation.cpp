#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue <int, vector<int>, greater <int>> pq;
    cout<<"Enter no of elements:\n";
    int n;
    cin>>n;
    while(n--){
        cout<<"Enter the value\n";
        int val;
        cin>>val;
        pq.push(val);
    }
    cout<<"Elements in min PQ are:\n";
    while(!pq.empty())
        cout<<pq.top()<<"\t", pq.pop();;
return 0;
}

