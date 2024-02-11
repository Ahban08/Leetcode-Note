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