#include <iostream>
#include <stdexcept>

using namespace std;

class MyArrayParent
{
protected:
	int capacity;
	int count;

	double* ptr;
public:
	MyArrayParent(int Dimension = 100)
	{
		cout << "MyArrayConstructor" << endl;
		ptr = new double[Dimension];
		capacity = Dimension;
		count = 0;
	}

	MyArrayParent(double* arr, int len)
	{
		cout << "MyArrayConstructor" << endl;
		capacity = len; 
		count = len;
		ptr = new double[capacity]; 

		for (int i = 0; i < count; i++) {
			ptr[i] = arr[i]; 
		}
	}

	~MyArrayParent()
	{
		cout << "MyArrayDestructor";
		if (ptr != NULL)
		{
			delete[] ptr;
			ptr = NULL;
		}
	}

	int Capacity() { return capacity; }
	int Size() { return count; }
	double GetComponent(int index)
	{
		if (index >= 0 && index < count)
			return ptr[index];
		return -1;

	}

	void SetComponent(int index, double value)
	{
		if (index >= 0 && index < count)
			ptr[index] = value;
	}

	void push(double value)
	{
		if (count < capacity)
		{
			ptr[count] = value;
			count++;
		}
		else
		{
			throw runtime_error("Ошибка: превышено максимальное количество элементов в массиве.");
		}
	}

	void RemoveLastValue()
	{
		if (count >= 0)
			count--;
	}

	double& operator[](int index) {
		if (index < 0 || index >= count) {
			throw out_of_range("Index out of range");
		}
		return ptr[index];
	}

	MyArrayParent& operator=(const MyArrayParent& V) {
		cout << "operator = " << endl;

		if (this != &V) { 
			if (ptr != nullptr) {
				delete[] ptr;
				ptr = nullptr;
			}

			capacity = V.capacity;
			count = V.count;
			ptr = new double[capacity];
			for (int i = 0; i < count; i++) {
				ptr[i] = V.ptr[i];
			}
		}

		return *this; 
	}

	MyArrayParent(const MyArrayParent& V) : capacity(V.capacity), count(V.count) {
		cout << "Copy constructor" << endl;
		ptr = new double[capacity];

		for (int i = 0; i < count; i++) {
			ptr[i] = V.ptr[i]; 
		}
	}


	void print()
	{
		cout << "MyArr, size: " << count << ", values: {";
		int i = 0;
		for (i = 0; i < count; i++)
		{
			cout << ptr[i];
			if (i != count - 1)
				cout << ", ";
		}
		cout << "}";
	}

	int IndexOf(double value)
	{
		for (int i = 0; i < count; i++) {
			if (ptr[i] == value) {
				return i;
			}
		}

		return -1; 
	}

};

class MyArrayChild : public MyArrayParent
{
public:
	MyArrayChild(int Dimension = 100) : MyArrayParent(Dimension) { cout << "My array child constructor"; }

	~MyArrayChild() { cout << "MyArrayChild destructor"; }

	void RemoveAt(int index = -1) {
		if (index == -1) {
			if (count > 0) {
				count--;
			}
		}
		else if (index >= 0 && index < count) {
			for (int i = index; i < count - 1; i++) {
				ptr[i] = ptr[i + 1];
			}
			count--;
		}
	}

	int IndexOf(double value, bool bFindFromStart = true) {
		if (bFindFromStart) {
			for (int i = 0; i < count; i++) {
				if (ptr[i] == value) {
					return i; 
				}
			}
		}
		else {
			for (int i = count - 1; i >= 0; i--) {
				if (ptr[i] == value) {
					return i; 
				}
			}
		}
		return -1; 
	}

	void InsertAt(int index, double value = -1) {
		if (index >= 0 && index <= count) {
			if (value != -1) {
				if (count < capacity) {
					for (int i = count; i > index; i--) {
						ptr[i] = ptr[i - 1];
					}
					ptr[index] = value;
					count++;
				}
				else {
					throw runtime_error("Ошибка: превышено максимальное количество элементов в массиве.");
				}
			}
			else {
				throw invalid_argument("Ошибка: не передано значение для вставки.");
			}
		}
	}

	MyArrayChild SubSequence(int StartIndex = 0, int Length = -1) {
		if (StartIndex < 0 || StartIndex >= count) {
			throw out_of_range("StartIndex is out of range");
		}

		if (Length == -1 || Length > count - StartIndex) {
			Length = count - StartIndex;
		}

		MyArrayChild subArray(Length);
		for (int i = 0; i < Length; i++) {
			subArray.push(ptr[StartIndex + i]);
		}

		return subArray;
	}


	MyArrayChild FilterArrayByCondition() {
		MyArrayChild resultArray(count);
		for (int i = 0; i < count; i++) {
			int number = static_cast<int>(ptr[i]); 
			int a = number / 10000;
			int b = (number / 1000) % 10;
			int c = (number / 100) % 10;
			int d = (number / 10) % 10;
			int e = number % 10;

			if (a * b == c && d * e == c) {
				resultArray.push(ptr[i]); 
			}
		}

		return resultArray;
	}

	MyArrayChild operator+(double value) {
		MyArrayChild result(*this); 
		result.push(value); 
		return result;
	}




};

class MySortedArray : public MyArrayChild {
public:
	MySortedArray(int Dimension = 100) : MyArrayChild(Dimension) {
		cout << "Конструктор MySortedArray" << endl;
	}

	MySortedArray FilterArrayByCondition() override {
		MySortedArray resultArray(count);
		int j = 0;
		for (int i = 0; i < count; i++) {
			if (i == 0 || ptr[i] >= ptr[i - 1]) {
				resultArray.push(ptr[i]);
				j++;
			}
		}
		return resultArray;
	}

	void push(double value) override {
		int i = count - 1;
		while (i >= 0 && ptr[i] > value) {
			ptr[i + 1] = ptr[i];
			i--;
		}
		ptr[i + 1] = value;
		count++;
	}

	int IndexOf(double value) override {
		int low = 0;
		int high = count - 1;

		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (ptr[mid] == value) {
				return mid;
			}
			else if (ptr[mid] < value) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}

		return -1;
	}
};


int main()
{
	if (true)
	{
		MyArrayParent arr;
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			arr.push(i + 1);
		}
		MyArrayParent p1;

		p1 = arr;
		p1.print();
		cout << endl;
	}
	char c; cin >> c;
	return 0;
}

