#include <iostream>

bool isPrime(long long);

int main()
{
	long long number;
	std::cout << "Input a number >> ";
	std::cin >> number;

	if (isPrime(number)) {
		std::cout << "Your number is prime.\n";
	}
	else {
		std::cout << "Your number is not prime.\n";
	}

	return 0;
}

bool isPrime(long long n) {
	if (n < 2) {
		return false;
	}
	else {
		long long j = 2;
		while (j * j <= n)
			if (n % j++ == 0) return false;
	}
	return true;
}