// 3994. Minimum Adjacent Swaps to Partition Array
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        // simple thought was to convert the array into 3 sections of 0 1 and 2
        // 0 for elems less than a, 1 for elems b/w a and b and 2 for elems greater than b
        // for the swapping logic any 0 or 1 on the right of a 2 will cause a swap
        // and any 0 to the right of a 1 will cause a swap
        // this step is not necessary but makes q easy
        for(int &num:nums){
            if(num<a) num=0;
            else if(num>=a&&num<=b) num=1;
            else num=2;
        }
        // for counting swaps hint was to use inversion pairs
        // but we can use 3 pointers marking the count of of 0's 1's and 2's 
        // scanning from left to right everyzero will need to swapped with 1 and 2 we have seen so far
        // for 1 it will be swapped with number of 2
        long long count=0;
        int zero=0,one=0,two=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==2) two++;
            else if(nums[i]==1){
                count+=two;
                one++;
            }
            else{
                count+=(two+one);
                zero++;
            }
        }
        const int MOD = 1e9+7;
        return count%MOD;
    } 
};