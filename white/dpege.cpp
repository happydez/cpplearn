#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

#define ull unsigned long long

bool isPrime(ull);
bool isValid(ull);
std::vector<ull> divisors(ull);

int main()
{
	for (ull i = 25317; i <= 51237; i++) {
		if (isValid(i)) {
			ull mp = -1;
			for (const auto& d : divisors(i)) {
				if (isPrime(d)) {
					mp = d;
				}
			}
			std::cout << i << " " << mp << std::endl;
		}
	}

	return 0;
}

bool isValid(ull n) {
	int kp = 0;
	std::vector<ull> div = divisors(n);
	for (const auto& d : div) {
		if (isPrime(d)) {
			kp++;
		}
	}
	return kp >= 6 ? true : false;
}

std::vector<ull> divisors(ull n) {
	std::vector<ull> div;
	for (ull i = 2; i < (int)std::sqrt(n); i++) {
		if (n % i == 0) {
			div.push_back(i);
			div.push_back(n / i);
		}
	}
	if (n % (int)std::sqrt(n) == 0) {
		div.push_back((int)std::sqrt(n));
	}
	std::sort(std::begin(div), std::end(div));
	return div;
}

bool isPrime(ull n) {
	if (n < 2) {
		return false;
	}
	else {
		ull j = 2;
		while (j * j <= n) {
			if (n % j++ == 0) {
				return false;
			}
		}
	}
	return true;
}