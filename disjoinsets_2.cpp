#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
// A class to represent a disjoint set
class DisjointSet
{
    unordered_map<int, int> parent;
 
    // stores the depth of trees
    unordered_map<int, int> rank;
 
public:
    // perform MakeSet operation
    void makeSet(vector<int> const &universe)
    {
        // create `n` disjoint sets (one for each item)
        for (int i: universe)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
 
    // Find the root of the set in which element `k` belongs
    int Find(int k)
    {
        // if `k` is not the root
        if (parent[k] != k)
        {
            // path compression
            parent[k] = Find(parent[k]);
        }
 
        return parent[k];
    }
 
    // Perform Union of two subsets
    void Union(int a, int b)
    {
        // find the root of the sets in which elements
        // `x` and `y` belongs
        int x = Find(a);
        int y = Find(b);
 
        // if `x` and `y` are present in the same set
        if (x == y) {
            return;
        }
 
        // Always attach a smaller depth tree under the
        // root of the deeper tree.
        if (rank[x] > rank[y]) {
            parent[y] = x;
        }
        else if (rank[x] < rank[y]) {
            parent[x] = y;
        }
        else {
            parent[x] = y;
            rank[y]++;
        }
    }
};
 
void printSets(vector<int> const &universe, DisjointSet &ds)
{
    for (int i: universe) {
        cout << ds.Find(i) << ' ';
    }
    cout << endl;
}
 
// Disjoint–Set data structure (Union–Find algorithm)
int main()
{
    // universe of items
    vector<int> universe = { 10, 20, 30, 40, 50 ,60,70};
 
    // initialize `DisjointSet` class
    DisjointSet ds;
 
    // create a singleton set for each element of the universe
    ds.makeSet(universe);
    printSets(universe, ds);
 
   
    ds.Union(20,30);
    ds.Union(40,50);
    ds.Union(60,70);
    ds.Union(50,60);
    ds.Union(30,70);
 printSets(universe, ds);
    return 0;
}