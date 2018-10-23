struct node{
        int key;
        int value;
        struct node *next;
        node(int k, int v):key(k),value(v){ next = NULL;}
};

class MyHashMap {
private:
    vector<node*>buckets;
    
    int hash(int key){
        int m = buckets.size();
        return key % m;
    }
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        for(int i=0; i<13000; i++){ buckets.push_back(NULL);}
    }
		
~MyHashMap(){
   node* curr;
   node* temp;
   for(int i=0; i<13000; i++){ 
        curr = buckets[i];
        while(curr != NULL){
            temp = curr->next;
            delete curr;
            curr = temp;
         }
    }
    temp = NULL;
    curr = NULL;
 }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = hash(key);
        if(buckets[index] == NULL)
            buckets[index] = new node(key,value);
        else{
            node* curr = buckets[index];
            node* prev;
            while(curr != NULL){
                if(key == curr->key){
                    curr->value = value;
                    return;
                }
                else{
                    prev = curr;
                    curr = curr->next;
                }
            }
            curr = new node(key,value);
            prev->next = curr;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = hash(key);
        if(buckets[index] == NULL)
            return -1;
        else{
            node* curr = buckets[index];
            while(curr != NULL){
                if(curr->key == key)
                    return curr->value;
                curr= curr->next;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = hash(key);
        node* curr = buckets[index];
        node* prev = NULL;
        while(curr != NULL){
            if(curr->key == key){
                if(prev != NULL) // deleting middle node
                    prev->next = curr->next;
                else  //if deleting head with other linked nodes or solo head node
                    buckets[index] = curr->next;
                delete curr;
                curr = NULL;
            }
            else{
                prev = curr;
                curr= curr->next;
            }
        }
       
    }
    
    
};