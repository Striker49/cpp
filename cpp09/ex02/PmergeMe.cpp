#include "PmergeMe.hpp"
#include "unistd.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>

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

void printElements(std::vector<int> vec) {
	size_t max = std::min(static_cast<size_t>(100), vec.size());
	for (size_t i = 0; i < max; i++)
		std::cout << vec[i] << " ";
	if (max < vec.size())
		std::cout << "[...] ";
	std:: cout << std::endl;
}

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

void sortPairsContainer(std::vector<std::pair<int, int> > *pairs) {
	std::pair<int, int> temp;
	std::vector<std::pair<int, int> >::iterator curr;
	std::vector<std::pair<int, int> >::iterator next;
	for (std::vector<std::pair<int, int> >::iterator it = pairs->begin(); it != pairs->end() - 1;) {
		curr = it;
		it++;
		next = it;
		if (curr->first < next->first)
			continue;
		temp = *curr;
		*curr = *next;
		*next = temp;
		sortPairsContainer(pairs);
	}
}

void createS(std::vector<std::pair<int, int> > *pairs, std::vector<int> *S, std::vector<int> *pend) {
	for (size_t i = 0; i < pairs->size(); i++)
		S->push_back((*pairs)[i].first);
	for (size_t i = 0; i < pairs->size(); i++)
		pend->push_back((*pairs)[i].second);
	(*pairs).clear();
}

void createJacobsthalSequence(std::vector<int> *vec, std::vector<int> *jacob) {
	int a = 1;
	int b = 1;
	int temp;
	jacob->push_back((*vec)[b]);
	std::cout << "Creating Jacobsthal number sequence..." << std::endl;
	for (int i = 0; i < vec->size(); i++) {
		temp = b;
		b += a * 2;
		a = temp;
		if (b > vec->size())
			break;
		jacob->push_back((*vec)[b]);
		std::cout << "vec[" << i << "]" << (*vec)[b] << std::endl;
	}
	printElements(*jacob);
}

void binaryInsertion(std::vector<int> *S, std::vector<int> *pend) {
	int n = S->size();
	int mid;
	if (S->size() % 2 != 0)
		mid = n / 2 + 1;
	else
		mid = n / 2;
	int left = mid - 1;
	int right = mid + 1;
	while (!pend->empty())
	{
		//std::cout << "Searching insertion placemement for [" << pend->front() << "]" << std::endl;
		//std::cout << "n "  << n << std::endl;
		//std::cout << "left "  << (*S)[left] << std::endl;
		//std::cout << "mid "  << (*S)[mid] << std::endl;
		//std::cout << "right "  << (*S)[right] << std::endl;
		//printElements(*S);
		if (( left == 0 && pend->front() < (*S)[left]) || (right == (n - 1) && pend->front() > (*S)[right]) || (pend->front() > (*S)[left] && pend->front() < (*S)[mid]) || (pend->front() < (*S)[right] && pend->front() > (*S)[mid]))
		{
			//std::cout << "Found insertion placemement for [" << pend->front() << "]" << std::endl;
			// std::cout << "n "  << n << std::endl;
			// std::cout << "left "  << (*S)[left] << std::endl;
			// std::cout << "right "  << (*S)[right] << std::endl;
			// std::cout << "Last pend[0] < S[left] " << "mid: " << mid << "p" << (*S)[mid] << std::endl;

			if (pend->front() < (*S)[left]) {
				//std::cout << "1=====" << std::endl;
				S->insert(S->begin() + left, pend->front());
			}
			else if (pend->front() > (*S)[right]) {
				//std::cout << "2=====" << std::endl;
				//std::cout << "inserting: " << pend->front() << std::endl;
				//std::cout << "mid" << (*S)[mid] << std::endl;
				//std::cout << "right" << (*S)[right] << std::endl;
				S->insert(S->begin() + right + 1, pend->front());
			}
			else if (pend->front() > (*S)[left] && pend->front() < (*S)[mid]) {
				//std::cout << "3=====" << std::endl;
				//std::cout << "inserting: " << pend->front() << std::endl;
				//std::cout << "mid" << (*S)[mid] << std::endl;
				//std::cout << "right" << (*S)[right] << std::endl;
				S->insert(S->begin() + mid, pend->front());
			}
			else if (pend->front() < (*S)[right] && pend->front() > (*S)[mid]) {

				S->insert(S->begin() + mid + 1, pend->front());
			}
			else
				S->insert(S->begin() + mid, pend->front());
			pend[0].erase(pend->begin(), pend->begin() + 1);
			n = S->size();
			if (n % 2 != 0)
				mid = std::max(n - 2, n / 2);
			else
				mid = n / 2;
			left = mid - 1;
			right = mid + 1;
			//printElements(*S);
		}
		else if (pend->front() < (*S)[left]) {
			if (left < n / 2)
			{
				mid = std::max(left, std::min(1, left / 2));
				left = mid - 1;
				right = mid + 1;
			}
			else {
				mid = std::max(left, std::min((n / 2), (n / 2 + left) / 2));
				left = mid - 1;
				right = mid + 1;
			}
		}
		else if (pend->front() > (*S)[right]) {
			if (right < n / 2)
			{
				mid = std::max((n / 2 - 1), std::min(right, ((n / 2) + right) / 2));
				left = mid - 1;
				right = mid + 1;
			}
			else {
				mid = std::max(n - 2, std::min(right, (right + n) / 2 - 1));
				left = mid - 1;
				right = mid + 1;
			}
		}
	}
}



std::vector<int> *insertElements(std::vector<int> *S, std::vector<int> *pend) {
	//insert first pend element in front of S
	S->insert(S->begin(), (*pend)[0]);
	pend->erase(pend->begin(), pend->begin() + 1);
	std::vector<int> jacob;
	createJacobsthalSequence(pend, &jacob);
	binaryInsertion(S, pend);
	//binaryInsertion(S, pend);
	//while (!jacob)
	
	return (S);
}

void algorithm(std::vector<int> *vec, std::deque<int> *deq) {
	double startTime = getTime();
	std::vector<int> S;
	std::vector<int> pend;
	int straggler = 0;
	int first;
	int sec;
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
		std::cout << "pair: " << it->first << " | " << it->second << std::endl;
	}

	sortPairs(&pairs);
	std::cout << "Sorted pairs bigger > smaller" << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		std::cout << "pair: " << it->first << " | " << it->second << std::endl;
	}

	sortPairsContainer(&pairs);
	std::cout << "Sort pairs container by bigger" << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		std::cout << "pair: " << it->first << " | " << it->second << std::endl;
	}

	createS(&pairs, &S, &pend);
	std::cout << "Put bigger in S, smaller and straggler in pend" << std::endl;
	std::cout << "S elements" << std::endl;
	if (straggler)
		pend.push_back(straggler);
	printElements(S);
	std::cout << "Pend elements" << std::endl;
	printElements(pend);

	vec = insertElements(&S, &pend);
	std::cout << "Insert pend elements in S" << std::endl;
	printElements(S);

	// std::sort(vec->begin(), vec->end());
	// std::sort(deq->begin(), deq->end());
	double endTime = getTime();
	std::cout << "After: ";
	printElements(*vec);
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vec->size() << " elements with std::vector : " << 
		std::setprecision(6) << (endTime - startTime) / 1000 << " µs" << std::endl;
	std::cout << "Time to process a range of " << deq->size() << " elements with std::deque : " << 
		std::setprecision(6) << (endTime - startTime) / 1000 << " µs" << std::endl;
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
