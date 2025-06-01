// 2929. Distribute Candies Among Children II
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long answer=0;
        for(int i=0;i<=min(limit, n);i++){
            answer+=max(min(limit, n - i) - max(0, n - i - limit) + 1, 0);
        }      
        return answer;
    }
};