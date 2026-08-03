// 486. Predict the Winner
class Solution {
private:
    bool helper(vector<int>& nums,int start,int end,int score1,int score2,bool toggle){
        if(end<start) {
            if(score1>=score2) return true;
            return false;
        }
        bool ans=false;
        if(toggle){// player 1 turn 
        // player 1 can try both situations freely
            ans |= (helper(nums,start+1,end,score1+nums[start],score2,!toggle) ||
                    helper(nums,start,end-1,score1+nums[end],score2,!toggle));
        }
        else{// player 2 turn 
        // player 2 can only win if it scores better in both situations 
            ans |= (helper(nums,start+1,end,score1,score2+nums[start],!toggle) &&
                    helper(nums,start,end-1,score1,score2+nums[end],!toggle));
        }
        return ans;
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        return helper(nums,0,nums.size()-1,0,0,true);
    }
};