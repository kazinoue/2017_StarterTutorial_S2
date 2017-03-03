//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE �ŊǗ������R���|�[�l���g
	TMemo *Memo1;
	TToolBar *ToolBar2;
	TLayout *Layout2;
	TButton *������^�̕������Q�Ƃ���;
	TButton *���ݑ���̃e�X�g;
	TButton *������̑���ƘA��;
	TButton *Format�֐��̗��p��;
	TButton *�N���X���g��Ȃ���;
	TButton *�N���X���g����;
	TButton *������ɑ΂��鑀��̗�;
	TButton *�\���̂��g����;
	void __fastcall ������^�̕������Q�Ƃ���Click(TObject *Sender);
	void __fastcall ���ݑ���̃e�X�gClick(TObject *Sender);
	void __fastcall ������̑���ƘA��Click(TObject *Sender);
	void __fastcall Format�֐��̗��p��Click(TObject *Sender);
	void __fastcall �N���X���g��Ȃ���Click(TObject *Sender);
	void __fastcall �N���X���g����Click(TObject *Sender);
	void __fastcall ������ɑ΂��鑀��̗�Click(TObject *Sender);
	void __fastcall �\���̂��g����Click(TObject *Sender);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
