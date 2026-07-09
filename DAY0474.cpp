// 3960. Frequency Balance Subarray
class Solution {
public:
    int getLength(vector<int>& nums) {
        // simple approach first key count of the freq of each number and at the same time keep a map of freq 
        // if a new elem is there then we make count of the num++ and freq[1] ++ 
        // if elem is seen then first store its prev count and decrease the freq[count]--
        // and if freq[count]==0 erase it to make it clean 
        // and then count of the num++ and as well as freq[count+1]++ since the freq of that elem is change from x to x+1 and we remove the record of x and add record of x+1 in the freq
        int size=nums.size();
        int length=0;
        for(int i=0;i<size;i++){
            unordered_map<int,int>count;
            unordered_map<int,int>freq;
            int freqOfCurrNum;
            for(int j=i;j<size;j++){
                freqOfCurrNum=count[nums[j]];
                if(freqOfCurrNum!=0){
                    freq[freqOfCurrNum]--;
                    if(freq[freqOfCurrNum]==0) freq.erase(freqOfCurrNum);
                } 
                count[nums[j]]++;
                freq[freqOfCurrNum+1]++;
                if(freq.size()==2){
                    int f1=max(freq.begin()->first,next(freq.begin())->first),f2=min(freq.begin()->first,next(freq.begin())->first);
                    if(f1==2*f2) length=max(length,j-i+1);
                }
                else if(freq.size()==1&&count.size()==1){
                    length=max(length,j-i+1);
                }
            }
        }
        return length;
    }
};