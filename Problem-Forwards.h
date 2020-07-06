/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: BSF Skeleton
Module: Problem-bsf-Forwards.h (Problem Function Forwards)
Author: Leonid B. Sokolinsky 
This source code is a part of BSF Skeleton
==============================================================================*/
#include "Problem-bsfTypes.h"	// Predefined Problem Parameters
#include "Problem-Types.h"		// Problem Types

static double Norm(PT_point_T x);	// Calculates the square of the vector norm
static bool ExitCondition(PT_bsf_parameter_T* parameter); 

//====================== Macros ================================
#define PF_MIN(x,y) (x<y?x:y)
