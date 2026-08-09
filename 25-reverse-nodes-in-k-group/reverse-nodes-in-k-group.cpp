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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // If k is 1, reversing 1 node does nothing, just return head.
        if (head == nullptr || k == 1) {
            return head;
        }
        
        // Dummy node to easily manage the head of the list
        ListNode* dummy = new ListNode(0, head);
        
        // prevGroupEnd will always point to the node immediately preceding 
        // the k-group we are about to reverse.
        ListNode* prevGroupEnd = dummy;
        
        while (true) {
            // 1. Check if there are at least k nodes left to form a group
            ListNode* kthNode = prevGroupEnd;
            for (int i = 0; i < k; ++i) {
                kthNode = kthNode->next;
                if (kthNode == nullptr) {
                    break;
                }
            }
            
            // If we don't have k nodes, we are done
            if (kthNode == nullptr) {
                break;
            }
            
            // 2. Setup pointers for reversal
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kthNode->next;
            
            ListNode* curr = groupStart;
            // Trick: Initialize prev to nextGroupStart so the tail of the 
            // reversed group automatically points to the rest of the list!
            ListNode* prev = nextGroupStart; 
            
            // 3. Reverse the k nodes
            for (int i = 0; i < k; ++i) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            
            // 4. Reconnect the reversed group to the previous part of the list
            prevGroupEnd->next = kthNode;
            
            // 5. Update prevGroupEnd for the next iteration
            // After reversal, groupStart is now the last node in the reversed group
            prevGroupEnd = groupStart;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
};