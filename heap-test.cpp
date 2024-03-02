
#include <iostream>
#include "heap.h"

using namespace std;


void print(Heap<int> &h) {
    for (size_t i = 0; i < h.size(); i++) {
        cout << h.v[i] << " ";
    }
    cout << endl;
}

void clear(Heap<int> &h) {
    while (!h.empty())
        h.pop();
}

int main() {
    Heap<int> h;
    h.push(5);
    h.push(3);
    h.push(7);
    h.push(1);
    print(h);
    h.pop();
    print(h);
    h.push(29);
    h.push(2);
    print(h);
    h.push(23);
    h.push(11);
    print(h);
    h.pop();
    print(h);
    h.push(17);
    h.push(13);
    print(h);
}