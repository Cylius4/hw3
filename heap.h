#ifndef HEAP_H
#define HEAP_H

#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>

template<typename T, typename PComparator = std::less<T> >
class Heap {
public:
    /**
     * @brief Construct a new Heap object
     *
     * @param m ary-ness of heap tree (default to 2)
     * @param c binary predicate function/functor that takes two items
     *          as an argument and returns a bool if the first argument has
     *          priority over the second.
     */
    Heap(int m = 2, PComparator c = PComparator());

    /**
    * @brief Destroy the Heap object
    *
    */
    ~Heap();

    /**
     * @brief Push an item to the heap
     *
     * @param item item to heap
     */
    void push(const T &item);

    /**
     * @brief Returns the top (priority) item
     *
     * @return T const& top priority item
     * @throw std::underflow_error if the heap is empty
     */
    T const &top() const;

    /**
     * @brief Remove the top priority item
     *
     * @throw std::underflow_error if the heap is empty
     */
    void pop();

    /// returns true if the heap is empty

    /**
     * @brief Returns true if the heap is empty
     *
     */
    bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
    size_t size() const;

private:
    /// Add whatever helper functions and data members you need below

    void trickleUp(size_t loc);

    void trickleDown(size_t loc);

    friend void print(Heap<int> &h);

    std::vector<T> v;
    int m;
    PComparator comp;

};

// Add implementation of member functions here
template<typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    return v.size();
}

template<typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return v.empty();
}

template<typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m(m), comp(c) {
}

template<typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {
}

template<typename T, typename PComparator>
void Heap<T, PComparator>::push(const T &item) {
    v.push_back(item);
    trickleUp(v.size() - 1);
}

template<typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(size_t loc) {
    while (loc < size()) {
        size_t iSmallest = loc;
        for (int i = 1; i <= m && loc * m + i < size(); ++i) {
            if (comp(v[loc * m + i], v[iSmallest])) iSmallest = loc * m + i;
        }
        if (iSmallest == loc) return;
        std::swap(v[iSmallest], v[loc]);
        loc = iSmallest;
    }
}

template<typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(size_t loc) {
    for (int i = loc; i > 0; i = (i - 1) / m) {
        if (comp(v[i], v[(i - 1) / m])) std::swap(v[i], v[(i - 1) / m]);
        else return;
    }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template<typename T, typename PComparator>
T const &Heap<T, PComparator>::top() const {
    // Here we use exceptions to handle the case of trying
    // to access the top element of an empty heap
    if (empty()) {
        // ================================
        // throw the appropriate exception
        // ================================
        throw std::underflow_error("Heap is empty");
    }
    // If we get here we know the heap has at least 1 item
    // Add code to return the top element
    return v[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template<typename T, typename PComparator>
void Heap<T, PComparator>::pop() {
    if (empty()) {
        // ================================
        // throw the appropriate exception
        // ================================

        throw std::underflow_error("Heap is empty");
    }
    if (size() == 1) {
        v.pop_back();
        return;
    }
    v[0] = v.back();
    v.pop_back();
    trickleDown(0);

}


#endif

