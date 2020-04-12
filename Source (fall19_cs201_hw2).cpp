#include <string>
#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

bool flag = false;

void linearSearch(int arr[], int num, int size) {

	int n = 0, pos = 0, c = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num)
		{
			c = 1;
			pos = i + 1;
			break;
		}
	}
	if (!flag) {
		if (c == 0) {
			cout << "Number not found..!!";
		}
		else {
			cout << num << " found at position " << pos << endl;
		}
		flag = true;
	}
}

int binarySearch(int arr[], int num, int top, int bottom) {
	if (bottom > top)
		return -1;
	int mid = (bottom + top) / 2;
	if (arr[mid] == num)
		return mid;
	if (arr[mid] > num)
		return binarySearch(arr, num, mid - 1, bottom);
	return binarySearch(arr, num, top, mid + 1);
}

//Helper function for adding elements into the array in sorted order
void arrADD(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = i;
	}
}

int main() {
	
	long int SIZE = 4194304;
	int* arr = new int[SIZE];
	int M;
	int const key = SIZE + 2;
	double duration;

	arrADD(arr, SIZE);

	clock_t startTime = clock();	
	//for (M = 0; M < 100; ++M) {
	//	linearSearch(arr, key, SIZE);
	//}
	for (M = 0; M < 100000; ++M) {
		binarySearch(arr, key, SIZE, 0);
	}
	duration = double(1000 * double(clock() - double(startTime)) / CLOCKS_PER_SEC);
	duration = duration / M;

	cout << "Execution took " << duration << " milliseconds." << endl;

	delete[] arr;
	arr = NULL;

	return 0;
}