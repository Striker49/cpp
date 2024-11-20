#include "btc.hpp"

int wrongInput(std::string str) {
	std::cout << str << std::endl;
	std::cout << "usage: ./btc input.txt" << std::endl;
	return (1);
}

int wrongFormat(std::string str) {
	(void)str;
	// std::cout << "Error: Date Format: YYYY-MM-DD => " << str << std::endl;
	std::cout << "Error: Date Format: YYYY-MM-DD" << std::endl;
	return (1);
}

int parseDate(std::string date) {
	if (date[4] != '-' || date[7] != '-')
		return (wrongFormat(date));
	std::string yearStr = date.substr(0, date.find("-"));
	std::string monthStr = date.substr(date.find("-") + 1, 2);
	std::string dayStr = date.substr(date.find_last_of("-") + 1, date.size());

	if (yearStr.length() != 4 || monthStr.length() != 2 || dayStr.length() != 2)
		return (wrongFormat(date));

	int year = std::stoi(date.substr(0, date.find("-")));
	int month = std::stoi(date.substr(date.find("-") + 1, 2));
	int day = std::stoi(date.substr(date.find_last_of("-") + 1, date.size()));

	if (year < 2009)
		return (std::cout << "Error: date before bitcoin was created\n", 1);
	if (month < 1 || month > 12 || ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day == 31))
		return (std::cout << "Error: impossible date\n", 1);
	if ((month == 2 && day > 28 && year % 4 != 0) || (month == 2 && day > 29))
		return (std::cout << "Error: impossible date\n", 1);
	if (day < 1 || day > 31)
		return (std::cout << "Error: impossible date\n", 1);
	return (0);
}

int parseValue(std::string value) {
	int val;
	if (value.empty() || value.find_last_not_of(" 	") == std::string::npos)
		return (std::cout << "Error: no value\n", 1);
	try {
		val = std::stoi(value);
	}
	catch (std::exception &e) {
		return (std::cout << "Error: too large a number\n", 1);
	}
	if (val < 0)
		return (std::cout << "Error: not a positive number\n", 1);
	if (val > 999)
		return (std::cout << "Error: too large a number\n", 1);
	return (0);
}

std::map<std::string, float>	getCSV() {
	std::map<std::string, float> db;
	std::ifstream file("data.csv");
	std::string line;
	if (!file.good()) 
		return (std::cout << "Error: could not open CVS file" << std::endl, db);
	while (std::getline(file, line)) {
		if (line == "date,exchange_rate")
			continue;
		db[line.substr(0, line.find(","))] = std::stof(line.substr(line.find(",") + 1, line.size()));
	}
	return (db);
}

int calcValue(std::string date, float value, std::map<std::string,float> db) {
	std::map<std::string, float>::iterator it;
	it = db.lower_bound(date);
	if (db.find(date) == db.end())
		it--;
	std::cout << date << " => " << value << " * " << it->second << " = "  << value * it->second << std::endl;
	return (0);
}

int	parseData(std::ifstream *file) {
	std::string line;
	std::string date;
	std::string value;
	std::map<std::string, float> db;

	db = getCSV();
	if (db.empty())
		return (std::cout << "Error: bad CSV file", 1);
	while(std::getline(*file, line)) {
		if (line == "date | value" || line.find_first_not_of(" 	"))
			continue;
		if (line.find("|") == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = line.substr(0, line.find("|") - 1);
		value = line.substr(line.find("|") + 1, line.size());

		if ((date.empty() || date.find_last_not_of(" 	") == std::string::npos) || value.empty() || value.find_last_not_of(" 	") == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (parseDate(date) || parseValue(value))
			continue;
		calcValue(date, std::stof(value), db);
	} 
	return (0);
}

int fileFormat(std::string str) {
	if (str.find(".") == std::string::npos || str.find(".") == 0 || str.find(".") == str.length() -1 )
		return(wrongInput(str.append(" is not a file")));

	std::ifstream file(str);

	if (!file.good())
		return (std::cout << "Error: could not open file " + str << std::endl, 1);

	if (parseData(&file))
		return (1);
	return (0);

}

int parseFile(char **argv) {
	std::string fileName(argv[1]);
	fileFormat(fileName);
	return (0);
}

int main(int argc, char **argv) {
	if (argc != 2)
		return (wrongInput("Error: wrong number of arguments..!"));
	else
		parseFile(argv);
	return (0);
}