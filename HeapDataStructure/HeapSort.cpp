// Binary heap,  complete binary tree
// parent node is always larger than child
// array based

// heapfy recursive like segment tree

template <typename T>
void heap_sort_q(std::vector<T> &vec)
{
    if (vec.empty())
        return;

    std::priority_queue<T> queue(vec.begin(), vec.end()); // max queue
    auto index = vec.size() - 1;
    while (!queue.empty())
    {
        vec[index--] = queue.top();
        queue.pop();
    }
}

int main()
{
    std::vector<int> v = {4, 2, 10, 3, 12, 6, 25, 5};

    heap_sort_q(v);

    for (const auto x : v)
    {
        std::cout << x << ' ';
    }
}