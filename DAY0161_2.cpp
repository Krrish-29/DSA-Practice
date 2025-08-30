// 3663. Find The Least Frequent Digit
class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string nums=to_string(n);
        int size=nums.size(),least=-1;
        vector<int>hashmap(10,0);
        for(char num:nums) hashmap[num-48]++;
        for(int i=0;i<10;i++){
            if(hashmap[i]!=0&&(least==-1||hashmap[i]<hashmap[least])) least=i;
        }
        return least;
    }
};