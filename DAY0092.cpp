// 2928. Distribute Candies Among Children I
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int answer=0;
        for(int i=0;i<=min(limit,n);i++){
            answer+=max(min(limit, n-i) - max(0, n - i - limit) + 1,0);
        }
        return answer;
    }
};