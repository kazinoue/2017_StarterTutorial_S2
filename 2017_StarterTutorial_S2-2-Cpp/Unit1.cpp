//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;

// このファイルに含まれるすべての関数で使えるグローバル変数。
UnicodeString globalMessage = L"グローバル変数です";

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::変数宣言に関するテストClick(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	// 変数は宣言と代入を同時に行える。
	int           	myIntVal   = 123456;					  // 整数型
	float         	myFloatVal = 1.2345678;                   // 浮動小数点型
	UnicodeString 	myString   = L"ユニコードの文字列です";   // 文字列型
	bool          	myBool     = true;                        // 論理値

	// ユニバーサル文字や実装依存の文字を使った変数
	int				\u30c7\u30eb\u30d5\u30a1\u30a4 = 2007;
	int             Cビルダー = 2017;

	Memo1->Lines->Add(L"■ユニバーサル文字や実装依存の文字を使った変数の扱い");
	Memo1->Lines->Add( Format("変数名: デルファイ 整数値: %d", ARRAYOFCONST((デルファイ))) );
	Memo1->Lines->Add( Format("変数名: Cビルダー  整数値: %d", ARRAYOFCONST((Cビルダー))) );

	// myIntVal = myString のように数値型に文字型は代入できない。
	myString = IntToStr(myIntVal);

	// この関数内で使えるローカル変数
	UnicodeString localMessage = L"親ブロックで代入した文字列";

	Memo1->Lines->Add(L"■関数開始後の最初の出力");
	Memo1->Lines->Add(localMessage);
	Memo1->Lines->Add("");

	{
		Memo1->Lines->Add(L"■ブロック内の処理１：同名の変数を子ブロックで宣言する。");

		UnicodeString localMessage = L"子ブロック１で宣言した変数に値を代入した。";
		Memo1->Lines->Add(localMessage);
	}

	Memo1->Lines->Add(L"■ブロック１を抜けた後の処理。子ブロック内での操作は親ブロックとは別の変数への操作なので影響されない");
	Memo1->Lines->Add(localMessage);
	Memo1->Lines->Add("");

	{
		Memo1->Lines->Add(L"■ブロック内の処理２　親ブロックの変数を参照、変更する。");
		Memo1->Lines->Add(localMessage);
		localMessage = L"親ブロックで宣言した変数の値を変更した。";
		Memo1->Lines->Add(localMessage);
	}

	Memo1->Lines->Add(L"■ブロック２を抜けた後の処理。子ブロック内での代入は親ブロックの変数に対するものなので、子ブロックの処理の結果のまま。");
	Memo1->Lines->Add(localMessage);


}
//---------------------------------------------------------------------------
void __fastcall TForm1::日付時刻の取り扱いのテストClick(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	// TDateTIme 型の変数を宣言して現在の日時を取得する。
	TDateTime myDateTime = Now();

	// 現在時刻を文字列に変換して表示する。
	ShowMessage( DateTimeToStr(myDateTime) );

}
//---------------------------------------------------------------------------
void __fastcall TForm1::型変換のテストClick(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	double myDouble  = 0;
	int    myInteger = 128;

	// 暗黙の型変換
	myDouble = myInteger;
	Memo1->Lines->Add(Format("整数値: %d", ARRAYOFCONST((myInteger))) );
	Memo1->Lines->Add(Format("整数値を実数型に代入した結果: %f",
		ARRAYOFCONST((myDouble))) );

	{
		// 暗黙の型変換では結果が狂う場合がある
		int    myInteger = 3;
		double myDouble  = myInteger / 2 * 0.2;
		Memo1->Lines->Add(Format("3 / 2 * 0.2 != %f",
			ARRAYOFCONST((myDouble))) );
	}

	{
		// 明示的な型変換を行うことで正しい結果になる
		int    myInteger = 3;
		double myDouble  = static_cast<double>(myInteger) / 2 * 0.2;
		Memo1->Lines->Add(Format("static_cast<double>(3) / 2 * 0.2 == %f",
			ARRAYOFCONST((myDouble))) );
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	Integer intValue = 0;
	UnicodeString strValue = L"12345";

	strValue.ToInt();

    Memo1->Lines->Add( L"文字列を数値に変換する処理の結果はデバッガでトレースしてみてください" );
}
//---------------------------------------------------------------------------
