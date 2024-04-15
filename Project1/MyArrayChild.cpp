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
			throw std::runtime_error("Ошибка: превышено максимальное количество элементов в массиве.");
		}
	}

	void RemoveLastValue()
	{
		if (count >= 0)
			count--;
	}

	double& operator[](int index) {
		if (index < 0 || index >= count) {
			throw std::out_of_range("Index out of range");
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

class MyAraayChild : public MyArrayParent
{
public:
	MyAraayChild(int Dimension = 100) : MyArrayParent(Dimension) { cout << "My array child constructor"; }

	~MyAraayChild() { cout << "MyArrayChild destructor"; }


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