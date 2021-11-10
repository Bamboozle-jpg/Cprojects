// assignments 2.19 2.24 2.27
// Kevin Bachelor

#include <stdio.h>

int main() {
	int integer1,integer2,integer3,integer4,nSum,nAverage,nProd,largest,smallest;

	printf("Enter three different integers pretty please : ");
	scanf("%d%d%d", &integer1, &integer2, &integer3);

	nSum = integer1 + integer2 + integer3;
	nAverage = nSum / 3;
	nProd = integer1 * integer2 * integer3;

	largest = integer1;
	if (integer2 > largest) {
		largest = integer2;
	}
	if (integer3 > largest) {
		largest = integer3;
	}

	smallest = integer1;
	if (integer2 < smallest) {
		smallest = integer2;
	}
	if (integer3 < smallest) {
		smallest = integer3;
	}

	printf("\n Sum is %d ", nSum);
	printf("\n Average is %d ", nAverage);
	printf("\n Product is %d ", nProd);
	printf("\n Largest is %d ", largest);
	printf("\n Smallest is %d ", smallest);

	printf("\n\nCool, now give me a number and I'll tell you if it's odd or even : ");
	scanf("%d", &integer4);

	if (integer4 % 2 == 0) {
		printf("That number is even!");
	} else {
		printf("That number is odd!");
	}

	printf("\n\nCheckerboard, but it's dumb : \n");
	printf("* * * * * * * *\n");
	printf(" * * * * * * * *\n");
	printf("* * * * * * * *\n");
	printf(" * * * * * * * *\n");
	printf("* * * * * * * *\n");
	printf(" * * * * * * * *\n");
	printf("* * * * * * * *\n");
	printf(" * * * * * * * *\n");

	printf("\nCheckerboard but it's smart\n");

	for (int i = 0; i < 4; i++) {
		printf("* * * * * * * *\n");
		printf(" * * * * * * * *\n");
	}
	return 0;
}
