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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE �ŊǗ������R���|�[�l���g
	TToolBar *ToolBar1;
	TButton *���N���X�̑���;
	TMemo *Memo1;
	TButton *�I�[�o�[���C�h����;
	TButton *�p��;
	TButton *struct�̗�;
	void __fastcall ���N���X�̑���Click(TObject *Sender);
	void __fastcall �I�[�o�[���C�h����Click(TObject *Sender);
	void __fastcall �p��Click(TObject *Sender);
	void __fastcall struct�̗�Click(TObject *Sender);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

