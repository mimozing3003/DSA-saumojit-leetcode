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
    ListNode* swapPairs(ListNode* head) {
        // Dummy node pointing to head helps handle the head swap cleanly
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        
        // Loop as long as there is a pair of nodes to swap
        while (prev->next != nullptr && prev->next->next != nullptr) {
            // Identify the two nodes to swap
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Execute the swap
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Move prev forward by two nodes (to the node that was originally 'first')
            prev = first;
        }
        
        // Save the new head and clean up the dummy node
        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
};