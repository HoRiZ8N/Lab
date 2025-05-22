#include <vector>
#include <functional>
#include <stdexcept>

template<typename T, typename Compare = std::less<T>>
class PriorityQueue {
private:
    std::vector<T> data;
    Compare comp;

    void siftUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (comp(data[parent], data[index])) {
                std::swap(data[parent], data[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void siftDown(int index) {
        int size = data.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && comp(data[largest], data[left])) {
                largest = left;
            }
            if (right < size && comp(data[largest], data[right])) {
                largest = right;
            }
            if (largest != index) {
                std::swap(data[index], data[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    explicit PriorityQueue(const Compare& compare = Compare()) : comp(compare) {}

    void push(const T& value) {
        data.push_back(value);
        siftUp(data.size() - 1);
    }

    void pop() {
        if (empty()) {
            throw std::out_of_range("PriorityQueue is empty");
        }
        std::swap(data.front(), data.back());
        data.pop_back();
        if (!empty()) {
            siftDown(0);
        }
    }

    const T& top() const {
        if (empty()) {
            throw std::out_of_range("PriorityQueue is empty");
        }
        return data.front();
    }

    size_t size() const {
        return data.size();
    }

    bool empty() const {
        return data.empty();
    }
};