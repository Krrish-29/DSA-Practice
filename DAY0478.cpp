// 1291. Sequential Digits
class Solution {
private:
    vector<int>ans;
    void backTrack(int low,int high,int num){
        if(num>high) return ;
        if(low<=num&&num<=high) ans.push_back(num);
        int digit=num%10;
        if(digit==9) return ;
        backTrack(low,high,(num*10)+digit+1);
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        for(int i=1;i<=9;i++) backTrack(low,high,i);
        sort(ans.begin(),ans.end());
        return ans;
    }
};