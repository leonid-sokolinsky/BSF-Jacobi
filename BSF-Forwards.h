/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: BSF Skeleton
Module: BSF-Forwards.h (Problem Independent Function Forwards)
Author: Leonid B. Sokolinsky 
This source code is a part of BSF Skeleton
==============================================================================*/
#include "BSF-Types.h"					// Problem Independent Types 

static void	BC_Init(bool* success);		// BSF Initialization
static void BC_Master();				// Master Process
static void BC_MasterMap(bool exit);
static void BC_MasterReduce();
static void BC_MpiRun();
static void BC_ProcessExtendedReduceList(BT_extendedReduceElem_T* reduceList, int index, int length,
	BT_extendedReduceElem_T** extendedReduceResult_P);
static void BC_ProcessExtendedReduceList_1(BT_extendedReduceElem_T_1* reduceList, int index, int length,
	BT_extendedReduceElem_T_1** extendedReduceResult_P);
static void BC_ProcessExtendedReduceList_2(BT_extendedReduceElem_T_2* reduceList, int index, int length,
	BT_extendedReduceElem_T_2** extendedReduceResult_P);
static void BC_ProcessExtendedReduceList_3(BT_extendedReduceElem_T_3* reduceList, int index, int length,
	BT_extendedReduceElem_T_3** extendedReduceResult_P);
static void BC_Worker();	// Worker Process
static bool BC_WorkerMap();
static void BC_WorkerReduce();

/*---------------- BSF-Variable Access ----------------------*/
void BV_AssignAddressOffset(int value);
void BV_AssignIterCounter(int value);
void BV_AssignJobCase(int value);
void BV_AssignMapSubList(PT_bsf_mapElem_T* value);
void BV_AssignMpiRank(int value);
void BV_AssignNumberInSublist(int value);
void BV_AssignNumOfWorkers(int value);
void BV_AssignSublistLength(int value);
