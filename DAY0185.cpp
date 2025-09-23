// 165. Compare Version Numbers
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int size1=version1.size(),size2=version2.size();
        int i=0,j=0;
        long v1,v2;
        while(i<size1&&j<size2){
            v1=0;v2=0;
            while(i<size1&&version1[i]!='.'&&version1[i]=='0') i++;
            while(i<size1&&version1[i]!='.'){
                v1=(v1*10+version1[i]-'0');
                i++;
            }
            while(j<size2&&version2[j]!='.'&&version2[j]=='0') j++;
            while(j<size2&&version2[j]!='.'){
                v2=(v2*10+version2[j]-'0');
                j++;
            }
            i++;
            j++;
            if(v1<v2) return -1;
            else if(v1>v2) return 1;
        }
        while(i<size1){
            if(version1[i]!='.'&&version1[i]!='0') return 1;
            i++;
        }
        while(j<size2){
            if(version2[j]!='.'&&version2[j]!='0') return -1;
            j++;
        }
        return 0;
    }
};