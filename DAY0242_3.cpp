// 3746. Minimum String Length After Balanced Removals
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a=0,b=0,size=s.size();
        for(char ch:s){
            if(ch=='a') a++;
            else b++;
        }
        return size-2*min(a,b);
    }
};