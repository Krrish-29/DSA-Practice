// 2048. Next Greater Numerically Balanced Number
class Solution {
private:
    vector<int>nums={0,1,2,3,4,5,6,7};
    int backTrack(int n,int curr,int size){
        if(size==0){
            for(int i=1;i<=7;i++){
                if(nums[i]!=0&&nums[i]!=i) return 0;
            }
            if(curr>n) return curr;
            else return 0;
        }
        int res=0;
        for(int i=1;i<=7;i++){
            if(nums[i]>0&&size>=nums[i]){
                nums[i]--;
                res=backTrack(n,curr*10+i,size-1);
                nums[i]++;
            }
            if(res!=0) break;
        }
        return res;
    }
public:
    int nextBeautifulNumber(int n) {
        int ans=0;
        ans=backTrack(n,0,to_string(n).size());
        if(ans==0) ans=backTrack(n,0,to_string(n).size()+1);
        return ans;
    }
};