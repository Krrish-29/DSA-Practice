// 1802. Maximum Value at a Given Index in a Bounded Array
class Solution {
private:
    long long calc(int len,int peak){
        if(peak>len){
            return (2*peak-len-1)*1LL*len/2;
        }
        return ((peak-1)*1LL*peak)/2+len-(peak-1);
    }
public:
    int maxValue(int n, int index, int maxSum) {
        int low=1,high=maxSum,mid;
        while(low<high){
            mid=low+(high-low+1)/2;
            long long minSum=calc(index,mid)+calc(n-index-1,mid)+mid;
            if(minSum<=maxSum) low=mid;
            else high=mid-1;
        }
        return low;
    }
};