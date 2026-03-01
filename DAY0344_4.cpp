// 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
class Solution {
public:
    int minPartitions(string n) {
        int maxEle=0;
        for(char &c:n){
            if(maxEle<c-'0') maxEle=c-'0';
        }
        return maxEle;
    }
};