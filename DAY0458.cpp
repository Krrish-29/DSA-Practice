// 3969. Valid Subarrays With Matching Sum Digits I
class Solution {
private:
    bool check(long long sum,int &x){
        int last=sum%10;
        while(sum>9){
            sum/=10;
        }
        int first=sum%10;
        if(first==x&&last==x) return true;
        return false;
    }
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int size=nums.size(),count=0;
        long long sum=0;
        for(int i=0;i<size;i++){
            sum=0;
            for(int j=i;j<size;j++){
                sum+=nums[j];
                if(check(sum,x)) count++;
            }
        }
        return count;
    }
};