// 717. 1-bit and 2-bit Characters
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int size=bits.size(),i;
        for(i=0;i<size-1;i++){
            if(bits[i]==1) i++;
        }
        if(i==size) return false;
        return true;
    }
};