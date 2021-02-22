// Finicky Counter 
// Demonstrates break and continue statements

#include <iostream>
using namespace std;

int main() {
	int count = 0;
	while (true) {
		count += 1;

		//end loop if count is greater than 10
		if (count > 10) {
			break;
		}

		if (count == 5) {
			continue;
		}

		cout << count << endl;
	}
}