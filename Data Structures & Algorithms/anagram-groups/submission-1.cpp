class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        
        for (const string& s : strs) {
            // Create a 26-byte string initialized with raw 0 values
            string key(26, 0); 
            
            for (char ch : s) {
                key[ch - 'a']++; // Increment raw byte count directly
            }
            
            hash[key].push_back(s);
        }
        
        vector<vector<string>> ans;
        // Reserving memory prevents vectors from dynamic resizing overhead
        ans.reserve(hash.size()); 
        
        for (auto& [s, lst] : hash) {
            ans.push_back(move(lst)); // 'move' passes ownership instead of copying data
        }
        
        return ans;
    }
};