/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: BSF Skeleton
Module: Problem-Data.h (Problem Data)
Prefix: PP
Author: Leonid B. Sokolinsky
This source code is a part of BSF Skeleton
==============================================================================*/
#include "Problem-Types.h"		// Problem Parameters 
//========================== Problem variables ====================================
static double* PD_g;
static double* PD_approximation;
//========================== Problem structures ====================================
static double PD_A[PP_N][PP_N];			// Coefficients of equations
static double PD_b[PP_N];				// Vector of right parts
static double PD_Alpha[PP_N][PP_N];		// Reduced matrix
static double PD_beta[PP_N];			// Reduced vector of right parts
static double PD_prevApproximatio[PP_N];// Previous approximation
