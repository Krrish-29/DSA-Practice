// 3993. Maximum Value of an Alternating Sequence
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        // two options start with s and add m to s to create a diff of <=m b/w the nums and then to alternate 
        // decrease by 1 to maximize the maximum elem 
        // options to start with s decrease by 1 and then increase by m again to maximize 
        // this can be done greedily in seq of even length since the last elem will be maximum with any option 
        // but in odd seq length the last elem will be less by 1 due to alternating nature to mitigate that reduce the length by 1
        // now for calculations starting from s to maximum elem we will have n/2 ups and n-1/2 downs 
        if(n%2==1) n--;
        return ((n/2)*1LL*m)-((n-1)/2)+s;
    }
};