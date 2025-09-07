// 1304. Find N Unique Integers Sum up to Zero
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>answer;
        for(int i=1;i<n/2+1;i++){
            answer.push_back(i);
            answer.push_back(-1*i);
        }
        if(n%2!=0)answer.push_back(0);
        return answer;
    }
};