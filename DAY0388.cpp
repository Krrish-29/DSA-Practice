// 2463. Minimum Total Distance Traveled
class Solution {
private:
    struct hash{
        size_t operator()(const tuple<int,int,int>&a) const {
            return (get<0>(a)*31*31)^(get<1>(a)*31)^get<2>(a);
        }
    };
    unordered_map<tuple<int,int,int>,long long,hash>dp;
    long long helper(vector<int>& robot, vector<vector<int>>& factory,int i,int j,int currLimit){
        if(i>=robot.size()) return 0;
        if(j>=factory.size()) return LLONG_MAX/100;
        auto key=make_tuple(i,j,currLimit);
        if(dp.count(key)) return dp[key];
        long long dist=LLONG_MAX;
        dist=min(dist,helper(robot,factory,i,j+1,0));
        if(currLimit<factory[j][1]){
            currLimit++;
            dist=min(dist,abs(robot[i]-factory[j][0])+helper(robot,factory,i+1,j,currLimit));
        }
        return dp[key]=dist;
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        int robotSize=robot.size(),factorySize=factory.size();
        return helper(robot,factory,0,0,0);
    }
};