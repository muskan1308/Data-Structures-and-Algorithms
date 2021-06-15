#include<iostream>
#include<stack>
using namespace std;
struct Node{
    int data;
    struct Node *next;
};

void append(Node **head, int data){
    Node *node = new Node();
    Node * ptr= *head;
    node->data= data;
    node->next=NULL;
    if(*head==NULL) *head= node;   
    else{
        while(ptr->next!=NULL) ptr=ptr->next;
        ptr->next=node;
    }
}
void printLinkedList(Node *head){
    while(head!=NULL) {
        cout<<head->data<<"  ";
        head=head->next;
    }
}

bool checkPalindrome(Node *head){
    int count=0;
    stack <int> st;
    Node *ptr=head;
    while(ptr!=NULL){
        st.push(ptr->data);
        ptr= ptr->next;
    }
    while(!st.empty() && head!=NULL){
        int x= st.top();
        st.pop();
        if(x!=head->data) return false;
        head=head->next;
    }
    return true;

}

int main(){
    int n=0;
    cout<<"Enter number of nodes in the Linked List\n";
    cin>>n;
    Node *head= NULL;
    while(n--){
        int t;
        cout<<"Enter node data\t";
        cin>>t;
        append(&head, t);
    }
    cout<<"LL is:\n";
    printLinkedList(head);
    
    bool ans= checkPalindrome(head);
    if(ans==true) cout<<"Linked List is a Palindrome\n";
    else
    cout<<"Linked List is not a Palindrome\n";

    return 0;
}