#include "main.h"

template<typename E>
Queue<E>::Queue() {}

template<typename E>
void Queue<E>::Enqueue(const E& element) {
    q.push(element);
}

template<typename E>
E* Queue<E>::Dequeue() {
    if (q.empty()) return nullptr;
    auto res = &q.front();
    q.pop();
    return res;
}

template<typename E>
size_t Queue<E>::size() const {
    return q.size();
}

template class Queue<int>;