// 3723. Maximize Sum of Squares of Digits
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans;
        int maxNum=0;
        if(sum>9*num) return "";
        for(int i=0;i<num;i++){
            if(sum>=9){
                sum-=9;
                ans.push_back('9');
            }
            else{
                ans.push_back(sum+'0');
                sum-=sum;
            }
        }
        return ans;
    }
};