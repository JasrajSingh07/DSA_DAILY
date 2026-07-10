class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        int currtime=0;
        queue<pair<int,pair<int,char>>>q;
        priority_queue<pair<int,char>>pq;
        for(auto&p:mp){
            pq.push({p.second,p.first});
        }
        for(;!q.empty()||!pq.empty();currtime++){
            if(!q.empty()&&q.front().first==currtime){
                pq.push(q.front().second);
                q.pop();

            }
            if(!pq.empty()){
                auto p= pq.top();
                pq.pop();
                p.first--;
                if(p.first>0){
                int ready=currtime+n+1;
                q.push({ready,p});
                }
            }
        }
        return currtime;
    }
};