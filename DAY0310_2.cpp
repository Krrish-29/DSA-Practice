// 3510. Minimum Pair Removal to Sort Array II
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        vector<long long>temp(nums.begin(),nums.end());
        set<pair<long long,int>>set;
        int badPairs=0,size=temp.size();
        for(int i=1;i<size;i++){
            set.insert({temp[i-1]+temp[i],i-1});
            if(temp[i-1]>temp[i]) badPairs++;
        }
        vector<int>nextIdx(size),prevIdx(size);
        for(int i=0;i<size;i++){
            nextIdx[i]=i+1;
            prevIdx[i]=i-1;
        }
        int op=0;
        while(badPairs!=0){
            int first = set.begin()->second;
            set.erase(set.begin());
            int second=nextIdx[first];
            int first_left=prevIdx[first];
            int second_right=nextIdx[second];
            if(temp[first]>temp[second]) badPairs--;
            if(first_left>=0){
                if(temp[first_left]>temp[first]&&temp[first_left]<=temp[first]+temp[second]) badPairs--;
                else if(temp[first_left]<=temp[first]&&temp[first_left]>temp[first]+temp[second]) badPairs++;
            }
            if(second_right<size){
                if(temp[second]<=temp[second_right]&&temp[first]+temp[second]>temp[second_right]) badPairs++;
                else if(temp[second]>temp[second_right]&&temp[first]+temp[second]<=temp[second_right]) badPairs--;
            }
            if(first_left>=0){
                set.erase({temp[first_left]+temp[first],first_left});
                set.insert({temp[first_left]+temp[first]+temp[second],first_left});
            }
            if(second_right<size){
                set.erase({temp[second]+temp[second_right],second});
                set.insert({temp[first]+temp[second]+temp[second_right],first});
                prevIdx[second_right]=first;
            }
            nextIdx[first]=second_right;
            temp[first]+=temp[second];
            op++;
        }
        return op;
    }
};