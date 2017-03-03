//---------------------------------------------------------------------------

#pragma hdrstop

#include "uTCar.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// TCar �C���X�^���X�̃R���X�g���N�^
TCar::TCar()
{
	Form1->Memo1->Lines->Add(L"[TCar::�R���X�g���N�^()]");
	Manufacture = "";
	SeriesName  = "";
	HorsePower  = 0;
	Color       = "";
}

TCar::TCar( String manufacture, String seriesname, int horsepower, String color )
	:Manufacture(manufacture), SeriesName(seriesname), HorsePower(horsepower), Color(color)
{
	Form1->Memo1->Lines->Add(
		Format(L"[TCar::�R���X�g���N�^( %s, %s, %d, %s )]",
			ARRAYOFCONST(( manufacture, seriesname, horsepower, color )))
		);
}

// TCar �C���X�^���X�̃f�X�g���N�^
TCar::~TCar()
{
	Form1->Memo1->Lines->Add(L"[TCar::�f�X�g���N�^]");
}

void TCar::AccelOn()
{
	Form1->Memo1->Lines->Add(L"[TCar::�A�N�Z���I��]");
}

void TCar::BreakOn()
{
	Form1->Memo1->Lines->Add(L"[TCar::�u���[�L����]");
}

//---------------------------------------------------------------------------
// TPoliceCar �̃R���X�g���N�^
TPoliceCar::TPoliceCar()
{
	Color = L"BlackWhite";
	Form1->Memo1->Lines->Add(L"  [TPolceCar::�R���X�g���N�^()]");
}

// TPoliceCar �̃f�X�g���N�^
TPoliceCar::~TPoliceCar() {
	Form1->Memo1->Lines->Add(L"  [TPolceCar::�f�X�g���N�^]");}
// TPoliceCar �̃R���X�g���N�^
TPoliceCar::TPoliceCar( String manufacture, String seriesname, int horsepower )
{
	Manufacture = manufacture;
	SeriesName  = seriesname;
	HorsePower  = horsepower;
	Color       = L"BlackWhite";

	Form1->Memo1->Lines->Add(
		Format(L"  [TPoliceCar::�R���X�g���N�^( %s, %s, %d )]",
			ARRAYOFCONST(( Manufacture, SeriesName, HorsePower )))
		);
	Form1->Memo1->Lines->Add(
		Format(L"  [TPoliceCar::�R���X�g���N�^( Color = %s )]",
			ARRAYOFCONST(( Color )))
		);
}

// �T�C������ on / off
void TPoliceCar::SirenOn()
{
	Form1->Memo1->Lines->Add(L"  [TPolceCar::�T�C������炷]");
}
void TPoliceCar::SirenOff()
{
	Form1->Memo1->Lines->Add(L"  [TPolceCar::�T�C����������]");
}

// �ԐF���� on / off
void TPoliceCar::RedLightOn()
{
	Form1->Memo1->Lines->Add(L"  [TPolceCar::�ԐF��������]");
}
void TPoliceCar::RedLightOff()
{
	Form1->Memo1->Lines->Add(L"  [TPolceCar::�ԐF��������]");
}

//---------------------------------------------------------------------------
void THyblidCar::AccelOn()
{
	Form1->Memo1->Lines->Add(L"  [THyblidCar::�n�C�u���b�h�����̃G���W���E���[�^�[����]");
}

void THyblidCar::BreakOn()
{
	Form1->Memo1->Lines->Add(L"  [THyblidCar::�u���[�L����]");
}


//---------------------------------------------------------------------------
// TStructCar �C���X�^���X�̃R���X�g���N�^
TStructCar::TStructCar()
{
	Form1->Memo1->Lines->Add(L"[TStructCar::�R���X�g���N�^()]");
	Manufacture = "";
	SeriesName  = "";
	HorsePower  = 0;
	Color       = "";
}

TStructCar::TStructCar( String manufacture, String seriesname, int horsepower, String color )
	:Manufacture(manufacture), SeriesName(seriesname), HorsePower(horsepower), Color(color)
{
	Form1->Memo1->Lines->Add(
		Format(L"[TStructCar::�R���X�g���N�^( %s, %s, %d, %s )]",
			ARRAYOFCONST(( manufacture, seriesname, horsepower, color )))
		);
}

// TStructCar �C���X�^���X�̃f�X�g���N�^
TStructCar::~TStructCar()
{
	Form1->Memo1->Lines->Add(L"[TStructCar::�f�X�g���N�^]");
}

void TStructCar::AccelOn()
{
	Form1->Memo1->Lines->Add(L"[TStructCar::�A�N�Z���I��]");
}

