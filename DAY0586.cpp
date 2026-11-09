// 4093. Maximize Sum After At Most K Digit Rearrangements
class Solution {
private:
    // greadily arrange the digits of the number
    int rearrange(int num){
        vector<int>freq(10,0);
        while(num > 0){
            freq[num%10]++;
            num /= 10;
        }
        int reordered=0;
        for(int i=9;i>=0;i--){
            for(int j=0;j<freq[i];j++){
                reordered = reordered*10 + i;
            }
        }
        return reordered;
    }
public:
    long long maximizeSum(vector<int>& nums, int k) {
        // for each number get its digits sort them and use them 
        // or using freq array use the largest digits first 
        // each number will either be > 0 or 0 when taken difference with original and number arranged to get 
        // maximum therefor while processing the numbers we can add the number itself initally and store its diff 
        // with rearranged number in priority queue (minHeap) to keep only k numbers at max and then adding them at last
        // to improve time complexity since the numbers in pq will only be touched in last we can store them in normal vector and sort at last (descending) and use only k elements at max  
        // the logic for first adding the original number is that even if we consider a better arranged version of the
        // the number the diff b/w the two can be used to increment the original to make upto the better version
        // and to maximize the yield we store the diff and sort them allowing us to choose the best top k diff 
        // this allows us to use all numbers and also take advantage of better numbers (by taking diff) till k
        long long sum = 0;
        // priority_queue< int, vector<int>,greater<int> >minHeap;
        vector<int>maxDiff;
        int rearrangedNum;
        for(int &num: nums){
            sum += num;
            rearrangedNum = rearrange(num);
            maxDiff.push_back(rearrangedNum - num);
            // if((rearrangedNum - num) > 0){
            //     minHeap.push(rearrangedNum - num);
            //     if(minHeap.size() > k) {
            //         minHeap.pop();
            //     }
            // }
        }
        // while(!minHeap.empty()){
        //     sum += minHeap.top();
        //     minHeap.pop();
        // }
        sort(maxDiff.begin(),maxDiff.end(),[](const int&a,const int&b){
            return a > b;
        });
        for(int i = 0; i < k; i++) sum += maxDiff[i];
        return sum;
    }
};