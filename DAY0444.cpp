// 1953. Maximum Number of Weeks for Which You Can Work
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum=0,maxEle=0;
        for(int &mile:milestones) {
            sum+=mile;
            maxEle=max(maxEle,mile*1LL);
        }
        // if the longest project avail is bigger than all ther others combined then all the others will
        // get completed except the bigger one and we can padd its week at start and end to maximize the 
        // weeks therefore 2*rest+1 else if we can mix and match and complete all projects milestones.
        long long rest=sum-maxEle;
        if(maxEle>rest) return 2*rest+1;
        return sum;
    }
};