/* Sort a nearly sorted (or K sorted) array */

/* Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
            k = 3 
Output : arr[] = {2, 3, 5, 6, 8, 9, 10} */
// for

// Given an array of size n, where every element
// is k away from its target position, sorts the
// array in O(nLogk) time.
int sortK(vector<int> array, int k)
{
    // Insert first k+1 items in a priority queue (or min heap)
    //(A O(k) operation). We assume, k < n.

    // min heap [0, k]
    priority_queue<int, vector<int>, greater<int>> pq(array, array + k + 1);

    // i is index for remaining elements in arr[] and index
    // is target index of for current minimum element in
    // Min Heapm 'hp'.
    int index = 0;
    for (int i = k + 1; i < n; i++)
    {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while (pq.empty() == false)
    {
        arr[index++] = pq.top();
        pq.pop();
    }
}