#include<iostream>
#include<vector>
using namespace std;
vector <vector<int>> res;
vector <int> temp;
void shortestPaths(vector <vector<int>> &graph, int src, int dest){
    temp.push_back(src);
    if(src==dest){
        res.push_back(temp);
    }
    else{
     for(auto node : graph[src]){
        shortestPaths(graph,node, dest);
    }
    }
    temp.pop_back();
}
int main(){
cout<<"Enter number of vertices\n";
    int n; cin>>n;
    vector <vector<int>> graph(n);
    for(int u=0;u<n;u++){
        cout<<"Enter number of edges corresponding to current vertex\n";
        int e; cin>>e;
        while(e--){
            cout<<"Enter dest vertex\n";
            int v;
            cin>>v;
            graph[u].push_back(v);
        }
    }
shortestPaths(graph,0, n-1);
for(int i=0;i<res.size();i++){
    for(int j=0;j< res[i].size();j++)
        cout<<res[i][j]<<" ";
    cout<<endl;
}
return 0;
}