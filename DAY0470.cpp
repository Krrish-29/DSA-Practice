// 3982. Sum of Integers with Maximum Digit Range
class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int sum=0,diff=0,largest,smallest,n;
        for(int &num:nums){
            largest=INT_MIN,smallest=INT_MAX;
            n=num;
            while(num>0){
                largest=max(largest,num%10);
                smallest=min(smallest,num%10);
                num/=10;
            }
            if(diff<(largest-smallest)){
                sum=n;
                diff=largest-smallest;
            }
            else if(diff==(largest-smallest)) sum+=n;
        }
        return sum;
    }
};