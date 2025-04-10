// 62. Unique Paths
class Solution {
    public:
        int uniquePaths(int m, double n) {
            int j=m-1>n-1?n-1:m-1;
            m+=(n-2);
            n=1;
            while(j>=1){
                n*=(m/double(j));
                m--;
                j--;
            }
            return round(n);
        }
    };