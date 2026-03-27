#include<iostream>
#include<string>
using namespace std;

class myCarStack
{
private:
	string arr[8];
	int topIndex;

public:
	myCarStack()
	{
		topIndex = -1;
	}
	bool isFull() const
	{
		return topIndex == 7;
	}
	bool isEmpty() const
	{
		return topIndex == -1;
	}
	void pushCar(string carNumber)
	{
		if (isFull())
		{
			cout << "Parking Lot Full! Cannot park car " << carNumber << endl;
			return;
		}
		arr[++topIndex] = carNumber;
		cout << "Car " << carNumber << " parked successfully!" << endl;
	}
	string popCar()
	{
		if (isEmpty())
		{
			cout << "The Parking Lot is Empty!" << endl;
			return "";
		}
		return arr[topIndex--];
	}
	void removeCar(string carNumber)
	{
		if (isEmpty())
		{
			cout << "Parking lot is empty! No car to remove!" << endl;
			return;
		}

		myCarStack temp;
		bool found = false;
		string current;

		while (!isEmpty())
		{
			current = popCar();
			if (current == carNumber)
			{
				cout << "Car " << carNumber << " removed successfully!" << endl;
				found = true;
				break;
			}
			else
			{
				temp.pushCar(current);
			}
		}
		while (!(temp.isEmpty()))
		{
			pushCar(temp.popCar());
		}
		if (!found)
		{
			cout << "Car " << carNumber << " not found in parking lot." << endl;
		}
	}
	bool searchCar(string carNumber) const 
	{
		for (int i = 0; i <= topIndex; i++) 
		{
			if (arr[i] == carNumber) return true;
		}
		return false;
	}
	void displayCars() const 
	{
		if (isEmpty())
		{
			cout << "Parking Lot is empty!" << endl;
			return;
		}
		cout << "Cars in parking lot (front to back): ";
		for (int i = topIndex; i >= 0; i--) 
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	int countCars() const 
	{
		return topIndex + 1;
	}

	string topCar() const 
	{
		if (isEmpty())
		{
			cout << "Parking Lot is empty!" << endl;
			return "";
		}
		return arr[topIndex];
	}
};

int main() 
{
	myCarStack parkingLot;
	int choice;
	string carNumber;

	do {
		cout << "\n--- Parking Lot Menu ---\n";
		cout << "1. Park a new car\n";
		cout << "2. Remove top car\n";
		cout << "3. Remove a specific car\n";
		cout << "4. Show car at front\n";
		cout << "5. Show total cars parked\n";
		cout << "6. Display all cars\n";
		cout << "7. Search for a car\n";
		cout << "8. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter car number: ";
			cin >> carNumber;
			parkingLot.pushCar(carNumber);
			break;
		case 2:
			cout << "Removed car: " << parkingLot.popCar() << endl;
			break;
		case 3:
			cout << "Enter car number to remove: ";
			cin >> carNumber;
			parkingLot.removeCar(carNumber);
			break;
		case 4:
			cout << "Car at front: " << parkingLot.topCar() << endl;
			break;
		case 5:
			cout << "Total cars parked: " << parkingLot.countCars() << endl;
			break;
		case 6:
			parkingLot.displayCars();
			break;
		case 7:
			cout << "Enter car number to search: ";
			cin >> carNumber;
			cout << (parkingLot.searchCar(carNumber) ? "Car found." : "Car not found.") << endl;
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