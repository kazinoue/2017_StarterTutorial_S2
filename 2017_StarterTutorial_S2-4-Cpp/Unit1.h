//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE �ŊǗ������R���|�[�l���g
	TButton *�֐��̋L�q���ƌĂяo��;
	TLayout *Layout1;
	TMemo *Memo1;
	TButton *�l�n���ƎQ�Ɠn��;
	TButton *�I�[�o�[���[�h�̗�Q;
	TButton *return�Ŕ������;
	TButton *�I�[�o�[���[�h�����̗�;
	TButton *�ċA�Ăяo���̗�;
	void __fastcall �֐��̋L�q���ƌĂяo��Click(TObject *Sender);
	void __fastcall �l�n���ƎQ�Ɠn��Click(TObject *Sender);
	void __fastcall overload_example( double n );
	void __fastcall overload_example( int n );
	void __fastcall �I�[�o�[���[�h�̗�QClick(TObject *Sender);
	void __fastcall return�Ŕ������Click(TObject *Sender);
	void __fastcall �I�[�o�[���[�h�����̗�Click(TObject *Sender);
	void __fastcall �ċA�Ăяo���̗�Click(TObject *Sender);
    int __fastcall  Recursive( int count );


private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
