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
// ����̂Ȃ��P���ȕ��̗�
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int iA = 1;
	int iB = 0;

	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	/* �R�����g�ł���[ */

	iB = iA + 2;
	Memo1->Lines->Insert(0, Format( "%d + 2 = %d", ARRAYOFCONST(( iA, iB )) ) );
}
//---------------------------------------------------------------------------
// if ���ɂ�镪��̗�
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	if (Switch1->IsChecked == True) {
		// if���� true / �^�̎��Ɏ��s����鏈��
		Memo1->Lines->Insert(0, L"Switch1 �� on �ł��B" );
	}

	if (Switch1->IsChecked == True) {
		// if���� true / �^�̎��Ɏ��s����鏈��
		Memo1->Lines->Insert(0, L"Switch1 �� on �ł��B" );
	}
	else {
		// if���� false / �U�̎��Ɏ��s����鏈��
		Memo1->Lines->Insert(0, L"Switch1 �� off �ł��B" );
	}
}
//---------------------------------------------------------------------------
// switch ... case �̗�
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	if (ListBox1->Selected == nullptr ) {
		Memo1->Lines->Insert( 0, L"���X�g�{�b�N�X�͖��I���ł��B" );
	}
	else
	{
		int a = StrToInt(ListBox1->Selected->Text);

		switch(a) {

			case 1:
			//�����P
			Memo1->Lines->Insert( 0, L"���X�g�{�b�N�X�̒l�� 1 �ł��B" );
			break;

			case 2:
			//����2
			Memo1->Lines->Insert( 0, L"���X�g�{�b�N�X�̒l�� 2 �ł��B" );
			break;

			case 3:
			//����3
			Memo1->Lines->Insert( 0, L"���X�g�{�b�N�X�̒l�� 3 �ł��B" );
			break;

			//�f�t�H���g�̏���
			default:
			Memo1->Lines->Insert( 0, L"���X�g�{�b�N�X�� 1 - 3 �ȊO���I�΂�Ă��܂��B" );
			break;
		}

		if (a == 1) {
			//�����P
		}
		else if ( a == 2 ) {
			//����2
		}
		else if ( a == 3 ) {
			//����3
		}
		else {
			// �f�t�H���g�̏���
		}
	}
}
//---------------------------------------------------------------------------
// for (�������� ; ���� ; �� ) { ����; �c } �̗�
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
// for ( �ϐ��錾 ; �z��܂��͗񋓌^ ) �̗�
// ���̋@�\�� C++11 �̋@�\�̂��߁A
//�u�]����Borland�R���p�C���v�𖳌��ɂ����ꍇ�����r���h�ł���B
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
// while() { ... } �̗�
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	Memo1->Lines->Insert(0,L"while���[�v�ɓ���O");

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
	Memo1->Lines->Insert(0,L"while���[�v����o��");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep(100);

	Memo1->Lines->Insert(0,L"while���[�v�ɓ���O");

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

	Memo1->Lines->Insert(0,L"while���[�v����o��");

}
//---------------------------------------------------------------------------

