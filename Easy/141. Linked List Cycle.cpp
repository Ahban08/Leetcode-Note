class Solution {
public:
    bool hasCycle(ListNode *head) {
        bool res = false;
        ListNode *curr = head;
        set<ListNode*> nodeSet; //用Set儲存

        while( curr!= nullptr){
            if( nodeSet.find(curr) == nodeSet.end()){
                nodeSet.insert(curr);
                curr = curr->next;
            }else{
                res = true;
                break;
            }
        }
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(N)

//Follow up: Can you solve it using O(1) (i.e. constant) memory?
//Floyd's Cycle Finding Algorithm
//利用Two Pointer一快一慢前進，若input中包含cycle則必定在有限時間內相遇
class Solution_2 {
public:
    bool hasCycle(ListNode *head) {
        bool res = false;
        ListNode *faster = head;
        if(head==nullptr){
            return res;
        }
        while( faster->next!= nullptr && faster->next->next!= nullptr){
            head = head->next;
            faster = faster->next->next;
            if(head == faster){
                res = true;
                break;
            }
        }
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(1)