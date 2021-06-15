#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class DisjointSet{
public:
    unordered_map <int,int> parent;

void makeset(vector<int> &array){
    
    for(int i=0;i<array.size();i++){
        parent[array[i]]= array[i];
    }
}

int Find(int a){
    if(parent[a]!=a)
        parent[a]= Find(parent[a]);
    return parent[a];
}
int Union(int a, int b){
    int x= Find(a);
    int y= Find(b);
    if(x==y) return 1;
    else parent[x]=y;
    return 0;
}
};

int main(){
    DisjointSet ds;
    vector <int> array= {1,2,3,4,5,6,7};
    ds.makeset(array);
    int e, src, dest;
    cout<<"Enter number of edges\t";
    cin>>e;
    int k=0;
    while(e--){
        cout<<"Enter source: ";
        cin>>src;
        cout<<"Enter destination: ";
        cin>>dest;
        k= ds.Union(src,dest);
        if(k==1) {cout<<"Graph contains cycle"; break;}
        }
    if(k==0) cout<<"No cycle found\n";
    
    return 0;    

}