/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: BSF Skeleton
Module: Problem-Parameters.h (Problem Parameters)
Prefix: PP
Author: Leonid B. Sokolinsky

This source code is a part of BSF Skeleton (https://github.com/leonid-sokolinsky/BSF-skeleton)
==============================================================================*/

//=========================== Problem Parameters =========================
#define PP_N 40					// Dimension of space
//#define PP_MAX_ITER_COUNT 10
#define PP_EPS 1E-9				// Precision

//-------------------------- Outpoot Parameters ---------------------------
#define PP_OUTPUT_LIMIT	11	// Number of Elements to output
//#define PP_MATRIX_OUTPUT	// Output Matrix

//-------------------------- Macroses ---------------------------
#define PF_MIN(x,y) (x<y?x:y)