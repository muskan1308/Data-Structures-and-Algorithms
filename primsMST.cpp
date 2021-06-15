#include<iostream>
#include<climits>
#include<unordered_map>
#include<vector>

using namespace std;
vector <int> parent;
vector <bool> MSTset;
vector <int> key;
int **graph;
int n;
int minKey(){
    int m=INT_MAX;
    int min_index;
    for(int i=0;i<MSTset.size();i++){
        if(MSTset[i]==false && key[i]<m) min_index=i, m= key[i];
    }
    return min_index;
}

void printMST(int **graph, int n){
    cout<<"Edge\t Weight\n";
    for(int i=1;i<n;i++){
        cout<<parent[i]<<" "<<i<<"  -> "<<graph[i][parent[i]];
        cout<<endl;
    }
}
void findMST(int **graph, int n){
    parent.resize(n);
    parent[0]=-1;   
    key.resize(n);
    MSTset.resize(n);
    for(int i=0;i<n;i++){
        key[i]= INT_MAX;
        MSTset[i]= false;
    }
    key[0]=0;

    while(n--){
        int u = minKey();
        MSTset[u]= true;
        for(int i=0;i<MSTset.size();i++){
            if(graph[u][i]!=0 && MSTset[i]==false && graph[u][i]<key[i])
                parent[i]= u, key[i]= graph[u][i];
        }
    }
}


int main(){
    int n;
    cout<<"Enter the number of vertices\n";
    cin>>n;
    int ** graph = new int*[n];
    for(int i=0;i<n;i++)
        graph[i]= new int[n];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j]= 0;
        }
    }
    int e;
    cout<<"Enter the number of edges. Remember: vertex index starts at 0\n";
    cin>>e;
    int src, dest, weight;
    while(e--){
        cout<<"Enter source\n";
        cin>>src;
        cout<<"Enter destination\n";
        cin>>dest;
        cout<<"Enter weight\n";
        cin>>weight;

        graph[src][dest]= weight;
        graph[dest][src]= weight;
    }
// n=5;
// int graph[5][5] = { { 0, 2, 0, 6, 0 }, 
//                         { 2, 0, 3, 8, 5 }, 
//                         { 0, 3, 0, 0, 7 }, 
//                         { 6, 8, 0, 0, 9 }, 
//                         { 0, 5, 7, 9, 0 } }; 
    findMST(graph,n);
    printMST(graph,n);
    return 0;
}