#include <iostream>
#include <chrono>

void task() {
	int i =0;
	int step = 1;
	long int sums = 0;
	while (i < 1000) {
		if (i % 3 == 0 or i % 5 == 0) {
			sums += i;
		}
		i += step;
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