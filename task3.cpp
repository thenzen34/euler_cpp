#include <iostream>
#include <chrono>
#include <vector>
#include <math.h>

bool is_simple(int x, std::vector<int> *divlist) {
	for ( int n : *divlist ) {
        if (x % n == 0) {
        	return false;
        }
    }
    divlist->push_back(x);
	return true;
}

void task() {
	unsigned long long int value = 600851475143, maxdiv = 0;
	std::vector<int> divlist = {};

	for (long int x = 3;x < ceil(sqrt(value));x += 2) {
		if (value % x == 0 and is_simple(x, &divlist)) {
			if (x > maxdiv) {
				maxdiv = x;
			}
		}
	}

	std::cout << maxdiv << std::endl;
}

int main ()
{
  using namespace std::chrono;

  high_resolution_clock::time_point t1 = high_resolution_clock::now();

  task();

  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

  std::cout << "It took me " << time_span.count() << " seconds.";
  std::cout << std::endl;

  return 0;
}