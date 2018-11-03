/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> cache; // old-->new
        
        RandomListNode* current = head; 
        RandomListNode* copy_head = NULL; 
        RandomListNode* copy_current = NULL; 
        while(current){
            if(copy_head == NULL){
                copy_head = new RandomListNode(current->label); 
                cache[current] = copy_head; 
                copy_current = copy_head; 
            }else{
                if(cache.find(current) == cache.end()){
                    cache[current] = new RandomListNode(current->label);     
                }
                copy_current->next = cache[current];
                copy_current = copy_current->next;
            }
            
            if(current->random){
                if(cache.find(current->random) != cache.end()){
                   
                }else{
                    cache[current->random] = new RandomListNode(current->random->label);            
                }
                copy_current->random = cache[current->random];
            }
            
            current = current->next;  
        }
        
        return copy_head;
    }
};