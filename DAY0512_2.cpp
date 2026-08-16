// 137. Single Number II
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // based on decimal value we cannot do much rather than using a map 
        // in binary we can check 1 bit of all numbers and find if number of 1's are in multiple of 3 then all 
        // repeat numbers have 1 bit at that place and single number does not have 1 there
        // if not then the 1 bit corressponds to the single number 
        // for negative numbers i am ignoring 32 nd bit, and just counting negatives , although the counting is repeating
        // due to number of negative * 32 => causing so if the single number is negative then %3 will be ==1
        int singleNum=0,ones,negatives=0;
        for(int i=0;i<=31;i++){
            ones=0;
            for(int &num:nums){
                if(num<0) negatives++;
                if( (num & (1<<i)) != 0 ) ones++;
            }
            if((ones%3)==1){
                singleNum |= (1<<i);
            }
        }
        if((negatives%3)==1) return -1*singleNum;
        return singleNum;
    }
};