/*
 * Matrix.cpp
 *
 *  Created on: Aug 24, 2018
 *      Author: daniel
 */

#include "Matrix.h"

namespace Matrices {

	void zero(Matrix& m, int sx, int sy) {

		for(int x = 0; x < sx; x++) {
			m.push_back(std::vector<double>(sy));
			for(int y = 0; y < sy; y++)
				m[x][y] = 0;
		}
	}

	bool isRowZero(const std::vector<double>& row) {

		for(double p : row) {
			if(p != 0)
				return false;
		}
		return true;
	}

	std::vector<double> getRow(const Matrix& m, unsigned int target) {
		return m[target];
	}

	std::vector<double> getColumn(const Matrix& m, unsigned int target) {
		std::vector<double> d;

		for(unsigned int i = 0; i < m.size(); i++)
			d.push_back(m[i][target]);

		return d;
	}

	void add(Matrix& m, const Matrix& n) {

		if(m.size() != n.size())
			return;

		for(unsigned int x = 0; x < m.size(); x++) {
			for(unsigned int y = 0; y < m[0].size(); y++) {
				m[x][y] += n[x][y];
			}
		}

	}

	void multiply(Matrix& m, const Matrix& n) {

		if(m[0].size() != n.size())
			return;

		Matrix t;
		zero(t, m.size(), n[0].size());

		for(unsigned int x = 0; x < t.size(); x++) {
			for(unsigned int y = 0; y < t[0].size(); y++) {
				std::vector<double> r = getRow(m, x);
				std::vector<double> c = getColumn(n, y);

				for(unsigned int p = 0; p < r.size(); p++) {
					t[x][y] += r[p] * c[p];
				}
			}
		}

		m = t;
	}

	void switchRows(Matrix& m, int t1, int t2) {

		Matrix t;
		zero(t, m.size(), m[0].size());
		identity(t);

		t[t1][t1] = 0;
		t[t2][t2] = 0;

		t[t1][t2] = 1;
		t[t2][t1] = 1;

		multiply(t, m);

		m = t;
	}

	void multiplyRow(Matrix& m, int target, double amount) {

		Matrix t;
		zero(t, m.size(), m[0].size());
		identity(t);

		t[target][target] = amount;

		multiply(t, m);

		m = t;
	}

	void addRow(Matrix& m, int t1, int t2) {
		addRowMultiple(m, t1, t2, 1);
	}

	void addRowMultiple(Matrix& m, int t1, int t2, double amount) {

		Matrix t;
		zero(t, m.size(), m[0].size());
		identity(t);

		t[t2][t1] = amount;

		multiply(t, m);

		m = t;
	}

	void makeSquare(Matrix& m) {

		if(m.size() == m[0].size())
			return;

		if(m.size() > m[0].size())
			for(unsigned int i = 0; i < m.size(); i++)
				for(unsigned int s = 0; s < (m.size() - m[0].size()); s++)
					m[i].push_back(0);

		if(m.size() < m[0].size())
			for(unsigned int s = 0; s < (m[0].size() - m.size()); s++)
				m.push_back(std::vector<double>(m[0].size()));
	}

	void removeZeroRows(Matrix& m) {
		for(unsigned int i = 0; i < m.size(); i++) {
			if(isRowZero(getRow(m, i)))
				m.erase(m.begin() + i);
		}
	}

	void echelonForm(Matrix& m) {

		for(unsigned int y = 0; y < m[0].size(); y++) {

			for(unsigned int x = 0; x < m.size(); x++) {

				if(isRowZero(getRow(m,x)))
					continue;

				if((x == y) && (m[x][y] != 0))
					multiplyRow(m, x, (double) 1 / m[x][y]);
				else if(x > y)
					addRowMultiple(m, y, x, -m[x][y]);

			}

		}
	}

	void reducedRowEchelonForm(Matrix& m) {

		makeSquare(m);

		Matrix t;
		zero(t, m.size(), m[0].size());

		echelonForm(m);

		for(unsigned int x = 0; x < t.size(); x++) {
			for(unsigned int y = 0; y < t[x].size(); y++) {
				t[x][y] = m[(m.size() - 1) - x][(m[y].size() - 1) - y];
			}
		}

		echelonForm(t);

		for(unsigned int x = 0; x < t.size(); x++) {
			for(unsigned int y = 0; y < t[x].size(); y++) {
				m[x][y] = t[(m.size() - 1) - x][(m[y].size() - 1) - y];
			}
		}

		echelonForm(m);

		removeZeroRows(m);

	}

	void print(const Matrix& m) {
		for(unsigned int x = 0; x < m.size(); x++) {
			for(unsigned int y = 0; y < m[0].size(); y++) {
				std::cout << m[x][y] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	void identity(Matrix& m) {
		for(unsigned int x = 0; x < m.size(); x++) {
			for(unsigned int y = 0; y < m[0].size(); y++) {
				if(x == y)
					m[x][y] = 1;
				else
					m[x][y] = 0;
			}
		}
	}

	bool isIdentity(const Matrix& m) {
		for(unsigned int x = 0; x < m.size(); x++) {
			for(unsigned int y = 0; y < m[0].size(); y++) {
				if((x == y) && (m[x][y] != 1))
					return false;
				if((x != y) && (m[x][y] != 0))
					return false;
			}
		}

		return true;
	}
}
