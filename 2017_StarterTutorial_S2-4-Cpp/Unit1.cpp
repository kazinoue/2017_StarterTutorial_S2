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

void __fastcall myShowFunction(UnicodeString message)
{
	ShowMessage( message );
}

void __fastcall Hello()
{
	ShowMessage( L"Hello C++Builder World" );
}

double ParamTest(int iNum)
{
	return iNum * 2;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::関数の記述順と呼び出しClick(TObject *Sender)
{
	myShowFunction( L"メッセージ" );
	Hello();

	myShowFunction(
		Format(
			"%f",
			ARRAYOFCONST(( static_cast<const long double>(ParamTest(8-1)) ))
		)
	);

	myShowFunction(
		Format(
			"%f",
			ARRAYOFCONST(( static_cast<const long double>(ParamTest(10.2)) ))
		)
	);
}

int call_by_value( int n )
{
	int retval = 3 * n;

	n = 0;
	return retval;
}

void call_by_reference( int &n )
{
	n = n * 3;
}

void __fastcall TForm1::overload_example( int n )
{
	Memo1->Lines->Add(
		Format(
			L"overload_example( int ) = %d",
			ARRAYOFCONST(( n ))
		)
	);
}

void __fastcall TForm1::overload_example( double n )
{
	Memo1->Lines->Add(
		Format(
			L"overload_example( double ) = %.16f",
			ARRAYOFCONST(( static_cast<const long double>(n) ))
		)
	);
}


//---------------------------------------------------------------------------
void __fastcall TForm1::値渡しと参照渡しClick(TObject *Sender)
{
	Memo1->Lines->Clear();

	int x, i = 4;

	Memo1->Lines->Add(
		Format(
			L"call_by_value 実行前: x = %d, i = %d (x は初期化されていないので値が不定）",
			ARRAYOFCONST(( x, i ))
		)
	);

	Memo1->Lines->Add( L"\n実行: x = call_by_value( i )" );
	x = call_by_value( i );
	Memo1->Lines->Add(
		Format(
			L"call_by_value 実行後: x = %d, i = %d（i は値渡しなので変わらない。x は関数実行後の戻り値が入る）",
			ARRAYOFCONST(( x, i ))
		)
	);

	Memo1->Lines->Add( L"\n実行: call_by_reference( x )" );
	 call_by_reference( x );
	 Memo1->Lines->Add(
		Format(
			L"call_by_reference 実行後: x = %d, i = %d（i は参照渡しなので値が変わった。x は変化なし）",
			ARRAYOFCONST(( x, i ))
		)
	 );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::オーバーロードの例２Click(TObject *Sender)
{
	Memo1->Lines->Clear();

	overload_example( 1 );
	overload_example( 3.141592 );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::returnで抜ける例Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep( 250 );

	UnicodeString str = L"Hello C++Builder";
	Memo1->Lines->Add( str + L"の文字を先頭から順番に調べて B が見つかったら抜ける例" );

	for (WCHAR c : str ) {
		if ( c == 'B' ) return; // 文字 'B' を見つけたら関数を抜ける

		Memo1->Lines->Add( Format(L"%s", ARRAYOFCONST(( c )) ) );
	}

	Memo1->Lines->Add( L"END" ); // return で抜けた場合はこの処理に到達しない
}
//---------------------------------------------------------------------------

int __fastcall DefaultParameter( int numA = 2, int numB = 3 )
{
	int total = numA * numB;
	return total;
}


void __fastcall TForm1::オーバーロード処理の例Click(TObject *Sender)
{
	Memo1->Lines->Clear();

	/* 以下の3つは同じ結果となる */
	Memo1->Lines->Add( IntToStr(DefaultParameter())       + L" = DefaultParameter()   の実行"  );
	Memo1->Lines->Add( IntToStr(DefaultParameter( 2 ))    + L" = DefaultParameter(2)  の実行" );
	Memo1->Lines->Add( IntToStr(DefaultParameter( 2, 3 )) + L" = DefaultParameter(2,3)の実行" );

}
//---------------------------------------------------------------------------

int __fastcall TForm1::Recursive( int count )
{
	int retval = count - 1;

	if ( retval > 0 ) Recursive( retval );  // 再帰呼び出しは実行条件を決めて行う

	Memo1->Lines->Add( L"再帰呼び出し" + IntToStr( retval ) + "回目" );
	return retval;
}

void __fastcall TForm1::再帰呼び出しの例Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Recursive( 3 );
}
//---------------------------------------------------------------------------

