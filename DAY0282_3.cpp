// 3761. Minimum Absolute Distance Between Mirror Pairs
class Solution {
private:
    int reverseNum(int num){
        bool flag=false;
        int revNum=0;
        while(num>0){
            if(num%10!=0||flag){
                flag=true;
                revNum=revNum*10+num%10;
            }
            num/=10;
        }
        return revNum;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>map;
        int dist=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i])!=map.end()) dist=min(dist,i-map[nums[i]]);
            map[reverseNum(nums[i])]=i;
        }
        return dist==INT_MAX?-1:dist;
    }
};