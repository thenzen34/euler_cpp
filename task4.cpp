#include <iostream>
#include <chrono>
#include <vector>

bool is_polyndrom(unsigned int x) {
    unsigned int r = 0, n = x, d;
    do {
        d = x % 10;
        r = r * 10 + d;
        x /= 10;
    } while (x != 0);
    if (n == r) {
        return true;
    }
    return false;
}

void task() {
    unsigned int result = 0, max_polyndrom = 0;

	for(unsigned int x = 100;x < 1000;x++) {
        for(unsigned int y = 100;y < 1000;y++) {
            result = x * y;
            if (is_polyndrom(result)) {
                if (max_polyndrom < result) {
                    max_polyndrom = result;
                }
            }
        }
	}

	std::cout << max_polyndrom << std::endl;
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
