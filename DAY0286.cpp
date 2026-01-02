// 1335. Minimum Difficulty of a Job Schedule
class Solution {
private:
    vector<vector<int>>dp;
    int maxDiff(vector<int>& jobDifficulty,int &size,int currDay,int currJob){
        int maxJob=jobDifficulty[currJob];
        if(currDay==1) {
            for(int i=currJob+1;i<size;i++){
                maxJob=max(maxJob,jobDifficulty[i]);
            }
            return maxJob;
        }
        if(dp[currJob][currDay]!=-1) return dp[currJob][currDay];
        int minSch=INT_MAX;
        for(int i=currJob;i<=size-currDay;i++){
            maxJob=max(maxJob,jobDifficulty[i]);
            int res=maxJob+maxDiff(jobDifficulty,size,currDay-1,i+1);
            minSch=min(minSch,res);
        }
        return dp[currJob][currDay]=minSch;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int size=jobDifficulty.size();
        dp.resize(size,vector<int>(d+1,-1));
        if(size<d) return -1;
        return maxDiff(jobDifficulty,size,d,0);
    }
};