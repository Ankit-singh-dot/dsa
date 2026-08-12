class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        list<int> negative_nums ;
        vector<int> ans; 
        int i = 0 ;
        int j = 0 ;
        while(j<n){
            if(arr[j] < 0){
                negative_nums.push_back(arr[j]);
            }
            if(j-i+1 < k ){
                j++;
            }
            else if(j-i+1 == k){
                if(negative_nums.size() == 0){
                    ans.push_back(0);
                }
                else {ans.push_back(negative_nums.front());
                 if (arr[i] == negative_nums.front()){
                    negative_nums.pop_front();
                }
                }
                i++;
                j++;
            }
        }
        return ans ;
    }
};