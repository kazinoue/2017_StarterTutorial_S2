//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE �ŊǗ������R���|�[�l���g
	TEdit *Edit1;
	TButton *DynamicArray�Ŏw��l�܂ł̑f����T��;
	TMemo *Memo1;
	TToolBar *ToolBar1;
	TButton *StaticArray��100�܂ł̑f����T��;
	TButton *C�X�^�C���̔z��Ŏw��l�܂ł̑f����T��;
	TButton *C�X�^�C���̔z���100�܂ł̑f����T��;
	TButton *�\���̂��g����;
	void __fastcall DynamicArray�Ŏw��l�܂ł̑f����T��Click(TObject *Sender);
	void __fastcall StaticArray��100�܂ł̑f����T��Click(TObject *Sender);
	void __fastcall C�X�^�C���̔z��Ŏw��l�܂ł̑f����T��Click(TObject *Sender);
	void __fastcall C�X�^�C���̔z���100�܂ł̑f����T��Click(TObject *Sender);
	void __fastcall �\���̂��g����Click(TObject *Sender);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
