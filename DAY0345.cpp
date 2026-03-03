// 3854. Minimum Operations to Make Array Parity Alternating
class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        if(nums.size()==1) return {0,0};
        int j;
        for(j=1;j<nums.size();j++){
            if(nums[j-1]!=nums[j]) break;
        }
        if(j==nums.size()) return {(int)nums.size()/2,1};
        int maxEle1=INT_MIN,minEle1=INT_MAX,odd=0;
        for(int i=0;i<nums.size();i++){
            if((i%2==0&&abs(nums[i])%2==0)||(i%2==1&&abs(nums[i])%2==1)){
                odd++;
                maxEle1=max({maxEle1,nums[i]-1});
                minEle1=min({minEle1,nums[i]+1});
            }
            else{
                maxEle1=max({maxEle1,nums[i]});
                minEle1=min({minEle1,nums[i]});
            }
        }
        int maxEle2=INT_MIN,minEle2=INT_MAX,even=0;
        for(int i=0;i<nums.size();i++){
            if((i%2==0&&abs(nums[i])%2==1)||(i%2==1&&abs(nums[i])%2==0)) {
                even++;
                maxEle2=max({maxEle2,nums[i]-1});
                minEle2=min({minEle2,nums[i]+1});
            }
            else{
                maxEle2=max({maxEle2,nums[i]});
                minEle2=min({minEle2,nums[i]});
            }
        }
        if(even==odd) {
            if((maxEle2-minEle2)>(maxEle1-minEle1)) return {odd,maxEle1-minEle1};
            else return {even,maxEle2-minEle2};
        }
        else if(even<odd) return {even,maxEle2-minEle2};
        return {odd,maxEle1-minEle1};
    }
};