// 2333. Minimum Sum of Squared Difference
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        // we need square of (nums1[i]-nums2[i]) , therefore we can use difference as absoulte value 
        // since -ve doesnt matter due to square
        // now what we need to do is to change these numbers so that the difference is minimized and the total sum as well
        // say if we +1 nums1[i] or -1 nums2[i] they do the same impact, and same when using -1 for nums1[i] and +1 for nums2[i]
        // therefore we can use either of k1 on nums1 and k2 on nums2 to do same work, we can combine k1+k2 to know how many 
        // operations can we perform in total on the numbers 
        // now we need to store each difference (absolute value) and its freq 
        // so that the highest difference can be reduced to make the highest impact with the same number of operations than
        // a smaller differences we have, the freq is useful as when reducing we cannot bindly reduce the difference to 0 
        // as when the curr diff we are reducing reaches a certain point then other differences can offer better value with same
        // amount of operations therefore we to use operations in an optimized manner we can reduce the highest diff to the 
        // second highest difference, and keep on doing it till we are out of operations or the difference aren't left to reduce 
        // and there can be a case where we have x amount of difference but only y (y<x) can be reduced with the operations left
        // that is why we need freq, freq * top1-top2 is amount of operations required to reduce the current diff to the second
        // largest diff, top1 -= (diff/freq); tells how much the top1 will be reduced to, either it will be top2 or somewhere before it
        // due to lack of operations in which we might have some diffs not being able to reduce to even that value 
        // and else reduce to top-1 that amount can be known from rem = diff%freq; 
        map<int,int,greater<int>>map; // abs diff, freq
        long long ans=0;
        int size = nums1.size();
        for(int i=0;i<size;i++){
            map[abs(nums1[i]-nums2[i])]++;
        }
        int k = k1+k2;
        int top1,freq,top2,rem;
        long long diff;
        while(k>0){
            top1 = map.begin()->first;
            if(top1==0) break; // all difference are now 0 
            freq = map.begin()->second;
            map.erase(top1);

            if(!map.empty()) top2 = map.begin()->first;
            else top2=0;

            diff = min(freq*1LL*(top1-top2),1LL*k);

            top1 -= (diff/freq); // reduced value of the diff after applying operations 

            rem = diff%freq; // diff's that couldn't be reduced to top1
            map[top1] += freq - rem; // how many reduced to top1
            if(rem) map[top1-1]+=rem; // how many couldn't be exactly reduced to top1
            k-=diff; // operations left
        }
        for(auto &it:map){
            ans+= (it.second)*1LL*(it.first)*(it.first);
        }
        return ans;
    }
};