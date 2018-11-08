class Solution {
public:
    string alienOrder(vector<string>& words) {
        // cache to save the relations between characters
        unordered_map<char, unordered_set<char>> c_hash; 
        // cache to record the incoming topologies
        unordered_map<char, int> degree; 

        string ans; 
        if(words.size() == 0)
            return ans; 

        for(auto word: words){
            for(auto c: word){
                degree[c] = 0; 
            }
        }
        // construct relationship first (build up topology)
        for(int i = 0; i < words.size() - 1; i++){
            string cur = words[i]; 
            string next = words[i+1]; 


            // find the minimal length of two words that you want to compare
            int minLength = min(cur.size(), next.size()); 
            for(int j = 0; j < minLength; j++){

                char c1 = cur[j]; 
                char c2 = next[j]; 

                if(c1 != c2) {
                    // find the relation between two characters
                    unordered_set<char> tmp_set;
                    if(c_hash.find(c1) != c_hash.end()){
                        tmp_set = c_hash[c1];
                    }
                    if(tmp_set.find(c2) == tmp_set.end()){
                        tmp_set.insert(c2); 
                        c_hash[c1] = tmp_set; 
                        degree[c2]++;
                    }
                    break; 
                }
            }
        }

        // traverse topology and figured out
        queue<char> bfs; 
        // find the source charactrer (incoming degree is 0)
        for (auto& it : degree){
            if(it.second == 0){
                bfs.push(it.first); 
                cout << it.first << endl;
            } // zero degree
        }

        while(!bfs.empty()){
            char current = bfs.front();
            bfs.pop(); 
            ans += current; 
            cout << ans << endl; 
            if(c_hash.find(current) != c_hash.end()){
                for(auto& c : c_hash[current]){
                    // reduce incoming degree because of traversed 
                    degree[c]--;
                    if(degree[c] == 0){
                        bfs.push(c);
                    }
                }
            }
           
        }
         // some loop in the topology
            if(ans.size() != degree.size()) return ""; 
            return ans; 
    }
};
