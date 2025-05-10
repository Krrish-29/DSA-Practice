// 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zero1=0,zero2=0;
        long long sum1=0,sum2=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]==0) zero1++;
            sum1+=nums1[i];
        }
        for(int i=0;i<nums2.size();i++){
            if(nums2[i]==0) zero2++;
            sum2+=nums2[i];
        }
        if((sum1>sum2&&zero2==0)||(sum2>sum1&&zero1==0)) return -1;
        sum1+=zero1,sum2+=zero2;
        if(sum1==sum2) return sum1;
        if(sum1>sum2&&sum2+(1LL*zero2*(INT_MAX-1))>=sum1||sum2>sum1&&sum1+(1LL*zero1*(INT_MAX-1))>=sum2) return max(sum1,sum2);
        return -1;
    }
};
//for time efficiency
// auto init = []() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return 'c';
// }();