#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge{
    int src;
    int dest;
    int weight;
};
struct compare{
    bool operator() (Edge const &a, Edge const &b) const {
        return a.weight < b.weight;
    }
};
class DisjointSet{
public:
    unordered_map <int,int> parent;
    vector <Edge> MST;

void makeset(vector<int> &array){
    
    for(int i=0;i<array.size();i++){
        parent[array[i]]= array[i];
    }
}

int Find(int a){
    if(parent[a]!=a)
        return Find(parent[a]);
    return parent[a];
}
void Union(vector <Edge> &edges, vector <int> &array){
    int n= array.size();
    int i=0;
    while(MST.size()!=n-1){
    Edge edge= edges[i];
    int x= Find(edge.src);
    int y= Find(edge.dest);
    if(x==y) return ;
    else {
        MST.push_back(edge);
        parent[x]=y;
    }
    i++;
    }
}

void printMST(){
    for(int i=0;i<MST.size();i++){
        cout<<MST[i].src<<" "<<MST[i].dest<<" "<<MST[i].weight<<endl;
    }
}


};
int main(){
    DisjointSet ds;
    vector <int> array= {1,2,3,4,5,6,7};
    ds.makeset(array);
   
    int e;
    cout<<"Enter number of edges\t";
    cin>>e;
    vector <struct Edge> edges(e);
    for(int i=0;i<e;i++){
        cout<<"Enter source: ";
        cin>>edges[i].src;
        cout<<"Enter destination: ";
        cin>>edges[i].dest;
        cout<<"Enter weight: ";
        cin>>edges[i].weight; 
        }
    sort(edges.begin(), edges.end(), compare());
    ds.Union(edges, array);
    ds.printMST();
    
    return 0;    

}