/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        bool res = false;
        ListNode *curr = head;
        int pos = 0;
        map<ListNode*, int> nodeMap;

        while( curr!= nullptr){
            if( nodeMap.find(curr) == nodeMap.end()){
                nodeMap[curr] = pos;
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