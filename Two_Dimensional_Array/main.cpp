#include <iostream>
using std::cout;

#include "Array2D.h"
#include "Row.h"

int main()
{
	cout << "\n--- Testing default ctor ---\n";
	Array2D<int> intArray;

	cout << "\n--- Testing 2-arg ctor ---\n";
	Array2D<int> intArray2Arg(4, 4);

	cout << "\n--- Testing operator[] in Array2D and Row, by pushing values into array ---\n"
		<< "--- Also testing Array2D getRow and getColumn methods ---\n";
	int value = 1;


	for (int row = 0; row < intArray2Arg.getRow(); row++)
	{
		for (int col = 0; col < intArray2Arg.getColumn(); col++)
		{
			cout << "intArray2Arg[" << row << "][" << col << "] = " << value << '\n';
			intArray2Arg[row][col] = value++;
		}
	}

	cout << "\n--- Testing copy ctor ---\n";
	Array2D<int> intArrayCopy(intArray2Arg);

	cout << "\n--- Testing Array2D operator= ---\n";
	intArray = intArrayCopy;

	cout << "\n\n";

	return 0;
}