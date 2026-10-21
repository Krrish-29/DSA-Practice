// 4007. Widest Possible Fence
class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        // the problem states that we can use a plank individually or combine it with others to make new planks
        // and at last what we want is to have a plank with maximum count (frequency) 
        // also each individual plank can be used only once 
        // so we start with a simple mapping for planks to get the idea of which planks appear the most without any combining
        // now we can combine these planks as well , either we stack 2 of same plank to ceate a new or
        // combine two different , if we combine 2 of same then the total of this new plank will be half of the original planks frequency
        // and for different planks we will be able to get the minimum of the 2 planks frequency
        // now these new combinations as well as original planks are the only possible planks we can have so we can find max of frequency from them.

        // orignal idea was to use a sorted freq map to get the planks and freq 
        // and then find how many more of a particular plank we can have starting with one and trying smaller planks than it 
        // to make it upto the required plank , but the only issue is when we might need a plank combination that was not in 
        // original planks, and might require combining other pairs as well 

        // therefore use a simple map to mark the original plank and create a new map for combinations 
        // which will also contain the original planks as well 
        // also either we can use ordered maps and then use a simple plank1 < plank2 condition to verify that we are not 
        // making same combination with same planks twice 
        // or use a seen set and simply check if a seen plank is seen again for plank2 or not
        // we can also use sorted maps and use plank1 < plank2 instead of seen set , cause the first plank would make combination with all other planks 
        // and the next plank will make combinations with planks greater than it, allowing for skipping repeated combinations (with previous) as well as wrong self combinations

        // time O(n^2) , space O(n^2)

        unordered_map<int,int>originalPlanks; // plank , freq
        int size = planks.size();
        for(int i=0;i<size;i++){
            originalPlanks[planks[i]]++;
        }
        unordered_map<int,int>planksComb = originalPlanks; // new plank combinations , freq
        unordered_set<int>seen;
        for(auto & plank1 : originalPlanks){
            planksComb[2*plank1.first] += plank1.second/2; // same plank doubled 
            seen.insert(plank1.first);
            for(auto & plank2 : originalPlanks){
                if(seen.count(plank2.first)) continue;
                planksComb[plank1.first + plank2.first] += min(plank1.second,plank2.second);
            }
        }
        int maxWidth=0;
        for(auto &newPlank:planksComb){
            maxWidth = max(maxWidth,newPlank.second);
        }
        return maxWidth;
    }
};