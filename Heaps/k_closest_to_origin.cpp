class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>pq;
        for(int i=0;i<k;i++){
            int distance=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push({distance,points[i]});
            
        }
        for(int i=k;i<points.size();i++){
            int distance=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            if(pq.top().first>distance){
                pq.pop();
                pq.push({distance,points[i]});
            }
            
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};