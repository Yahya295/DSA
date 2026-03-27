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

public:
	myStack(int cap)
	{
		capacity = cap;
		arr = new T[capacity];
		topIndex = -1;
	}
	~myStack()
	{
		delete[] arr;
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
	}
	T pop()
	{
		if (this->isEmpty()) 
		{
			cout << "Stack Underflow! Cannot pop." << endl;
			return T(); 
		}
		return arr[topIndex--];
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
	do {
		cout << "\n--- Stack Menu ---\n";
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Top\n";
		cout << "4. Display\n";
		cout << "5. Check if Empty\n";
		cout << "6. Check if Full\n";
		cout << "0. Exit\n";
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
			s.display();
			break;
		case 5:
			cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
			break;
		case 6:
			cout << (s.isFull() ? "Stack is full." : "Stack is not full.") << endl;
			break;
		case 0:
			cout << "Exiting program..." << endl;
			break;
		default:
			cout << "Invalid choice! Try again." << endl;
		}
	} while (choice != 0);

	return 0;
}