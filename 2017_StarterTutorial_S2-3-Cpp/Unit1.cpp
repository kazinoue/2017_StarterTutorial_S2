//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
// 分岐のない単純な文の例
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int iA = 1;
	int iB = 0;

	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	/* コメントですよー */

	iB = iA + 2;
	Memo1->Lines->Insert(0, Format( "%d + 2 = %d", ARRAYOFCONST(( iA, iB )) ) );
}
//---------------------------------------------------------------------------
// if 文による分岐の例
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	if (Switch1->IsChecked == True) {
		// if文が true / 真の時に実行される処理
		Memo1->Lines->Insert(0, L"Switch1 が on です。" );
	}

	if (Switch1->IsChecked == True) {
		// if文が true / 真の時に実行される処理
		Memo1->Lines->Insert(0, L"Switch1 が on です。" );
	}
	else {
		// if文が false / 偽の時に実行される処理
		Memo1->Lines->Insert(0, L"Switch1 が off です。" );
	}
}
//---------------------------------------------------------------------------
// switch ... case の例
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	if (ListBox1->Selected == nullptr ) {
		Memo1->Lines->Insert( 0, L"リストボックスは未選択です。" );
	}
	else
	{
		int a = StrToInt(ListBox1->Selected->Text);

		switch(a) {

			case 1:
			//処理１
			Memo1->Lines->Insert( 0, L"リストボックスの値は 1 です。" );
			break;

			case 2:
			//処理2
			Memo1->Lines->Insert( 0, L"リストボックスの値は 2 です。" );
			break;

			case 3:
			//処理3
			Memo1->Lines->Insert( 0, L"リストボックスの値は 3 です。" );
			break;

			//デフォルトの処理
			default:
			Memo1->Lines->Insert( 0, L"リストボックスは 1 - 3 以外が選ばれています。" );
			break;
		}

		if (a == 1) {
			//処理１
		}
		else if ( a == 2 ) {
			//処理2
		}
		else if ( a == 3 ) {
			//処理3
		}
		else {
			// デフォルトの処理
		}
	}
}
//---------------------------------------------------------------------------
// for (初期化文 ; 条件 ; 式 ) { 処理; … } の例
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	int total = 0;
	for ( int counter = 1; counter <= 10; counter ++) {
		total += counter;
		Memo1->Lines->Insert(
			0,
			Format(
				"counter = %d  total = %d",
				ARRAYOFCONST(( counter, total ))
			)
		);
	}
}
//---------------------------------------------------------------------------
// for ( 変数宣言 ; 配列または列挙型 ) の例
// この機能は C++11 の機能のため、
//「従来のBorlandコンパイラ」を無効にした場合だけビルドできる。
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	int total = 0;
	int addvalues[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for ( int counter : addvalues ) {
		total += counter;
		Memo1->Lines->Insert(
			0,
			Format(
				"counter = %d  total = %d",
				ARRAYOFCONST(( counter, total ))
			)
		);
	}

}
//---------------------------------------------------------------------------
// while() { ... } の例
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	Memo1->Lines->Insert(0,L"whileループに入る前");

	int total   = 0;
	int counter = 0;
	while ( counter <= 10 ) {
		total += counter;
		Memo1->Lines->Insert(
			0,
			Format(
				"counter = %d  total = %d",
				ARRAYOFCONST(( counter, total ))
			)
		);
		counter++;
	}
	Memo1->Lines->Insert(0,L"whileループから出た");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	Memo1->Lines->Insert(0,L"whileループに入る前");

	int total   = 0;
	int counter = 0;

	do {
		total += counter;
		Memo1->Lines->Insert(
			0,
			Format(
				"counter = %d  total = %d",
				ARRAYOFCONST(( counter, total ))
			)
		);
		counter++;
	}
	while ( counter <= 10 );

	Memo1->Lines->Insert(0,L"whileループから出た");

}
//---------------------------------------------------------------------------

