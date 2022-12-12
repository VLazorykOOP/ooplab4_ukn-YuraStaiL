#include <iostream>
#include <string.h>

#ifndef MATRIXUINT_H
#define MATRIXUINT_H
typedef unsigned int ui;

class VectorUInt {
private:
	unsigned int* arr;
	unsigned int size;
	int codeError;

public:
	static unsigned int count;
	VectorUInt();
	VectorUInt(unsigned int elems);
	VectorUInt(unsigned int elems, unsigned int value);
	VectorUInt(VectorUInt& inp);
	~VectorUInt();
	VectorUInt operator++(int);
	VectorUInt operator--(int);
	bool operator!();
	VectorUInt operator~();
	VectorUInt operator-();
	VectorUInt operator=(VectorUInt& input);
	VectorUInt operator+(VectorUInt& input);
	VectorUInt operator+(unsigned int input);

	VectorUInt operator-(VectorUInt& input);
	VectorUInt operator-(unsigned int input);

	VectorUInt operator*(VectorUInt& input);
	VectorUInt operator*(unsigned int input);

	VectorUInt operator/(VectorUInt& input);
	VectorUInt operator/(unsigned int input);

	VectorUInt operator%(VectorUInt& input);
	VectorUInt operator%(unsigned int input);

	VectorUInt operator|(VectorUInt& input);
	VectorUInt operator|(unsigned int input);

	VectorUInt operator^(VectorUInt& input);
	VectorUInt operator^(unsigned int input);

	VectorUInt operator+=(VectorUInt& input);
	VectorUInt operator+=(unsigned int input);

	VectorUInt operator-=(VectorUInt& input);
	VectorUInt operator-=(unsigned int input);

	VectorUInt operator*=(VectorUInt& input);
	VectorUInt operator*=(unsigned int input);

	VectorUInt operator/=(VectorUInt& input);
	VectorUInt operator/=(unsigned int input);

	VectorUInt operator%=(VectorUInt& input);
	VectorUInt operator%=(unsigned int input);

	VectorUInt operator|=(VectorUInt& input);
	VectorUInt operator|=(unsigned int input);

	VectorUInt operator^=(VectorUInt& input);
	VectorUInt operator^=(unsigned int input);

	friend std::ostream& operator<<(std::ostream& os, const VectorUInt& out);
	friend std::istream& operator>>(std::istream& is, const VectorUInt& in);

	bool operator==(VectorUInt& input);
	bool operator!=(VectorUInt& input);

	unsigned int& operator[](const unsigned int index);
	void operator()();

	bool operator>(VectorUInt& input);
	bool operator>=(VectorUInt& input);
	bool operator<(VectorUInt& input);
	bool operator<=(VectorUInt& input);
};

ui VectorUInt::count = 0;

VectorUInt::VectorUInt() {
	arr = new ui[1];
	arr[0] = 0;
	codeError = 0;
	size = 1;
	count++;
}

VectorUInt::VectorUInt(ui elems) {
	arr = new ui[elems];
	size = elems;
	for (ui i = 0; i < elems; i++)
		arr[i] = 0;
	codeError = 0;
	count++;
}

VectorUInt::VectorUInt(ui elems, ui value) {
	arr = new ui[elems];
	size = elems;
	for (ui i = 0; i < elems; i++)
		arr[i] = value;
	codeError = 0;
	count++;
}

VectorUInt::VectorUInt(VectorUInt& inp) {
	arr = new ui[inp.size];
	size = inp.size;
	for (ui i = 0; i < size; i++) {
		arr[i] = inp.arr[i];
	}
	codeError = 0;
	count++;
}

VectorUInt::~VectorUInt() {
	delete[] arr;
	count--;
}

VectorUInt VectorUInt::operator++(int) {
	for (ui i = 0; i < size; i++) {
		arr[i] += 1;
	}
	return *this;
}

VectorUInt VectorUInt::operator--(int) {
	for (ui i = 0; i < size; i++) {
		arr[i] -= 1;
	}
	return *this;
}

bool VectorUInt::operator!() {
	if (size != 0)
		return true;
	else
		return false;
}

VectorUInt VectorUInt::operator~() {
	for (ui i = 0; i < size; i++) {
		arr[i] = ~arr[i];
	}
	return *this;
}

VectorUInt VectorUInt::operator-() {
	for (ui i = 0; i < size; i++) {
		arr[i] = 0 - arr[i];
	}
	return *this;
}

VectorUInt VectorUInt::operator=(VectorUInt& input) {
	VectorUInt result(input.size);
	for (ui i = 0; i < input.size; i++) {
		result.arr[i] = input.arr[i];
	}
	return result;
}

VectorUInt VectorUInt::operator+(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	VectorUInt result(elems);
	for (ui i = 0; i < elems; i++) {
		result.arr[i] = arr[i] + input.arr[i];
	}
	return result;
}

VectorUInt VectorUInt::operator+(unsigned int input) {
	VectorUInt result(size);
	for (ui i = 0; i < size; i++) {
		result.arr[i] = arr[i] + input;
	}
	return result;
}

VectorUInt VectorUInt::operator-(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	VectorUInt result(elems);
	for (ui i = 0; i < elems; i++) {
		result.arr[i] = arr[i] - input.arr[i];
	}
	return result;
}

VectorUInt VectorUInt::operator-(unsigned int input) {
	VectorUInt result(size);
	for (ui i = 0; i < size; i++) {
		result.arr[i] = arr[i] - input;
	}
	return result;
}

VectorUInt VectorUInt::operator*(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	VectorUInt result(elems);
	for (ui i = 0; i < elems; i++) {
		result.arr[i] = arr[i] * input.arr[i];
	}
	return result;
}

VectorUInt VectorUInt::operator*(unsigned int input) {
	VectorUInt result(size);
	for (ui i = 0; i < size; i++) {
		result.arr[i] = arr[i] * input;
	}
	return result;
}

VectorUInt VectorUInt::operator/(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	VectorUInt result(elems);
	for (ui i = 0; i < elems; i++) {
		result.arr[i] = arr[i] / input.arr[i];
	}
	return result;
}

VectorUInt VectorUInt::operator/(unsigned int input) {
	VectorUInt result(size);
	for (ui i = 0; i < size; i++) {
		result.arr[i] = arr[i] / input;
	}
	return result;
}

VectorUInt VectorUInt::operator%(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	VectorUInt result(elems);
	for (ui i = 0; i < elems; i++) {
		result.arr[i] = arr[i] % input.arr[i];
	}
	return result;
}

VectorUInt VectorUInt::operator%(unsigned int input) {
	VectorUInt result(size);
	for (ui i = 0; i < size; i++) {
		result.arr[i] = arr[i] % input;
	}
	return result;
}

VectorUInt VectorUInt::operator|(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	VectorUInt result(elems);
	for (ui i = 0; i < elems; i++) {
		result.arr[i] = arr[i] | input.arr[i];
	}
	return result;
}

VectorUInt VectorUInt::operator|(unsigned int input) {
	VectorUInt result(size);
	for (ui i = 0; i < size; i++) {
		result.arr[i] = arr[i] | input;
	}
	return result;
}

VectorUInt VectorUInt::operator^(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	VectorUInt result(elems);
	for (ui i = 0; i < elems; i++) {
		result.arr[i] = arr[i] ^ input.arr[i];
	}
	return result;
}

VectorUInt VectorUInt::operator^(unsigned int input) {
	VectorUInt result(size);
	for (ui i = 0; i < size; i++) {
		result.arr[i] = arr[i] ^ input;
	}
	return result;
}

VectorUInt VectorUInt::operator+=(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	for (ui i = 0; i < elems; i++) {
		arr[i] = arr[i] += input.arr[i];
	}
	return *this;
}

VectorUInt VectorUInt::operator+=(unsigned int input) {
	for (ui i = 0; i < size; i++) {
		arr[i] = arr[i] += input;
	}
	return *this;
}

VectorUInt VectorUInt::operator-=(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	for (ui i = 0; i < elems; i++) {
		arr[i] = arr[i] -= input.arr[i];
	}
	return *this;
}

VectorUInt VectorUInt::operator-=(unsigned int input) {
	for (ui i = 0; i < size; i++) {
		arr[i] = arr[i] -= input;
	}
	return *this;
}

VectorUInt VectorUInt::operator*=(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	for (ui i = 0; i < elems; i++) {
		arr[i] = arr[i] *= input.arr[i];
	}
	return *this;
}

VectorUInt VectorUInt::operator*=(unsigned int input) {
	for (ui i = 0; i < size; i++) {
		arr[i] = arr[i] *= input;
	}
	return *this;
}

VectorUInt VectorUInt::operator/=(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	for (ui i = 0; i < elems; i++) {
		arr[i] = arr[i] /= input.arr[i];
	}
	return *this;
}

VectorUInt VectorUInt::operator/=(unsigned int input) {
	for (ui i = 0; i < size; i++) {
		arr[i] = arr[i] /= input;
	}
	return *this;
}

VectorUInt VectorUInt::operator%=(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	for (ui i = 0; i < elems; i++) {
		arr[i] = arr[i] %= input.arr[i];
	}
	return *this;
}

VectorUInt VectorUInt::operator%=(unsigned int input) {
	for (ui i = 0; i < size; i++) {
		arr[i] = arr[i] %= input;
	}
	return *this;
}

VectorUInt VectorUInt::operator|=(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	for (ui i = 0; i < elems; i++) {
		arr[i] = arr[i] |= input.arr[i];
	}
	return *this;
}

VectorUInt VectorUInt::operator|=(unsigned int input) {
	for (ui i = 0; i < size; i++) {
		arr[i] = arr[i] |= input;
	}
	return *this;
}

VectorUInt VectorUInt::operator^=(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	for (ui i = 0; i < elems; i++) {
		arr[i] = arr[i] ^= input.arr[i];
	}
	return *this;
}

VectorUInt VectorUInt::operator^=(unsigned int input) {
	for (ui i = 0; i < size; i++) {
		arr[i] = arr[i] ^= input;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const VectorUInt& out) {
	for (ui i = 0; i < out.size; i++) {
		os << out.arr[i] << " ";
	}
	os << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, const VectorUInt& in) {
	for (ui i = 0; i < in.size; i++) {
		is >> in.arr[i];
	}
	return is;
}

bool VectorUInt::operator==(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	for (ui i = 0; i < elems; i++) {
		if (arr[i] != input.arr[i])
			return false;
	}
	return true;
}

bool VectorUInt::operator!=(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	for (ui i = 0; i < elems; i++) {
		if (arr[i] == input.arr[i])
			return false;
	}
	return true;
}

unsigned int& VectorUInt::operator[](const unsigned int index) {
	if (index > size) {
		return arr[size - 1];
		codeError = -1;
	}
	return arr[index];
}

void VectorUInt::operator()() {
	//???
}

bool VectorUInt::operator>(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	for (ui i = 0; i < elems; i++) {
		if (arr[i] <= input.arr[i])
			return false;
	}
	return true;
}

bool VectorUInt::operator>=(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	for (ui i = 0; i < elems; i++) {
		if (arr[i] < input.arr[i])
			return false;
	}
	return true;
}

bool VectorUInt::operator<(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	for (ui i = 0; i < elems; i++) {
		if (arr[i] >= input.arr[i])
			return false;
	}
	return true;
}

bool VectorUInt::operator<=(VectorUInt& input) {
	ui elems = size <= input.size ? size : input.size;
	for (ui i = 0; i < elems; i++) {
		if (arr[i] > input.arr[i])
			return false;
	}
	return true;
}


class MatrixUInt {
private:
	VectorUInt* UIntArray;
	ui rows, cols;
	int codeError;

public:
	static int num_matrix;
	MatrixUInt();
	MatrixUInt(ui size);
	MatrixUInt(ui rows_, ui cols_);
	MatrixUInt(ui rows_, ui cols_, ui value_);
	MatrixUInt(const MatrixUInt& input);
	~MatrixUInt();

	int getRows() const;
	int getCols() const;
	int getCodeError() const;

	friend std::ostream& operator<<(std::ostream& os, const MatrixUInt& out);
	friend std::istream& operator>>(std::istream& is, const MatrixUInt& in);

	MatrixUInt operator++(int);
	MatrixUInt operator--(int);
	bool operator!();
	MatrixUInt operator~();
	MatrixUInt operator-();
	MatrixUInt operator=(MatrixUInt& input);

	MatrixUInt operator+(MatrixUInt& input);
	MatrixUInt operator+(int input);
	MatrixUInt operator-(MatrixUInt& input);
	MatrixUInt operator-(int input);
	MatrixUInt operator*(MatrixUInt& input);
	MatrixUInt operator*(int input);
	MatrixUInt operator*(VectorUInt& input);
	MatrixUInt operator/(int input);
	MatrixUInt operator%(int input);

	MatrixUInt operator+=(const MatrixUInt& input);
	MatrixUInt operator+=(const int input);
	MatrixUInt operator-=(const MatrixUInt& input);
	MatrixUInt operator-=(const int input);
	MatrixUInt operator*=(const MatrixUInt& input);
	MatrixUInt operator*=(VectorUInt& input);
	MatrixUInt operator*=(const int input);
	MatrixUInt operator/=(const int input);
	MatrixUInt operator%=(const int input);

	MatrixUInt operator|(const MatrixUInt& input);
	MatrixUInt operator^(const MatrixUInt& input);
	MatrixUInt operator^(const int input);
	MatrixUInt operator&(const MatrixUInt& input);
	MatrixUInt operator&(const int input);
	MatrixUInt operator<<=(const int input);
	MatrixUInt operator>>=(const int input);
	MatrixUInt operator>>=(const MatrixUInt& input);
	MatrixUInt operator<<=(const MatrixUInt& input);
	MatrixUInt operator|=(const MatrixUInt& input);
	MatrixUInt operator|=(const int input);
	MatrixUInt operator^=(const MatrixUInt& input);
	MatrixUInt operator^=(const int input);
	MatrixUInt operator&=(const MatrixUInt& input);
	MatrixUInt operator&=(const int input);

	MatrixUInt operator==(const MatrixUInt& input);
	MatrixUInt operator!=(const MatrixUInt& input);
	MatrixUInt operator>(const MatrixUInt& input);
	MatrixUInt operator>=(const MatrixUInt& input);
	MatrixUInt operator<(const MatrixUInt& input);
	MatrixUInt operator<=(const MatrixUInt& input);

	VectorUInt operator[](int);
};

#endif // MATRIXUINT_H

int MatrixUInt::num_matrix = 0;

MatrixUInt::MatrixUInt() {
	UIntArray = nullptr;
	rows = 0;
	cols = 0;
	codeError = 0;
	num_matrix++;
}

MatrixUInt::MatrixUInt(ui size) {
	UIntArray = new VectorUInt[size];
	for (ui i = 0; i < size; i++) {
		UIntArray[i] = VectorUInt(size);
	}
	rows = size;
	cols = size;
	codeError = 0;
	num_matrix++;
}

MatrixUInt::MatrixUInt(ui rows_, ui cols_) {
	UIntArray = new VectorUInt[rows_];
	for (ui i = 0; i < rows_; i++) {
		UIntArray[i] = VectorUInt(cols_);
	}
	rows = rows_;
	cols = cols_;

	codeError = 0;
	num_matrix++;
}

MatrixUInt::MatrixUInt(ui rows_, ui cols_, ui value_) {
	UIntArray = new VectorUInt[cols_];
	for (ui i = 0; i < rows_; i++) {
		UIntArray[i] = VectorUInt(cols_, value_);
	}
	rows = rows_;
	cols = cols_;
	codeError = 0;
	num_matrix++;
}

MatrixUInt::MatrixUInt(const MatrixUInt& input) {
	UIntArray = new VectorUInt[input.rows];
	for (ui i = 0; i < input.rows; i++) {
		UIntArray[i] = input.UIntArray[i];
	}
	rows = input.rows;
	cols = input.cols;
	codeError = 0;
	num_matrix++;
}

MatrixUInt::~MatrixUInt() {
	delete[] UIntArray;
	num_matrix--;
}

std::ostream& operator<<(std::ostream& os, const MatrixUInt& out) {
	for (ui i = 0; i < out.rows; i++, os << std::endl) {
		for (ui z = 0; z < out.cols; z++)
			os << out.UIntArray[i][z] << " ";
	}
	return os;
}

std::istream& operator>>(std::istream& is, const MatrixUInt& in) {
	for (ui i = 0; i < in.rows; i++) {
		for (ui z = 0; z < in.cols; z++)
			is >> in.UIntArray[i][z];
	}
	return is;
}

int MatrixUInt::getRows() const { return rows; }

int MatrixUInt::getCols() const { return cols; }

int MatrixUInt::getCodeError() const { return codeError; }

MatrixUInt MatrixUInt::operator++(int) {
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			UIntArray[i][z] += 1;
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator--(int) {
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			UIntArray[i][z] -= 1;
		}
	}
	return *this;
}

bool MatrixUInt::operator!() {
	if (rows != 0 && cols != 0)
		return true;
	return false;
}

MatrixUInt MatrixUInt::operator~() {
	MatrixUInt result(*this);
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			result.UIntArray[i][z] = ~UIntArray[i][z];
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator-() {
	MatrixUInt result(*this);
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			result.UIntArray[i][z] = -UIntArray[i][z];
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator=(MatrixUInt& input) {
	if ((rows != input.rows) || (cols != input.cols)) {
		if (UIntArray)
			delete[] UIntArray;
		rows = input.rows;
		cols = input.cols;
		UIntArray = new VectorUInt[cols];
		codeError = 0;
	}
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			UIntArray[i][z] = input.UIntArray[i][z];
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator+(MatrixUInt& input) {
	ui res_rows = rows <= input.rows ? rows : input.rows;
	ui res_cols = cols <= input.cols ? cols : input.cols;
	MatrixUInt result(res_rows, res_cols);
	for (ui i = 0; i < res_rows; i++) {
		for (ui z = 0; z < res_cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] + input.UIntArray[i][z];
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator+(int input) {
	MatrixUInt result(rows, cols);
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] + input;
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator-(MatrixUInt& input) {
	ui res_rows = rows <= input.rows ? rows : input.rows;
	ui res_cols = cols <= input.cols ? cols : input.cols;
	MatrixUInt result(res_rows, res_cols);
	for (ui i = 0; i < res_rows; i++) {
		for (ui z = 0; z < res_cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] - input.UIntArray[i][z];
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator-(int input) {
	MatrixUInt result(rows, cols);
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] - input;
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator*(MatrixUInt& input) {
	if (cols != input.rows) {
		std::cout << "Error! Can't multiply matrix, when cols1 not equal rows2."
			<< std::endl;
		MatrixUInt nullMatrix(1);
		return nullMatrix;
	}
	MatrixUInt result(rows, input.cols);
	for (ui i = 0; i < rows; i++) {
		for (ui j = 0; j < input.cols; j++) {
			for (ui k = 0; k < cols; k++) {
				result.UIntArray[i][j] += UIntArray[i][k] * input.UIntArray[k][j];
			}
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator*(int input) {
	MatrixUInt result(rows, cols);
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] * input;
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator*(VectorUInt& input) {
	if (cols != input.getSize()) {
		std::cout << "Error! Can't multiply matrix and vector, when cols matrix "
			"not equal size of vector."
			<< std::endl;
		MatrixUInt nullMatrix(1, cols);
		return nullMatrix;
	}
	MatrixUInt result(1, cols);
	for (ui i = 0; i < rows; i++) {
		result.UIntArray[0][i] = 0;
		for (ui z = 0; z < cols; z++) {
			result.UIntArray[0][i] += UIntArray[i][z] * input[z];
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator/(int input) {
	MatrixUInt result(rows, cols);
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] / input;
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator%(int input) {
	MatrixUInt result(rows, cols);
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] % input;
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator+=(const MatrixUInt& input) {
	ui res_rows = rows <= input.rows ? rows : input.rows;
	ui res_cols = cols <= input.cols ? cols : input.cols;
	for (ui i = 0; i < res_rows; i++) {
		for (ui z = 0; z < res_cols; z++) {
			UIntArray[i][z] += input.UIntArray[i][z];
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator+=(const int input) {

	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			UIntArray[i][z] += input;
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator-=(const MatrixUInt& input) {
	ui res_rows = rows <= input.rows ? rows : input.rows;
	ui res_cols = cols <= input.cols ? cols : input.cols;
	for (ui i = 0; i < res_rows; i++) {
		for (ui z = 0; z < res_cols; z++) {
			UIntArray[i][z] += input.UIntArray[i][z];
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator-=(const int input) {

	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			UIntArray[i][z] += input;
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator*=(const MatrixUInt& input) {
	if (cols != input.rows) {
		std::cout << "Error! Can't multiply matrix, when cols1 not equal rows2."
			<< std::endl;
		MatrixUInt nullMatrix(1);
		return nullMatrix;
	}
	MatrixUInt result(rows, input.cols);
	for (ui i = 0; i < rows; i++) {
		for (ui j = 0; j < input.cols; j++) {
			for (ui k = 0; k < cols; k++) {
				result.UIntArray[i][j] += UIntArray[i][k] * input.UIntArray[k][j];
			}
		}
	}
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < input.cols; z++) {
			UIntArray[i][z] = result.UIntArray[i][z];
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator*=(const int input) {
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			UIntArray[i][z] = UIntArray[i][z] * input;
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator*=(VectorUInt& input) {
	if (cols != input.getSize()) {
		std::cout << "Error! Can't multiply matrix and vector, when cols matrix "
			"not equal size of vector."
			<< std::endl;
		MatrixUInt nullMatrix(1, cols);
		return nullMatrix;
	}
	MatrixUInt result(1, cols);
	for (ui i = 0; i < rows; i++) {
		result.UIntArray[0][i] = 0;
		for (ui z = 0; z < cols; z++) {
			result.UIntArray[0][i] += UIntArray[i][z] * input[z];
		}
	}
	for (ui i = 0; i < cols; i++) {
		UIntArray[0][i] = result.UIntArray[0][i];
	}
	rows = 1;
	return *this;
}

MatrixUInt MatrixUInt::operator/=(const int input) {
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			UIntArray[i][z] = UIntArray[i][z] / input;
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator%=(const int input) {
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			UIntArray[i][z] = UIntArray[i][z] % input;
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator|(const MatrixUInt& input) {
	MatrixUInt result(rows, cols);
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] | input.UIntArray[i][z];
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator^(const MatrixUInt& input) {
	MatrixUInt result(rows, cols);
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] ^ input.UIntArray[i][z];
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator^(const int input) {
	MatrixUInt result(rows, cols);
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] ^ input;
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator&(const MatrixUInt& input) {
	MatrixUInt result(rows, cols);
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] & input.UIntArray[i][z];
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator&(const int input) {
	MatrixUInt result(rows, cols);
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] & input;
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator>>=(const int input) {
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			UIntArray[i][z] >>= input;
		}
	}
	return *this;
}
MatrixUInt MatrixUInt::operator<<=(const int input) {
	std::cout << "<<=\n";
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			UIntArray[i][z] <<= input;
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator>>=(const MatrixUInt& input) {
	ui res_rows = rows <= input.rows ? rows : input.rows;
	ui res_cols = cols <= input.cols ? cols : input.cols;
	for (ui i = 0; i < res_rows; i++) {
		for (ui z = 0; z < res_cols; z++) {
			UIntArray[i][z] >>= input.UIntArray[i][z];
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator<<=(const MatrixUInt& input) {
	ui res_rows = rows <= input.rows ? rows : input.rows;
	ui res_cols = cols <= input.cols ? cols : input.cols;
	for (ui i = 0; i < res_rows; i++) {
		for (ui z = 0; z < res_cols; z++) {
			UIntArray[i][z] <<= input.UIntArray[i][z];
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator|=(const MatrixUInt& input) {
	ui res_rows = rows <= input.rows ? rows : input.rows;
	ui res_cols = cols <= input.cols ? cols : input.cols;
	for (ui i = 0; i < res_rows; i++) {
		for (ui z = 0; z < res_cols; z++) {
			UIntArray[i][z] |= input.UIntArray[i][z];
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator|=(const int input) {
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			UIntArray[i][z] |= input;
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator^=(const MatrixUInt& input) {
	ui res_rows = rows <= input.rows ? rows : input.rows;
	ui res_cols = cols <= input.cols ? cols : input.cols;
	for (ui i = 0; i < res_rows; i++) {
		for (ui z = 0; z < res_cols; z++) {
			UIntArray[i][z] ^= input.UIntArray[i][z];
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator^=(const int input) {
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			UIntArray[i][z] ^= input;
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator&=(const MatrixUInt& input) {
	ui res_rows = rows <= input.rows ? rows : input.rows;
	ui res_cols = cols <= input.cols ? cols : input.cols;
	for (ui i = 0; i < res_rows; i++) {
		for (ui z = 0; z < res_cols; z++) {
			UIntArray[i][z] |= input.UIntArray[i][z];
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator&=(const int input) {
	for (ui i = 0; i < rows; i++) {
		for (ui z = 0; z < cols; z++) {
			UIntArray[i][z] |= input;
		}
	}
	return *this;
}

MatrixUInt MatrixUInt::operator==(const MatrixUInt& input) {
	ui res_rows = rows <= input.rows ? rows : input.rows;
	ui res_cols = cols <= input.cols ? cols : input.cols;
	MatrixUInt result(res_rows, res_cols);
	for (ui i = 0; i < res_rows; i++) {
		for (ui z = 0; z < res_cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] == input.UIntArray[i][z];
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator!=(const MatrixUInt& input) {
	ui res_rows = rows <= input.rows ? rows : input.rows;
	ui res_cols = cols <= input.cols ? cols : input.cols;
	MatrixUInt result(res_rows, res_cols);
	for (ui i = 0; i < res_rows; i++) {
		for (ui z = 0; z < res_cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] != input.UIntArray[i][z];
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator>(const MatrixUInt& input) {
	ui res_rows = rows <= input.rows ? rows : input.rows;
	ui res_cols = cols <= input.cols ? cols : input.cols;
	MatrixUInt result(res_rows, res_cols);
	for (ui i = 0; i < res_rows; i++) {
		for (ui z = 0; z < res_cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] > input.UIntArray[i][z];
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator<(const MatrixUInt& input) {
	ui res_rows = rows <= input.rows ? rows : input.rows;
	ui res_cols = cols <= input.cols ? cols : input.cols;
	MatrixUInt result(res_rows, res_cols);
	for (ui i = 0; i < res_rows; i++) {
		for (ui z = 0; z < res_cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] < input.UIntArray[i][z];
		}
	}
	return result;
}

MatrixUInt MatrixUInt::operator<=(const MatrixUInt& input) {
	ui res_rows = rows <= input.rows ? rows : input.rows;
	ui res_cols = cols <= input.cols ? cols : input.cols;
	MatrixUInt result(res_rows, res_cols);
	for (ui i = 0; i < res_rows; i++) {
		for (ui z = 0; z < res_cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] <= input.UIntArray[i][z];
		}
	}
	return result;
}

VectorUInt MatrixUInt::operator[](int index) {
	if (index >= rows) {
		codeError = -1;
		return UIntArray[rows - 1];
	}
	return UIntArray[index];
}

MatrixUInt MatrixUInt::operator>=(const MatrixUInt& input) {
	ui res_rows = rows <= input.rows ? rows : input.rows;
	ui res_cols = cols <= input.cols ? cols : input.cols;
	MatrixUInt result(res_rows, res_cols);
	for (ui i = 0; i < res_rows; i++) {
		for (ui z = 0; z < res_cols; z++) {
			result.UIntArray[i][z] = UIntArray[i][z] >= input.UIntArray[i][z];
		}
	}
	return result;
}