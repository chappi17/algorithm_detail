#include <iostream>
#include <vector>

template <typename T>
class MemoryPool {
public:
    MemoryPool(size_t size) {
        // 초기 메모리 풀 크기만큼 객체를 미리 생성하여 풀에 추가
        for (size_t i = 0; i < size; ++i) {
            freeList.push_back(new T());
        }
    }

    ~MemoryPool() {
        // 메모리 풀에 있는 모든 객체를 삭제
        for (auto item : freeList) {
            delete item;
        }
    }

    T* allocate() {
        // 메모리 풀에서 객체 하나를 할당
        if (freeList.empty()) {
            // 풀이 비었을 경우 새로운 객체 생성
            return new T();
        } else {
            // 풀에 객체가 있을 경우 마지막 객체를 반환하고 풀에서 제거
            T* obj = freeList.back();
            freeList.pop_back();
            return obj;
        }
    }

    void deallocate(T* object) {
        // 사용이 끝난 객체를 메모리 풀에 반환
        freeList.push_back(object);
    }

private:
    std::vector<T*> freeList;  // 사용 가능한 객체들을 저장하는 리스트
};

// 사용자 정의 클래스 예
class Enemy {
public:
    Enemy() { std::cout << "Enemy created.\n"; }
    ~Enemy() { std::cout << "Enemy destroyed.\n"; }
};

int main() {
    MemoryPool<Enemy> enemyPool(5);  // Enemy 객체 5개를 위한 메모리 풀 생성

    // Enemy 객체를 메모리 풀에서 할당받음
    Enemy* e1 = enemyPool.allocate();
    Enemy* e2 = enemyPool.allocate();

    // 할당받은 Enemy 객체를 메모리 풀로 반환
    enemyPool.deallocate(e1);
    enemyPool.deallocate(e2);

    // 메모리 풀에서 객체를 다시 할당받아 사용
    Enemy* e3 = enemyPool.allocate();
    Enemy* e4 = enemyPool.allocate();

    return 0;  // 프로그램 종료 시 MemoryPool 소멸자에서 모든 Enemy 객체가 삭제됨
}
