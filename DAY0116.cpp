// 3201. Find the Maximum Length of Valid Subsequence I
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0,odd=0,size=nums.size();
        // int odd_even=0,even_odd=0;
        int alternate=1,previous=nums[0];
        for(int num=0;num<size;num++){
            if(nums[num]%2==0){
                even++;
                // odd_even=max(odd_even,even_odd+1);
            }
            else{
                odd++;
                // even_odd=max(even_odd,odd_even+1);
            } 
            if(num>0&&nums[num]%2!=previous%2){
                alternate++;
                previous=nums[num];
            }
        }
        // return max({even,odd,even_odd,odd_even});
        return max({even,odd,alternate});
    }
};