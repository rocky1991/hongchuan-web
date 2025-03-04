// Triple 
// Demonstrates function overloading


#include <iostream>
#include <string>

using namespace std;

int triple(int number);
string triple(string text);
string triple(string a, string b);

int main() {
	cout << "Tripling 5: " << triple(5) << "\n\n";
	cout << "Tripling 'gamer': " << triple("gamer") << endl;
	cout << "Concating string: " << triple("sdf", "234") << endl;

	return 0;
}

int triple(int number) {
	return (number * 3);
}

string triple(string text) {
	return (text + text + text);
}
string triple(string a, string b){
	return (a + b);
}
