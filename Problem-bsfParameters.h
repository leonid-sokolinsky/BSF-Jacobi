/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: BSF Skeleton
Module: Problem-bsfParameters.h (Predefined Problem Parameters)
Prefix: PP_BSF
Author: Leonid B. Sokolinsky
This source code is a part of BSF Skeleton
==============================================================================*/

//=========================== Skeleton Parameters =========================
#define PP_MAX_MPI_SIZE 500			// Maximal MPI Size
#define PP_BSF_PRECISION 4			// Decimal precision on output
#define PP_BSF_ITER_OUTPUT			// If it is defined then Iteration Output is performed
#define PP_BSF_TRACE_COUNT 1		// Each PP_BSF_TRACE_COUNT-th iteration to be outputted
#define PP_BSF_MAX_JOB_CASE 0
#define PP_BSF_FRAGMENTED_MAP_LIST	// If it is defined, the worker-node stores only its part of the map-list. 
										// Otherwise, the map-list is replicated on each worker-node. 
//--------------------------- OpenMP Parameters ---------------------------
//#define PP_BSF_OMP				// If PP_BSF_OMP is defined then OpenMP is turned on for Map Step
//#define PP_BSF_NUM_THREADS 2	// If PP_BSF_NUM_THREADS is udefined then all accessable threads are used
//=========================== Skeleton Variables =========================
static int PP_BSF_addressOffset;
static int PP_BSF_iterCounter;
static int PP_BSF_jobCase;
static void* PP_BSF_mapSubList;
static int PP_BSF_mpiRank;
static int PP_BSF_numberInSublist;
static int PP_BSF_numOfWorkers;
static int PP_BSF_sublistLength;