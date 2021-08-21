#pragma once
#include <queue>

template <typename E>  // E is the element type.
class Queue {
public:
  Queue();
  void Enqueue(const E& element);
  E* Dequeue();  // Returns NULL if the queue is empty.
  size_t size() const;
private:
  std::queue<E> q;
};

