// 66. Plus One
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size=digits.size()-1,carry=1;
        for(int i=size;i>=0;i--){
            digits[i]+=carry;
            if(digits[i]<=9) return digits;
            digits[i]=0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};