#include "helper.h"
#include<ctime>
#include<chrono>		// system_clock
#include<iomanip>		// has std::put_time
#include <iostream>
using std::cout;
using std::cin;

namespace BookReader {


int Helper::ReadInt(int low, int high) {
	cout << "\nEnter number in range " << low << " - " << high << ": ";
	int value;

	cin >> value;

	if (low <= value && value <= high)
		return value;

	cout << "ERROR: invalid number...Try again\n";
	return ReadInt(low, high);
}

int Helper::ShowReadMenu(const vector<string> &choices) {
	cout << "\nMenu:\n";
	for (int ch = 0; ch < (int) choices.size(); ++ch) {
		cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
	}
	return ReadInt(1, choices.size());
}

string Helper::GetCurrentTimeDate() {	// src: https://stackoverflow.com/questions/17223096/outputting-date-and-time-in-c-using-stdchrono
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
	return ss.str();
}

}
