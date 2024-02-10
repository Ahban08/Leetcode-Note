#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* res = nullptr;

        while(head != nullptr){
            res = new ListNode(head->val, res);
            head = head->next;
        }
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution_2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* res = nullptr, *next;

        while(head != nullptr){
            next = head->next;
            head->next = res;
            res = head;
            head = next;
        }
        return res;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(1)

int main() {
    Solution sol;
    ListNode* input = new ListNode();
    cout << "Output: " << sol.reverseList(input) << endl;
    return 0;
}