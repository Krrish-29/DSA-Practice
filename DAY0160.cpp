// 3021. Alice and Bob Playing Flower Game
class Solution {
public:
    long long flowerGame(int n, int m) {
        // 1 to n n+1/2 odd
        // n/2 even 
        // 1 to m m+1/2 odd
        // m/2 even
        // odd in one and even in another the alice wins
        return ((m+1LL)/2)*(n/2)+((n+1LL)/2)*(m/2);
    }
};