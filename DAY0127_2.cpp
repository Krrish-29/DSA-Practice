// 274. H-Index
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int index=0,size=citations.size();
        sort(citations.begin(),citations.end());
        for(int i=size-1;i>=0;i--){
            if(citations[i]!=0&&index<citations[i]){
                index++;  
            }
        }
        return index;
    }
};