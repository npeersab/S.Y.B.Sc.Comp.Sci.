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
	cout << hours << ":" << minutes << ":" << seconds << "\n";
}

Time Time :: add(Time time) {
	Time time1;

	time1.seconds = seconds + time.seconds;

	time1.minutes = minutes + time.minutes;
	time1.minutes += time1.seconds / 60;
	time1.seconds = time1.seconds % 60;

	time1.hours = hours + time.hours;
	time1.hours += time1.minutes / 60;
	time1.minutes = time1.minutes % 60;

	return time1;
}

Time Time :: diff(Time time) {
	Time time1;

	time1.seconds = seconds - time.seconds;

	time1.minutes = minutes - time.minutes;
	if (time1.seconds < 0) {
		time1.minutes--;
		time1.seconds += 60;
	}

	time1.hours = hours - time.hours;
	if (time1.minutes < 0) {
		time1.hours--;
		time1.minutes += 60;
	}
	return time1;
}	

int main() {
	Time time1;

	time1.setTime(1, 20, 40);
	cout << "Time 1: ";
	time1.showTime();

	Time time2;
	time2.setTime(2, 40, 20);
	cout << "Time 2: ";
	time2.showTime();

	Time time3 = time1.add(time2);
	cout << "Adding Time 2 to Time 1: ";
	time3.showTime();

	Time time4 = time3.diff(time2);
	cout << "Subtracting Time 2 from Time 3: ";
	time4.showTime();
}
