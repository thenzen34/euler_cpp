#include <iostream>
#include <chrono>

void task() {
	long int last1 = 1, last2 = 2, f = 0, sums = 2;

	while (last2 < 4000000) {
		f = last2 + last1;
		last1 = last2;
		last2 = f;
		if (f % 2 == 0) {
			sums += f;
		}
	}
	std::cout << sums << std::endl;
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