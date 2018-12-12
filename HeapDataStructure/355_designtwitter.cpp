#include <vector>

// user-id ---> tweetId,

//pq<tweedId> sort by

// user ---> vector<feed>

// vector<int> // all tweetIds

//tweedId ---> in the origin id

// every user sort its own tweeds, use linked list to manager tweeds under one user

// merge k sorted list into top , merge k linked list



class Compare
{
  public:
    bool operator()(ListNode *lhs, ListNode *rhs)
    {
        // maximum on top (most recent)
        return lhs->val < rhs->val;
    }
};

class Twitter
{
  private:
    //vector<int> tweeds;
    // tweed id, index (date)
    //unordered_map<int, int> tweed_cache;
    unordered_map<int, unordered_set<int>> user_feed_cache; // user default feed himself
    unordered_map<int, ListNode*> user_tweeds_cache; 
    unordered_map<int, int> tweeds_cache; // 
  public:
    /** Initialize your data structure here. */
    Twitter()
    {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        //1. check if it feed itself
        user_feed_cache[userId].insert(userId);
        
        ListNode*tmp = user_tweeds_cache[userId]; 
        int currentId = tweeds_cache.size();
        user_tweeds_cache[userId] = new ListNode(currentId);
        tweeds_cache[currentId] = tweetId;
        user_tweeds_cache[userId]->next = tmp;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        unordered_set<int> feed = user_feed_cache[userId];
        vector<ListNode *> lists; // k sorted list

        for (auto itr = feed.begin(); itr != feed.end(); ++itr)
        {
            int usrId = *itr;
            lists.push_back(user_tweeds_cache[usrId]);
        }
        return mergeKLists(lists, 10);
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        user_feed_cache[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        if(followerId == followeeId){
            return;
        }
        if (user_feed_cache[followerId].find(followeeId) != user_feed_cache[followerId].end())
        {
            user_feed_cache[followerId].erase(followeeId);
        }
    }

    vector<int> mergeKLists(vector<ListNode *> &lists, int k)
    {
        vector<int> ans;

        std::priority_queue<ListNode *, std::vector<ListNode *>, Compare> q;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != NULL)
            {
                q.push(lists[i]);
            }
        }

        while (!q.empty())
        {
            //出队列
            ListNode *tmp = q.top();
            ans.push_back(tweeds_cache[tmp->val]);
            if (ans.size() == k)
            {
                return ans;
            }
            q.pop();
            //判断当前链表是否为空，不为空就将新元素入队
            ListNode *next = tmp->next;
            if (next != NULL)
            {
                q.push(next);
            }
        }
        return ans;
    }
};