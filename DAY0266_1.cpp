// 3769. Sort Integers by Binary Reflection
class Solution {
private:
    int getBinary(int num){
        int b=0,two=1;
        bool flag=false;
        for(int i=31;i>=0;i--){
            if(num&(1<<i)){
                flag=true;
                b+=1*two;
                two<<=1;
            }
            else if(flag) two<<=1;
        }
        return b;
    }
    void merge(vector<int>& nums, vector<int>& b, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> Lb(n1), Rb(n2);
        vector<int> Lnums(n1), Rnums(n2);
        for (int i = 0; i < n1; i++) {
            Lb[i] = b[left + i];
            Lnums[i] = nums[left + i];
        }
        for (int i = 0; i < n2; i++) {
            Rb[i] = b[mid + 1 + i];
            Rnums[i] = nums[mid + 1 + i];
        }
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if ((Lb[i] < Rb[j])||(Lb[i] == Rb[j] && Lnums[i] <= Rnums[j])) {
                b[k] = Lb[i];
                nums[k] = Lnums[i];
                i++;
            } else {
                b[k] = Rb[j];
                nums[k] = Rnums[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            b[k] = Lb[i];
            nums[k] = Lnums[i];
            i++; k++;
        }
        while (j < n2) {
            b[k] = Rb[j];
            nums[k] = Rnums[j];
            j++; k++;
        }
    }
    void mergeSort(vector<int>& nums, vector<int>& b, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(nums, b, left, mid);
            mergeSort(nums, b, mid + 1, right);
            merge(nums, b, left, mid, right);
        }
    }
public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<int>b;
        for(int &num:nums){
            b.push_back(getBinary(num));
        }
        mergeSort(nums,b,0,nums.size()-1);
        return nums;
    }
};