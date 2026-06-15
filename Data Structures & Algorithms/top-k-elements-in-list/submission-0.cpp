class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;

        for(int i : nums){
            mpp[i]++;
        }

        vector<vector<int>>freq(nums.size()+1);

        for(auto it : mpp){
            int num = it.first;
            int c = it.second;

            freq[c].push_back(num);
        }

        vector<int>result;
        for ( int i =freq.size()-1; i>0 ; --i){
            for(int n : freq[i]){
                result.push_back(n);
                if(result.size()==k)return result;
            }
        }
      return result ;   
    }
};
