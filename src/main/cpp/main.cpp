/*
 * main.cpp
 *
 *  Created on: Aug 24, 2018
 *      Author: daniel
 */

#include "Matrix.h"

int main() {

	Matrix m1 = {
			{ 5,  0, -2,  0 },
			{ 9,  0,  0, -2 },
			{ 0,  2, -3, -1 },
	};

	Matrices::reducedRowEchelonForm(m1);
	Matrices::print(m1);

	return 0;
}

