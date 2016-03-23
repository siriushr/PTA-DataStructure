#include <iostream>
using namespace std;

void PrintN(int N) {
			 if (N) {
				 PrintN(N - 1);
				 printf("%d\n", N);
			 }
			 return;
		 }

int main() {
	int N;
	cin >> N;
	PrintN(N);
	return 0;
}
