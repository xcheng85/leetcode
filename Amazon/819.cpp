"a, a, a, a, b,b,b,c, c"

// cannot use space to separate sentence
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // stringstream to vector<string>
        unordered_set<string> cache(banned.begin(), banned.end()); 
        unordered_map<string, int> hash; 
        stringstream lineStream(paragraph);
        string tmp; 
        vector<string> segments; 
        while(lineStream >> tmp)
            segments.push_back(tmp);
        
        int maxFrequency = 0; 
        string maxFrequentWord; 
        for(auto s: segments){
            string lowerCase = s; 
            for(auto& c : lowerCase){
                if(c >= 'A' && c <= 'Z'){
                    c = 'a' + c - 'A'; 
                }
            }
            if(!(lowerCase[lowerCase.size()-1] >= 'a' && lowerCase[lowerCase.size()-1] <= 'z')){
                lowerCase = lowerCase.substr(0, lowerCase.size()-1);
            }

            if(cache.find(lowerCase) == cache.end()){
                hash[lowerCase]++; 
                if(hash[lowerCase] > maxFrequency){
                    maxFrequentWord = lowerCase;
                    maxFrequency = hash[lowerCase];
                }
            }
        }
        
        return maxFrequentWord;
    }
};

// accpted
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // stringstream to vector<string>
        unordered_set<string> cache(banned.begin(), banned.end()); 
        unordered_map<string, int> hash; 
        vector<string> segments; 
        
        int anchor = 0; 
        for(int i = 0; i < paragraph.size(); i++){
            char c = paragraph[i]; 
            if(isalpha(c) == 0){
                if(i > anchor){
                    string word = paragraph.substr(anchor, i - anchor); 
                    segments.push_back(word); 
                }
                anchor = i+1; 
            }
        }
        if(anchor != paragraph.size() - 1){
            string word = paragraph.substr(anchor, paragraph.size() - anchor);
            segments.push_back(paragraph.substr(anchor, paragraph.size() - anchor)); 
        }
        
        int maxFrequency = 0; 
        string maxFrequentWord; 
        for(auto& s: segments){
            for(auto& c:s){
                c = tolower(c); 
            }
            cout << s << endl;
            if(cache.find(s) == cache.end()){
                hash[s]++; 
                if(hash[s] > maxFrequency){
                    maxFrequentWord = s;
                    maxFrequency = hash[s];
                }
            }
        }
        
        return maxFrequentWord;
    }
};