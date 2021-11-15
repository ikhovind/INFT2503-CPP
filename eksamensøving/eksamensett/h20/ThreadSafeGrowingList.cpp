//
// Created by ingebrigt on 15.11.2021.
//

#include <functional>
#include "ThreadSafeGrowingList.h"
#include <mutex>

std::mutex ThreadSafeGrowingList::nums_mutex;

void ThreadSafeGrowingList::for_each(const std::function< void(int)> &lambda) {
    std::lock_guard<std::mutex> lock(ThreadSafeGrowingList::nums_mutex);
    for (auto a : this->nums) {
        lambda(a);
    }
}

void ThreadSafeGrowingList::add(int i) {
    std::lock_guard<std::mutex> lock(ThreadSafeGrowingList::nums_mutex);
    this->nums.emplace_back(i);
}
