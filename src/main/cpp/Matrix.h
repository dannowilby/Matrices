/*
 * Matrix.h
 *
 *  Created on: Aug 24, 2018
 *      Author: daniel
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
#include <iostream>

typedef std::vector<std::vector<double>> Matrix;

/**
 * Augment by adding columns as negative
 */

namespace Matrices {

	void zero(Matrix& m, int sx, int sy);

	bool isRowZero(const std::vector<double>& row);
	std::vector<double> getRow(const Matrix& m, unsigned int target);
	std::vector<double> getColumn(const Matrix& m, unsigned int target);

	void add(Matrix& m, const Matrix& n);
	void multiply(Matrix& m, const Matrix& n);

	// add row t1 to t2
	void addRow(Matrix& m, int t1, int t2);
	void addRowMultiple(Matrix& m, int t1, int t2, double amount);
	void switchRows(Matrix& m, int t1, int t2);
	void multiplyRow(Matrix& m, int t, double amount);

	void makeSquare(Matrix& m);
	void removeZeroRows(Matrix& m);

	/**
	 * Does not check if matrix is square! And does not make it square! Multiplication won't work.
	 */
	void echelonForm(Matrix& m);
	void reducedRowEchelonForm(Matrix& m);

	void print(const Matrix& m);
	void identity(Matrix& m);

	bool isIdentity(const Matrix& m);
}

#endif /* MATRIX_H_ */
