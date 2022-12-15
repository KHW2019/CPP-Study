#include <iostream>
using namespace std;

int CheckNumber(unsigned int num) {

	if (num <= 1) {
		return 1;
	}

	unsigned int result = 0;
	//cout << "Number before for loop == " << num << endl;

	for (int i = 0; i < num; i++) {
		//cout << endl;
		cout << "Before result : " << result << endl;
		//cout << "i Value: " << i << endl;
		//cout << "Ci = " << CheckNumber(i) << endl;
		//cout << "Number in for loop == " << num << endl;
		//cout << "Cn - i -1 = " << CheckNumber(num - i -1) << endl;
		//cout << "Ci * Cn - i -1 = " << CheckNumber(i) * CheckNumber(num - i - 1) << endl;

		result += CheckNumber(i) * CheckNumber(num - i - 1);

		cout << "After result : " << result << endl;
		//cout << endl;
	}

	return result;


}

int main() {
	int num;
	cin >> num;    //Reading input from STDIN
	cout << "Output number is " << CheckNumber(num) << endl;	// Writing output to STDOUT
	return 0;
}