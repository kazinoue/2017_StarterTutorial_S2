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
#include <FMX.Types.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE �ŊǗ������R���|�[�l���g
	TMemo *Memo1;
	TButton *�ϐ��錾�Ɋւ���e�X�g;
	TButton *���t�����̎�舵���̃e�X�g;
	TButton *�^�ϊ��̃e�X�g;
	TButton *Button1;
	void __fastcall �ϐ��錾�Ɋւ���e�X�gClick(TObject *Sender);
	void __fastcall ���t�����̎�舵���̃e�X�gClick(TObject *Sender);
	void __fastcall �^�ϊ��̃e�X�gClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
