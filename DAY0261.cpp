// 1925. Count Square Sum Triples
class Solution {
public:
    int countTriples(int n) {
        int count=0;
        for(int i=3;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int c=sqrt((i*i)+(j*j));
                if(c<=n&&(c*c)==(i*i)+(j*j)) count+=2;
            }
        }
        return count;
    }
};