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
        if(head == NULL || head -> next == NULL) return head;
        ListNode* temp = new ListNode(0);
        temp -> next = head;
        ListNode* prev = temp;
        while(prev -> next && prev -> next -> next){
            ListNode* curr = prev -> next;
            ListNode* curr1 = prev -> next -> next;
            curr -> next = curr1 -> next;
            curr1 -> next = curr;
            prev -> next = curr1;
            prev = curr;
        }
        return temp -> next;
    }
};