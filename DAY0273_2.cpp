// 3780. Maximum Sum of Three Numbers Divisible by Three
class Solution {
    struct Greater { 
        bool operator()(const int& a, const int& b) const { 
            return a > b; 
        } 
    };
public:
    int maximumSum(vector<int>& nums) {
        vector<int>rem0,rem1,rem2;
        for(int num:nums){
            if(num%3==0) rem0.push_back(num);
            else if(num%3==1) rem1.push_back(num);
            else rem2.push_back(num);
        }
        sort(rem0.begin(),rem0.end(),Greater());
        sort(rem1.begin(),rem1.end(),Greater());
        sort(rem2.begin(),rem2.end(),Greater());
        int sum=0;
        if(rem2.size()>=3) sum=max(sum,rem2[0]+rem2[1]+rem2[2]);  
        if(rem1.size()>=3) sum=max(sum,rem1[0]+rem1[1]+rem1[2]);  
        if(rem0.size()>=3) sum=max(sum,rem0[0]+rem0[1]+rem0[2]);  
        if(rem2.size()>=1&&rem1.size()>=1&&rem0.size()>=1) sum=max(sum,rem2[0]+rem1[0]+rem0[0]);  
        return sum;
    }
};