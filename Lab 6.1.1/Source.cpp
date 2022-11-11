#include <iostream>  

#include <iomanip>  

#include <time.h>  
using namespace std;

void random(int* mas, const int size, const int min, const int max, const int i) {
	mas[i] = min + rand() % (max - min + 1);
	if (i < size - 1)
		random(mas, size, min, max, i + 1);
}

void wivid(int* mas, const int size, const int i) {
	cout << setw(4) << mas[i];
	if (i < size - 1)
		wivid(mas, size, i + 1);
	else
		cout << setw(4) << endl;

}

int kilkist(int* mas, const int size, int n, int i) {
	if (i < size - 1) {
		if (mas[i] < 0)
			++n;
		kilkist(mas, size, n, i + 1);
	}
	else
		return n;
}


int suma(int* mas, const int size, int i, int S)
{
	S += mas[i];
	if (i < size - 1)
		return suma(mas, size, i + 1, S);
	else
		return S;
}


void criteriy(int* mas, const int size, int i) {
	if (i < size) {
		if (mas[i] > 0 || mas[i] % 2 != 0 && mas[i] < 0)
			mas[i] = 0;
		criteriy(mas, size, i + 1);
	}
	else
		cout << endl;
}

int main() {

	srand((unsigned)time(NULL));
	int min = -15;
	int max = 75;
	const int n = 24;
	int b[n];

	cout << "Massive: " << endl;
	random(b, n, min, max, 0);//putting random elements into empty array  
	wivid(b, n, 0); //printing filled with elements  
	cout << endl;

	criteriy(b, n, 0);//changing elements to zero  
	cout << "Final result: " << endl;
	wivid(b, n, 0);
	cout << endl;

	int num = kilkist(b, n, 0, 0);//number of elements we require  
	cout << "Amount of elements: " << num << endl;
	cout << endl;

	int sum = suma(b, n, 0, 0);//sum  
	cout << "Sum: " << sum << endl;
	cout << endl;

	return 0;
}
