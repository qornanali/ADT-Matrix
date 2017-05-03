/*
============================================================
Program 		: matrix.h
Deskripsi		: header body untuk matrix linked list
Dimodifikasi 	: Ali Qornan Jaisyurrahman / 151511007 
				Akhmad Nawawi / 151511005
Sumber 			: Ryan Haidy Papudi/131524025
Tanggal/Versi 	: 28/04/2016
============================================================ 
*/
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

#ifndef matrix_H
#define matrix_H 

void InsertNode(List *L, infotype X, int i, int j);

void InsertNext(address PP, address P);

void InsertDown(address PP, address P);

void Display(List L);

void SumMatrix(List *L3, List L1, List L2,int i,int j);

int JumlahElmt(List L);

#endif
