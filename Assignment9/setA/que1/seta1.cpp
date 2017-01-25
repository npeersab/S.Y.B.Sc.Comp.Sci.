#include <iostream>

using namespace std;

class Time {
	private:
		int hours, minutes, seconds;

	public:
		void setTime(int, int, int);
		void showTime();
		Time add(Time);
		Time diff(Time);
};

void Time :: setTime(int hr, int min, int sec) {
	hours = hr;
	minutes = min;
	seconds = sec;
}

void Time :: showTime() {
	cout << hours << ": " << minutes << ": " << seconds;
}

Time Time :: add(Time time) {
	
}

int main() {

}
