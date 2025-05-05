// 790. Domino and Tromino Tiling
class Solution {
    public:
        int numTilings(int n) {
            if(n<3) return n;
            long a=1,b=1,c=2;
            for(int i=0;i<=n-3;i++){
                long d=(2*c+a)%(int)(1e9+7);
                a=b;
                b=c;
                c=d;
            }
            return c%(int)(1e9+7);
        }
    };

// class Solution {
//     public:
//         int dynamic_recursive(vector<long>&arr,int n){
//             if(n==1) return 1;
//             if(n==2) return 2;
//             if(n==3) return 5;
//             if(arr[n]!=-1) return arr[n];
//             return arr[n]=(2L*dynamic_recursive(arr,n - 1)+dynamic_recursive(arr,n - 3))%(1000000007);
//         }
//         int numTilings(int n) {
//             vector<long>answer(n+1,-1);
//             return dynamic_recursive(answer,n);
//         }
//     };