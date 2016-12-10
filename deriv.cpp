#include <string>
#include <iostream>
#include <map>
#include <cctype>


void updateMap(std::map<int, int>* map, int a, int n) {
	auto iter = map->find(n);
	if (iter == map->end()) {
		(*map)[n] = a;		
	} else {
		iter->second = iter->second + a;
	}
}

std::map<int, int> readPolynomial(std::string input) {
	std::map<int, int> map;

	auto i = input.begin();
	
	while (true) {
		if (i == input.end()) break;

		int sign = 1;
		int a = 1;
		int n = 0;

		if (*i == '-') {
			sign = -1;
			i++;
		} else if (*i == '+') {
			sign = 1;
			i++;
		} 

		if (isdigit(*i)) {
			a = *i - '0';
			while (1) {
				i++;
				if (i == input.end() || !isdigit(*i)) break;
				a = 10 * a + (*i - '0');
			}

			if (i == input.end() || *i != '*') {
				updateMap(&map, a * sign, 0);
				continue;
			}
			i++;			
		}

		if (*i == 'x') {
			i++;
			if (i == input.end() || *i != '^') {
				updateMap(&map, a * sign, 1);
				continue;
			}
			i++; // skip ^
			n = *i - '0';
			while (1) {
				i++;
				if (i == input.end() || !isdigit(*i)) break;
				n = 10 * n + (*i - '0');
			} 
			updateMap(&map, a * sign, n);
		}
	}

	/*for (auto i = map.begin(); i != map.end(); i++) {
    	std::cout << i->first << ' ' << i->second << '\n';
  	}*/

	return map;
}

std::string derivative(std::string input) {
	std::map<int, int> map = readPolynomial(input);

	std::string out;
	for (auto i = map.crbegin(); i != map.crend(); i++) {
		int a = i->second;
		int n = i->first;
		if (a != 0 && n > 0) {
			out += (out.empty() || a < 0 ? "" : "+");
			if (n == 1) {
				out += std::to_string(a);
			} else if (n == 2) {
				out += std::to_string(a * n) + "*x";
			} else {	
			    out += std::to_string(a * n) + "*x^" + std::to_string(n - 1);
			}
		}
  	}
	
	//std::cout << out << std::endl;

	return out;
}

int main(int argc, char** argv) {
	std::cout << derivative("x+x+x+x+x+x+x+x+x+x") << std::endl;
	std::cout << derivative("x^10000+x+1") << std::endl;
	std::cout << derivative("x^2+x") << std::endl;
}