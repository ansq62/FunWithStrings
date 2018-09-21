/***************************************************************************
 * This program executes two main parts.  Part A gives a userprompt for the *
 * size and values of an array.  It then passes an array to a function that *
 * determines the smallest value, then dynamically allocates a new array    *
 * that duplicates the first array WITHOUT the smallest values.  In Part B, *
 * the program executes a userprompt for a C++ string that is then passed   *
 * to a function with a variable of type WordSplit (shown below). The first *
 * and the last words of the string will be determined and stored in various*
 * elements of WordSplit.                                                   *
 ****************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


struct WordSplit {
	string originalString;
	string lastWord;
	string firstWord;
	int totalWords;
};

//Function prototypes for PART A. The definitions of these
//functions are below.
int *duplicate_without_smallest (int [], int, int&);
int find_lowest (int[], int);
void display_array (int[], int);

//Function prototypes for PART B.  The definitions of these
//functions are below.
void funWithStrings (string, WordSplit&);
void displayStrElements(WordSplit);



int main()
{
	/***********************PART A**************************/
	int n;
	cout << "Please enter a size"; //User input for array size.
	cin >> n;

	const int SIZE = n;
	int mainArr[SIZE];

	for(int count = 0; count < SIZE; count++)//User input for array.
	{
		cout << "Please enter number " << count + 1 << endl;
		cin >> mainArr[count];
	}

	int dupSIZE = 0; //allocated memory for duplicate array.
	int *dupArr = nullptr;
	dupArr = duplicate_without_smallest (mainArr, SIZE, dupSIZE);//FUNCTION CALL.

	cout << "Here is our first array: " << endl;
	display_array(mainArr, SIZE);//FUNCTION CALL.

	cout << "Here is our duplicate array without the lowest value: " << endl;
	display_array(dupArr, dupSIZE);//FUNCTION CALL.

	delete [] dupArr;//Free up allocated memory.
	dupArr = nullptr;

	/************************PART B**************************/

	cin.ignore(); //Skip what's in keyboard buffer.
	string input;
	WordSplit words;//STRUCT variable.
	cout << "Please enter a string: ";
	getline(cin, input);

	funWithStrings(input, words); //FUNCTION CALL.

	displayStrElements(words); //FUNCTION CALL.


	return 0;
}

/******************************************************************
 * This function searches a given array for the smallest element. *
 * It then sums up the the number of duplicate elements of the    *
 * smallest element and stores the sum in a counter variable.  It *
 * then dynamically allocates an array to hold the original array *
 * MINUS THE SMALLEST ELEMENTS. Lastly, it returns the size of the*
 * smaller array as well as the smaller size (through ref var).   *
 ******************************************************************/

int *duplicate_without_smallest (int array[], int arraySIZE, int &newSIZE)
{
	int smallest = find_lowest(array, arraySIZE); //FUNCTION CALL.

	int index;
	int count = 0;

	for(index = 0; index < arraySIZE; index++)
	{
		if(array[index] != smallest)
		{
			newSIZE++;
		}
	}

	int *newArr = nullptr;  //Dynamic allocation of an array.
	newArr = new int[newSIZE];

	for(index = 0; index < arraySIZE; index++)
	{
		if(array[index] != smallest) //smallest is not included.
		{
			newArr[count] = array[index];
			count++;
		}
	}

	return newArr;


}

/***************************************************************
 *This function finds the lowest value in a given array then   *
 *returns it through the return statement                      *
 ***************************************************************/

int find_lowest (int array[], int arraySIZE)
{
	int lowest;
	lowest = array[0];
	for (int count = 1; count < arraySIZE; count++)
	{
		if(array[count] < lowest)
		{
			lowest = array[count];
		}
	}
	return lowest;
}

/*************************************************************
 * This function displays a given array of a given size.     *
 *************************************************************/

void display_array (int array[], int SIZE)
{
	for (int count = 0; count < SIZE; count++)
	{
		cout << array[count] << " ";
	}

	cout << endl;
}

/*************************************************************
 * This function:                                            *
 * 1) Calculates the total number of words of a given string.*
 * 2) Stores that string into the given WordSplit variable   *
 *    element .originalString.                               *
 * 3) Finds the first word in the string and stores it in    *
 *    .firstWord.                                            *
 * 4) Finds the last word in the string and stores it in     *
 *    .lastWord.                                             *
 *************************************************************/
void funWithStrings (string firstStr, WordSplit &wordStuff)
{
	int wordCount;
	int curPos = 0; //Position of .find.
	bool wordFound = true;

	while(wordFound == true)
	{

		if(firstStr.find(' ', curPos) != string::npos)
		{
			curPos = firstStr.find(' ', curPos) + 1;
			wordCount++;
		}

		else //Counts one word strings.
		{
			wordCount++;
			wordFound = false;
		}


	}
	wordStuff.totalWords = wordCount;

	//Stores the string in the WordSplit variable.
	wordStuff.originalString = firstStr;



	//This is the code for storing the first word.
	int sizeFirst = 0;
	if(wordStuff.originalString.find(' ') != string::npos)
	{
		sizeFirst = wordStuff.originalString.find(' ');
		wordStuff.firstWord = wordStuff.originalString.substr(0, sizeFirst);
	}



	//This is the code for storing the last word.
	int sizeLast = wordStuff.originalString.size() - curPos;
	wordStuff.lastWord = wordStuff.originalString.substr(curPos, sizeLast);

}

/***************************************************************
 * This function displays the contents of the struct variable  *
 * WordSplit.                                                  *
 ***************************************************************/

void displayStrElements(WordSplit wordStuff)
{
	cout << "The original string is \"" << wordStuff.originalString << "\".";
	cout << "The first word of the string is \"" << wordStuff.firstWord << "\",";
	cout << " and the last word of the string is \"" << wordStuff.lastWord;
	cout << "\"." << endl;
	cout << "This string contained " << wordStuff.totalWords << " words.";
}

