#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class DisjointSet{
public:
    unordered_map <int, int> parent ;
    unordered_map <int,int> rank;

void makeset(vector<int> &array){
    int n= array.size();
    for(int i=0;i<n;i++){
        parent[array[i]]=array[i];
        rank[array[i]]=0;
    }
} 
int Find(int a){

   if(parent[a]!=a){
       parent[a]= Find(parent[a]);
     //  cout<<"find: parent of "<<a<<"is "<<parent[a]<<endl;
   }
   return parent[a];
}

void Union(int a, int b ) {
    int a_parent= Find(a);
    int b_parent= Find(b);
    if(a_parent==b_parent) return;
    
    if(rank[a_parent]>rank[b_parent]){
        parent[b_parent]=a_parent;
       // cout<<"union of "<<a<<" and "<<b<<" : 1. parent of "<<b_parent<<"is "<<a_parent<<endl;
        }
    else if(rank[a_parent]<rank[b_parent]){
        parent[a_parent]=b_parent;
     //   cout<<"union of "<<a<<" and "<<b<<" : 2. parent of "<<a_parent<<"is "<<b_parent<<endl;
    }
    else{
        parent[a_parent]=b_parent;
        rank[b_parent]++;
     //   cout<<"union of "<<a<<" and "<<b<<" : 3. parent of "<<a_parent<<" is "<<b_parent<<endl;
       // cout<<"rank of "<<b_parent<<" is: "<<rank[b_parent]<<endl;
    }
}
void printrank(DisjointSet &ds){
    for(auto it: rank){
     //   cout<<"rank of: "<<it.first<<" is "<<it.second<<endl;
    }
}
};

void printSets(vector<int> &array, DisjointSet &ds){
    for(int i=0;i<array.size();i++){
        cout<<ds.Find(array[i])<<" ";
    }
    cout<<endl;
}


int main(){

    vector <int> array= {1,2,3,4,5,6,7,8};
    DisjointSet ds;
    ds.makeset(array);
    
    printSets(array,ds);
    ds.Union(1,2);
   
    ds.Union(2,3);
    ds.Union(4,5);
    ds.Union(6,7);
    ds.Union(5,6);
    ds.Union(3,7);
   // cout<<ds.Find(1);
    printSets(array,ds);
  //  cout<<ds.Find(2);
   ds.printrank(ds);
    return 0;
}