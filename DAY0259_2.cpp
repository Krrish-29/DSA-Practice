// 3767. Maximize Points After Choosing K Tasks
class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int size=technique1.size();
        vector<int>diff;
        long long count=0;
        for(int i=0;i<size;i++){
            if(technique1[i]>=technique2[i]){
                k--;
                count+=technique1[i];
            }
            else{
                count+=technique2[i];
                diff.push_back(technique2[i]-technique1[i]);
            }
        }
        sort(diff.begin(),diff.end());
        int i=0;
        while(k>0){
            count-=diff[i];
            i++;
            k--;
        }
        return count;
    }
};