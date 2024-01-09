/*
머쓱이는 친구들과 동그랗게 서서 공 던지기 게임을 하고 있습니다. 
공은 1번부터 던지며 오른쪽으로 한 명을 건너뛰고 그다음 사람에게만 던질 수 있습니다.
친구들의 번호가 들어있는 정수 배열 numbers와 정수 K가 주어질 때, k번째로 공을 던지는 사람의 번호는 무엇인지 return 하도록 solution 함수를 완성해보세요.

제한사항
2 < numbers의 길이 < 100
0 < k < 1,000
numbers의 첫 번째와 마지막 번호는 실제로 바로 옆에 있습니다.
numbers는 1부터 시작하며 번호는 순서대로 올라갑니다.

1. 순환구조, 환형 링크드 리스트로 접근하면 될까
2. 링크드 리스트 구조 만들기 -(값, 포인터)
3. 환형 구조 만들기 -head에 next는 다시 head 자신이 된다
3.2 head 가 있다면, 임시 temp 노드를 만들고, 그 노드를 head 로 할당한다. 그 다음, 
temp->next가 head가 되는 부분까지 탐색하고 찾게되면, temp -> next는 새로운 노드로 할당하고, 새로운 노드의 next를 다시 head로 만든다. 
4.공은 다음 다음 사람을 가리키고, 그 횟수를 몇번 했는지가  k

*/
#include <string>
#include <vector>

using namespace std;


class Node
{
public:
    int value;
    Node* next;

    Node(int Val)
        :value(Val),
        next(nullptr)
    {    }

};

class CircularLinkedlist
{
public:
    Node* head;
    CircularLinkedlist()
        :head(nullptr)
    {    }


    void plus(int value)
    {
        Node* newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node* temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    int ThrowBall(int k)
    {
        Node* current = head;
        for (int i = 1; i < k; i++)
        {
            current = current->next->next;
        }
        return current->value;
    }
};

int solution(vector<int> numbers, int k) {
    int answer = 0;

    CircularLinkedlist circle;

    for (int i = 0; i < numbers.size(); i++)
    {
        circle.plus(numbers[i]);
    }

    answer =circle.ThrowBall(k);


    return answer;
}

int main()
{
    solution({ 1,2,3, },3);
}
