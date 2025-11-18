// 3724. Minimum Operations to Transform Array
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long count=0;
        int size=nums1.size();
        int diff=INT_MAX;
        bool flag=false;
        for(int i=0;i<size;i++){
            count+=abs(nums2[i]-nums1[i]);
            if((nums1[i]<=nums2[size]&&nums2[i]>=nums2[size])||(nums1[i]>=nums2[size]&&nums2[i]<=nums2[size])) flag=true;
            diff=min({diff,abs(nums1[i]-nums2[size]),abs(nums2[i]-nums2[size])});
        }
        if(flag) return count+1;
        return count+1+diff;
    }
};