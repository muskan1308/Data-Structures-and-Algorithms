#include<iostream>
#include<queue>
#define pii pair<int,int>
using namespace std;
int main(){
    cout<<"Enter no of vertices\n";
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
cout<<"Graph is:\n Origin\t"<<"Destination, Weight\n";
for(int i=0;i<n;i++){ 
    cout<<i<<"\t";
    for(int v=0;v<graph[i].size();v++)
        cout<<graph[i][v].first<<","<<graph[i][v].second<<"\t\t";
    cout<<endl;
}
    vector <bool> VisitedSet(n, false);
    vector <int> distance(n, INT_MAX);
    distance[0]=0;
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0,0}); //distance is first, vertex is second as we have to sort min by distance
    while(!pq.empty()){ 
        int u= pq.top().second;
        pq.pop();
        VisitedSet[u]= true;
        for(int i=0;i<graph[u].size();i++){
            // cout<<"graph[u] size is: "<<graph[u].size()<<endl;
            // cout<<"graph[u][i].first is: "<<graph[u][i].first<<endl;
            if(VisitedSet[graph[u][i].first]==false){
            if(distance[graph[u][i].first]> distance[u]+ graph[u][i].second) {
            distance[graph[u][i].first]= distance[u] + graph[u][i].second;
            pq.push({distance[graph[u][i].first],graph[u][i].first});
            // cout<<"Updating distance of "<<graph[u][i].first<<" as: "<< distance[graph[u][i].first]<<endl;
            }
            }
        }
    }
    cout<<"Shortest Path array\n";
    for(int i=0;i<n;i++){
        cout<<distance[i]<<"\t";
    }
    cout<<endl;
    cout<<"Visited array is\n";
    for(int i=0;i<n;i++){
        cout<<VisitedSet[i]<<"\t";
    }
   return 0;
}