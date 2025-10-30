// 1526. Minimum Number of Increments on Subarrays to Form a Target Array
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int size=target.size(),op=target[0];
        for(int i=1;i<size;i++){
            if(target[i]>=target[i-1]){
                op+=(target[i]-target[i-1]);
            }
        }
        return op;
    }
};