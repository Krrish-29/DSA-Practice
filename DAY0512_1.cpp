// 1356. Sort Integers by The Number of 1 Bits
class Solution {
public:
    int bits(int &num){
        int setBits=0;
        for(int i=0;i<=31;i++){
            if( (num & (1<<i)) !=0 ) setBits++;
        }
        return setBits;
    }
    vector<int> sortByBits(vector<int>& arr) {
        // store all nums in a 2d vector acc to their setbit count and sort before starting so that all nums are in 
        // sorted manner to they can be accessed in a simple order
        // vector<vector<int>>bitMap(32);
        // sort(arr.begin(),arr.end());
        // for(int &num:arr){
        //     bitMap[bits(num)].push_back(num);
        // }
        // arr={};
        // for(auto &vec:bitMap){
        //     for(int &num:vec){
        //         arr.push_back(num);
        //     }
        // }
        // return arr;
        
        // sort using lambda using setbit count 
        sort(arr.begin(),arr.end(),[&](int &a,int &b) {
            if(bits(a) == bits(b)) return a<b;
            return bits(a) < bits(b);
        });
        return arr;
    }
};