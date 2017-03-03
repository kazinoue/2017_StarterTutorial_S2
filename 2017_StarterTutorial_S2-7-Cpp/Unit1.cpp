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
void __fastcall TForm1::���N���X�̑���Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Memo1->Lines->Add(L"���N���X�̑���");

	TCar *MyCar      = new TCar( L"Nissan", L"GT-R", 565, L"Silver" );
	MyCar->AccelOn();

//  Manufacture �� protected �Ȃ̂ŃN���X�̊O����͎Q�Ƃł��Ȃ�
//	Memo1->Lines->Add( MyCar->Manufacture );

//  TCar �ɂȂ����\�b�h�͌ĂׂȂ�
//	MyCar->SirenRinging();

	delete MyCar;

	Memo1->Lines->Add("");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::�I�[�o�[���C�h����Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Memo1->Lines->Add(L"THybridCar = new THyblidCar() �𑀍삷��ꍇ");
	{
		THyblidCar *HyblidCar = new THyblidCar();
		HyblidCar->AccelOn();
		HyblidCar->BreakOn();
		delete HyblidCar;
	}

	Memo1->Lines->Add("");
	Memo1->Lines->Add(L"TCar = new THyblidCar() �𑀍삷��ꍇ");
	{
		TCar *HyblidCar = new THyblidCar();

		// AccelOn() �� TCar �� virtual �錾����Ă���̂ŃI�[�o�[���C�h�ł���
		HyblidCar->AccelOn();

		// BreakOn() �� virtual �錾����Ă��Ȃ��̂ŃI�[�o�[���C�h�ł����A���N���X�̃��\�b�h�����s�����
		HyblidCar->BreakOn();

		delete HyblidCar;
	}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::�p��Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Memo1->Lines->Add(L"�N���X�̌p���i�R���X�g���N�^�A�f�X�g���N�^�̌Ă΂���j");

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

void __fastcall TForm1::struct�̗�Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Memo1->Lines->Add(L"struct{}�̗�");

	TStructCar *MyCar      = new TStructCar( L"Nissan", L"GT-R", 565, L"Silver" );
	MyCar->AccelOn();

//  struct �̃����o�͖����I�� protected , private �錾���Ȃ�����͂��ׂĎQ�Ƃł���
	Memo1->Lines->Add( MyCar->Manufacture );

	delete MyCar;

	Memo1->Lines->Add("");

}
//---------------------------------------------------------------------------

