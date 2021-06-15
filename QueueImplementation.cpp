#include<iostream>
#include<vector>
using namespace std;
vector <int> queue;
int front=0;
int last=0;
void enqueue(vector<int> &queue, int a, int m){
    if(front==0 && queue.size()==m)
    cout<<"Queue is full\n";
    else {
    queue.push_back(a);
    last=last+1;
    }
}
void dequeue(){
    if(front!=last)
        front = front+1;
    else
        cout<<"Queue is empty!\n";
}
int frontItem(){
    if(front!=last)
        return queue[front];
    else
        return 0;
}
int main(){
    int n;
    cout<<"Enter number of elements to be pushed into queue\t";
    cin>>n;
    int m=n;
    while(n--){
        int item;
        cout<<"Enter item";
        cin>>item;
        enqueue(queue,item,m);
    }
    bool y,x;
    cout<<"Do you want to remove first element? (1/0)\t";
    cin>>y;
    if(y==true) dequeue();
    int ele;
    cout<<"Do you want to append more elements? (1/0)\t";
    cin>>x;
    cout<<"enter element\n";
    cin>>ele;
    if(x==true) enqueue(queue, ele,m);
    cout<<"Do you want to view front element?\n";
    cin>>y;
    if(y==true) cout<<frontItem();
    cout<<"Final queue from front to last is:\n";
    for(int i= front; i<queue.size();i++)
        cout<<queue[i]<<"\t";
    return 0;
}