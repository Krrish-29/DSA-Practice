// 3397. Maximum Number of Distinct Elements After Operations
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int count=0,prev=INT_MIN;
        // map<int,int>map;
        // for(int num:nums){
        //     map[num]++;
        // }
        // for(auto x:map){
        //     for(int i=0;i<x.second;i++){
        //         if(x.first-k>=prev){
        //             count++;
        //             prev=x.first-k+1;
        //         }
        //         else if(x.first-k<prev&&x.first+k>=prev){
        //             count++;
        //             prev++;
        //         }
        //     }
        // }
        sort(nums.begin(),nums.end());
        for(int x:nums){
            if(x-k>=prev){
                count++;
                prev=x-k+1;
            }
            else if(x-k<prev&&x+k>=prev){
                count++;
                prev++;
            }
        }
        return count;
    }
};