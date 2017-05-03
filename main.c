/*
============================================================
Program 		: main.c
Deskripsi		: driver program utama
Dimodifikasi 	: Ali Qornan Jaisyurrahman / 151511007 
				Akhmad Nawawi / 151511005
Sumber 			: Ani Rahmani / 23501007
Tanggal/Versi 	: 28/04/2016
============================================================ 
*/
#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main()
{	/* Kamus */
	List A,B,C;
	infotype X;
	int i,j,k,l,m,n;
	puts("Matrix A");
	printf("Jumlah kolom : "); scanf("%d",&i);
	printf("Jumlah baris : "); scanf("%d",&j);
	
	CreateList(&A);
	for(m=0;m<i;m++){
		for(n=0;n<j;n++){
			printf("[%d][%d] = ",m,n);
			scanf("%d",&X);
			InsertNode(&A,X,i,j);
		}
	}
	system("cls");
	printf("Matrix A : \n");Display(A);
	getch();
	system("cls");
	puts("Matrix B");
	printf("Jumlah kolom : "); scanf("%d",&k);
	printf("Jumlah baris : "); scanf("%d",&l);
	CreateList(&B);
	for(m=0;m<k;m++){
		for(n=0;n<l;n++){
			printf("[%d][%d] = ",m,n);
			scanf("%d",&X);
			InsertNode(&B,X,k,l);
		}
	}
	if(i!=m || j!=n){
		printf("Ordo beda\n");
	}else{
		system("cls");
		printf("Matrix B : \n");Display(B);
		getch();
		system("cls");
		printf("Matrix A : \n");Display(A);
		printf("Dijumlahkan dengan\n");
		printf("Matrix B : \n");Display(B);
		printf("Sama dengan\n");
		CreateList(&C);
		SumMatrix(&C,A,B,i,j);
		printf("Matrix C : \n");Display(C);
	}

	return 0;
}

