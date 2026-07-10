/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
    struct compare{
        bool operator()(Node* a,Node* b){
            if(a->data>b->data)
                return true;
            else return false;
            
        }  
    };
    priority_queue<Node*,vector<Node*>,compare>pq;
    for(int i=0;i<arr.size();i++)
        if(arr[i])
            pq.push(arr[i]);
    Node* dummy= new Node(0);
    Node *curr=dummy;
    Node* prev=nullptr;
    Node* temp=nullptr;
    while(!pq.empty()){
        temp=pq.top();
        curr->next=temp;
        prev=curr;
        curr=curr->next;
        pq.pop();
        if(temp->next)
            pq.push(temp->next);
        
    }
    if(temp)
        temp->next=nullptr;
    return dummy->next;
    }
};