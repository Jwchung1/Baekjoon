#include <iostream>
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Resource 획득\n"; }
    ~Resource() { std::cout << "Resource 해제\n"; }
    void doSomething() { std::cout << "Resource 작업 수행\n"; }
};

void uniqueOwnership() {
    std::unique_ptr<Resource> res = std::make_unique<Resource>();
    res->doSomething();
    // res가 스코프를 벗어나면 Resource는 자동으로 해제됨
}

void sharedOwnership() {
    std::shared_ptr<Resource> res1 = std::make_shared<Resource>();
    {
        std::shared_ptr<Resource> res2 = res1; // 공유 소유권
        res2->doSomething();
        // res2가 스코프를 벗어나도 res1이 여전히 소유하고 있으므로 Resource는 해제되지 않음
    }
    res1->doSomething();
    // res1이 스코프를 벗어나면 Resource가 해제됨
}

int main() {
    uniqueOwnership();
    sharedOwnership();
    return 0;
}
