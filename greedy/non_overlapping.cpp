class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>a,const vector<int>b){
            return a[1]<b[1];
        });
        int ans=0;
        int end=INT_MIN;
        for(int i=0;i<intervals.size();i++){
            if(end<=intervals[i][0])
                {ans++;
                end=intervals[i][1];}
        }
        return intervals.size()-ans;
    }
};