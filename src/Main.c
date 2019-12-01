/*
 ============================================================================
 Name        : Adaptive_Model_Predictive_Control.c
 Author      : Daniel Mårtensson
 Version     : 1.0
 Copyright   : MIT
 Description : Adaptive Model Predictive Control
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "CControl/Headers/Configurations.h"
#include "CControl/Headers/Functions.h"

int main() {

	/*
	 * In this example we have selected the following configuration inside Confiugration.h
	 * SELECTED_CONTROL_STRATEGY MANUAL
	 * q 1000 // Initial diagonal values for P matrix for system identification. 1000 is a good number
	 * LAMBDA 1 // Forgetting factor for system identification. Lambda Should not be less than zero
	 * POLY_LENGTH 6 // Length of polynomials A(q), B(q) and C(q) in Recursive least squares

	 * HORIZON 50 // How long we want to look in the future
	 * ALPHA 0.1 // This will prevent dead-beat control and gives more smooth input values
	 * INTEGRATION TRUE // Enable integral action inside model - Recommended
	 * ITERATION_LIMIT 100 // This is for MPC
	 * ANTI_WINDUP ALWAYS_INTEGRATE // The integral function for MRAC
	 * LEARNING 0.0001 // For MRAC
	 */

	/* MRAC works as K1 and K2 integrates over time so y -> r when time -> inf
	 * r ----{K1}*(-LEARNING)---->+()----->G(s)-----------------------> y
	 *               			  -^            			  |
	 *               			   |            			  |
	 *                			   |              			  |
	 *                  		   |----*(LEARNING){K2}<-------
	 */

	float y[RDIM] = {7};
	float u[RDIM] = {0};
	float r[RDIM] = {51};
	float K1[RDIM] = {3.1};
	float K2[RDIM] = {4.1};

	// Compute now
	mrac(y, u, r, K1, K2);

	// Show input signal
	printf("Our output signal\n");
	print(u, RDIM, 1);

	return EXIT_SUCCESS;
}