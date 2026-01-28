// 826. Most Profit Assigning Work
class Solution {
private:
    int partition(vector<int>&arr1,vector<int>&arr2,int left,int right){
        int i=left-1,j=left;
        while(j<right){
            if(arr1[j]<=arr1[right]){
                i++;
                swap(arr1[i],arr1[j]);
                swap(arr2[i],arr2[j]);
            }
            j++;
        }
        swap(arr1[i+1],arr1[right]);
        swap(arr2[i+1],arr2[right]);
        return i+1;
    }
    void QuickSort(vector<int>&arr1,vector<int>&arr2,int left,int right){
        if(left<right){
            int pivot=partition(arr1,arr2,left,right);
            QuickSort(arr1,arr2,left,pivot-1);
            QuickSort(arr1,arr2,pivot+1,right);
        }
    }
    int lowerBound(vector<int>&arr,int target){
        int left=0,right=arr.size()-1,mid,ans=-1;
        while(left<=right){
            mid=left+(right-left)/2;
            if(arr[mid]<=target){
                left=mid+1;
                ans=mid;
            }
            else right=mid-1;
        }
        return ans;
    }
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // QuickSort(difficulty,profit,0,difficulty.size()-1);
        vector<pair<int,int>>job;
        for(int i=0;i<difficulty.size();i++){
            job.push_back({difficulty[i],profit[i]});
        }
        sort(job.begin(),job.end());
        profit[0]=job[0].second;
        for(int i=1;i<difficulty.size();i++){
            profit[i]=max(job[i].second,profit[i-1]);
        }
        for(int i=0;i<difficulty.size();i++){
            difficulty[i]=job[i].first;
        }

        // for(int i=1;i<difficulty.size();i++){
        //     profit[i]=max(profit[i],profit[i-1]);
        // }
        int maxProfit=0;
        for(int &work:worker){
            // int idx=lowerBound(difficulty,work);
            int idx=upper_bound(difficulty.begin(),difficulty.end(),work)-difficulty.begin()-1;
            if(idx!=-1)  maxProfit+=profit[idx];
        }
        return maxProfit;
    }
};