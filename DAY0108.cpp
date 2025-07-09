// 1751. Maximum Number of Events That Can Be Attended II
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<int>next(n);
        for(int i=0;i<n;i++){
            int left=i+1,right=n,middle;
            while(left<right){
                middle=left+(right-left)/2;
                if(events[middle][0]>events[i][1]) right=middle;
                else left=middle+1;
            }
            next[i]=left;
        }
        vector<int>maximum(n+1);
        for(int i=0;i<k;i++){
            vector<int>curr(n+1);
            for(int j=n-1;j>=0;j--){
                curr[j]=max(curr[j+1],events[j][2]+(next[j]<n?maximum[next[j]]:0));
            }
            maximum=curr;
        }
        return maximum[0];
    }
};