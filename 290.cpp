class Solution {
public:
    bool wordPattern(string pattern, string str) {
        std::istringstream iss(str);
        std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());
        
        if(pattern.size() != results.size())
            return false; 
        
        unordered_map<char, string> myHash1; 
        unordered_map<string, char> myHash2; 
        
        for(int i = 0; i < pattern.size(); i++){
            if(myHash1.find(pattern[i]) == myHash1.end() && myHash2.find(results[i]) == myHash2.end()){
                myHash1[pattern[i]] = results[i]; 
                myHash2[results[i]] = pattern[i]; 
            }else if(myHash1.find(pattern[i]) != myHash1.end() && results[i] != myHash1[pattern[i]])
            {
                return false;
            }else if(myHash2.find(results[i]) != myHash2.end() && pattern[i] != myHash2[results[i]]){
                return false; 
            }
        }
        
        return true; 
    }
};