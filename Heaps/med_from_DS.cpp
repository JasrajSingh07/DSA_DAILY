class MedianFinder {
private:
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int max=maxh.size();
        int min=minh.size();
        if(max==0){
            maxh.push(num);
            return;
            }
        int maxt=maxh.top();
        int mint=min!=0?minh.top():0;
        if(max>min){
            if(num>maxt)
                minh.push(num);
            else{
                int temp=maxh.top();
                maxh.pop();
                minh.push(temp);
                maxh.push(num);
            }
        }
        else{
            if(num<mint)
                maxh.push(num);
            else{
                int temp=minh.top();
                minh.pop();
                maxh.push(temp);
                minh.push(num);
            }
        }
    }
    
    double findMedian() {
        int max=maxh.size();
        int min=minh.size();
        if(max==min){
            return ((double)maxh.top()+(double)minh.top())/2;
        }
        else
            return maxh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */