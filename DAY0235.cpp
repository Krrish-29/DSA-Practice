// 2654. Minimum Number of Operations to Make All Array Elements Equal to 1
class Solution {
int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
public:
    int minOperations(vector<int>& nums) {
        int ones=0;
        for(int num:nums) if(num==1) ones++;
        if(ones>0) return nums.size()-ones;


        int size=nums.size(),minSize=INT_MAX;
        for(int i=0;i<size;i++){
            int g=nums[i];
            for(int j=i;j<size;j++){
                g=gcd(g,nums[j]);
                if(g==1) {
                    minSize=min(minSize,j-i);
                    break;
                }
            }
        }
        if(minSize==INT_MAX) return -1;
        return size+minSize-1;
    }
};