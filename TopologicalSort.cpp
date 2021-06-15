#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector <bool> visitedSet;
stack <int> st;
void topologicalSort(vector <vector<int>> Graph, int s){
 //   cout<<"called top sort\n";
    visitedSet[s]=true;
    for(int i=0;i<Graph[s].size();i++){
        if(visitedSet[Graph[s][i]]==false) {
             cout<<"calling top sort on\t"<<Graph[s][i]<<endl;
            topologicalSort(Graph, Graph[s][i]);
        }
    }
  //  cout<<"Size of stack in top sort is:\t"<<st.size()<<endl;
    cout<<"pushing element s on stack:\t"<<s<<endl;
    st.push(s);
}

int main(){
    cout<<"Enter number of vertices\n";
    int n; cin>>n;
    vector <vector<int>> Graph(n);
    for(int u=0;u<n;u++){
        cout<<"Enter number of edges corresponding to current vertex\n";
        int e; cin>>e;
        while(e--){
            cout<<"Enter dest vertex\n";
            int v;
            cin>>v;
            Graph[u].push_back(v);
        }
    }
    visitedSet.resize(n);
    for(int i=0;i<n;i++){
        visitedSet[i]= false;
    }
    for(int i=0;i<n;i++){
        if(visitedSet[i]==false){
        //cout<<"calling top sort\n";
        cout<<"calling top sort on\t"<<i<<endl;
        topologicalSort(Graph, i);
        }
    }
  //  cout<<"size of stack is: \t"<<st.size()<<endl;;
    while(!st.empty()){
         cout<<st.top()<<"\t";
        st.pop();
    }
    return 0;
}