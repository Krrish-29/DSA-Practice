// 4062. Transform Array Using Pair Operations
class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        // the main oberservation is that the operations performed
        // as source[i] + source[j] = source[i] + source[j] - delta + delta , leading to same sum
        // of the array so the problem boils down to if the sum of the both arrays is same
        // then there will a way to convert the source to target 
        long long sum=0;
        for(int &num:source) sum+=num;
        for(int &num:target) sum-=num;
        return sum == 0;
    }
};