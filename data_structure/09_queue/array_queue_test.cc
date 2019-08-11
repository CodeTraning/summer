#include <iostream>
#include "array_queue.hpp"
using namespace std;

int main() {
	auto do_traverse = [&](auto item) { cout << item << ' '; };

	ArrayQueue<int> array_queue_1(3);
	array_queue_1.enqueue(1);
    array_queue_1.enqueue(2);
    array_queue_1.enqueue(3);
    // array_queue_1.enqueue(4);  // throw
    array_queue_1.traverse(do_traverse);
    cout << "#" <<endl;

    ArrayQueue<int> array_queue_2(array_queue_1); // copy constructor
    array_queue_2.traverse(do_traverse);
    cout << "$" << endl;


    ArrayQueue<int> array_queue_3(move(array_queue_2));  // move constructor
    array_queue_3.traverse(do_traverse);
    cout << "#" << endl;
    array_queue_2.traverse(do_traverse);
    cout << "$" << endl;

    cout << array_queue_3.head() << endl;
    array_queue_3.dequeue();
    cout << array_queue_3.head() << endl;
    array_queue_3.dequeue();
    cout << array_queue_3.head() << endl;
    array_queue_3.dequeue();
    // cout << array_queue_3.head() << endl;  // throw
    // array_queue_3.dequeue();  // throw
    cout << "#" << endl;

    ArrayQueue<int> array_queue_4(1);
    array_queue_4 = array_queue_1;  // copy assignment
    array_queue_4.traverse(do_traverse);
    cout << "$" << endl;

    ArrayQueue<int> array_queue_5(100);
    array_queue_5 = move(array_queue_4);  // move assignment
    array_queue_5.traverse(do_traverse);
    cout << endl;
    array_queue_4.traverse(do_traverse);
    cout << endl;

    cout << array_queue_5.head() << endl;
    array_queue_5.dequeue();
    cout << array_queue_5.head() << endl;
    array_queue_5.dequeue();
    cout << array_queue_5.head() << endl;
    array_queue_5.dequeue();
    // cout << array_queue_5.head() << endl;  // throw
    // array_queue_5.dequeue();  // throw

    return 0;
}