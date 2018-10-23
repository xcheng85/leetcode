/* Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

Hint:

Consider the palindromes of odd vs even length. What difference do you notice?
Count the frequency of each character.
If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times? */


class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        int cnt = 0;
        for (auto a : s) ++m[a];
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second % 2) ++cnt;
        }
// 偶数长度字符串，每个字符都是偶数
// 奇数长度字符串， 只有一个 

        return cnt == 0 || (s.size() % 2 == 1 && cnt == 1);
    }
};

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> t;
        for (auto a : s) {
            if (t.find(a) == t.end()) t.insert(a);
            else t.erase(a);
        }
        return t.empty() || t.size() == 1;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] == nums.size() || nums[i] == i){
                continue; 
            }else{
                if(nums[i] != i){
                    int tmp = nums[nums[i]]; 
                    nums[nums[i]] = nums[i]; 
                    nums[i] = tmp;
                }
            }
            
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == nums.size())
                return i; 
        }
        return nums.size(); 
    }
};