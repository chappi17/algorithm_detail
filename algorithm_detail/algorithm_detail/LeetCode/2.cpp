/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(-1), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;
  struct ListNode 
  {
      int val;
      ListNode *next;
      ListNode() : val(-1), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {

        ListNode* dummyHead = new ListNode(0); // 결과 연결 리스트의 더미 헤드
        ListNode* current = dummyHead; // 결과 연결 리스트의 현재 노드
        int carry = 0; // 자리 올림을 저장하는 변수

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // 현재 자리의 합계를 저장하는 변수

            if (l1 != nullptr) {
                sum += l1->val; // l1의 현재 노드 값을 합계에 추가
                l1 = l1->next; // l1을 다음 노드로 이동
            }

            if (l2 != nullptr) {
                sum += l2->val; // l2의 현재 노드 값을 합계에 추가
                l2 = l2->next; // l2를 다음 노드로 이동
            }

            carry = sum / 10; // 합계에서 자리 올림을 계산
            current->next = new ListNode(sum % 10); // 합계의 일의 자리를 사용하여 새 노드 생성
            current = current->next; // 결과 리스트에서 현재 노드를 다음 노드로 이동
        }

        ListNode* result = dummyHead->next; // 더미 헤드를 제외한 실제 결과 리스트
        delete dummyHead; // 더미 헤드 메모리 해제
        return result; // 결과 리스트 반환
};


int main()
{

    return -1;
}