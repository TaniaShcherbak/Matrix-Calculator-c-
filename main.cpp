#include <iostream>
#include <math.h>
#include<stdlib.h>
#include<time.h>
#include <bits/stdc++.h>
using namespace std;
void InputMatrix (int **mas, int,int);
void OutputMatrix (int **mas,int,int);
void DeleteMatrix (int **mas,int,int);
int main() {
	system("color FD");
	system("title M a t r i x   C a l c u l a t i o n");
	int col1,row1,col2,row2;
	int number;
	while (number!=6) {
		system("cls");
		cout<<"     M a t r i x   C a l c u l a t i o n     "<<endl;
		cout<<"Type in the number of operation"<<endl<<"1-addition;"<<endl
		<<"2-subtraction;"<<endl
		<<"3-multiplication of matrices;"<<endl
		<<"4-multiplication by a number;"<<endl
		<<"5-transposed matrix;"<<endl
		<<"6-exit"<<endl;
		cin>>number;
			switch (number) {
				case 1:
			/*Adding matrices of the same size. We initialize 2 dynamic arrays for input and one dynamic array for the result.
			 Filling and exporting the elements of the array to the consol's screen is implemented via functions*/
				{
					cout<<"Addition of matrices"<<endl;
					cout<<"Type in number of rows and cols of matrices"<<endl<<"rows=";
					cin>>row1;
					cout<<"cols=";
					cin>>col1;
					int **FirstMatrix=new int *[row1];
					for (int i=0;i<row1;i++){
						FirstMatrix[i]=new int [col1];
					}
					cout<<"Type in first matrix"<<endl;
					InputMatrix (FirstMatrix,row1,col1);
					int **SecondMatrix=new int *[row1];
					for (int i=0;i<row1;i++){
						SecondMatrix[i]=new int [col1];
					}
					cout<<"Type in second matrix"<<endl;
					InputMatrix (SecondMatrix,row1,col1);
					int **ResultMatrix=new int *[row1];
					for (int i=0;i<row1;i++){
						ResultMatrix[i]=new int [col1];
					}
					for (int i=0;i<row1;i++ ){
						for (int j=0;j<col1;j++){
							ResultMatrix[i][j]=FirstMatrix[i][j]+SecondMatrix[i][j];
						}
					}
					OutputMatrix (FirstMatrix,row1,col1);
					cout<<"   +   "<<endl;
					OutputMatrix (SecondMatrix,row1,col1);
					cout<<"Result of addition:"<<endl;
					OutputMatrix (ResultMatrix,row1,col1);
					DeleteMatrix (FirstMatrix,col1,row1);
					DeleteMatrix (SecondMatrix,col1,row1);
					DeleteMatrix (ResultMatrix,col1,row1);
					cout<<"Press any button to return to the menu"<<endl;
					system("pause > nul");
					break;
				}	
				case 2:
				/*Subtracting matrices of the same size. We initialize 2 dynamic arrays for input and one dynamic array for the result.
				 Filling and exporting the elements of the array to the consol's screen is implemented via functions*/
				{
				 	cout<<"Subtraction of matrices"<<endl;
				 	cout<<"Type in number of rows and cols of matrices"<<endl<<"rows=";
					cin>>row1;
					cout<<"cols=";
					cin>>col1;
					int **FirstMatrix=new int *[row1];
					for (int i=0;i<row1;i++){
						FirstMatrix[i]=new int [col1];
					}
					cout<<"Type in first matrix"<<endl;
					InputMatrix (FirstMatrix,row1,col1);
					int **SecondMatrix=new int *[row1];
					for (int i=0;i<row1;i++){
						SecondMatrix[i]=new int [col1];
					}
					cout<<"Type in second matrix"<<endl;
					InputMatrix (SecondMatrix,row1,col1);
					int **ResultMatrix=new int *[row1];
					for (int i=0;i<row1;i++){
						ResultMatrix[i]=new int [col1];
					}
					for (int i=0;i<row1;i++ ){
						for (int j=0;j<col1;j++){
							ResultMatrix[i][j]=FirstMatrix[i][j]-SecondMatrix[i][j];
						}
					}
					OutputMatrix (FirstMatrix,row1,col1);
					cout<<"   -   "<<endl;
					OutputMatrix (SecondMatrix,row1,col1);
					cout<<"Result of subtraction:"<<endl;
					OutputMatrix (ResultMatrix,row1,col1);
					DeleteMatrix (FirstMatrix,col1,row1);
					DeleteMatrix (SecondMatrix,col1,row1);
					DeleteMatrix (ResultMatrix,col1,row1);
					cout<<"Press any button to return to the menu"<<endl;
					system("pause > nul");
					break;
				}
				case 3:
				/*Multiplicating matrices of the same size. We initialize 2 dynamic arrays for input and one dynamic array for the result.
				 Filling and exporting the elements of the array to the consol's screen is implemented via functions*/
				{
				 	cout<<"Multiplication of matrices"<<endl;
				 	cout<<"Type in number of rows and cols of first matrix"<<endl<<"rows=";
					cin>>row1;
					cout<<"cols=";
					cin>>col1;
					int **FirstMatrix=new int *[row1];
					for (int i=0;i<row1;i++){
						FirstMatrix[i]=new int [col1];
					}
					cout<<"Type in first matrix"<<endl;
					InputMatrix (FirstMatrix,row1,col1);
					cout<<"Type in number of rows and cols of second matrix."<<endl<<"Number of rows of second matrix must match cols of first"<<endl<<"rows=";
					cin>>row2;
					cout<<"cols=";
					cin>>col2;
					int **SecondMatrix=new int *[row2];
					for (int i=0;i<row2;i++){
						SecondMatrix[i]=new int [col2];
					}
					cout<<"Type in second matrix"<<endl;
					InputMatrix (SecondMatrix,row2,col2);
					if (col1!=row2){
						cout<<"The operation is not possible for the given matrix size"<<"Please change cize of matrix";
					}
					else {
						int **ResultMatrix=new int *[row1];
						for (int i=0;i<row1;i++){
							ResultMatrix[i]=new int [col2];
						}
						for (int i=0;i<row1;i++ ){
							for (int j=0;j<col2;j++){
								ResultMatrix[i][j]=0;
								for (int k = 0; k < col1; k++){
									ResultMatrix[i][j]+=FirstMatrix[i][k]*SecondMatrix[k][j];
								}
							}
						}
						OutputMatrix (FirstMatrix,row1,col1);
						cout<<"   *   "<<endl;
						OutputMatrix (SecondMatrix,row2,col2);
						cout<<"Result of multiplication:"<<endl;
						OutputMatrix (ResultMatrix,row1,col2);
						DeleteMatrix (ResultMatrix,col2,row1);
					}
					DeleteMatrix (FirstMatrix,col1,row1);
					DeleteMatrix (SecondMatrix,col1,row1);
					cout<<"Press any button to return to the menu"<<endl;
					system("pause > nul");
				 	break;
				}	
				case 4:
				/*Multiplication a matrix by a number. We initialize 1 dynamic array for input and one dynamic array for the result and 1 static variable.
				 Filling and exporting the elements of the array to the consol's screen is implemented via functions*/
				{
				 	cout<<"Multiplication by a number"<<endl;
				 	cout<<"Type in number of rows and cols of matrix"<<endl<<"rows=";
					cin>>row1;
					cout<<"cols=";
					cin>>col1;
					int **Matrix=new int *[row1];
					for (int i=0;i<row1;i++){
						Matrix[i]=new int [col1];
					}
					cout<<"Type in matrix"<<endl;
					InputMatrix (Matrix,row1,col1);
					int multiplier;
					cout<<"Type in multiplier-number ";
					cin>>multiplier;
					int **ResultMatrix=new int *[row1];
					for (int i=0;i<row1;i++){
						ResultMatrix[i]=new int [col1];
					}
					for (int i=0;i<row1;i++ ){
						for (int j=0;j<col1;j++){
							ResultMatrix[i][j]=Matrix[i][j]*multiplier;
						}
					}
					OutputMatrix (Matrix,row1,col1);
					cout<<" * "<<multiplier<<" ="<<endl;
					OutputMatrix (ResultMatrix,row1,col1);
					DeleteMatrix (Matrix,col1,row1);
					DeleteMatrix (ResultMatrix,col1,row1);
					cout<<"Press any button to return to the menu"<<endl;	
					system("pause > nul");
					break;
				}
				case 5:
				/*Transposition of a matrix. We initialize one dynamic array for input and one dynamic array for the result.
				 Filling and exporting the elements of the array to the consol's screen is implemented via functions*/
				{
					cout<<"Transposed matrix"<<endl;
					cout<<"Type in number of rows and cols of matrix"<<endl<<"rows=";
					cin>>row1;
					cout<<"cols=";
					cin>>col1;
					int **Matrix=new int *[row1];
					for (int i=0;i<row1;i++){
						Matrix[i]=new int [col1];
					}
					cout<<"Type in matrix"<<endl;
					InputMatrix (Matrix,row1,col1);
					int **ResultMatrix=new int *[row1];
					for (int i=0;i<row1;i++){
						ResultMatrix[i]=new int [col1];
					}
					for (int i=0;i<col1;i++ ){
						for (int j=0;j<row1;j++){
							ResultMatrix[i][j]=Matrix[j][i];
						}
					}
					OutputMatrix (Matrix,row1,col1);
					cout<<"Result of transposition:"<<endl;
					OutputMatrix (ResultMatrix,row1,col1);
					DeleteMatrix (Matrix,col1,row1);
					DeleteMatrix (ResultMatrix,col1,row1);
					cout<<"Press any button to return to the menu"<<endl;
					system("pause > nul");
					break;	
				}
				default:
				{
					if (number==6){
						break;	
					}
					else {
						cout<<"Ooops, it's not a point of menu. Please chooce point of menu"<<endl;	
						cout<<"Press any button to return to the menu"<<endl;
						system("pause > nul");
						break;
					}		
				}	
			}
		}
	}
void InputMatrix (int **mas,int col,int row){
	for (int i=0;i<col;i++){
		for (int j=0;j<row;j++){
			cout<<"["<<i<<"]["<<j<<"] =";
			cin>>mas[i][j];
		}
	}
}
void OutputMatrix (int **mas, int col,int row){
	for (int i=0;i<col;i++){
		for (int j=0;j<row;j++){
			cout<<mas[i][j]<<"  ";
		}
		cout<<endl;
	}
}
void DeleteMatrix (int **mas,int col,int row){
	for (int i=0; i<row;i++){
		delete []mas[i];
	}
	delete mas;
}
