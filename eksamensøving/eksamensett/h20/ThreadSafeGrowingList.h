//
// Created by ingebrigt on 15.11.2021.
//

#ifndef H20_THREADSAFEGROWINGLIST_H
#define H20_THREADSAFEGROWINGLIST_H


#include <vector>
#include <mutex>
#include <functional>

class ThreadSafeGrowingList {
private:
    static std::mutex nums_mutex;
    std::vector<int> nums;
public:
    ThreadSafeGrowingList() : nums() {}
    void add(int i);
    void for_each(const std::function<void(int) > &lambda);
};


#endif //H20_THREADSAFEGROWINGLIST_H
