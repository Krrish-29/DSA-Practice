// 2433. Find The Original Array of Prefix Xor
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        // xor is commutative and assosiative
        // doing x ^ y = z is same as doing x ^ z = y
        int size=pref.size(),totalXor=pref[0];
        for(int i=1;i<size;i++){
            pref[i] = totalXor^pref[i];
            totalXor^=pref[i];
        }
        return pref;
    }
};