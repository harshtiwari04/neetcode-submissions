class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(),piles.end());
        int l =1;


        int res =r;

        while(l<=r){
            int k = l + (r-l)/2;

            long long totaltime =0;

            for(int p:piles){
                totaltime +=ceil(static_cast<double>(p)/k);
            }
            if(totaltime <= h){
                res=k;
                r=k-1;
            }
            else{
                l=k+1;
            }
        }

     return res ;   
    }
};
