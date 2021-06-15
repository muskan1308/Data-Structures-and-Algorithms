#include<iostream>
#include<queue>
#include<vector>
#define pii pair <int,int> 
using namespace std;
int main(){
    
    cout<<"Enter number of vertices\n";
    int n;
    cin>>n;
    vector < vector< pii >> graph(n);
    int u=0;
    for(int u=0;u<n;u++){
        cout<<"Enter number of edges adjacent to current vertex\n";
        int e;
        cin>>e;
        while(e--){
            int v, wt;
            cout<<"Enter the vertex and edge weight\n";
            cin>>v;
            cin>>wt;
            graph[u].push_back(make_pair(v,wt));
            graph[v].push_back(make_pair(u,wt));
        }
    }
    cout<<"Origin\t"<<"Destination, Weight\n";
for(int i=0;i<n;i++){ 
    cout<<i<<"\t";
    for(int v=0;v<graph[i].size();v++)
        cout<<graph[i][v].first<<","<<graph[i][v].second<<"\t\t";
    cout<<endl;
}
return 0;
}