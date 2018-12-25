//Billy McAllister

#include <iostream>
#include <unordered_map>
#include <string>

//Only used a class object for practice. Useful if using multiple Vending Machines(VM).
//Actually entire project is for practice
class machine {
public: 

	double cost, price, amount, remainder, inserted;
	std::string input;

	std::unordered_map<std::string, double> items = { { "coke", 1 },{ "monster", 2.75 }
		,{ "snack", 0.75 },{ "gum", 0.25 } };

	double costs(std::string input) {
		for (int i = 0; i<input.length(); i++) {
			input[i] = tolower(input[i]);
		}
		for (auto& p : items) {
			if (input == p.first) {
				price = p.second;
			}
		}
		return price;
	}

	void Vending() {
		amount = price;

		while (price != 0) {
			std::cin >> inserted;
			price -= inserted;

			if (price > 0) {
				std::cout << "Remainder: $" << price << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

			if (price < 0) {
				price = abs(price);
				std::cout << "Change: $" << price << std::endl;
				price = 0;
			}

			if (price == 0) {
				std::cout << input << " has been dispensed";
			}
		}
		

	}

};

int main() {

	std::cout << "Please select an item from the list to vend.\n"
		<< "Coke - $1\t" << "Monster - $2.75\n" << "Snack - $0.75\t"
		<< "Gum - $0.25\n";

	machine VM;

	getline(std::cin, VM.input);

	std::cout << "Please insert: $" << VM.costs(VM.input) << std::endl;
	
	
	VM.Vending();


	std::cin.get();
	std::cin.get();
}