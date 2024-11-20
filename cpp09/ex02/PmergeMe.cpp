#include "PmergeMe.hpp"
#include "unistd.h"

int wrongInput(std::string str) {
	std::cout << str << std::endl;
	std::cout << "usage: ./PmergeMe 1 2 3 4 5 6 7 8 9 0" << std::endl;
	return (1);
}

size_t getTime() {
	std::time_t result = std::time(NULL);
	// std::cout << result << " seconds since Epoch" << std::endl;
	return (result);
}

int parseInput(char **argv, int argc, std::vector<int> *vec, std::deque<int> *deq) {

	std::string str;
	for (int i = 1; i < argc; i++) {
		str = argv[i];
		if (str.find_first_not_of("1234567890 	") != std::string::npos)
			return (std::cout << "Error" << std::endl, 1);
		if (str.length() > 10 || (str.length() == 10 && str.compare("2147483647") > 0))
			return (std::cout << "Error" << std::endl, 1);
		vec->push_back(std::stoi(str));
		deq->push_back(std::stoi(str));
	}
	return (0);
}

void printElements(std::vector<int> *vec) {
	size_t max = std::min(static_cast<size_t>(100), vec->size());
	for (size_t i = 0; i < max; i++)
		std::cout << (*vec)[i] << " ";
	if (max < vec->size())
		std::cout << "[...] ";
}

void algorithm(std::vector<int> *vec, std::deque<int> *deq) {
	double startTime = getTime();
	std::sort(vec->begin(), vec->end());
	std::sort(deq->begin(), deq->end());
	usleep(1000000);
	double endTime = getTime();
	std::cout << "After: ";
	printElements(vec);
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vec->size() << " elements with std::vector : " << 
		std::setprecision(6) << (endTime - startTime) / 1000 << " µs" << std::endl;
	std::cout << "Time to process a range of " << deq->size() << " elements with std::deque : " << 
		std::setprecision(6) << (endTime - startTime) / 1000 << " µs" << std::endl;
}

void compute(std::vector<int> *vec, std::deque<int> *deq) {
	(void)deq;
	std::cout << "Before: ";
	printElements(vec);
	std::cout << std::endl;

	algorithm(vec, deq);


}

int main(int argc, char **argv) {
	if (argc < 2)
		return (wrongInput("Error"));
	std::vector<int> vec;
	std::deque<int> deq;
	if (parseInput(argv, argc, &vec, &deq))
		return (1);
	compute(&vec, &deq);
	return (0);
}
