#include<iostream>
#include<vector>
using namespace std;
vector <int> stack;
int first=0;
void push(vector <int> &s, int a, int max){
    if(first!=0){
        first= first-1;
        stack[first]=a;
        return;
    }
   else {
    if(first==0 && stack.size()==max)
    cout<<"Stack is full, index out of bounds\n";
    else
    stack.push_back(a);
    return;
    }
}
void pop(){
    stack.pop_back();
}
int top(){
    if(stack.size()!=0) return stack[stack.size()-1];
    else 
    return 0;
}
int main(){
    int n;
    cout<<"Enter number of elements to be pushed onto stack";
    cin>>n;
    int m=n;
    while(n--){
        int item;
        cout<<"Enter item";
        cin>>item;
        push(stack,item,m);
    }
    bool y,x;
    cout<<"Do you want to delete top element? (1/0)";
    cin>>y;
    if(y==true) pop();
    int ele;
    cout<<"Do you want to push more elements? (1/0)";
    cin>>x;
    cout<<"enter element\n";
    cin>>ele;
    if(x==true) push(stack, ele,m);
    cout<<"Do you want to view top element?\n";
    cin>>y;
    if(y==true) cout<<top();
    cout<<"Final stack from top to bottom is:\n";
    for(int i= stack.size()-1;i>=first;i--)
        cout<<stack[i]<<"\t";
    
    return 0;
}