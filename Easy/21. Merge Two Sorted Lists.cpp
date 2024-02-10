class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //建立新的node，且res指向此node
        //將res指標指的位置assign給curr，所以res和curr指向同一個node
        ListNode *res = new ListNode(), *curr = res; 

        while(list1 != nullptr && list2 != nullptr){
            if( list1->val > list2->val){
                curr->next = list2;
                list2 = list2->next;
            }else{
                curr->next = list1;
                list1 = list1->next;
            }
            curr = curr->next;
        }
        if(list1 != nullptr){
            curr->next = list1;
        }if(list2 != nullptr){
            curr->next = list2;
        }
        //第一個node為初始化時所建立，不為結果值
        res = res->next; 
        return res;
    }
};
//Time Complexity: O(N+M)
//Space Complexity: O(1)