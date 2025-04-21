// 2145. Count the Hidden Sequences
class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            long value=0,maximum=0,minimum=0;
            for(int i = 0;i<differences.size();i++){
                value+=differences[i];
                maximum=max(maximum,value);
                minimum=min(minimum,value);
            }
            return max(0L,upper-lower-maximum+minimum+1);
        }
    };