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
    void reorderList(ListNode* head) {
        ListNode *curr = head;
        // int count = 0;
        // stack<ListNode> first, second;
        if(curr->next != nullptr && curr->next->next!=nullptr){
            while(curr->next->next!=nullptr){
                // count++;
                curr = curr->next;
            }
            curr->next->next = head->next;
            head->next = curr->next;
            curr->next = nullptr;
            head = head->next->next;
            reorderList(head);
        }
    }
};
//Time Complexity: O(N^2)
//Space Complexity: O(N)

class Solution_2 {
public:
    void reorderList(ListNode* head) {
        //Find mid node
        ListNode *slow = head, *fast = head, *midHead;
        while(fast->next!= nullptr && fast->next->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        midHead = slow->next;
        slow->next = nullptr;
        
        //Reverse
        ListNode *reverse =nullptr, *temp;
        while(midHead!= nullptr){
            temp = midHead;
            midHead = midHead->next;
            temp->next = reverse;
            reverse = temp;
        }

        //Merge
        ListNode *curr = head, *nextCurr, *nextReverse;
        while(reverse!=nullptr){
            nextCurr = curr->next;
            nextReverse = reverse->next;
            curr->next =reverse;
            reverse->next = nextCurr;
            curr = nextCurr;
            reverse = nextReverse;
        }
        
    }
};
//Time Complexity: O(N)
//Space Complexity: O(1)