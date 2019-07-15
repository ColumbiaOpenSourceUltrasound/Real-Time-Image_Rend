//
//  Wrapper to make queue thread-safe
//
//  Copyright © 2019 Saveliy Yusufov <sy2685@columbia.edu>
//
//

#ifndef SAFE_QUEUE_H
#define SAFE_QUEUE_H

#include <mutex>
#include <queue>


template<class T>
class SafeQueue {

private:
    std::queue<T> q;
    std::mutex m;

public:

    void push(T elem) {
        std::lock_guard<std::mutex> lock(m);
        q.push(elem);
    }

    bool pop_front(T& elem) {
        std::lock_guard<std::mutex> lock(m);

        if (q.empty()) {
            return false;
        }
        elem = q.front();
        q.pop();

        return true;
    }

    int size() {
        std::lock_guard<std::mutex> lock(m);
        return q.size();
    }

};
#endif
