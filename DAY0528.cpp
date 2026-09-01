// 1073. Adding Two Negabinary Numbers
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        // not an easy one , the main logic is
        // we start from right to left adding the bits of arr1 and arr2 with carry 
        // with carry begin 1 ,0 or -1 , if the sum is less than 0 then the carry will be 1
        // if sum is 0 or 1 then no carry , carry = 0
        // if sum is more than 1 then carry becomes -1
        // after all this apply same logic to the carry left if it is
        // also remove leading zeros , and reverse the ans
        if(arr1.size()<arr2.size()) return addNegabinary(arr2,arr1);
        int i=arr1.size()-1,j=arr2.size()-1;
        vector<int>ans;
        int bit1,bit2,sum;
        int carry=0;
        while(i>=0){
            bit1 = i>=0?arr1[i--]:0;
            bit2 = j>=0?arr2[j--]:0;
            sum = bit1+bit2+carry;
            if(sum<0) carry=1;
            else if(sum>1) carry = -1;
            else carry=0;
            ans.push_back(abs(sum%2));
        }
        while(carry!=0){
            sum = carry;
            if(sum<0) carry=1;
            else if(sum>1) carry = -1;
            else carry=0;
            ans.push_back(abs(sum%2));
        }
        while(ans.back()==0&&ans.size()>1) ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};