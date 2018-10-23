struct node
{
    int key;
    struct node *next;
    node(int k) : key(k) { next = NULL; }
};

class MyHashSet
{
  private:
    vector<node *> buckets;

    int hash(int key)
    {
        int m = buckets.size();
        return key % m;
    }

  public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        for (int i = 0; i < 13000; i++)
        {
            buckets.push_back(NULL);
        }
    }
    ~MyHashSet()
    {
        node *curr;
        node *temp;
        for (int i = 0; i < 13000; i++)
        {
            curr = buckets[i];
            while (curr != NULL)
            {
                temp = curr->next;
                delete curr;
                curr = temp;
            }
        }
        temp = NULL;
        curr = NULL;
    }

    void add(int key)
    {
        int index = hash(key);
        if(buckets[index] == NULL)
            buckets[index] = new node(key);
        else{
            node* curr = buckets[index];
            node* prev;
            while(curr != NULL){
                if(key == curr->key){
                    return;
                }
                else{
                    prev = curr;
                    curr = curr->next;
                }
            }
            curr = new node(key);
            prev->next = curr;
        }
    }

    void remove(int key)
    {
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

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        int index = hash(key);
        if(buckets[index] == NULL)
            return false;
        else{
            node* curr = buckets[index];
            while(curr != NULL){
                if(curr->key == key)
                    return true;
                curr= curr->next;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */