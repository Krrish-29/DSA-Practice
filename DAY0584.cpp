// 1124. Longest Well-Performing Interval
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        // a simple solution of the problem is brute force with 2 loops to check all ranges to get max
        // where count tiring and non tiring days and check interval with tiring days are more than non tiring days 
        // to get the max size interval

        // for optimized solution, the problem feels like sliding window but its not cause sliding window cannot
        // maximize the range/length of the interval it can help in finding the max value interval 
        // therefore to maximize the interval we to use a map to store the occurence to events with index
        // so that if in future we find a similar event.
        // first convert the hours > 8 to +1 and < 8 to -1 since numbers have no meaning 
        // we need +1 more than -1 in the interval
        // then traverse over this array while maintain a totalsum which if is ever > 0
        // means that the whole interval till the current number is good and can be taken (as it will be the longest)
        // else we try to find the sum-1 in the map if not found we add it
        // if found then we take difference b/w i - map[sum-1]
        // the reason of sum - 1 is, example take sum as -4 if we had seen -5 earlier that means
        // there had to be one and the point where we had -5 is before +1 so to find interval length
        // subtract current index - map[sum-1]


        // brute force
        // int size = hours.size();
        // int maxLen = 0,tiring,nonTiring;
        // for(int i = 0; i < size; i++){
        //     tiring = 0;
        //     nonTiring = 0;
        //     for(int j = i; j < size; j++){
        //         if(hours[j] > 8) tiring++;
        //         else nonTiring++;
        //         if(tiring > nonTiring) maxLen = max( maxLen, tiring + nonTiring);
        //     }
        // }
        // return maxLen;

        // optimized 
        int size = hours.size();
        int maxLen = 0,currSum = 0;
        unordered_map<int,int>seen; // value , index
        for(int i = 0; i < size; i++){
            if(hours[i] > 8) hours[i] = +1;
            else hours[i] = -1;
            currSum += hours[i];
            if(currSum > 0) maxLen = i+1;
            else{
                if(seen.count(currSum-1)){
                    maxLen = max(maxLen, i - seen[currSum-1]);
                }
                if(!seen.count(currSum)){
                    seen[currSum] = i;
                }
            }
        }
        return maxLen;
    }
};