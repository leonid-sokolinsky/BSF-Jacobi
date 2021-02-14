/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: BSF Skeleton
Module: Problem-bsfTypes.h (Predefined Problem-depended BSF Types)
Prefix: PT_bsf
Author: Leonid B. Sokolinsky
This source code is a part of BSF Skeleton (https://github.com/leonid-sokolinsky/BSF-skeleton)
==============================================================================*/
#pragma once
#include "Problem-Types.h"		// Problem Types 

//=========================== BSF Types =========================
struct PT_bsf_parameter_T {			
	PT_vector_T x;	// Current approximation
};
struct PT_bsf_mapElem_T {		
	int columnNo;				// Column number in matrix Alpha
	PT_vector_T column;			// Column of reduced matrix		
};
struct PT_bsf_reduceElem_T {		
	PT_vector_T column;		// Column of intermediate matrix		
};

struct PT_bsf_reduceElem_T_1 {				
	// optional filling
};

struct PT_bsf_reduceElem_T_2 {
	// optional filling
};

struct PT_bsf_reduceElem_T_3 {
	// optional filling
};