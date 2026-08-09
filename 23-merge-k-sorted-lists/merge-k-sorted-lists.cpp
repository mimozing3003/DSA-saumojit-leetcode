#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Custom comparator for the priority queue to create a Min-Heap
    struct compare {
        bool operator()(const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Priority queue to store the current nodes being evaluated
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        // Push the head of each non-empty list into the priority queue
        for (ListNode* list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }
        
        // Dummy node to help build the result list easily
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        // Process nodes until the heap is empty
        while (!pq.empty()) {
            // Get the smallest node
            ListNode* smallest = pq.top();
            pq.pop();
            
            // Add it to our merged list
            tail->next = smallest;
            tail = tail->next;
            
            // If the extracted node has a next node, push it into the heap
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }
        
        ListNode* head = dummy->next;
        delete dummy;
        
        return head;
    }
};