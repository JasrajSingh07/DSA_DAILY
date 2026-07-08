class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<=k;i++)
            pq.push(arr[i]);
        int i=0;
        for(;i+k+1<arr.size();i++){
            arr[i]=pq.top();
            pq.pop();
            pq.push(arr[i+k+1]);
        }
        while(!pq.empty()){
            arr[i++]=pq.top();
            pq.pop();
        }
    }   
    
}