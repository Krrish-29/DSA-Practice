// 3980. Minimum Operations to Transform Binary String
class Solution {
public:
    int minOperations(string s1, string s2) {
        int size=s1.size(),operations=0;
        // tough question can be done with dp or greedy 
        // greedy solution works like this we move left to right and check each position at a time 
        // assuming that anything to the left is resovled and anything to right may or may not be
        // if s1[i]==s2[i] move to next directly 
        // else if s1 is 0 increment by one operation since its a easy fix and move on
        // the problem arises with 1 
        // we have two options either to use previously complete seq or the next seq of chars
        
        // if i>0 we try to use prev chars and since they will be equal (both 1 or 0) it will require us 2 operations to fix the seq (
        // s1 => 0 1 ,s2 => 0 0 ===> we convert s1 to 1 1 then to 0 0
        // s1 => 1 1 ,s2 => 1 0 ===> we convert s1 to 0 0 then to 1 0
        // )

        // if i<size-1 means we can use next seq of chars to fix 
        // if s1[i+1]==s2[i+1] then we will require 2 operations similar to how we use prev chars to fix 
        // (
        // s1 => 1 0,s2 => 0 0 ===> we convert s1 to 1 1 then to 0 0
        // s1 => 1 1,s2 => 0 1  ===> we convert s1 to 0 0 then to 0 1
        // )

        // if s1[i+1] is a 0 then first it will be converted to a 1 then both 1's to 0's then the 0 back to a 1
        // if s1[i+1] is a 1 then it can be directly converted to a 0 and both s1[i]==s2[i] s1[i+1]==s2[i+1] will be satisfied 

        // we will try to prefer the next seq of chars if the cost from both cases is equal since using next seq to chars will make sure more chars are fixed in less cost 
        if(s1.size()==1){
            if(s1[0]!=s2[0]){
                if(s1[0]=='1') return -1;
                else return 1;
            }
            return 0;
        }
        for(int i=0;i<size;i++){
            if(s1[i]==s2[i]) continue;
            if(s1[i]=='1'){
                int prev=INT_MAX,next=INT_MAX;
                if(i>0){// if s1 i-1 is 0 or 1 it will take 2 operations regard less 
                    prev=min(prev,2);
                }
                if(i+1<size){
                    if(s1[i+1]==s2[i+1]) next=min(next,2);
                    else if(s1[i+1]=='0') next=min(next,3);
                    else if(s1[i+1]=='1') next=min(next,1);
                }

                if(next<=prev){
                    operations+=next;
                    i++;
                }
                else { operations+=prev; }
            }
            else { operations++; }
        }
        return operations;
    }
};