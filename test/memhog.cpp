#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstring>  // for memset

int main() {
    std::vector<char*> allocations;

    std::cout << "Allocating ~100MB of memory...\n";

    for (int i = 0; i < 100; ++i) {
        char* block = new char[1024 * 1024]; // 1MB
        memset(block, 1, 1024 * 1024);       // <-- Ghi vào toàn bộ block để ép kernel cấp RAM
        allocations.push_back(block);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    std::cout << "Done allocating. Sleeping...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));

    for (auto ptr : allocations) {
        delete[] ptr;
    }

    std::cout << "Freed memory.\n";
    return 0;
}
