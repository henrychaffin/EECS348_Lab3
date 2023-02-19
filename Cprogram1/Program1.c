#include <stdio.h>
int main() {

	//NUMBERS FILE
	FILE *numbersFile = fopen("numbers.txt", "r");
	float numbers[12];
	for (int i = 0; i < 12; i++) {
		fscanf(numbersFile, "%f", &numbers[i]);
	}

	//MONTHS CONST
	const char *months[12] = {
	    "January", "February", "March", "April",
	    "May", "June", "July", "August",
	    "September", "October", "November", "December"
	};

	//TITLE
	printf("SALES: \n");

	//MONTHLY SALES
	printf("\nMONTHLY SALES: \n");
	for (int i = 0; i < 12; i++) {
		printf("%-10s $%.2f\n", months[i], numbers[i]);
	}

	//SALES SUMMARY
	printf("\nSALES SUMMARY: \n");
	//minimum
	float minimum = numbers[0];
	for (int i = 0; i < 12; i++) {
		if (numbers[i] < minimum) {
			minimum = numbers[i];
		}
	}
	printf("Minimum sales: $%.2f\n", minimum);
	//maximum
	float maximum = numbers[0];
	for (int i = 0; i < 12; i++) {
		if (numbers[i] > maximum) {
			maximum = numbers[i];
		}
	}
	printf("Maximum sales: $%.2f\n", maximum);
	//average
	float total;
	for (int i = 0; i < 12; i++) {
		total += numbers[i];
	}
	printf("Average sales: $%.2f\n", total/12);

	//MOVING AVERAGE
	printf("\nMOVING AVERAGE: \n");
	float movingAverage[7];
	for (int i = 0; i <= 6; i++) {
		float sum = 0;
		for (int j = i; j < (i + 6); j++) {
			sum += numbers[j];
		}
		movingAverage[i] = sum / 6;
	}
	for (int i = 0; i <= 6; i++) {
		printf("%-10s - %-10s $%.2f\n", months[i], months[i + 5], movingAverage[i]);
	}


	//SALES REPORT
	printf("\nSALES REPORT: \n");
	int salesReport[12];
	for (int i = 0; i < 12; i++) {
		salesReport[i] = i;
	}
	for (int i = 0; i < 12; i++) {
		for (int j = (i + 1); j < 12; j++) {
			if (numbers[salesReport[i]] < numbers[salesReport[j]]) {
				float temp = salesReport[i];
				salesReport[i] = salesReport[j];
				salesReport[j] = temp;
			}
		}
	}
	for (int i = 0; i < 12; i++) {
		printf("%-10s $%.2f\n", months[salesReport[i]], numbers[salesReport[i]]);
	}
}
