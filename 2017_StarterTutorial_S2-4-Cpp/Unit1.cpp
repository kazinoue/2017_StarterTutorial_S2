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
void __fastcall TForm1::�֐��̋L�q���ƌĂяo��Click(TObject *Sender)
{
	myShowFunction( L"���b�Z�[�W" );
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
void __fastcall TForm1::�l�n���ƎQ�Ɠn��Click(TObject *Sender)
{
	Memo1->Lines->Clear();

	int x, i = 4;

	Memo1->Lines->Add(
		Format(
			L"call_by_value ���s�O: x = %d, i = %d (x �͏���������Ă��Ȃ��̂Œl���s��j",
			ARRAYOFCONST(( x, i ))
		)
	);

	Memo1->Lines->Add( L"\n���s: x = call_by_value( i )" );
	x = call_by_value( i );
	Memo1->Lines->Add(
		Format(
			L"call_by_value ���s��: x = %d, i = %d�ii �͒l�n���Ȃ̂ŕς��Ȃ��Bx �͊֐����s��̖߂�l������j",
			ARRAYOFCONST(( x, i ))
		)
	);

	Memo1->Lines->Add( L"\n���s: call_by_reference( x )" );
	 call_by_reference( x );
	 Memo1->Lines->Add(
		Format(
			L"call_by_reference ���s��: x = %d, i = %d�ii �͎Q�Ɠn���Ȃ̂Œl���ς�����Bx �͕ω��Ȃ��j",
			ARRAYOFCONST(( x, i ))
		)
	 );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::�I�[�o�[���[�h�̗�QClick(TObject *Sender)
{
	Memo1->Lines->Clear();

	overload_example( 1 );
	overload_example( 3.141592 );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::return�Ŕ������Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Application->ProcessMessages();
	Sleep( 250 );

	UnicodeString str = L"Hello C++Builder";
	Memo1->Lines->Add( str + L"�̕�����擪���珇�Ԃɒ��ׂ� B �����������甲�����" );

	for (WCHAR c : str ) {
		if ( c == 'B' ) return; // ���� 'B' ����������֐��𔲂���

		Memo1->Lines->Add( Format(L"%s", ARRAYOFCONST(( c )) ) );
	}

	Memo1->Lines->Add( L"END" ); // return �Ŕ������ꍇ�͂��̏����ɓ��B���Ȃ�
}
//---------------------------------------------------------------------------

int __fastcall DefaultParameter( int numA = 2, int numB = 3 )
{
	int total = numA * numB;
	return total;
}


void __fastcall TForm1::�I�[�o�[���[�h�����̗�Click(TObject *Sender)
{
	Memo1->Lines->Clear();

	/* �ȉ���3�͓������ʂƂȂ� */
	Memo1->Lines->Add( IntToStr(DefaultParameter())       + L" = DefaultParameter()   �̎��s"  );
	Memo1->Lines->Add( IntToStr(DefaultParameter( 2 ))    + L" = DefaultParameter(2)  �̎��s" );
	Memo1->Lines->Add( IntToStr(DefaultParameter( 2, 3 )) + L" = DefaultParameter(2,3)�̎��s" );

}
//---------------------------------------------------------------------------

int __fastcall TForm1::Recursive( int count )
{
	int retval = count - 1;

	if ( retval > 0 ) Recursive( retval );  // �ċA�Ăяo���͎��s���������߂čs��

	Memo1->Lines->Add( L"�ċA�Ăяo��" + IntToStr( retval ) + "���" );
	return retval;
}

void __fastcall TForm1::�ċA�Ăяo���̗�Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Recursive( 3 );
}
//---------------------------------------------------------------------------

