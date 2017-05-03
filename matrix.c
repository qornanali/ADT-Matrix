/*
============================================================
Program 		: matrix.c
Deskripsi		: modul untuk matrix linked list
Dimodifikasi 	: Ali Qornan Jaisyurrahman / 151511007 
				Akhmad Nawawi / 151511005
Sumber 			: Ryan Haidy Papudi/131524025
Tanggal/Versi 	: 28/04/2016
============================================================ 
*/
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"
#include "matrix.h"

void InsertNode(List *L, infotype X, int i, int j){
	
	address P=Alokasi(X),
			PP=First(*L),
			FirstBar=First(*L);
	int k=1,l=1;
	boolean status=true;
	
	if(JumlahElmt(*L)<i*j){
		if(ListEmpty(*L)){
			First(*L)=P;
		} else {
			while(Next(PP)!=Nil){
				PP=Next(PP);
				k++;
				if(k==i && Next(PP)==Nil ){
					if(Down(FirstBar)==Nil){
						InsertDown(FirstBar,P);
						status=false;
					} else {
						FirstBar=Down(FirstBar);
						PP=FirstBar;
					}
					k=1;
					l++;
				}
			}
			if(status==true) InsertNext(PP,P);
		}
	} else {
		printf("\nMatrix overflow !\n");
	}
}

void InsertNext(address PP, address P){
	Next(PP) = P;
	Prev(P) = PP;
	if(Up(PP)!=Nil){
		Up(P) = Next(Up(PP));
		Down(Next(Up(PP))) = P;
	}
}

void InsertDown(address PP, address P){
	Down(PP)=P;
	Up(P)=PP;
}

void Display(List L){
	address P=First(L),
			PP=First(L);
	
	if( P==Nil) { 
		printf("List Kosong !\n");
	} else { 
	    do {
		  if(Prev(P)==Nil) printf(" ");
	 	  printf("%d ",Info(P));
		  P=Next(P);
		  if(P==Nil) {
		  	PP=Down(PP);
		  	P=PP;
		  	printf("\n");
		  }
	    } while(P!=Nil); 
	}
  	printf("\n");
}

void SumMatrix(List *L3, List L1, List L2,int i, int j){
	address P1=First(L1),
			PP1=First(L1),
			P2=First(L2),
			PP2=First(L2);
	infotype X;
	
	do {
		X=Info(P1)+Info(P2);
		InsertNode(&(*L3),X,i,j);
		P1=Next(P1);
		P2=Next(P2);
		if(P1==Nil && P2==Nil) {
			PP1=Down(PP1);
		 	PP2=Down(PP2);
			P1=PP1;
			P2=PP2;
		}
	} while(P1!=Nil && P2!=Nil); 
}

int JumlahElmt(List L)
{ 
	address P,PP;
	int JmlElm=0;
	
	if(ListEmpty(L)){
 		return 0;
	} else { 
		P=First(L);
		PP=P;
    	do {
			JmlElm++;  
			P=Next(P);
			
			if(P==Nil) {
		  		PP=Down(PP);
		  		P=PP;
			}  
	    }while(P!=Nil);
  	}
    return JmlElm;		      
}
