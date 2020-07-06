/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: BSF Skeleton
Module: BSF-VariableAccess.h (Access to BSF-skeleton variables)
Prefix: BV
Author: Leonid B. Sokolinsky
This source code is a part of BSF Skeleton
==============================================================================*/
void BV_AssignAddressOffset(int value) { PP_BSF_addressOffset = value; };
void BV_AssignIterCounter(int value) { PP_BSF_iterCounter = value; };
void BV_AssignJobCase(int value) { PP_BSF_jobCase = value; };
void BV_AssignMapSubList(PT_bsf_mapElem_T* value) { PP_BSF_mapSubList = value; };
void BV_AssignMpiRank(int value) { PP_BSF_mpiRank = value; };
void BV_AssignNumberInSublist(int value) { PP_BSF_numberInSublist = value; };
void BV_AssignNumOfWorkers(int value) { PP_BSF_numOfWorkers = value; };
void BV_AssignSublistLength(int value) { PP_BSF_sublistLength = value; };
