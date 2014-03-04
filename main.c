#include <stdio.h>
#include "measurement.h"


int main(int argc, char *argv[]) {
	
	/*Tmeasurement m;
	char* file = "C:\\Users\\m\\Desktop\\Datastructures and Algorithms TI00AC30-3001\\mea.dat";
	
	printMeasurements(m);
	printf("Mean is %.4lf\n", meanMeasurements(m));
	fflush(stdin); getchar();*/

	Tmeasurement m1, m2;
	char* file = "C:\\Users\\m\\Desktop\\Datastructures and Algorithms TI00AC30-3001\\mea.dat";
	m1 = readMeasurements(file);
	printMeasurements(m1);
	m2 = copy(m1);
	incMeasurements(m2, 0.1);
	printf("Mean m1 is %.4lf\n", meanMeasurements(m1));
	printf("Mean m2 is %.4lf\n", meanMeasurements(m2));
	fflush(stdin); getchar();

	return 0;
}