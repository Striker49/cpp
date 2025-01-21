#include "PmergeMe.hpp"

int wrongInput(std::string str) {
	std::cout << str << std::endl;
	std::cout << "usage: ./PmergeMe 1 2 3 4 5 6 7 8 9 0" << std::endl;
	return (1);
}

size_t getTime() {
	time_t result = time(NULL);
	// std::cout << result << " seconds since Epoch" << std::endl;
	return (result);
}

bool findDuplicate(std::vector<int> *vec, std::vector<int>::iterator it) {
	if (find(vec->begin(), vec->end(), *it) != vec->end() && find(vec->begin(), vec->end(), *it) != it)
		return (true);
	return (false);
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
	for (std::vector<int>::iterator it = vec->begin(); it != vec->end(); it++) {
		if (findDuplicate(vec, it))
			return (std::cout << "Duplicates are not allowed: " << *it << std::endl, 1);
	}
	return (0);
}

template <typename T>
void printElements(T Container) {
	size_t max = std::min(static_cast<size_t>(100), Container.size());
	for (size_t i = 0; i < max; i++)
		std::cout << Container[i] << " ";
	if (max < Container.size()) {
		std::cout << "[...] ";
		std::cout << Container.back();
	}
	std:: cout << std::endl;
}

// void printElements(std::vector<int> vec) {
// 	size_t max = std::min(static_cast<size_t>(100), vec.size());
// 	for (size_t i = 0; i < max; i++)
// 		std::cout << vec[i] << " ";
// 	if (max < vec.size()) {
// 		std::cout << "[...] ";
// 		std::cout << vec.back();
// 	}
// 	std:: cout << std::endl;
// }

void sortPairs(std::vector<std::pair<int, int> > *pairs) {
	int temp;
	for (std::vector<std::pair<int, int> >::iterator it = pairs->begin(); it != pairs->end(); it++) {
		if ( it->first > it->second)
			continue;
		temp = it->first;
		it->first = it->second;
		it->second = temp;
	}
}

void sortPairsContainer(std::vector<std::pair<int, int> >* pairs) {
    bool swapped;
    do {
        swapped = false;
        for (std::vector<std::pair<int, int> >::iterator it = pairs->begin(); it != pairs->end() - 1; ++it) {
            std::vector<std::pair<int, int> >::iterator next = it + 1;
            if (it->first > next->first) {
                std::swap(*it, *next);
                swapped = true;
            }
        }
    } while (swapped);
}

void createS(std::vector<std::pair<int, int> > *pairs, std::vector<int> *S, std::vector<int> *pend) {
	for (size_t i = 0; i < pairs->size(); i++) 
		S->push_back((*pairs)[i].first);
	for (size_t i = 0; i < pairs->size(); i++)
		pend->push_back((*pairs)[i].second);
	(*pairs).clear();
}

void createJacobsthalSequence(std::vector<int> vec, std::vector<int> *jacob) {
	size_t a = 1;
	size_t b = 1;
	size_t temp;
	std::cout << "Creating Jacobsthal number sequence..." << std::endl;
	//push with -1 so it takes into account that count starts at 0
	jacob->push_back(b - 1);
	// std::cout << "vec[" << "0" << "]" << (*vec)[b] << std::endl;
	for (size_t i = 1; i < vec.size(); i++) {
		temp = b;
		b += a * 2;
		a = temp;
		if (b > vec.size())
			break;
		jacob->push_back(b - 1);
		// std::cout << "vec[" << i << "]" << (*vec)[b] << std::endl;
	}
	std::cout << "jacob numbers: ";
	printElements(*jacob);
}

std::vector<int>::iterator binarySearch(std::vector<int> *S, int item, std::vector<int>::iterator low, std::vector<int>::iterator high) {
	(void)*S;
	while (low < high) {
		std::vector<int>::iterator mid = low + (std::distance(low, high) / 2);
		if (item == *mid)
			return (mid);
		else if (item > *mid)
			low = mid + 1;
		else high = mid;
	}
	return (low);
}

void bi(std::vector<int> *S, std::vector<int> pend) {
	
	std::vector<int>::iterator pos;
	std::vector<int>::iterator it = pend.begin();

	while (it != pend.end()) {
		std::vector<int>::iterator lowerbound = S->begin();
		std::vector<int>::iterator upperbound = S->end();

		pos = binarySearch(S, *it, lowerbound, upperbound);
		// std::cout << "S: ";
		// printElements(*S);
		// std::cout << "Inserting: " << *it << std::endl;
		// std::cout << "pos: " << *pos << std::endl;

		S->insert(pos, *it);
		it++;
	}
}


void binaryInsertion(std::vector<int> *S, std::vector<int> pend, std::vector<int> *jacob) {
	//Putting jacobsthal elements at the beginning of pend
	// std::cout << "putting jacob elements at the beginning of pend" << std::endl;
	while (!jacob->empty()) {
		int index = 1;
		// printElements(*pend);
		pend.insert(pend.begin(), pend[jacob->back() - 1]);
		// printElementspend;
		pend.erase(pend.begin() + jacob->back() - 1 + index, pend.begin() + (jacob->back() - 1 + index + 1));
		jacob->pop_back();
		index++;
		// printElements(*jacob);
	}
	// std::cout << "FINISHED putting jacob elements at the beginning of pend" << std::endl;
	printElements(pend);
	bi(S, pend);
	// std::cout << "FINISHED binary sorting elements of pend in S" << std::endl;
}

std::vector<int> *insertElements(std::vector<int> *S, std::vector<int> pend) {
	//insert first pend element in front of S
	S->insert(S->begin(), pend[0]);
	pend.erase(pend.begin(), pend.begin() + 1);
	std::vector<int> jacob;
	createJacobsthalSequence(pend, &jacob);
	binaryInsertion(S, pend, &jacob);
	
	return (S);
}

bool isSorted(std::vector<int> *vec) {
	for (unsigned long i = 0; i < vec->size() - 1; i++) {
		if ((*vec)[i] >= (*vec)[i + 1])
			return (false);
	}
	return (true);
}

void vectorOperation(std::vector<int> *vec) {
	double vecStartTime = clock();
	std::vector<int> S;
	std::vector<int> pend;
	int straggler = 0;
	int first;
	int sec;

	if (vec->size() % 2 != 0)
	{
		straggler = vec->back();
		vec->pop_back();
	}
	std::vector<std::pair<int, int> > pairs;
	for (std::vector<int>::iterator it = vec->begin(); it != vec->end(); it++) {
		first = *it;
		*it++;
		sec = *it;
		pairs.push_back(std::make_pair(first, sec));
	}
	vec->clear();
	std::cout << "Created pairs" << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		// std::cout << "pair: " << it->first << " | " << it->second << std::endl;
	}

	sortPairs(&pairs);
	std::cout << "Sorted pairs bigger > smaller" << std::endl;
	// for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
	// 	std::cout << "pair: " << it->first << " | " << it->second << std::endl;
	// }

	sortPairsContainer(&pairs);
	std::cout << "Sort pairs container by bigger" << std::endl;
	// for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
	// 	std::cout << "pair: " << it->first << " | " << it->second << std::endl;
	// }

	createS(&pairs, &S, &pend);
	std::cout << "Put bigger in S, smaller and straggler in pend" << std::endl;
	std::cout << "S elements" << std::endl;
	if (straggler)
		pend.push_back(straggler);
	printElements(S);
	std::cout << "Pend elements" << std::endl;
	printElements(pend);

	vec = insertElements(&S, pend);
	double vecEndTime = clock();
	std::cout << "Insert pend elements in S" << std::endl;
	std::cout << "After: ";
	printElements(S);
	std::cout << std::endl;
	std::cout << "Time to process a range of " << S.size() << " elements with std::vector : " << 
	std::fixed << std::setprecision(9) << (vecEndTime - vecStartTime) / 1000000.0 << " s" << std::endl;
	if (!isSorted(vec)) {
		std::cout << "\033[31m" << "Container is NOT sorted!!!" << "\033[0m" << std::endl;
		return;
	}
	else
		std::cout << "\033[32m" << "Container is sorted" << "\033[0m" << std::endl;
}

// void vectorOperation(std::vector<int> *vec) {
// 	double vecStartTime = clock();
// 	std::vector<int> S;
// 	std::vector<int> pend;
// 	int straggler = 0;
// 	int first;
// 	int sec;

// 	if (vec->size() % 2 != 0)
// 	{
// 		straggler = vec->back();
// 		vec->pop_back();
// 	}
// 	std::vector<std::pair<int, int> > pairs;
// 	for (std::vector<int>::iterator it = vec->begin(); it != vec->end(); it++) {
// 		first = *it;
// 		*it++;
// 		sec = *it;
// 		pairs.push_back(std::make_pair(first, sec));
// 	}
// 	vec->clear();
// 	std::cout << "Created pairs" << std::endl;
// 	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
// 		// std::cout << "pair: " << it->first << " | " << it->second << std::endl;
// 	}

// 	sortPairs(&pairs);
// 	std::cout << "Sorted pairs bigger > smaller" << std::endl;
// 	// for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
// 	// 	std::cout << "pair: " << it->first << " | " << it->second << std::endl;
// 	// }

// 	sortPairsContainer(&pairs);
// 	std::cout << "Sort pairs container by bigger" << std::endl;
// 	// for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
// 	// 	std::cout << "pair: " << it->first << " | " << it->second << std::endl;
// 	// }

// 	createS(&pairs, &S, &pend);
// 	std::cout << "Put bigger in S, smaller and straggler in pend" << std::endl;
// 	std::cout << "S elements" << std::endl;
// 	if (straggler)
// 		pend.push_back(straggler);
// 	printElements(S);
// 	std::cout << "Pend elements" << std::endl;
// 	printElements(pend);

// 	vec = insertElements(&S, pend);
// 	double vecEndTime = clock();
// 	std::cout << "Insert pend elements in S" << std::endl;
// 	std::cout << "After: ";
// 	printElements(S);
// 	std::cout << std::endl;
// 	std::cout << "Time to process a range of " << S.size() << " elements with std::vector : " << 
// 	std::fixed << std::setprecision(9) << (vecEndTime - vecStartTime) / 1000000.0 << " s" << std::endl;
// 	if (!isSorted(vec)) {
// 		std::cout << "\033[31m" << "Container is NOT sorted!!!" << "\033[0m" << std::endl;
// 		return;
// 	}
// 	else
// 		std::cout << "\033[32m" << "Container is sorted" << "\033[0m" << std::endl;
// }

void algorithm(std::vector<int> *vec, std::deque<int> *deq) {
	// double vecStartTime;
	if (vec->size() < 2) {
		std::cout << "After: ";
		printElements(*vec);
		std::cout << std::endl;
		std::cout << "Time to process a range of " << vec->size() << " elements with std::vector : " << 
		std::setprecision(6) << "0" << " µs" << std::endl;
		std::cout << "Time to process a range of " << deq->size() << " elements with std::deque : " << 
		std::setprecision(6) << "0" << " µs" << std::endl;
		return;
	}
	vectorOperation(vec);
	// dequeOperation(deq);
}

void compute(std::vector<int> *vec, std::deque<int> *deq) {
	(void)deq;
	std::cout << "Before: ";
	printElements(*vec);
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
