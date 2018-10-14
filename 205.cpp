class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false; 
        
        unordered_map<char, char> myHash1; 
        unordered_map<char, char> myHash2; 
        
        for(int i = 0; i < s.size(); i++){
            if(myHash1.find(s[i]) == myHash1.end() && myHash2.find(t[i]) == myHash2.end()){
                myHash1[s[i]] = t[i]; 
                myHash2[t[i]] = s[i]; 
            }else{
                if(myHash1.find(s[i]) != myHash1.end() && myHash1[s[i]] != t[i])
                    return false; 
                if(myHash2.find(t[i]) != myHash2.end() && myHash2[t[i]] != s[i])
                    return false; 
            }
        }
        return true; 
    }
};