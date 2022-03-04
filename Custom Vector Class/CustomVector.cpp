#include <iostream>
#include <assert.h>
using namespace std;

template <typename T, size_t initialSize = 5>
class CustomVector
{
private:
	T* arr = new T[initialSize];
	size_t currentCapacity = initialSize;
	size_t count{};
	typedef T* iterator;
	typedef const T* const_iterator;

public:
	CustomVector() {}
	CustomVector(initializer_list<T> dataList)
	{
		for (T data : dataList)
		{
			push_back(data);
		}
	}
	void push_back(T data)
	{
		count++;
		if (count >= currentCapacity)
		{
			increaseSize();
		}
		arr[count - 1] = data;
	}
	T pop_back()
	{
		T data = arr[count - 1];
		arr[count - 1] = T{}; // resets empty slot to default value of T
		count--;
		return data;
	}
	size_t size()
	{
		return count;
	}
	T at(int index)
	{
		return arr[index];
	}
	void increaseSize()
	{
		const int size = currentCapacity * 2;
		T* newArr = new T[size];
		for (size_t i = 0; i < count; i++)
		{
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = nullptr;
		arr = newArr;
		currentCapacity = size;
	}
	T& operator[](int index)
	{
		assert(index >= 0 && index < (int)count);
		return arr[index];
	}
	const T& operator[](int index) const
	{
		assert(index >= 0 && index < (int)count);
		return arr[index];
	}
	~CustomVector() { delete[] arr; }
	iterator begin() { return &arr[0]; }
	const_iterator begin() const { return &arr[0]; }
	iterator end() { return &arr[count]; }
	const_iterator end() const { return &arr[count]; }
};

int main()
{

	CustomVector<int> customVector{1337, 666};
	customVector.push_back(1);
	customVector.push_back(2);
	customVector.push_back(3);
	customVector.push_back(4);
	customVector.push_back(5);

	//cout << customVector.pop_back() << endl;
	//cout << customVector.pop_back() << endl;

	//for (size_t i = 0; i < customVector.size(); i++)
	//{
	//	cout << customVector.at(i) << " ";
	//}
	for (int i : customVector)
	{
		cout << i << " ";
	}
	cout << "size: " << customVector.size() << endl;

	//cout << customVector[14];
}