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
void __fastcall TForm1::DynamicArrayで指定値までの素数を探すClick(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(500);

	// 指定された値までの素数を「エラトステネスのふるい」で探す

	// 素数を探す範囲をフォームから受け取る
	int calcRange = StrToInt(Edit1->Text);

	// 動的配列を確保する
	DynamicArray<bool> primeNumber;
	primeNumber.Length = calcRange;

	// 配列の値を true で初期化
	for (int i = primeNumber.Low; i <= primeNumber.High; i++)
		primeNumber[i] = true;

	// 1 は除外して探す
	for (int i = 2; i <= primeNumber.High ; i++) {
		if ( primeNumber[i] == true ) {
			// 見つかった素数を表示する
			Memo1->Lines->Insert(0, IntToStr(i) );

			// 素数の倍数は素数ではないので調査範囲から外すために false にする
			for (int j = 0; i * j < calcRange ; j++)
				primeNumber[ i * j ] = false;
		}
	}

	// 使い終わったので解放しておく
	primeNumber.Length = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StaticArrayで100までの素数を探すClick(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(500);
	// 指定された値までの素数を「エラトステネスのふるい」で探す

	// 動的配列を確保する
	const int calcRange = 1000;
	StaticArray<bool, calcRange> primeNumber;

	// 配列の値を true で初期化
	for (int i = 0; i < calcRange; i++)
		primeNumber[i] = true;

	// 1 は除外して探す
	for (int i = 2; i < calcRange ; i++) {
		if ( primeNumber[i] == true ) {
			// 見つかった素数を表示する
			Memo1->Lines->Insert(0, IntToStr(i) );

			// 素数の倍数は素数ではないので調査範囲から外すために false にする
			for (int j = 0; i * j < calcRange ; j++)
				primeNumber[ i * j ] = false;
		}
	}
	// 静的配列は解放しなくてよい
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Cスタイルの配列で指定値までの素数を探すClick(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(500);
	// 指定された値までの素数を「エラトステネスのふるい」で探す

	// 素数を探す範囲をフォームから受け取る
	int calcRange = StrToInt(Edit1->Text);

	// 動的配列を確保する
	bool *primeNumber;
	primeNumber = new bool[calcRange];

	// 配列の値を true で初期化
	for (int i = 0 ; i < calcRange ; i++)
		primeNumber[i] = true;

	// 1 は除外して探す
	for (int i = 2; i < calcRange ; i++) {
		if ( primeNumber[i] == true ) {
			// 見つかった素数を表示する
			Memo1->Lines->Insert(0, IntToStr(i) );

			// 素数の倍数は素数ではないので調査範囲から外すために false にする
			for (int j = 0; i * j < calcRange ; j++)
				primeNumber[ i * j ] = false;
		}
	}

	// 使い終わったので解放しておく
	delete[] primeNumber;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Cスタイルの配列で100までの素数を探すClick(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(500);
	// 指定された値までの素数を「エラトステネスのふるい」で探す

	// 静的配列を確保する
	const int calcRange = 1000;
	bool primeNumber[calcRange];

	// 配列の値を true で初期化
	for (int i = 0 ; i < calcRange ; i++)
		primeNumber[i] = true;

	// 1 は除外して探す
	for (int i = 2; i < calcRange ; i++) {
		if ( primeNumber[i] == true ) {
			// 見つかった素数を表示する
			Memo1->Lines->Insert(0, IntToStr(i) );

			// 素数の倍数は素数ではないので調査範囲から外すために false にする
			for (int j = 0; i * j < calcRange ; j++)
				primeNumber[ i * j ] = false;
		}
	}

	// 静的配列は解放しなくてよい
}

// 構造体 zioCode の型を定義
struct SZipCode{
	String Pref;
	String City;
	String Area;
};

//---------------------------------------------------------------------------
void __fastcall TForm1::構造体を使う例Click(TObject *Sender)
{
	Memo1->Lines->Clear();

	// 変数の作成
	SZipCode *zipCode;
	zipCode = new SZipCode[9999999];

	// 値の代入１
	zipCode[1120004].Pref=L"東京都";
	zipCode[1120004].City=L"文京区";
	zipCode[1120004].Area=L"後楽";

	// 値の代入２
	zipCode[1120004] = { L"東京都", L"文京区", L"後楽" };

	// 値の参照
	Memo1->Lines->Insert(0, "都道府県："   + zipCode[1120004].Pref );
	Memo1->Lines->Insert(0, "市区町村名：" + zipCode[1120004].City ) ;
	Memo1->Lines->Insert(0, "町域名："     + zipCode[1120004].Area );

	// 後始末
	delete[] zipCode;
}
//---------------------------------------------------------------------------
