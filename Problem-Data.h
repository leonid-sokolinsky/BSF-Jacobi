/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: BSF Skeleton
Module: Problem-Data.h (Problem Data)
Prefix: PP
Author: Leonid B. Sokolinsky
This source code is a part of BSF Skeleton
==============================================================================*/
#include "Problem-Types.h"		// Problem Parameters 

//=========================== Variables for BSF-skeleton Parameters =========================
static int PP_BSF_addressOffset;
static int PP_BSF_iterCounter;
static int PP_BSF_jobCase;
static int PP_BSF_mpiRank;
static int PP_BSF_numberInSublist;
static int PP_BSF_numOfWorkers;
static int PP_BSF_sublistLength;

//========================== Problem variables ====================================
static double* PD_g;
static double* PD_approximation;
//========================== Problem structures ====================================
static double PD_A[PP_N][PP_N];			// Coefficients of equations
static double PD_b[PP_N];				// Vector of right parts
static double PD_Alpha[PP_N][PP_N];		// Reduced matrix
static double PD_beta[PP_N];			// Reduced vector of right parts
static double PD_prevApproximatio[PP_N];// Previous approximation
