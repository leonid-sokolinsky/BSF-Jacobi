/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: BSF Skeleton
Module: Problem-bsfCode.cpp (Problem-dependent Code)
Prefix: PI
Author: Leonid B. Sokolinsky
This source code is a part of BSF Skeleton
==============================================================================*/
#include "Problem-Data.h"			// Problem Types 
#include "Problem-Forwards.h"		// Problem Function Forwards
using namespace std;

//----------------------- Access to BSF-skeleton parameters  -----------------
void PC_bsf_AssignAddressOffset(int value) { PP_BSF_addressOffset = value; };
void PC_bsf_AssignIterCounter(int value) { PP_BSF_iterCounter = value; };
void PC_bsf_AssignJobCase(int value) { PP_BSF_jobCase = value; };
void PC_bsf_AssignMpiRank(int value) { PP_BSF_mpiRank = value; };
void PC_bsf_AssignNumberInSublist(int value) { PP_BSF_numberInSublist = value; };
void PC_bsf_AssignNumOfWorkers(int value) { PP_BSF_numOfWorkers = value; };
void PC_bsf_AssignSublistLength(int value) { PP_BSF_sublistLength = value; };

//----------------------- Predefined problem-dependent functions -----------------
void PC_bsf_Init(bool* success) { // success=false if initialization is unsuccessful

	PD_g = (double*)malloc(PP_N * sizeof(double));
	if (PD_g == NULL) {
		*success = false;
		return;
	};
	/**/for (int i = 0; i < PP_N; i++) { // Generating Matrix A
		for (int j = 0; j < i; j++)
			PD_A[i][j] = 1;
		PD_A[i][i] = i * 2;
		for (int j = i + 1; j < PP_N; j++)
			PD_A[i][j] = 0;
	};
	PD_A[0][0] = 1;/**/

/*	PD_A[0][0] = 5;		PD_A[0][1] = -2;	PD_A[0][2] = 3;
	PD_A[1][0] = -3;	PD_A[1][1] = 9;		PD_A[1][2] = 1;
	PD_A[2][0] = 2;		PD_A[2][1] = -1;	PD_A[2][2] = -7;/**/

	/**/for (int i = 0; i < PP_N; i++) // Generating Vector of right parts
		PD_b[i] = i + 2 * i;
	PD_b[0] = 1;/**/

/*	PD_b[0] = -1;
	PD_b[1] = 2;
	PD_b[2] = 3;/**/

	for (int i = 0; i < PP_N; i++) { // Clculating reduced matrix Alpha
		for (int j = 0; j < PP_N; j++)
			PD_Alpha[i][j] = -PD_A[i][j] / PD_A[i][i];
		PD_Alpha[i][i] = 0;
	};

	for (int i = 0; i < PP_N; i++) // Clculating reduced vector beta
		PD_beta[i] = PD_b[i] / PD_A[i][i];
}; 

void PC_bsf_AssignListSize(int* listSize) {
	*listSize = PP_N;
};

void PC_bsf_CopyParameter(PT_bsf_parameter_T* parameterIn, PT_bsf_parameter_T* parameterOut) {
	for (int j = 0; j < PP_N; j++)
		parameterOut->approximation[j] = parameterIn->approximation[j];
};

void PC_bsf_SetParameter(PT_bsf_parameter_T* parameter) {
	PD_approximation = parameter->approximation;
};

void PC_bsf_MapF(PT_bsf_mapElem_T* mapElem, PT_bsf_reduceElem_T* reduceElem, 
	int* success // 1 - reduceElem was produced successfully (default); 0 - otherwise
){
	/*debug*//*
#define NODE 0
	if (PP_BSF_mpiRank == NODE) {
		cout << PP_BSF_mpiRank << ":=========>PC_bsf_MapF: numberInSublis = " << PP_BSF_numberInSublist 
			<< "\tsublistLength = " << PP_BSF_sublistLength 
			<< "\tmapElem->columnNo = " << mapElem->columnNo << endl;
		cout << "PD_approximation = ";
		for (int j = 0; j < PP_N; j++) cout << setw(8) << PD_approximation[j]; cout << endl;
	};
	/*end debug*/

	for (int i = 0; i < PP_N; i++)
		reduceElem->column[i] = PD_Alpha[i][mapElem->columnNo] * PD_approximation[mapElem->columnNo];

	/*debug*//*
	if (PP_BSF_mpiRank == NODE) {
		cout << "reduceElem->column:";
		for (int i = 0; i < PP_N; i++)
			cout << setw(8) << reduceElem->column[i];
		cout << endl;
	};
	/*end debug*/
};

void PC_bsf_MapF_1(PT_bsf_mapElem_T* mapElem, PT_bsf_reduceElem_T_1* reduceElem,
	int* success // 1 - reduceElem was produced successfully (default); 0 - otherwise
) {
	/* not used */
};

void PC_bsf_MapF_2(PT_bsf_mapElem_T* mapElem, PT_bsf_reduceElem_T_2* reduceElem,
	int* success // 1 - reduceElem was produced successfully (default); 0 - otherwise
) {
	/* not used */
};

void PC_bsf_MapF_3(PT_bsf_mapElem_T* mapElem, PT_bsf_reduceElem_T_3* reduceElem,
	int* success // 1 - reduceElem was produced successfully (default); 0 - otherwise
	) {
	// optional filling
};

void PC_bsf_ReduceF(PT_bsf_reduceElem_T* x, PT_bsf_reduceElem_T* y, PT_bsf_reduceElem_T* z) { // z = x + y

	for (int i = 0; i < PP_N; i++)
		z->column[i] = x->column[i] + y->column[i];
};
void PC_bsf_ReduceF_1(PT_bsf_reduceElem_T_1* x, PT_bsf_reduceElem_T_1* y, PT_bsf_reduceElem_T_1* z) {/* not used */};
void PC_bsf_ReduceF_2(PT_bsf_reduceElem_T_2* x, PT_bsf_reduceElem_T_2* y, PT_bsf_reduceElem_T_2* z) {/* not used */};
void PC_bsf_ReduceF_3(PT_bsf_reduceElem_T_3* x, PT_bsf_reduceElem_T_3* y, PT_bsf_reduceElem_T_3* z) {/* not used */ }

void PC_bsf_ProcessResults(
	bool* exit, // "true" if Stopping Criterion is satisfied, and "false" otherwise
	PT_bsf_reduceElem_T* reduceResult,
	int reduceCounter, // Number of successfully produced Elrments of Reduce List
	PT_bsf_parameter_T* parameter, // Current Approximation
	int* jobCase
) {
	for (int j = 0; j < PP_N; j++) {
		PD_prevApproximatio[j] = parameter->approximation[j];
		parameter->approximation[j] = reduceResult->column[j] + PD_beta[j];
	};

	/*debug*//*
	int rank; MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	cout << rank << ":=========>PC_bsf_ProcessResults: parameter->approximation:" << endl;
	for (int j = 0; j < PP_N; j++)
		cout << setw(8) << parameter->approximation[j];
	cout << endl;
	/*end debug*/

	if (ExitCondition(parameter))
		*exit = true;
	else
		*exit = false;
};

void PC_bsf_ProcessResults_1(
	bool* exit, // "true" if Stopping Criterion is satisfied, and "false" otherwise
	PT_bsf_reduceElem_T_1* reduceResult,
	int reduceCounter, // Number of successfully produced Elrments of Reduce List
	PT_bsf_parameter_T* parameter, // Current Approximation
	int* jobCase
) {
	// optional filling
};

void PC_bsf_ProcessResults_2(
	bool* exit, // "true" if Stopping Criterion is satisfied, and "false" otherwise
	PT_bsf_reduceElem_T_2* reduceResult,
	int reduceCounter, // Number of successfully produced Elrments of Reduce List
	PT_bsf_parameter_T* parameter, // Current Approximation
	int* jobCase
) {
	// optional filling
};

void PC_bsf_ProcessResults_3(
	bool* exit, // "true" if Stopping Criterion is satisfied, and "false" otherwise
	PT_bsf_reduceElem_T_3* reduceResult,
	int reduceCounter, // Number of successfully produced Elrments of Reduce List
	PT_bsf_parameter_T* parameter, // Current Approximation
	int* newJobCase
	) {
	// optional filling
};

void PC_bsf_ParametersOutput(int numOfWorkers, PT_bsf_parameter_T parameter) {
	cout << "=================================================== Jacobi MR ====================================================" << endl;
	cout << "Number of Workers: " << numOfWorkers << endl;
#ifdef PP_BSF_OMP
#ifdef PP_BSF_NUM_THREADS
	cout << "Number of Threads: " << PP_BSF_NUM_THREADS << endl;
#else
	cout << "Number of Threads: " << omp_get_num_procs() << endl;
#endif // PP_BSF_NUM_THREADS
#else
	cout << "OpenMP is turned off!" << endl;
#endif // PP_BSF_OMP

	cout << "Dimension: N = " << PP_N << endl;
	cout << "Eps_Square = " << PP_EPS << endl;
#ifdef PP_MATRIX_OUTPUT
	cout << "------- Matrix A & Column b -------" << endl;
	for (int i = 0; i < PP_N; i++) {
		for (int j = 0; j < PP_N; j++)
			cout << setw(7) << PD_A[i][j];
		cout << setw(7) << PD_b[i] << endl;
	};
	cout << endl;
	cout << "------- Matrix Alpha & Column Beta -------" << endl;
	for (int i = 0; i < PP_N; i++) {
		for (int j = 0; j < PP_N; j++)
			cout << setw(7) << PD_Alpha[i][j];
		cout << setw(7) << PD_beta[i] << endl;
	};
	cout << endl;
#endif // PP_MATRIX_OUTPUT
	cout << "Initial approximation: "; for (int j = 0; j < PF_MIN(PP_OUTPUT_LIMIT, PP_N); j++) cout << setw(7) << parameter.approximation[j]; cout << (PP_OUTPUT_LIMIT < PP_N ? "..." : "") << endl;
	cout << "-------------------------------------------" << endl;
};

void PC_bsf_IterOutput(PT_bsf_reduceElem_T* reduceResult, int reduceCounter, PT_bsf_parameter_T parameter,
	double elapsedTime, int newJobCase) {
	cout << "------------------ " << PP_BSF_iterCounter << " ------------------" << endl;
	cout << "Approximation:\t\t"; for (int j = 0; j < PF_MIN(PP_OUTPUT_LIMIT, PP_N); j++) cout << setw(12) << parameter.approximation[j]; cout << (PP_OUTPUT_LIMIT < PP_N ? "..." : "") << endl;/**/

};

void PC_bsf_IterOutput_1(PT_bsf_reduceElem_T_1* reduceResult, int reduceCounter, PT_bsf_parameter_T parameter,
	double elapsedTime, int newJobCase)
{
	cout << "------------------ " << PP_BSF_iterCounter << " ------------------" << endl;
	/* not used */
};

void PC_bsf_IterOutput_2(PT_bsf_reduceElem_T_2* reduceResult, int reduceCounter, PT_bsf_parameter_T parameter,
	double elapsedTime, int newJobCase)
{
	cout << "------------------ " << PP_BSF_iterCounter << " ------------------" << endl;
	/* not used */
};

void PC_bsf_IterOutput_3(PT_bsf_reduceElem_T_3* reduceResult, int reduceCounter, PT_bsf_parameter_T parameter,
	double elapsedTime, int jobCase) {
	cout << "------------------ " << PP_BSF_iterCounter << " ------------------" << endl;
	// optional filling

};

void PC_bsf_ProblemOutput(PT_bsf_reduceElem_T* reduceResult, int reduceCounter, PT_bsf_parameter_T parameter,
	double t) {// Output Function
	cout << "=============================================" << endl;
	cout << "Time: " << t << endl;
	cout << "Iterations: " << PP_BSF_iterCounter << endl;
	cout << "Solution: "; for (int j = 0; j < PF_MIN(PP_OUTPUT_LIMIT, PP_N); j++) cout << setw(12) << parameter.approximation[j]; cout << (PP_OUTPUT_LIMIT < PP_N ? "..." : "") << endl;/**/
};

void PC_bsf_ProblemOutput_1(PT_bsf_reduceElem_T_1* reduceResult, int reduceCounter, PT_bsf_parameter_T parameter,
	double t) {// Output Function
	// optional filling
};

void PC_bsf_ProblemOutput_2(PT_bsf_reduceElem_T_2* reduceResult, int reduceCounter, PT_bsf_parameter_T parameter,
	double t) {// Output Function
	// optional filling
};

void PC_bsf_ProblemOutput_3(PT_bsf_reduceElem_T_3* reduceResult, int reduceCounter, PT_bsf_parameter_T parameter,
	double t) {// Output Function
	// optional filling
};

void PC_bsf_SetInitParameter(PT_bsf_parameter_T* parameter) {
	for (int i = 0; i < PP_N; i++) // Generating coordinates of initial appriximation
		parameter->approximation[i] = PD_beta[i];
};

void PC_bsf_SetMapSubList(PT_bsf_mapElem_T* sublist, int sublistLength, int offset, bool* success) {
	for (int i = 0; i < sublistLength; i++) 
			sublist[i].columnNo = i + offset;
	/*debug*//*
	int rank; MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	cout << rank << ":=========>PC_bsf_SetMapSubList: sublistLength = " << sublistLength << "\toffset = " << offset << endl;
	for (int i = 0; i < sublistLength; i++)
		cout << setw(5) << sublist[i].columnNo;
	cout << endl;
	/*end debug*/
};

//----------------------------- User functions -----------------------------
static double Norm(PT_point_T x) {
	double sum = 0;
	/*#ifdef PP_BSF_OMP
	#ifdef PP_BSF_NUM_THREADS
	#pragma omp parallel for num_threads(PP_BSF_NUM_THREADS) reduction(+:sum)
	#else
	#pragma omp parallel for reduction(+:sum)
	#endif // PP_BSF_NUM_THREADS
	#endif // PP_BSF_OMP/**/
	for (int j = 0; j < PP_N; j++)
		sum += x[j] * x[j];
	return sqrt(sum);
};

static bool ExitCondition(PT_bsf_parameter_T* parameter) {
	PT_point_T difference; // Difference between current and previous approximations

#ifdef PP_MAX_ITER_COUNT
	if (PP_BSF_iterCounter > PP_MAX_ITER_COUNT) {
		cout << "Acceptable maximum number of iterations is exceeded: PP_MAX_ITER_COUNT = " << PP_MAX_ITER_COUNT << endl;
		return true;
	};
#endif // PP_MAX_ITER_COUNT

	for (int j = 0; j < PP_N; j++)
		difference[j] = PD_prevApproximatio[j] - parameter->approximation[j];
	if (Norm(difference) < PP_EPS)
		return true;
	else
		return false;
};
