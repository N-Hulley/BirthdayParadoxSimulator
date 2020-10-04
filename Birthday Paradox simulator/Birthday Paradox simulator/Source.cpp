#include <iostream>
#include <ctime>

inline int runSimulation(int * birthdays) {
	
	// Populate birthdays
	for (int i = 0; i < 365; i++)
		birthdays[i] = rand() % 364;

	// Check birthday
	for (int i = 0; i < 365; i++) 
		for (int x = 0; x < i; x++) 
			// When two birhtdays are the same
			if (x != i && birthdays[i] == birthdays[x]) 
				return i;

	return 366;
}

int main() {
	
	
	int PeopleTaken = 0;
	int totalSetSize = 100000;
	int most = 0;
	int least = 366;
	bool showCurrent = true;
	time_t  timev;
	srand(time(&timev));
	std::cout.precision(20);
	int * birthdays = new int[365];
	// GO FOREVER
	int iteration = 0;
	while (true) {
		iteration++;
		int amount;
		// Run simmulation
		for (int i = 1; i < totalSetSize + 1; i++) {

			// find the amount of people taken to have the same birthday to a sum
			amount = runSimulation(birthdays);
			if (amount > most) most = amount;
			PeopleTaken += amount;
		}
		// Output resaults
		printf("%s%i%s\n", "Using a set of ", totalSetSize * iteration, " people:");
		printf("%s%i\n", "   The most days it took was ", most);
		printf("%s%f\n\n", "   The mean days taken was ", double(PeopleTaken) / double(totalSetSize * iteration));
	}




	// Run simmulation
	for (int i = 1; i < totalSetSize+1; i++) {
		
		// find the amount of people taken to have the same birthday to a sum
		int amount = runSimulation(birthdays);
		if (amount > most) most = amount;
		if (amount < least) least = amount;
		PeopleTaken += amount;

		printf("%s%i%s%i\n", "Result for simulation ", i, " is ", amount);
	}
	std::cout << "\n\n\n\n";

	// Output resaults
	std::cout << "Using a set of " << totalSetSize << " people: \n";
	std::cout << "   The most days it took was " << most << '\n';
	std::cout << "   The least days it took was " << least << '\n';
	std::cout << "   The mean days taken was " << float(PeopleTaken) / float(totalSetSize);
	std::cout << "\n\nPress any key to continue...";
	std::cin.get();
}