//---------------------------------------------------------------------------

#pragma hdrstop

#include "uTCar.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// TCar インスタンスのコンストラクタ
TCar::TCar()
{
	Form1->Memo1->Lines->Add(L"[TCar::コンストラクタ()]");
	Manufacture = "";
	SeriesName  = "";
	HorsePower  = 0;
	Color       = "";
}

TCar::TCar( String manufacture, String seriesname, int horsepower, String color )
	:Manufacture(manufacture), SeriesName(seriesname), HorsePower(horsepower), Color(color)
{
	Form1->Memo1->Lines->Add(
		Format(L"[TCar::コンストラクタ( %s, %s, %d, %s )]",
			ARRAYOFCONST(( manufacture, seriesname, horsepower, color )))
		);
}

// TCar インスタンスのデストラクタ
TCar::~TCar()
{
	Form1->Memo1->Lines->Add(L"[TCar::デストラクタ]");
}

void TCar::AccelOn()
{
	Form1->Memo1->Lines->Add(L"[TCar::アクセルオン]");
}

void TCar::BreakOn()
{
	Form1->Memo1->Lines->Add(L"[TCar::ブレーキ操作]");
}

//---------------------------------------------------------------------------
// TPoliceCar のコンストラクタ
TPoliceCar::TPoliceCar()
{
	Color = L"BlackWhite";
	Form1->Memo1->Lines->Add(L"  [TPolceCar::コンストラクタ()]");
}

// TPoliceCar のデストラクタ
TPoliceCar::~TPoliceCar() {
	Form1->Memo1->Lines->Add(L"  [TPolceCar::デストラクタ]");}
// TPoliceCar のコンストラクタ
TPoliceCar::TPoliceCar( String manufacture, String seriesname, int horsepower )
{
	Manufacture = manufacture;
	SeriesName  = seriesname;
	HorsePower  = horsepower;
	Color       = L"BlackWhite";

	Form1->Memo1->Lines->Add(
		Format(L"  [TPoliceCar::コンストラクタ( %s, %s, %d )]",
			ARRAYOFCONST(( Manufacture, SeriesName, HorsePower )))
		);
	Form1->Memo1->Lines->Add(
		Format(L"  [TPoliceCar::コンストラクタ( Color = %s )]",
			ARRAYOFCONST(( Color )))
		);
}

// サイレンの on / off
void TPoliceCar::SirenOn()
{
	Form1->Memo1->Lines->Add(L"  [TPolceCar::サイレンを鳴らす]");
}
void TPoliceCar::SirenOff()
{
	Form1->Memo1->Lines->Add(L"  [TPolceCar::サイレンを消す]");
}

// 赤色灯の on / off
void TPoliceCar::RedLightOn()
{
	Form1->Memo1->Lines->Add(L"  [TPolceCar::赤色灯をつける]");
}
void TPoliceCar::RedLightOff()
{
	Form1->Memo1->Lines->Add(L"  [TPolceCar::赤色灯を消す]");
}

//---------------------------------------------------------------------------
void THyblidCar::AccelOn()
{
	Form1->Memo1->Lines->Add(L"  [THyblidCar::ハイブリッド向けのエンジン・モーター操作]");
}

void THyblidCar::BreakOn()
{
	Form1->Memo1->Lines->Add(L"  [THyblidCar::ブレーキ操作]");
}


//---------------------------------------------------------------------------
// TStructCar インスタンスのコンストラクタ
TStructCar::TStructCar()
{
	Form1->Memo1->Lines->Add(L"[TStructCar::コンストラクタ()]");
	Manufacture = "";
	SeriesName  = "";
	HorsePower  = 0;
	Color       = "";
}

TStructCar::TStructCar( String manufacture, String seriesname, int horsepower, String color )
	:Manufacture(manufacture), SeriesName(seriesname), HorsePower(horsepower), Color(color)
{
	Form1->Memo1->Lines->Add(
		Format(L"[TStructCar::コンストラクタ( %s, %s, %d, %s )]",
			ARRAYOFCONST(( manufacture, seriesname, horsepower, color )))
		);
}

// TStructCar インスタンスのデストラクタ
TStructCar::~TStructCar()
{
	Form1->Memo1->Lines->Add(L"[TStructCar::デストラクタ]");
}

void TStructCar::AccelOn()
{
	Form1->Memo1->Lines->Add(L"[TStructCar::アクセルオン]");
}

