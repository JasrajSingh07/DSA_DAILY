class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        vector<pair<int,pair<int,int>>>meet;
        for(int i=0;i<s.size();i++){
            meet.push_back({i+1,{s[i],f[i]}});
        }
        sort(meet.begin(),meet.end(),[](const auto& a,const auto& b ){
            return a.second.second<b.second.second;
        });
        vector<int>ans;
        int end=-1;
        for(int i=0;i<meet.size();i++ ){
            if(end<meet[i].second.first)
                {ans.push_back(meet[i].first);
                end=meet[i].second.second;}
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};