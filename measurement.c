#include "measurement.h"
#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>

Tmeasurement readMeasurements(char* filename){
	Tmeasurement tmp;
	FILE *my_file;
	int i = 0;
	
	my_file = fopen(filename, "r");
	if (my_file == NULL) {
		printf("Unable to open %s\n", filename);
	}
	else{
		printf("Reading measurements from \n%s...\n", filename);
		while (!feof(my_file)) {
			if (i == 0){
				fscanf(my_file, "%d", &tmp.num_of_measure);
				tmp.measurement = (float*)calloc(tmp.num_of_measure, sizeof(float));
			}else
				fscanf(my_file, "%f", &tmp.measurement[i-1]);
			i++;
		}
		fclose(my_file);
	}
	return tmp;
	free(tmp.measurement);
}
void printMeasurements(Tmeasurement m){
	for (int i = 0; i < m.num_of_measure; i++)
		printf("%f\n", m.measurement[i]);
}
double meanMeasurements(Tmeasurement m){
	float sum = 0;
	for (int i = 0; i < m.num_of_measure; i++)
		sum += m.measurement[i];
	return (double)(sum / m.num_of_measure);
}
void incMeasurements(Tmeasurement m, double increment){
	for (int i = 0; i < m.num_of_measure; i++)
		m.measurement[i] += increment;
}
Tmeasurement copy(Tmeasurement m){
	Tmeasurement tmp;
	tmp.num_of_measure = m.num_of_measure;
	tmp.measurement = (float*)calloc(tmp.num_of_measure, sizeof(float));
	for (int i = 0; i < tmp.num_of_measure; i++)
		tmp.measurement[i] = m.measurement[i];
	return tmp;
	free(tmp.measurement);
}