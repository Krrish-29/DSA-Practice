// 3024. Type of Triangle
class Solution {
public:
    string triangleType(vector<int>& nums) {
        // if(!(nums[0]+nums[1]>nums[2]&&nums[0]+nums[2]>nums[1]&&nums[1]+nums[2]>nums[0])) return "none";
        // string answer;
        // int equality =0;
        // for(int i=0;i<3;i++){
        //     for(int j=i+1;j<3;j++){
        //         if(nums[i]==nums[j]) equality++;
        //     }
        // }
        // if(equality==3) answer="equilateral";
        // if(equality==1) answer="isosceles";
        // if(equality==0) answer="scalene";
        // return answer;
        
        if(!(nums[0]+nums[1]>nums[2]&&nums[0]+nums[2]>nums[1]&&nums[1]+nums[2]>nums[0])) return "none";
        if(nums[0]==nums[1]&&nums[1]==nums[2]) return "equilateral";
        if((nums[0]==nums[1]&&nums[1]!=nums[2])||(nums[0]==nums[2]&&nums[1]!=nums[2])|(nums[1]==nums[2]&&nums[0]!=nums[1])) return "isosceles";
        else return "scalene";
    }
};