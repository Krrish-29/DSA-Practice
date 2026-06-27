// 3020. Find the Maximum Number of Elements in Subset
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // first get the freq of each elem in the nums using a ordered map
        // after that iterate over each elem at a time and handle few situations 
        // observation -> seq length will be odd
        // if we get 1 then make seq length odd and mark the seq complete and break out 
        // else we start with the number and check its freq if it is 2 or more then it can be used to increase the length of the seq by 2 , if we get the freq of a number a 1 then seq will need to be terminated , and if we get freq as 0 then any seq we already had would be always even length so decrease the length by 1.
        // after every round multiple number by itself and check if that number exists or has been seen to make it little faster
        map<long long,int>freq;
        for(int &num:nums) {
            freq[num]++;
        }

        unordered_set<long long>seen;
        int length=1,currLength;
        long long currNum;
        bool seqComplete=false;
        for(auto it=freq.begin();it!=freq.end();++it){
            currNum=(*it).first;
            currLength=0;
            seqComplete=false;
            while(freq.count(currNum)&&!seen.count(currNum)){
                seen.insert(currNum);
                if(currNum==1) {
                    if(freq[currNum]%2==0) currLength=freq[currNum]-1;
                    else currLength=freq[currNum];
                    seqComplete=true;
                    break;
                }
                else if(freq[currNum]>=2) {
                    currLength+=2;
                }
                else if(freq[currNum]>=1) {
                    currLength++;
                    seqComplete=true;
                    break;
                }
                else {
                    seqComplete=true;
                    currLength--;
                    break;
                }
                currNum*=currNum;
            }
            if(!seqComplete) currLength--;
            length=max(length,currLength);
        }
        return length;
    }
};