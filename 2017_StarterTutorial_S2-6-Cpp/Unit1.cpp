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
void __fastcall TForm1::文字列型の文字を参照するClick(TObject *Sender)
{
	Memo1->Lines->Clear();

	String strUTF16 = u"Hello C++Builder";

	// 文字列の各文字を配列として参照する
	for ( int i = 1 ; i <= strUTF16.Length() ; i++ )
		Memo1->Lines->Add( Format( "i=%d: %s", ARRAYOFCONST(( i, strUTF16[i] )) ) );

	// 文字列の各文字を部分文字列として抜き出す
//	for ( int i = 1 ; i <= strUTF16.Length() ; i++ )
//		Memo1->Lines->Add( strUTF16.SubString(i,1) );

	// ポインタとキャストを使って抜き出す例
//	for ( int i = 0 ; i < strUTF16.Length() ; i++ )
//		Memo1->Lines->Add(
//			static_cast<WideChar>( *(strUTF16.FirstChar() + i) )
//		);

	// Clang (C++11) で範囲ベースの for ループで文字列を１文字づつ処理する例
	// コンパイルオプションで「従来のコンパイラを使用」を無効化した場合に利用できる
	// 変数を auto 宣言すると必要な型がコンパイル時に自動的に決まる
//	for ( auto character: strUTF16 ) Memo1->Lines->Add( character );
}

//---------------------------------------------------------------------------
void __fastcall TForm1::相互代入のテストClick(TObject *Sender)
{
	Memo1->Lines->Clear();

	AnsiString strSJIS;
	UTF8String strUTF8;
	String 	 strUTF16;

	strSJIS  = L"日本語";
	strUTF8  = L"日本語";
	strUTF16 = L"日本語";

	strSJIS  = L"⌘";
	strUTF8  = L"⌘";
	strUTF16 = L"⌘";

	strSJIS  = L"𠮷野屋";
	strUTF8  = L"𠮷野屋";
	strUTF16 = L"𠮷野屋";

	strSJIS  = L"日本語";  	// OK: L"日本語" は Shift_JISで表せる文字である
	strUTF8  = static_cast<UTF8String>(strSJIS);     // OK: UnicodeにはすべてのShift_JISが含まれる
	strUTF8  = static_cast<UTF8String>(strSJIS);     // OK: UnicodeにはすべてのShift_JISが含まれる
	strUTF16 = strSJIS;     // OK: UnicodeにはすべてのShift_JISが含まれる
	Memo1->Lines->Add( L"SJIS : " + strSJIS  );
	Memo1->Lines->Add( L"UTF8 : " + strUTF8  );
	Memo1->Lines->Add( u"UTF16: " + strUTF16 );
	Memo1->Lines->Add( "" );

	strUTF16 = L"⌘";     	// OK: Unicodeを扱う型にUnicode文字を代入している
	strUTF8  = static_cast<UTF8String>(strUTF16);    // OK: Unicode同士なので常に成功するが、データ形式の変換が生じる
	Memo1->Lines->Add( L"UTF8 : " + strUTF8  );
	Memo1->Lines->Add( u"UTF16: " + strUTF16 );
	Memo1->Lines->Add( "" );

	strSJIS  = L"𠮷野屋";	// NG: 「𠮷 = つちよし」はShift_JISに存在しない文字なので失われる
	Memo1->Lines->Add( L"SJIS : " + strSJIS  );
	strSJIS  = strUTF8;     // NG: strUTF8 = "⌘" のため、Shift_JIS に代入すると失われる
	Memo1->Lines->Add( L"SJIS : " + strSJIS  );
}
//---------------------------------------------------------------------------
void __fastcall TForm1::文字列の代入と連結Click(TObject *Sender)
{
	Memo1->Lines->Clear();

	String str1 = L"Hello";
	String str2 = L"C++Builder";

	Memo1->Lines->Add( "str1 = " + str1 );
	Memo1->Lines->Add( "str2 = " + str2 );

	str1 = str1 + L" " + str2;
	Memo1->Lines->Add( u"str1 + str2 = " + str1 ); // "Hello C++Builder" と表示される
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Format関数の利用例Click(TObject *Sender)
{
	Memo1->Lines->Clear();

	String strWeather, strOutput;
	int iTemparture;

	strWeather = L"雨";
	iTemparture = 20;

	//Formatはこんな感じで使えます
	strOutput = Format(
		L"明日の天気は %s 、気温は %d 度になるでしょう",
		ARRAYOFCONST(( strWeather, iTemparture ))
	);

	Memo1->Lines->Add( strOutput );
}


// クラスを使わない例
struct SZipCode {
	int ZipCode;
	String Pref;
	String City;
	String Area;
};

// 関数宣言部
String getFullAddress( SZipCode zipCode );

// 都道府県名 + 市区町村名 + 町域名を連結して返す処理
String getFullAddress( SZipCode zipCode ) {
	return zipCode.Pref + " " + zipCode.City + " " + zipCode.Area;
}

void __fastcall TForm1::クラスを使わない例Click(TObject *Sender)
{
	Memo1->Lines->Clear();

	// 構造体の変数を作り、初期化する
	SZipCode zipdata = { 1120004, L"東京都", L"文京区", L"後楽" };

	// 関数名だけでは TZipCode との関連付けが分かりづらい
	Memo1->Lines->Add( getFullAddress( zipdata ) );
}
//---------------------------------------------------------------------------


// クラスの例
class TZipCode {
public: // メンバ変数。public宣言でクラス外から操作可能
	int ZipCode;
	String Pref;
	String City;
	String Area;
	// クラスに紐づく関数（メンバ関数）の宣言
	String getFullAddress();
};

// 都道府県名 + 市区町村名 + 町域名を連結して返す処理
String TZipCode::getFullAddress() {
	return Pref + " " + City + " " + Area;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::クラスを使う例Click(TObject *Sender)
{
	Memo1->Lines->Clear();

	// クラスの実体（オブジェクト）を作り、メンバを初期化する
	TZipCode zipdata = { 1120004, L"東京都", L"文京区", L"後楽" };

	// メンバ関数の実行はオブジェクトに対する操作である
	Memo1->Lines->Add( zipdata.getFullAddress() );

}
//---------------------------------------------------------------------------


void __fastcall TForm1::文字列に対する操作の例Click(TObject *Sender)
{
	Memo1->Lines->Clear();

	String str = L"  [Delphi/C+Builder]  ";
	Memo1->Lines->Add( str.UpperCase() + IntToStr(str.UpperCase().Length()) );
	Memo1->Lines->Add( str.LowerCase() + IntToStr(str.LowerCase().Length()) );
	Memo1->Lines->Add( str.Trim()      + IntToStr(str.Trim().Length())      );
	Memo1->Lines->Add( str.TrimLeft()  + IntToStr(str.TrimLeft().Length())  );
	Memo1->Lines->Add( str.TrimRight() + IntToStr(str.TrimRight().Length()) );
}
//---------------------------------------------------------------------------





class TZipCode2 {
private: // クラス内だけで使う変数や関数の宣言。変数は特に理由がある場合を除いて private 宣言する。
	int ZipCode;
	String Pref;
	String City;
	String Area;
public:  // クラス外から利用できる変数や関数の宣言。外部との相互の受け渡しが必要な変数のみ public 宣言する。
	String getFullAddress();

	// 特別な意味を持つメンバ関数の宣言
	TZipCode2( int ZipcCode, String Prev, String City, String Area );    // クラスと同名の関数は、オブジェクトの生成時に実行（コンストラクタ）
	~TZipCode2();                            // クラス名に  ~ が付く関数はオブジェクト破棄で実行（デストラクタ）
};

TZipCode2::TZipCode2( int Z, String P, String C, String A ) {
	// オブジェクト生成時の初期化処理を書く
	ZipCode = Z; Pref = P; City = C; Area = A;
}

TZipCode2::~TZipCode2() {
	// 破棄時の終了処理を書く。クラスの操作に伴って動的生成したオブジェクトは、ここで確実に捨てる
}

String TZipCode2::getFullAddress() {
	return Pref + " " + City + " " + Area;
}


void __fastcall TForm1::構造体を使う例Click(TObject *Sender)
{
	Memo1->Lines->Clear();

	// 構造体の変数を作り、初期化する
	TZipCode2 *zipdata = new TZipCode2( 1120004, L"東京都", L"文京区", L"後楽" );

	// 関数名だけでは TZipCode との関連付けが分かりづらい
	Memo1->Lines->Add( zipdata->getFullAddress() );

	delete zipdata;


	TZipCode2 zipdata2( 1120004, L"東京都", L"文京区", L"後楽" );

	// 関数名だけでは TZipCode との関連付けが分かりづらい
	Memo1->Lines->Add( zipdata2.getFullAddress() );
}
//---------------------------------------------------------------------------

