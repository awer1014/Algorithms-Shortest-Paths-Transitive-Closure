//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


int n,range,maxRange,maxInt,start,ln;
int **Edge;
int **SSAD;
int **A;

 void newMatrix(int flag) {
	 if(Edge != NULL) {
		 for(int i = 0; i < ln; i++) {
			 delete[] Edge[i];
		 }
		 delete[] Edge;
	 }
	 Edge = new int*[n];
	 for(int i = 0;i < n;i++){
		 Edge[i] = new int[n];
	}
}


 void ran(bool b) {
	 int a;newMatrix(1);if(b) {
		 for(int i = 0; i < n; i++) {
			 for(int j = i+1; j < n; j++) {
				 a = rand()%range+1;
				 Edge[i][j] = a > maxRange ? maxInt:a;
				 Edge[j][i] = Edge[i][j];
			 }
			 Edge[i][i] = maxInt;
		 }
	 }
	 else {
		 for(int i = 0; i < n; i++) {
			 for(int j = 0; j < n; j++) {
				 a = rand()%range+1;
				 Edge[i][j] = a > maxRange ? maxInt:a;
			 }
			 Edge[i][i] = maxInt;
		 }
	 }
 }


 void draw(int flag) {
	 if (flag == 1) {
		 Form1->StringGrid1->RowCount = n;
		 Form1->StringGrid1->ColCount = n;
		 for (int i = 0; i < n; i++) {
			 for (int j = 0; j < n; j++) {
				 Form1->StringGrid1->Cells[j][i] = Edge[i][j];
			 }
		 }
	 }
 	else if (flag == 2) {
		Form1->StringGrid2->RowCount = n;
		Form1->StringGrid2->ColCount = n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				Form1->StringGrid2->Cells[j][i] = SSAD[i][j];
			}
		}
	}

 	else if(flag == 3){
 		Form1->StringGrid3->RowCount = n;
 		Form1->StringGrid3->ColCount = n;
 		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				Form1->StringGrid3->Cells[j][i] = A[i][j];
			}
		}
	}
 	else if(flag == 4) {
 		Form1->StringGrid4->RowCount = n;
 		Form1->StringGrid4->ColCount = n;
 		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				Form1->StringGrid4->Cells[i][j] = Form1->StringGrid3->Cells[i][j]==maxInt?0:1;
			}
		}
	}
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	FILE *fp;
	AnsiString out;
	if (OpenDialog1->Execute()) {
		out = OpenDialog1->FileName;
		fp = fopen(out.c_str(), "r+");
		fscanf(fp, "%d %d %d %d", &n, &range, &maxRange, &maxInt);

		Edit1->Text = n;
		Edit2->Text = range;
		Edit3->Text = maxRange;
		Edit4->Text = maxInt;

		newMatrix(1);
    draw(1);
		ln = n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fscanf(fp, "%d", &Edge[i][j]);
			}
		}
		newMatrix(2);
		fclose(fp);
	}
	else
	Memo1->Lines->Add("Nothing happens.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{// generate G
	n = StrToInt(Edit1->Text);
	range = StrToInt(Edit2->Text);
	maxRange = StrToInt(Edit3->Text);
	maxInt = StrToInt(Edit4->Text);
	start = StrToInt(Edit5->Text);
	ran(CheckBox2->Checked);
	ln = n;
	if(CheckBox1->Checked) {
		draw(1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	//single Source All Destinations
	int num = 1;
	int *D = new int[n],*found = new int[n],*from = new int[n];
	SSAD = new int*[n];
	for (int i = 0; i < n; i++) {
		D[i] = Edge[start][i];
		SSAD[i] = new int[n];
		found[i] = 0;
		from[i] = i;
	}

	found[start] = 1;
	D[start] = 0;

	for (int i = 0; i < n; i++) {
		SSAD[i][0] = D[i];
	}

	while (num < n) {
		int min;
		for(int i = 0; i < n; i++) {
			if(!found[i]) {
				min = i;break;
			}
		}
		for(int i = 0; i < n; i++) {
			if(D[i] < D[min] && found[i] == 0) {
				min = i;
			}
		}
		if(D[min] < maxInt) {
			found[min] = 1;
			num++;
			Memo1->Lines->Add("min = " + IntToStr(min));
		}
		else break;
		for (int i = 0; i < n; i++) {
			if (!found[i]) {
				D[i] = D[i] < D[min] + Edge[min][i] ? D[i]:D[min] + Edge[min][i];
				from[i] = D[i] < D[min] + Edge[min][i] ? i:min;
			}
			SSAD[i][num-1] = D[i];
		}
	}

	if(num < n) {
		Memo1->Lines->Add("No solution for this case.");
	}
	else if (CheckBox3->Checked) {
		for (int i = 0; i < n; i++) {
			String str = "The shortest distance from " + IntToStr(start) + " to " + IntToStr(i) + " is " + IntToStr(D[i]);
			str += " with path start ";
			if (from[i] != i) {
				for(int j = i; from[j] != j; j = from[j]) {
					str = str + "--[" + IntToStr(D[i]) + "]-->" + IntToStr(from[i]) + "-->";
				}
			}
			else {
				str += "-->";}str += "end";Memo1->Lines->Add(str);
			}
		}
	Memo1->Lines->Add("------------------------------------------");

	draw(2);

	for (int i = 0; i < n; i++) {
		delete[] SSAD[i];
	}
	delete SSAD;
	delete D;
	delete found;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  //All Pairs
	A = new int*[n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = Edge[i][j];
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				A[i][j]= A[i][j] < A[i][k]+A[k][j]?A[i][j]:A[i][k]+A[k][j];
			}
		}
	}

	draw(3);

	for (int i = 0; i < n; i++) {
		delete[] A[i];
	}
	delete A;
}
//------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
 //Transitive Closure
 	draw(4);
}
//---------------------------------------------------------------------------
