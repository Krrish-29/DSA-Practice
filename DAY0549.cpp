// 4059. Lexicographically Largest Power Array
class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        // the idx i corresponds to 14-i th bit 
        // so we start with 14th bit meaning it would be filled in 0th idx
        // now for solving the initial thought is to sort the numbers based on the ith bit 
        // to make sure we have 1's before 0's and split the 1's group from 0's
        // this is done for each idx on the groups we previously created 
        // now each split might or might not result into new 1 and 0 group 
        // if we get 0 at ith pos in a group then we split that group and skip and other groups below

        // now this will work but we can also do this greadily by first getting all 1's at ith pos
        // and keeping 1's and 0's in separate groups and at any time if we get 0 after finishing that 
        // group we skipping iteration for other group and create a new set using
        // the groups we split into new and the others that were skipped for now 
        // if a group only had 1 then it would be simply counted and put back again
        // if it had any 0's then any other groups will be skipped and we will not count 1's in them
        // since we needed to maximize the j (first elems having ith bit set)
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