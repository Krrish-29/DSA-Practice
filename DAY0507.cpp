// 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int size=nums.size(),sum=nums[0];
        for(int i=1;i<size;i++){
            if(nums[i]-nums[i-1]==1){
                sum+=nums[i];
            }
            else break;
        }
        set<int>set;
        for(int i=0;i<size;i++){
            set.insert(nums[i]);
        }
        if(!set.count(sum)) return sum;
        for(auto it=set.find(sum);it!=set.end();++it){
            auto it2=next(it);
            if(it2==set.end()) return sum+1;
            if(*it2-*it==1) sum++;
            else return sum+1;
        }
        return -1;
    }
};