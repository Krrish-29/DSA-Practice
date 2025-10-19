// 3718. Smallest Missing Multiple of K
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int>table(100/k,0);
        for(int num:nums){
            if(num%k==0) table[num/k-1]++;
        }
        for(int i=0;i<100/k;i++){
            if(table[i]==0) return (i+1)*k;
        }
        return k*(100/k)+k;
    }
};