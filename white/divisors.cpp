#include <iostream>
#include <vector>
#include <algorithm>

std::vector<long long> divisors(long long);

int main()
{
	long long number;
	std::cout << "Input a natural number >> ";
	std::cin >> number;

	if (number < 1) {
		std::cout << "This number is not a natural.";
	}
	else {
		std::cout << "Number divisors: ";
		for (const auto& n : divisors(number)) {
			std::cout << n << " ";
		}
		std::cout << "\n";
	}

	return 0;
}

std::vector<long long> divisors(long long n) {
	long long nsqrt = (int)std::sqrt(n);
	std::vector<long long> div;

	for (long long i = 1; i <= nsqrt; i++) {
		if (n % i == 0) {
			div.push_back(i);
			if (i != nsqrt) {
				div.push_back(n / i);
			}
		}
	}

	std::sort(begin(div), end(div));
	return div;
}
