class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows=mat.size();
        int n=mat[0].size();
        int l=0;
        int h=n-1;
        while(h>=l){
            int m=l+(h-l)/2;
            int midx;
            for(int i=0,max=INT_MIN;i<rows;i++){
                if(mat[i][m]>max){
                    max=mat[i][m];
                    midx=i;
                }
            }
            if(mat[midx][m]>(m-1>=0?mat[midx][m-1]:INT_MIN)&&mat[midx][m]>(m+1<n?mat[midx][m+1]:INT_MIN))
                return {midx,m};
            else if(mat[midx][m]<mat[midx][m-1])
                h=m-1;
            else
                l=m+1;
        }
        return {};
    }
};