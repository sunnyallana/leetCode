#include <iostream>
#include <queue>
using namespace std;


/*

Question:
Write a C++ function kthSmallestElement that takes an integer array receiveArray, its starting index receiveStart, size receiveSize, and an integer receiveK.The function should findand return the kth smallest element in the array using a max heap.

Code Explanation :
1) The function kthSmallestElement takes four parameters : an integer array receiveArray, starting index receiveStart, array size receiveSize, and an integer receiveK.
2) A priority_queue named pqOne is initialized as a max heap.This priority queue is used to store the k smallest elements encountered so far.
3) The first loop runs from the starting index(receiveStart) to receiveK - 1. During this loop, the first receiveK elements are inserted into the max heap.
4) The second loop runs from receiveK to receiveSize - 1. For each element in this range, if the element is smaller than the maximum element in the max heap(i.e., pqOne.top()), the maximum element is popped from the max heap, and the current element is inserted.
5) After processing all elements, the top element of the max heap(the kth smallest element) is returned.

*/


// Used max heap to find kth smallest element in O(nlogn)
int kthSmallestElement(int* receiveArray, int receiveStart, int receiveSize, int receiveK) {
	priority_queue<int> pqOne;
	for (int i = receiveStart; i < receiveK; i++) {
		pqOne.push(receiveArray[i]);
	}
	for (int i = receiveK; i < receiveSize; i++) {
		if (receiveArray[i] < pqOne.top()) {
			pqOne.pop();
			pqOne.push(receiveArray[i]);
		}
	}
	return pqOne.top();
}


/*

Question:

Implement a C++ function kthLargestElement that takes an integer array receiveArray, its starting index receiveStart, size receiveSize, and an integer receiveK.The function should findand return the kth largest element in the array using a min heap.

Code Explanation :

1) The function kthLargestElement takes four parameters : an integer array receiveArray, starting index receiveStart, array size receiveSize, and an integer receiveK.
2) A priority_queue named pqOne is initialized as a min heap using the greater comparator.This priority queue is used to store the k largest elements encountered so far.
3) The first loop runs from the starting index(receiveStart) to receiveK - 1. During this loop, the first receiveK elements are inserted into the min heap.
4) The second loop runs from receiveK to receiveSize - 1. For each element in this range, if the element is greater than the minimum element in the min heap(i.e., pqOne.top()), the minimum element is popped from the min heap, and the current element is inserted.
5) After processing all elements, the top element of the min heap(the kth largest element) is returned.

*/


// Used min heap to find kth largest element in O(nlogn)
int kthLargestElement(int* receiveArray, int receiveStart, int receiveSize, int receiveK) {
	priority_queue<int, vector<int>, greater<int>> pqOne;
	for (int i = receiveStart; i < receiveK; i++) {
		pqOne.push(receiveArray[i]);
	}
	for (int i = receiveK; i < receiveSize; i++) {
		if (receiveArray[i] > pqOne.top()) {
			pqOne.pop();
			pqOne.push(receiveArray[i]);
		}
	}
	return pqOne.top();
}



int main(void) {
	int* arrayOne = new int[5];
	arrayOne[0] = 99999;
	arrayOne[1] = 99;
	arrayOne[2] = 22;
	arrayOne[3] = 666;
	arrayOne[4] = 74;
	cout << kthSmallestElement(arrayOne, 0, 5, 3) << endl;
	cout << kthLargestElement(arrayOne, 0, 5, 2) << endl;
}


