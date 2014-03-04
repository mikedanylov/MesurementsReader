
typedef struct{
	float* measurement;
	int num_of_measure;
} Tmeasurement;

Tmeasurement readMeasurements(char *filename);
void printMeasurements(Tmeasurement m);
double meanMeasurements(Tmeasurement m);
void incMeasurements(Tmeasurement m, double increment);
Tmeasurement copy(Tmeasurement m);