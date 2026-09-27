// 4059. Lexicographically Largest Power Array
class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        // the idx i corresponds to 14-i th bit 
        // so we start with 14th bit meaning it would be filled in 0th idx of the power array 
        // now for solving the initial thought is to sort the numbers based on the ith bit  
        // to make sure we have 1's before 0's 
        // now the main idea is to split the numbers into groups and keeping it that way therefore each time the numbers gets
        // divided into smaller group based on the setBits they contributed
        // and split of 1's and 0's is done only till we do not get a 0 at ith pos after that 
        // sorting the groups wont help so we can skip counting set bits in it and reordering them as well

        // now this would work but we can also start with nums and make 2 groups of 0 and 1 
        // having set bit at ith pos and store it then moving to 13th bit we go over these new groups 
        // first over 1 group and separate again and if we get 0 then there is no point counting setBits 
        // and separating the other group left we can create new set with all this and move to 12th bit 
        // and do this again and the reason we are not counting after the curr group if we get 0 is that 
        // first it wont do anything and might even reduce our set bits count for some ith pos
        
        // the analogy is that we can take a group of elems as a free flow of items that can be rearranged to maximize the 
        // set bit we get at ith pos and we do this again and again (try to visualize the spliting of groups) 
        vector<int>power(15,0);
        int setBits=0,size;
        vector<vector<int>>group;
        group.push_back(nums);
        vector<vector<int>>newGroup;
        vector<int>set,notSet;
        for(int bit=14;bit>=0;bit--){
            newGroup={};
            setBits=0;
            bool continuousSetBit=true;

            for(auto &vec:group){
                set={};
                notSet={};
                size = vec.size();
                if(continuousSetBit){
                    for(int i=0;i<size;i++){
                        if( (vec[i]>>bit) & 1 ) {
                            setBits++;
                            set.push_back(vec[i]);
                        }
                        else {  
                            continuousSetBit=false;
                            notSet.push_back(vec[i]);
                        }
                    }
                    if(!set.empty()) newGroup.push_back(set);
                    if(!notSet.empty()) newGroup.push_back(notSet);
                }
                else{
                    newGroup.push_back(vec);
                }
            }
            group = newGroup;
            power[14-bit] = setBits;
        }
        return power;
    }
};