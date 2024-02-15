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
        ListNode *curr=head;
        vector<ListNode*> node;//記住每個指標的位置，以便快速找到Nth，以空間換取時間

        while(curr!= nullptr){
            node.push_back(curr);
            curr = curr->next;
        }
        
        int size = int(node.size());
        if(size==n){
            head = head->next;
        }else{
            node[size-n-1]->next = node[size-n]->next;
        }
        return head;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(N)

//Follow up: Could you do this in one pass?
//利用快慢指標，兩個指標之間相差n個節點，則快指標指到最後一個node時，慢指標的下一個node即為要被移除的node
class Solution_2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast= head;

        while(n>0){
            fast = fast->next;
            n--;
        }
        if(fast == nullptr){
            head = head->next;
        }else{
            while(fast->next!=nullptr){
                fast = fast->next;
                slow = slow->next;
            }
            slow->next = slow->next->next;
        }
        return head;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(1)