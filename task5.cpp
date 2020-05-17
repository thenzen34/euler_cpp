#include <iostream>
#include <chrono>
#include <vector>

bool is_find(int x, const std::vector<int> *divlist) {
	for ( int n : *divlist ) {
        if (x % n > 0) {
        	return false;
        }
    }
	return true;
}

void task() {
    unsigned int nmbr = 2520;
    unsigned int step = 19;
    std::vector<int> divlist = {step};

	while (!is_find(nmbr, &divlist)) {
        nmbr += 1;
	}

	divlist.clear();

	for (int x = 2;x < 21; x++) {
        divlist.push_back(x);
    }

    while (!is_find(nmbr, &divlist)) {
        nmbr += step;
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
