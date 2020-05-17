#include <iostream>
#include <chrono>
#include <vector>
#include <math.h>

bool is_simple(int x) {
    for (long int n = 2;n < ceil(sqrt(x)) + 1;n += 1) {
        if (x % n == 0) {
        	return false;
        }
    }
	return true;
}

void task() {
	unsigned long long int nmbr = 13, cnt = 6;
	while (cnt < 10001) {
        nmbr +=2;
        if (is_simple(nmbr)) {
            cnt +=1;
        }
	}

	std::cout << nmbr << std::endl;
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
