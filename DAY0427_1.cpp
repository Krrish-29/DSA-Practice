// 3936. Minimum Swaps to Move Zeros to End
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int size=nums.size();
        vector<int>temp=nums;
        sort(temp.begin(),temp.end(),[](const int &a,const int &b){
           return  a>b;
        });
        int count=0;
        for(int i=0;i<size;i++){
            if(nums[i]==0&&temp[i]!=0) count++;
        }
        return count;
    }
};