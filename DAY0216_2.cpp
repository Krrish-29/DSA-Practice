// 1679. Max Number of K-Sum Pairs
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int num:nums) freq[num]++;
        int count=0;
        for(auto p:freq){
            if(p.first>=k||p.second==0) continue;
            //check each element and accordingly decrement freq
            // if(k==2*p.first) {
            //     count+=(p.second/2);
            //     freq[p.first]=(p.second/2);
            // }
            // else{
            //     if(freq.find(k-p.first)!=freq.end()&&freq[k-p.first]>0){
            //         int minVal=min(freq[k-p.first],p.second);
            //         freq[k-p.first]-=minVal;
            //         freq[p.first]-=minVal;
            //         count+=minVal;
            //     }
            // }

            // check each element only once and do not check previous elements
            if(k-p.first==p.first){
                count+=(p.second/2);
            }
            else if(freq.find(k-p.first)!=freq.end()&&k-p.first>p.first){
                count+=min(freq[k-p.first],p.second);
            }
        }
        return count;
    }
};