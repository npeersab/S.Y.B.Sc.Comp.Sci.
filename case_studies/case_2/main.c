#include"head.h"
main() {
	insertData();
	printf("\nResult: \nThe Minimum is %d\nThe Maximum is %d\nThe Median is %d\nThe 1st Quartile is %d\nThe 3rd Quartile is %d\n", getMin(), getMax(), getMed(), getQ1(), getQ2());
}
