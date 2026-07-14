class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            return a[0]<b[0];
        });
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(ans.back()[1]>=intervals[i][0]){
                if(ans.back()[1]<intervals[i][1]){
                    vector<int>temp=ans.back();
                    ans.pop_back();
                    ans.push_back({temp[0],intervals[i][1]});
                }
            }
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};