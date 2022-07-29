#include <iostream>
#include <vector>
#include <random>
#include <chrono>  

using namespace std;


int main()
{
	vector<int>Item{ 0,1,2,3,4,5,6,7,8,9 };  // values for entry
	vector<int>Result(4, 0); // initialize the Core vector with 0 spaces and 0 value (as default vector already initialize int with 0)
	vector<int>Try(4, 0); // initialize the vector input with 4 spaces and 10 value;

	  
	unsigned seed = chrono::system_clock::now().time_since_epoch().count(); // obtain a time-based seed:

	shuffle(Item.begin(), Item.end(), default_random_engine(seed));

	for (int i = 0; i < 4; i++) // Generate the Vector and increase its size to 4 spaces
	{
		Result.at(i) = Item.at(i); // random numbers for each space
	}

	cout << "\t" << "Welcome to Bull and Cows Game" << endl
		<< "\t" << "The rules of the game are simples" << endl
		<< "\n" << "You have to hit 4 numbers in 4 allocations (Numbers from 0 to 9)" << endl
		<< "\n" << "A Bull means that you hit a right number in the right spot" << endl
		<< "\n" << "A Cow means that you hit a right number in the wrong spot" << endl
		<< "\n" << "HAVE FUN!" << endl;

	while (1) // game loop for each attempt
	{
		bool CC = false;

			for (int i = 0; i < Try.size(); i++)
			{
				char Get;
				int Char_value = '0';
				cin >> Get;
				Get -= Char_value;
				Try.at(i) = Get;
			}

		int Cow_general_count = 0;
		int Cow_count = 0;
		int Bull_count = 0;

		for (int i = 0; i < Result.size(); i++)
		{
			if (Result.at(i) == Try.at(i)) Bull_count++;

			for (int j = 0; j < Result.size(); j++)
			{
				if (Result.at(i) == Try.at(j)) Cow_general_count++;
			}
		}

			Cow_count = Cow_general_count - Bull_count;
		
		cout << "\n" << "\t" << "Bull" << "\t" << "Cow" << endl
			<< "\t" << Bull_count << "\t" << Cow_count << endl;

		if (Bull_count == 4)
		{
			cout << "\nParabens, Voce conseguiu!!!!!" << "\n\n";
			return 0;
		}

	}
	return 0;
}

