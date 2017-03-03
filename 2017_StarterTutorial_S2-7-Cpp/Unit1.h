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
__published:	// IDE で管理されるコンポーネント
	TToolBar *ToolBar1;
	TButton *基底クラスの操作;
	TMemo *Memo1;
	TButton *オーバーライド処理;
	TButton *継承;
	TButton *structの例;
	void __fastcall 基底クラスの操作Click(TObject *Sender);
	void __fastcall オーバーライド処理Click(TObject *Sender);
	void __fastcall 継承Click(TObject *Sender);
	void __fastcall structの例Click(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

