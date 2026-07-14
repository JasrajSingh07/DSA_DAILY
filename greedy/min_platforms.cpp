class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        vector<pair<int,bool>>trains;
        for(int i=0;i<arr.size();i++){
            trains.push_back({arr[i],true});
            trains.push_back({dep[i],false});
        }
        sort(trains.begin(), trains.end(), [](const pair<int, bool>& a, const pair<int, bool>& b) {
            if (a.first != b.first)
                return a.first < b.first;   
            return a.second > b.second;     
        });        
        int act=0;
        int ans=0;
        for(int i=0;i<trains.size();i++){
            if(trains[i].second==true){
                act++;
            }
            else
                act--;
            ans=max(ans,act);
        }
        return ans;
    }
};