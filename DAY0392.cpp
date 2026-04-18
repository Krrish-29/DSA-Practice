// 567. Permutation in String
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>map1(26,0),map2(26,0);
        int size1=s1.size(),size2=s2.size();
        if(size1>size2) return false;
        for(int i=0;i<size1;i++) {
            map1[s1[i]-'a']++;
            map2[s2[i]-'a']++;
        }
        if(map1==map2) return true;
        for(int i=size1;i<size2;i++){
            map2[s2[i-size1]-'a']--;
            map2[s2[i]-'a']++;
            bool flag=true;
            for(int j=0;j<26;j++){
                if(map1[j]!=0&&map1[j]!=map2[j]) flag=false;
            }
            if(flag) return true;
        }
        return false;
    }
};