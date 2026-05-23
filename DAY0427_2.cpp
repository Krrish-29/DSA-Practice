// 3937. Minimum Operations to Make Array Modulo Alternating I
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int size=nums.size(),count=INT_MAX;
        for(int x=0;x<k;x++){
            for(int y=0;y<k;y++){
                if(x==y) continue;
                int currCount=0;
                for(int i=0;i<size;i++){
                    int rem=(nums[i]%k);
                    if(i%2==0){
                       currCount+=min((x-rem+k)%k,(rem-x+k)%k);
                    }
                    else{
                       currCount+=min((y-rem+k)%k,(rem-y+k)%k);
                    }
                }
                count=min(count,currCount);
            }
        }
        return count;
    }
};