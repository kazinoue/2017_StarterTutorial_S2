//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
#include "uTCar.h"
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
void __fastcall TForm1::基底クラスの操作Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Memo1->Lines->Add(L"基底クラスの操作");

	TCar *MyCar      = new TCar( L"Nissan", L"GT-R", 565, L"Silver" );
	MyCar->AccelOn();

//  Manufacture は protected なのでクラスの外からは参照できない
//	Memo1->Lines->Add( MyCar->Manufacture );

//  TCar にないメソッドは呼べない
//	MyCar->SirenRinging();

	delete MyCar;

	Memo1->Lines->Add("");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::オーバーライド処理Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Memo1->Lines->Add(L"THybridCar = new THyblidCar() を操作する場合");
	{
		THyblidCar *HyblidCar = new THyblidCar();
		HyblidCar->AccelOn();
		HyblidCar->BreakOn();
		delete HyblidCar;
	}

	Memo1->Lines->Add("");
	Memo1->Lines->Add(L"TCar = new THyblidCar() を操作する場合");
	{
		TCar *HyblidCar = new THyblidCar();

		// AccelOn() は TCar で virtual 宣言されているのでオーバーライドできる
		HyblidCar->AccelOn();

		// BreakOn() は virtual 宣言されていないのでオーバーライドできず、基底クラスのメソッドが実行される
		HyblidCar->BreakOn();

		delete HyblidCar;
	}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::継承Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Memo1->Lines->Add(L"クラスの継承（コンストラクタ、デストラクタの呼ばれ方）");

	TPoliceCar *PoliceCar = new TPoliceCar( L"Nissan", L"GT-R", 565 );
	PoliceCar->AccelOn();
	PoliceCar->RedLightOn();
	PoliceCar->SirenOn();
	PoliceCar->SirenOff();
	PoliceCar->RedLightOff();
	delete PoliceCar;

	Memo1->Lines->Add("");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::structの例Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Memo1->Lines->Add(L"struct{}の例");

	TStructCar *MyCar      = new TStructCar( L"Nissan", L"GT-R", 565, L"Silver" );
	MyCar->AccelOn();

//  struct のメンバは明示的に protected , private 宣言しない限りはすべて参照できる
	Memo1->Lines->Add( MyCar->Manufacture );

	delete MyCar;

	Memo1->Lines->Add("");

}
//---------------------------------------------------------------------------

