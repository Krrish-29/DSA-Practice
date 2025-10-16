// 2598. Smallest Missing Non-negative Integer After Operations
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int>hashtable(value,0);
        for(int num:nums){
            hashtable[(num%value+value)%value]++;
        }
        int i=0;
        while(hashtable[i%value]--!=0) i++;
        return i;
    }
};