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
__published:	// IDE で管理されるコンポーネント
	TMemo *Memo1;
	TToolBar *ToolBar2;
	TLayout *Layout2;
	TButton *文字列型の文字を参照する;
	TButton *相互代入のテスト;
	TButton *文字列の代入と連結;
	TButton *Format関数の利用例;
	TButton *クラスを使わない例;
	TButton *クラスを使う例;
	TButton *文字列に対する操作の例;
	TButton *構造体を使う例;
	void __fastcall 文字列型の文字を参照するClick(TObject *Sender);
	void __fastcall 相互代入のテストClick(TObject *Sender);
	void __fastcall 文字列の代入と連結Click(TObject *Sender);
	void __fastcall Format関数の利用例Click(TObject *Sender);
	void __fastcall クラスを使わない例Click(TObject *Sender);
	void __fastcall クラスを使う例Click(TObject *Sender);
	void __fastcall 文字列に対する操作の例Click(TObject *Sender);
	void __fastcall 構造体を使う例Click(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
