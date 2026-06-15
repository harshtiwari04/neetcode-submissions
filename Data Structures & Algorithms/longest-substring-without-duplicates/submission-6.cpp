class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ch;
        int l=0;
        int res =0;

        for(int i=0;i<s.size();i++){
            while(ch.find(s[i])!=ch.end()){
                ch.erase(s[l]);
                l++;
            }
            ch.insert(s[i]);
            res=max(res,i-l+1);
        }
        return res;
        
    }
};
