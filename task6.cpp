#include <iostream>
#include <chrono>
#include <vector>

void task() {
	unsigned long long int sums = 0, sums_sqr = 0;
	std::vector<int> divlist = {};

	for (long int x = 1;x < 101;x += 1) {
		sums_sqr += x*x;
		sums += x;
	}

	std::cout << sums*sums - sums_sqr << std::endl;
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
