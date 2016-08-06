/*

Copyright (c) 2015 Cromulence LLC

Authors: Cromulence <cgc@cromulence.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

#include <prng.h>


int minimum(unsigned int a, unsigned int b) {

	if (a < b)
		return a;
	else
		return b;
}

int max(int a, int b) {

	if (a > b)
		return a;
	else
		return b;

}

int rand( void )
{
	return (random_in_range( 0, RAND_MAX-1 ));
}

void srand( unsigned int seed )
{
	seed_prng( seed );
}

int atoi( const char *pStr )
{
	int value = 0;
	int negative = 0;

	while ( isspace( *pStr ) )
		pStr++;

	if ( *pStr == '\0' )
		return 0;

	if ( *pStr == '-' )
	{
		negative = 1;
		pStr++;
	}

	// Read in string
	while ( isdigit( *pStr ) )
		value = (value * 10) + (*pStr++ - '0');

	if ( negative )
		return (-value);
	else
		return value;	
}



double atof( char *pStr )
{

double tmpNumber;
int factor = 1;
int sign;
int isFloat = 0;
int digit_value;

	while (*pStr == ' ')
		++pStr;

	if (*pStr == '-') {
		sign = -1;
		++pStr;
	}
	else
		sign = 1;

	while (pStr) {

		if (*pStr == '.') {
			isFloat = 1;
			++pStr;
			continue;
		}

		if (*pStr >= '0' && *pStr <= '9') {

			digit_value = *pStr - '0';

			tmpNumber *= 10;

			tmpNumber += digit_value;

			if (isFloat)
				factor *= 10;

		}
		else
			break;

		++pStr;
	}

	tmpNumber = tmpNumber * sign;

	if (isFloat)
		tmpNumber = tmpNumber / factor;

	return tmpNumber;

}
