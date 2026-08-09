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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node that points to the head. 
        // This makes it easy to handle edge cases, like removing the very first node.
        ListNode* dummy = new ListNode(0, head);
        
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // Move the fast pointer n + 1 steps ahead.
        // We do n + 1 so that the slow pointer lands exactly on the node 
        // immediately *before* the one we want to delete.
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        // Move both pointers until the fast pointer reaches the end of the list
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Skip the nth node from the end
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        // Free the memory of the removed node (Best practice in C++)
        delete nodeToDelete;
        
        // Get the actual head of the modified list and clean up the dummy
        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
};