/*
 * Algebra.c
 *
 *  Created on: 5 oct. 2019
 *      Author: Daniel Mårtensson
 */

#include "../../CControl/Headers/Functions.h"
#include "../../CControl/Headers/Configurations.h"

/*
 * Transpose of A
 */
void tran(float* A, int row, int column) {

	float B[row*column];
	float* transpose;
	float* ptr_A = A;

	for (int i = 0; i < row; i++) {
		transpose = &B[i];
		for (int j = 0; j < column; j++) {
			*transpose = *ptr_A;
			ptr_A++;
			transpose += row;
		}
	}

	// Copy!
	memcpy(A, B, row*column*sizeof(float));

}

/*
 * C = A*B
 */
void mul(float* A, float* B, float* C, int row_a, int column_a, int column_b) {

	// Data matrix
	float* data_a = A;
	float* data_b = B;

	for (int i = 0; i < row_a; i++) {
		// Then we go through every column of b
		for (int j = 0; j < column_b; j++) {
			data_a = &A[i * column_a];
			data_b = &B[j];

			*C = 0; // Reset
			// And we multiply rows from a with columns of b
			for (int k = 0; k < column_a; k++) {
				*C += *data_a * *data_b;
				data_a++;
				data_b += column_b;
			}
			C++; // ;)
		}
	}
}

/*
 * This solves x from (A^T*A + ALPHA*I)*x = A^T*b
 */
void linsolve(float* A, float* x, float* b, int row_a, int column_a) {


	// AT - Transpose A
	float AT[column_a*row_a]; // Same dimension as A, just swapped rows and column
	memcpy(AT, A, column_a*row_a*sizeof(float)); // Copy A -> AT
	tran(AT, row_a, column_a); // Now turn the values of AT to transpose

	// ATb = AT*b
	float ATb[row_a];
	memset(ATb, 0, row_a * sizeof(float));
	mul(AT, b, ATb, column_a, row_a, 1);

	// ATA = AT*A
	float ATA[column_a*column_a];
	memset(ATA, 0, column_a*column_a * sizeof(float));
	mul(AT, A, ATA, column_a, row_a, column_a);

	// ATA = ATA + alpha*I.
	for(int i = 0; i < column_a; i++){
		*(ATA + i*column_a + i) = *(ATA + i*column_a + i) + ALPHA; // Don't need identity matrix here because we only add on diagonal
	}

	// Make ATA to upper triangular
	float pivot = 0.0;
	for(int j = 0; j < column_a; j++){ // Column
		for(int i = 0; i < column_a; i++){ // row
			if(i > j){
				pivot = *(ATA + i*column_a + j) / *(ATA + j*column_a + j);
				for(int k = 0; k < column_a; k++){
					*(ATA + i*column_a + k) = *(ATA + i*column_a + k) - pivot * *(ATA + j*column_a + k);
				}
				*(ATb + i) = *(ATb + i) - pivot * *(ATb + j);
			}
		}
	}

	/*
	 * Time to solve x from ATAx = ATb.
	 */
	memset(x, 0, column_a * sizeof(float)); // Reset
	for(int i = column_a-1; i >= 0; i--){ // Column
		pivot = 0.0; // This is our sum
		for(int j = i; j < column_a; j++){ // Row
			pivot += *(ATA + i*column_a + j)* * (x + j);
		}
		*(x + i) = (*(ATb + i) - pivot) / *(ATA + i*column_a + i);
	}

}

/*
 * A to A^(-1) - Notice that only square matrices are allowed
 */
void inv(float* A, int row){

	// Create iA matrix - The inverse
	float iA[row*row];
	memset(iA, 0, row*row*sizeof(float));

	// Create identity vector and solve Ax=I_i for every i
	float I[row];
	memset(I, 0, row*sizeof(float));
	for(int i = 0; i < row; i++){
		*(I + i) = 1;
		linsolve(A, I, I, row, row);
		for(int j = 0; j < row; j++)
			*(iA + j*row + i) = *(I + j);
		memset(I, 0, row*sizeof(float));
	}

	// Copy over iA -> A
	memcpy(A, iA, row*row*sizeof(float));

}

/**
 * This is linear programming with simplex method:
 * Max c^Tx
 * S.t Ax <= b
 *      x >= 0
 *
 * Call this function with the sizes
 * A [m*n] // Matrix
 * b [m] // Constraints
 * c [n] // Objective function
 * x [n] // Solution
 * row_a = m
 * column_a = n
 *
 * This is used for Model Predictive Control.
 * The key idea is to find the U value from Y = PHI*X + GAMMA*U where U >= 0 and GAMMA*U <= Y - PHI*X.
 * It practice it means that your input signal cannot be negative and the input signal will result so your
 * output (e.g temperature, position, pressure, velocity etc) will not be larger than your reference vector
 */
void linprog(float* c, float* A, float* b, float* x, int row_a, int column_a, int iteration_limit){

	// Clear the solution
	memset(x, 0, column_a*sizeof(float));

	// Create the tableau with space for the slack variables s and p as well
	float tableau[(row_a+1)*(column_a+row_a+2)]; // +1 because the extra row for objective function and +2 for the b vector and slackvariable for objective function
	memset(tableau, 0, (row_a+1)*(column_a+row_a+2)*sizeof(float));

	// Load the constraints
	int j = 0;
	for(int i = 0; i < row_a; i++){
		// First row
		memcpy(tableau + i*(column_a+row_a+2), A + i*column_a, column_a*sizeof(float));

		// Slack variable s
		j = column_a + i;
		tableau[i*(column_a+row_a+2) + j] = 1;

		// Add b vector
		tableau[i*(column_a+row_a+2) + (column_a+row_a+2-1)] = *(b+i);
	}

	// Negative objective function
	for(int i = 0; i < column_a; i++){
		tableau[(row_a+1-1)*(column_a+row_a+2) + i] = -*(c +i);
	}
	// Slack variable for the objective function
	tableau[(row_a+1-1)*(column_a+row_a+2) + (column_a+row_a+2-2)] = 1;
	// Done!

	// Print tableau
	//print(tableau,(row_a+1),(column_a+row_a+2));

	// Do row operations
	float entry = 0.0;
	int pivotColumIndex = 0;
	int pivotRowIndex = 0;
	float pivot = 0.0;
	float value1 = 0.0;
	float value2 = 0.0;
	float value3 = 0.0;
	float smallest = 0.0;
	int count = 0;
	do{
		// Find our pivot column
		pivotColumIndex = 0;
		entry = 0.0;
		for(int i = 0; i < (column_a+row_a+2) -1; i++){ // -1 because we don't want to count with the last column
			value1 = *(tableau + (row_a+1-1)*(column_a+row_a+2) + i); // Bottom row
			if(value1 < entry){
				entry = value1;
				pivotColumIndex = i;
			}
		}
		//printf("Entry = %f\n", entry);
		// If the smallest entry is equal to 0 or larger than 0, break
		if(entry >= 0.0 || count >= iteration_limit)
			break;

		// Find our pivot row
		pivotRowIndex = 0;
		value1 = *(tableau + 0*(column_a+row_a+2) + pivotColumIndex); // Value in pivot column
		value2 = *(tableau + 0*(column_a+row_a+2) + (column_a+row_a+2-1)); // Value in the b vector
		smallest = value2/value1; // Initial smallest value
		for(int i = 1; i < row_a; i++){
			value1 = *(tableau + i*(column_a+row_a+2) + pivotColumIndex); // Value in pivot column
			value2 = *(tableau + i*(column_a+row_a+2) + (column_a+row_a+2-1)); // Value in the b vector
			value3 = value2/value1;
			if( (value3 > 0  && value3 < smallest ) || smallest < 0 ){
				smallest = value3;
				pivotRowIndex = i;
			}
		}

		// We know where our pivot is. Turn the pivot into 1
		// 1/pivot * PIVOT_ROW -> PIVOT_ROW
		pivot = *(tableau + pivotRowIndex*(column_a+row_a+2) + pivotColumIndex); // Our pivot value
		//printf("pivotRowIndex = %i, pivotColumIndex = %i, pivot = %f\n", pivotRowIndex, pivotColumIndex, pivot);
		for(int i = 0; i < (column_a+row_a+2); i++){
			value1 = *(tableau + pivotRowIndex*(column_a+row_a+2) + i); // Our row value at pivot row
			*(tableau + pivotRowIndex*(column_a+row_a+2) + i) = value1 * 1/pivot; // When value1 = pivot, then pivot will be 1
		}
		//printf("Set to 1\n");
		//print(tableau,(row_a+1),(column_a+row_a+2));

		// Turn all other values in pivot column into 0. Jump over pivot row
		// -value1* PIVOT_ROW + ROW -> ROW
		for(int i = 0; i < row_a + 1; i++){
			if(i != pivotRowIndex){
				value1 = *(tableau + i*(column_a+row_a+2) + pivotColumIndex); // This is at pivot column
				for(int j = 0; j < (column_a+row_a+2); j++){
					value2 = *(tableau + pivotRowIndex*(column_a+row_a+2) + j); // This is at pivot row
					value3 = *(tableau + i*(column_a+row_a+2) + j); // This is at the row we want to be 0 at pivot column
					*(tableau + i*(column_a+row_a+2) + j) = -value1*value2 + value3;
				}
			}
		}
		//printf("Set to 0\n");
		//print(tableau,(row_a+1),(column_a+row_a+2));

		// Count for the iteration
		count++;

	}while(entry < 0); // Continue if we have still negative entries

	// Now when we have shaped our tableau. Let's find the optimal solution. Sum the columns
	for(int i = 0; i < column_a; i++){
		value1 = 0; // Reset
		for(int j = 0; j < row_a + 1; j++){
			value1 += *(tableau + j*(column_a+row_a+2) + i); // Summary
			value2 = *(tableau + j*(column_a+row_a+2) + i); // If this is 1 then we are on the selected

			// Check if we have a value that are very close to 1
			if(value1 < 1.00001 && value1 > 0.99999 && value2 > 0.99999){
				*(x + i) = *(tableau + j*(column_a+row_a+2) + (column_a+row_a+2-1));
			}
		}
	}

	//print(tableau,(row_a+1),(column_a+row_a+2));

}