//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;

// ���̃t�@�C���Ɋ܂܂�邷�ׂĂ̊֐��Ŏg����O���[�o���ϐ��B
UnicodeString globalMessage = L"�O���[�o���ϐ��ł�";

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::�ϐ��錾�Ɋւ���e�X�gClick(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	// �ϐ��͐錾�Ƒ���𓯎��ɍs����B
	int           	myIntVal   = 123456;					  // �����^
	float         	myFloatVal = 1.2345678;                   // ���������_�^
	UnicodeString 	myString   = L"���j�R�[�h�̕�����ł�";   // ������^
	bool          	myBool     = true;                        // �_���l

	// ���j�o�[�T������������ˑ��̕������g�����ϐ�
	int				\u30c7\u30eb\u30d5\u30a1\u30a4 = 2007;
	int             C�r���_�[ = 2017;

	Memo1->Lines->Add(L"�����j�o�[�T������������ˑ��̕������g�����ϐ��̈���");
	Memo1->Lines->Add( Format("�ϐ���: �f���t�@�C �����l: %d", ARRAYOFCONST((�f���t�@�C))) );
	Memo1->Lines->Add( Format("�ϐ���: C�r���_�[  �����l: %d", ARRAYOFCONST((C�r���_�[))) );

	// myIntVal = myString �̂悤�ɐ��l�^�ɕ����^�͑���ł��Ȃ��B
	myString = IntToStr(myIntVal);

	// ���̊֐����Ŏg���郍�[�J���ϐ�
	UnicodeString localMessage = L"�e�u���b�N�ő������������";

	Memo1->Lines->Add(L"���֐��J�n��̍ŏ��̏o��");
	Memo1->Lines->Add(localMessage);
	Memo1->Lines->Add("");

	{
		Memo1->Lines->Add(L"���u���b�N���̏����P�F�����̕ϐ����q�u���b�N�Ő錾����B");

		UnicodeString localMessage = L"�q�u���b�N�P�Ő錾�����ϐ��ɒl���������B";
		Memo1->Lines->Add(localMessage);
	}

	Memo1->Lines->Add(L"���u���b�N�P�𔲂�����̏����B�q�u���b�N���ł̑���͐e�u���b�N�Ƃ͕ʂ̕ϐ��ւ̑���Ȃ̂ŉe������Ȃ�");
	Memo1->Lines->Add(localMessage);
	Memo1->Lines->Add("");

	{
		Memo1->Lines->Add(L"���u���b�N���̏����Q�@�e�u���b�N�̕ϐ����Q�ƁA�ύX����B");
		Memo1->Lines->Add(localMessage);
		localMessage = L"�e�u���b�N�Ő錾�����ϐ��̒l��ύX�����B";
		Memo1->Lines->Add(localMessage);
	}

	Memo1->Lines->Add(L"���u���b�N�Q�𔲂�����̏����B�q�u���b�N���ł̑���͐e�u���b�N�̕ϐ��ɑ΂�����̂Ȃ̂ŁA�q�u���b�N�̏����̌��ʂ̂܂܁B");
	Memo1->Lines->Add(localMessage);


}
//---------------------------------------------------------------------------
void __fastcall TForm1::���t�����̎�舵���̃e�X�gClick(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	// TDateTIme �^�̕ϐ���錾���Č��݂̓������擾����B
	TDateTime myDateTime = Now();

	// ���ݎ����𕶎���ɕϊ����ĕ\������B
	ShowMessage( DateTimeToStr(myDateTime) );

}
//---------------------------------------------------------------------------
void __fastcall TForm1::�^�ϊ��̃e�X�gClick(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	double myDouble  = 0;
	int    myInteger = 128;

	// �Öق̌^�ϊ�
	myDouble = myInteger;
	Memo1->Lines->Add(Format("�����l: %d", ARRAYOFCONST((myInteger))) );
	Memo1->Lines->Add(Format("�����l�������^�ɑ����������: %f",
		ARRAYOFCONST((myDouble))) );

	{
		// �Öق̌^�ϊ��ł͌��ʂ������ꍇ������
		int    myInteger = 3;
		double myDouble  = myInteger / 2 * 0.2;
		Memo1->Lines->Add(Format("3 / 2 * 0.2 != %f",
			ARRAYOFCONST((myDouble))) );
	}

	{
		// �����I�Ȍ^�ϊ����s�����ƂŐ��������ʂɂȂ�
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

    Memo1->Lines->Add( L"������𐔒l�ɕϊ����鏈���̌��ʂ̓f�o�b�K�Ńg���[�X���Ă݂Ă�������" );
}
//---------------------------------------------------------------------------
