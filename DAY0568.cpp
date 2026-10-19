// 1943. Describe the Painting
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        // mark the start and end of each segment with its paint value 
        // since we need to process the points in a sorted manner either sort or use map
        // then we need to iterate over these points if the sum currently is 0 then 
        // it means we have nothing in this segemnt so far and we can start from the current point with its paint value added
        // and anytime we see another point and our sum is not zero that means the curr segment value will change 
        // therefore we need to add the curr segment with its curr value sum and the segment is from previous starting point to
        // the curr point, and from the curr point there will be a new start and new sum till next time we reach a point
        // multiple points sharing start or end , do not need "S" or "E" marking as we are only concerned with intervals formed 
        // b/w points either they be 2 start/end/or both points and the intervals paint value 

        // for easier understanding consider that each segment has some contribution to paint value but only inside its interval
        // start with some point and any segemnt that is currently open contributes paint value to the total of the paint
        // and if the segment ends its paint value is reduced from the total, these changes of total values with starting and ending 
        // have to be returned 
        map<int,long long>map;   
        for(auto &segment:segments){
            map[segment[0]]+=segment[2];
            map[segment[1]]-=segment[2];
        }
        vector<vector<long long>>painting;
        long long currSum=0;
        int start=-1;
        for(auto &it:map){
            if(currSum == 0) {
                currSum+=it.second; 
                start = it.first;
            }
            else {
                painting.push_back({start,it.first,currSum});
                start = it.first; 
                currSum+=it.second;
            }
        }
        return painting;
    }
};