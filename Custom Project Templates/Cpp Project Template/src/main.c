/**
 * @file main.c
 *
 * @brief Testovaci projekt slouzici jako rychly vzor pro nasledujici projekty
 * @author Jiri Peska (xpeska05)
 */

#include "include/lib.h"

int main(int argc, char *argv[])
{
	printError();

	int firstNumber = 42;
	int secondNumber = 3;

	printf("Soucet dvou cisel je: %d\n", addNumbers(firstNumber, secondNumber));

	return 0;
}

