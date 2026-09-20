// 4043. Count Rotations With Exactly K Equal Adjacent Pairs
class Solution {
public:
    int countRotations(string s, int k) {
        // start by creating a new str which is rotated using substr and simply traverse it 
        // to optimize we can see that we only compare x and x-1 of the new string 
        // we can keep the same string and introduce a new starting point i as well
        // so that the comparison start from 0 1 , 1 2  2 3 and for next rotation 
        // 1 2, 2 3, and so on and to keep it cyclic do %size
        // also to better understand the old string will have its starting shifted by 1 to right  to be new string we also doing the same and since the elems at first would go to last making a cycle to replicate that we do %size
        // string str;
        int count=0,score=0,size=s.size();
        for(int i=0;i<size;i++){
            // str = s.substr(i,size-i) + s.substr(0,i);
            score=0;
            for(int x=1;x<size;x++){
                // if(str[x]==str[x-1]) score++;
                if(s[ (i+x)%size ] == s[ (i+x-1)%size ]) score++;
            }
            if(score==k) count++;
        }
        return count;
    }
};