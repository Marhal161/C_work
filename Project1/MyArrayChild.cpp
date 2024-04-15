#include <iostream>

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

	}

	void RemoveLastValue()
	{
		if (count >= 0)
			count--;
	}

	double& operator[](int index)
	{


	}

	MyArrayParent& operator=(const MyArrayParent& V)
	{
		cout << "operator = " << endl;
	}

	MyArray(const MyArrayParent& V)
	{
		cout << "Copy constructor";
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