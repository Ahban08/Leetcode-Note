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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = new ListNode(), *curr = res;
        size_t listsSize;
        map<int,set<int>> listsMap;//key存node值，value存lists的index集合
        set<int> empty;

        listsSize = lists.size();//K
        for(int i = 0; i < listsSize; i++){
            if(lists[i]!=nullptr){
                listsMap[lists[i]->val].insert(i);
            }else{
                empty.insert(i);
            }
        }
        while(empty.size()!=listsSize){
            int min = listsMap.begin()->first;
            set<int> itlistsMap = listsMap.begin()->second;
            for (auto it=itlistsMap.begin(); it!=itlistsMap.end(); it++){
                int index = *it;
                curr->next = lists[index];
                curr = curr->next;
                listsMap[min].erase(index);
                if(lists[index]->next!=nullptr){
                    lists[index] =lists[index]->next;
                    listsMap[lists[index]->val].insert(index);
                }else{
                    empty.insert(index);
                }
            }
            if(listsMap[min].empty()){
                listsMap.erase(listsMap.begin());
            }
        }
        res = res->next;
        return res;
    }
};
//N is the total number of elements across all lists, K is the number of lists.
//Time Complexity: O(NlogK)
//Space Complexity: O(N)

class Solution_2 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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

    //Divide and Conquer
    ListNode* partionAndMerge(vector<ListNode*>& lists, int first, int last){
        if( first > last){
            return nullptr;
        }else if( first == last){
            return lists[first];
        }else{
            int mid = (first+last)/2;
            ListNode *list1 = partionAndMerge(lists , first , mid);
            ListNode *list2 = partionAndMerge(lists , mid+1 , last);
            return mergeTwoLists(list1, list2);
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if(k == 0){
            return nullptr;
        }else{
            return partionAndMerge(lists, 0, k-1);
        }

    }
};
//Time Complexity: O(NlogK)
//Space Complexity: O(1)