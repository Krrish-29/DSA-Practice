// 3513. Number of Unique XOR Triplets I
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // this question has one trick 
        // 2^x = n and find x ceil , all numbers in that range of 0 to 2^x can be generated if n falls in range 0 to 2^ceil(x)
        int n=nums.size();
        if(n<=2) return n;
        int highestPower=0;
        while(n>0){
            n/=2;
            highestPower++;
        }
        return pow(2,highestPower);
    }
};