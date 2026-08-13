// 89. Gray Code
class Solution {
public:
    int getGreyCode(int num){
        return num ^ (num >> 1);
    }
    vector<int> grayCode(int n) {
        vector<int>ans;
        n = pow(2,n);
        for(int i=0;i<n;i++){
            ans.push_back(getGreyCode(i));
        }
        return ans;
    }
};