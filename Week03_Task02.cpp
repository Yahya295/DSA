#include<iostream>
using namespace std;

template <typename T>
class AbstractStack 
{
public:
	virtual void push(T value) = 0;
	virtual T pop() = 0;
	virtual T top() const = 0;
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
	virtual ~AbstractStack() {}
};

template <typename T>
class myStack : public AbstractStack<T>
{
private:
	T* arr;
	int capacity;
	int topIndex;

	T* minArr;
	int minTopIndex;

public:
	myStack(int cap)
	{
		capacity = cap;
		arr = new T[capacity];
		topIndex = -1;

		minArr = new T[capacity];
		minTopIndex = -1;
	}
	~myStack()
	{
		delete[] arr;
		delete[] minArr;
	}
	void push(T value)
	{
		if (this->isFull())
		{
			cout << "Stack Overflow! Cannot push " << value << endl;
			return;
		}
		else
		{
			arr[++topIndex] = value;
		}
		if (minTopIndex == -1 || value <= minArr[minTopIndex]) 
		{
			minArr[++minTopIndex] = value;
		}
	}
	T pop()
	{
		if (isEmpty()) 
		{
			cout << "Stack Underflow! Cannot pop." << endl;
			return T();
		}

		T popped = arr[topIndex--];   

		if (popped == minArr[minTopIndex]) 
		{
			minTopIndex--;
		}

		return popped;
	}

	T top() const
	{
		if (this->isEmpty())
		{
			cout << "Stack is empty!" << endl;
			return T();
		}
		return arr[topIndex];
	}
	T getMin() const 
	{
		if (minTopIndex == -1) {
			cout << "Stack is empty! No minimum." << endl;
			return T();
		}
		return minArr[minTopIndex];
	}
	bool isEmpty() const
	{
		return topIndex == -1;
	}
	bool isFull() const
	{
		return topIndex == capacity - 1;
	}
	void display() const 
	{
		if (this->isEmpty()) 
		{
			cout << "Stack is empty!" << endl;
			return;
		}
		cout << "Stack elements (top to bottom): ";
		for (int i = topIndex; i >= 0; i--) 
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() 
{
	int size;
	cout << "Enter maximum size of stack: ";
	cin >> size;

	myStack<int> s(size);

	int choice, value;
	do 
	{
		cout << "\n--- Stack Menu ---\n";
		cout << "1. Push element\n";
		cout << "2. Pop element\n";
		cout << "3. Show top element\n";
		cout << "4. Check if stack is empty\n";
		cout << "5. Check if stack is full\n";
		cout << "6. Display stack elements\n";
		cout << "7. Show minimum element\n";
		cout << "8. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter value to push: ";
			cin >> value;
			s.push(value);
			break;
		case 2:
			cout << "Popped value: " << s.pop() << endl;
			break;
		case 3:
			cout << "Top value: " << s.top() << endl;
			break;
		case 4:
			cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
			break;
		case 5:
			cout << (s.isFull() ? "Stack is full." : "Stack is not full.") << endl;
			break;
		case 6:
			s.display();
			break;
		case 7:
			cout << "Minimum element: " << s.getMin() << endl;
			break;
		case 8:
			cout << "Exiting program..." << endl;
			break;
		default:
			cout << "Invalid choice! Try again." << endl;
		}
	} while (choice != 8);

	return 0;
}
