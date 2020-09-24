// PiMonteCarlo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

double sample();
double getRandom();
int main()
{
	cout << sample();
}

double sample()
{
	int hits = 0;
	int progress = 0;
	
	for (int sample = 1; sample < INT_MAX; sample++)
	{
		double x = getRandom();
		double y = getRandom();
		if (sqrt(pow(x-.5, 2) + pow(y-.5, 2))<.5)
		{
			hits++;
		}
		int temp = progress;
		progress = double(sample) / INT_MAX * 100;

		if (temp < progress)
		{
			cout << "[" <<progress << "%]\t";
			cout << setprecision(15) << (double(hits) / sample) / .25 << endl;
		}


	}
	return (double(hits)/INT_MAX)/.25;


}

double getRandom()
{
	return ((double)rand() / RAND_MAX);
}