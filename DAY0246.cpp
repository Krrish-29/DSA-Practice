// 1262. Greatest Sum Divisible by Three
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int ans=0;
        // vector<int>rem1,rem2;
        // for(int num:nums) {
        //     ans+=num;
        //     if(num%3==1) rem1.push_back(num);
        //     if(num%3==2) rem2.push_back(num);
        // }
        // if(ans%3==0) return ans;
        // if(ans%3==1){
        //     ans=max((rem1.size()>0?ans-rem1[0]:INT_MIN),(rem2.size()>1?ans-(rem2[0]+rem2[1]):INT_MIN));
        // }
        // else{
        //     ans=max((rem2.size()>0?ans-rem2[0]:INT_MIN),(rem1.size()>1?ans-(rem1[0]+rem1[1]):INT_MIN));
        // }
        // return ans;

        int ans=0;
        int rem1s1=INT_MAX,rem1s2=INT_MAX,rem2s1=INT_MAX,rem2s2=INT_MAX;
        for(int num:nums) {
            ans+=num;
            if(num%3==1) {
                if(num<rem1s1){
                    rem1s2=rem1s1;
                    rem1s1=num;
                }
                else if(num<rem1s2){
                    rem1s2=num;
                }
            }
            else if(num%3==2) {
                if(num<rem2s1){
                    rem2s2=rem2s1;
                    rem2s1=num;
                }
                else if(num<rem2s2){
                    rem2s2=num;
                }
            }
        }
        if(ans%3==1){
            ans=max(rem1s1==INT_MAX?INT_MIN:ans-rem1s1,rem2s1!=INT_MAX&&rem2s2!=INT_MAX?ans-(rem2s1+rem2s2):INT_MIN);
        }  
        else if(ans%3==2){
            ans=max(rem2s1==INT_MAX?INT_MIN:ans-rem2s1,rem1s1!=INT_MAX&&rem1s2!=INT_MAX?ans-(rem1s1+rem1s2):INT_MIN);
        }
        return ans;
    }
};