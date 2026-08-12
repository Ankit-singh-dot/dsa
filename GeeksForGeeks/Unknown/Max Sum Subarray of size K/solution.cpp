class Solution {
    public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
       int i = 0 ; 
       int j = 0 ;
       long long sum = 0 ;
       int maxi = 0 ;
       while(j<n) {
        sum += arr[j] ; 
        if(j-i+1<k){
            j++; 
        } else if (j-i+1 == k)
        {
            maxi = max(maxi,(int)sum);
            sum = sum - arr[i];
            i++;
            j++;
        }
        
       }
       return maxi ;
    }
};