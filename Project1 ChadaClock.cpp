//Name: Khai Tran
//Date: 03/15/2026
//Class: CS-210


#include <iostream>
#include <chrono>
#include <thread>
#include <tuple>
#include <iomanip>

using namespace std;

int dataEdit;
int milHour = 23;
int minute = 59;
int hour = 11;
int second = 55;
bool stop = false;

string morningOrNight(){    
	if ((milHour >= 12) && (milHour <= 23)) {        
		return "  P.M.";
	}
	else {
		return "  A.M.";
	}
}
void starPrint(int j, int k) {
	for (int m = 0; m < k; m++) {
		for (int i = 0; i < j; i++) {
			cout << '*';
		}        cout << "  ";
	}
}

tuple<int, int, int, int> timeCheck() {
//created tuple to manage edit manage and track time in one function, in order from second to hour    //
	if (second >= 60) {
		second = 0;
		minute ++;
	}    
	if (minute >= 60) {
		hour++;
		milHour++;
		minute = 0;
	}
	if ((hour == 12) && (second > 59)) {
		hour = 1;
	}
	if (milHour >= 24) {
		milHour = 0;
	}
	return make_tuple(hour, minute, second, milHour);
}

void show12HourTime() {
	//prints the time in standard format pulling data from tuple    
	cout << setfill('0') << setw(2) << get<0>(timeCheck()) << ":";
	cout << setfill('0') << setw(2) << get<1>(timeCheck()) << ":";
	cout << setfill('0') << setw(2) << get<2>(timeCheck()) << morningOrNight();
}

void show24HourTime(){
	//prints the time in 24-hour format pulling data from tuple
	cout << setfill('0') << setw(2) << get<3>(timeCheck()) << ":";
	cout << setfill('0') << setw(2) << get<1>(timeCheck()) << ":";
	cout << setfill('0') << setw(2) << get<2>(timeCheck());
}

void printTime(){
	//assembles the display    
	starPrint(27, 2);
	cout << endl;
	cout << "*       12-Hour Clock     *  *      24-Hour Clock      *" <<endl;
	cout << "*       ";
	show12HourTime();
	cout << "    *" << "  *        ";
	show24HourTime();
	cout << "         *" << endl;
	starPrint(27, 2);

	cout << endl;
	this_thread::sleep_for(chrono::seconds(1));
	// sleeps so print statement only executes at a set interval of 1 second
	}

void menuDisplay(){
	//option selection to change time or exit
	starPrint(27, 1);
	cout << endl << "*    1 - Add One Hour     *" << endl;
	cout << "*    2 - Add One Minute   *" << endl;
	cout << "*    3 - Add One Second   *" << endl;
	cout << "*    4 - Exit Program     *" << endl;
	starPrint(27, 1);

	cin >> dataEdit;
	//switch case for user input to add time    
	switch (dataEdit) {
		case 1:
			hour++;
			milHour++;
			printTime();
			break;
		case 2:
			minute++;
			printTime();
			break;
		case 3:
			second++;
			second--;
			printTime();
			break;
		case 4:
			cout << "Goodbye." << endl;
			break;
	}
}

int main() {
	//while(!stop) {
	printTime();
	second++;
	//esc key would set "stop" variable to true and end the program then displaying the menu 
//}    
	void menuDisplay();
//un-comment line 123 and line 27 to test loop  
	return 0;
}