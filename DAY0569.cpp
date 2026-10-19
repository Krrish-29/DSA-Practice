// 4078. Three Fibonacci Sum
class Solution {
public:
    bool threeFibonacciSum(int n) {
        int x=0,y=1,z=1; // simulate the sequence 
        while(x+y+z<=n){
            if(x+y+z == n) return true;
            x = y;
            y = z;
            z = x+y;
        }
        return false;
    }
};