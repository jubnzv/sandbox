// https://leetcode.com/problems/merge-k-sorted-lists/
//
// Given an array of linked-lists lists, each linked list is sorted in ascending
// order.
//
// Merge all the linked-lists into one sort linked-list and return it.
//
// Example 1:
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
//
// Example 2:
// Input: lists = []
// Output: []
//
// Example 3:
// Input: lists = [[]]
// Output: []
//
// Constraints:
//  k == lists.length
//  0 <= k <= 10^4
//  0 <= lists[i].length <= 500
//  -10^4 <= lists[i][j] <= 10^4
//  lists[i] is sorted in ascending order.
//  The sum of lists[i].length won't exceed 10^4.
#include <iostream>
#include <queue>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ListNodeComparator {
public:
  bool operator()(const ListNode *Lhs, const ListNode *Rhs) {
    return Lhs->val > Rhs->val;
  }
};

class Solution {
public:
  // Naive implementation using std::priority_queue
  ListNode *mergeKLists(std::vector<ListNode *> &Lists) {
    if (Lists.empty())
      return nullptr;

    std::priority_queue<ListNode *, std::vector<ListNode *>, ListNodeComparator>
        Heap;
    for (const auto &List : Lists)
      for (auto *CurEl = List; CurEl != nullptr; CurEl = CurEl->next)
        Heap.push(CurEl);

    if (Heap.empty()) // [[]] case
      return nullptr;

    ListNode *ResultHead = Heap.top();
    ListNode *ResultCur = ResultHead;
    Heap.pop();
    while (!Heap.empty()) {
      ResultCur->next = Heap.top();
      ResultCur = Heap.top();
      Heap.pop();
    }
    ResultCur->next = nullptr;

    return ResultHead;
  }
};

int main(int argc, char *argv[]) {
  ListNode *L1_1 = new ListNode(1);
  ListNode *L1_2 = new ListNode(2);
  L1_1->next = L1_2;
  ListNode *L2_1 = new ListNode(3);
  ListNode *L2_2 = new ListNode(4);
  L2_1->next = L2_2;

  std::vector<ListNode *> Lists = {L1_1, L2_1};

  auto S = Solution();

  S.mergeKLists(Lists);

  return 0;
}
