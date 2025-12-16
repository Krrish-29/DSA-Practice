// 2110. Number of Smooth Descent Periods of a Stock
class Solution {
public:
    long long getDescentPeriods(vector<int>& descent) {
        long long descents=0;
        int size=descent.size(),len=1;
        for(int i=1;i<size;i++){
            if(descent[i-1]-descent[i]==1) len++;
            else {
                descents=descents+(len*1LL*(len+1))/2;
                len=1;
            }
        }
        return descents+(len*1LL*(len+1))/2;
    }
};