/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: BSF Skeleton
Module: Problem-bsf-Forwards.h (Problem Function Forwards)
Author: Leonid B. Sokolinsky 
This source code is a part of BSF Skeleton (https://github.com/leonid-sokolinsky/BSF-skeleton)
==============================================================================*/
#include "Problem-bsfTypes.h"	// Predefined Problem Parameters
#include "Problem-Types.h"		// Problem Types

inline PT_float_T A(int i, int j);		// Matrix A
inline PT_float_T Alpha(int i, int j);	// Redused matrix Alpha
inline PT_float_T b(int i);				// Column b of right parts
inline PT_float_T beta(int i);			// Reduced colunm beta
static double Norm(PT_vector_T x);	// Calculates the square of the vector norm
static bool StopCond(PT_bsf_parameter_T* parameter); // Calculates the stop condition