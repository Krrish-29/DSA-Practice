// 3304. Find the K-th Character in String Game I
class Solution {
public:
    char recursion(string s,int size ,int k){
        for(int i=0;i<size;i++){
            s+=((char)s[i]+1);
        }
        if(size>k){
            return s[k];
        }
        return recursion(s,size*2,k);
    }
    char kthCharacter(int k) {
        return recursion("a",1,k-1);
    }
};