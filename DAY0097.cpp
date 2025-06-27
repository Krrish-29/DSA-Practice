// 344. Reverse String
class Solution {
public:
    void reverseString(vector<char>& s) {
        int size=s.size();
        char temp;
        for(int i=0;i<size/2;i++){
            temp=s[i];
            s[i]=s[size-1-i];
            s[size-1-i]=temp;
        }
    }
};