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
__published:	// IDE で管理されるコンポーネント
	TEdit *Edit1;
	TButton *DynamicArrayで指定値までの素数を探す;
	TMemo *Memo1;
	TToolBar *ToolBar1;
	TButton *StaticArrayで100までの素数を探す;
	TButton *Cスタイルの配列で指定値までの素数を探す;
	TButton *Cスタイルの配列で100までの素数を探す;
	TButton *構造体を使う例;
	void __fastcall DynamicArrayで指定値までの素数を探すClick(TObject *Sender);
	void __fastcall StaticArrayで100までの素数を探すClick(TObject *Sender);
	void __fastcall Cスタイルの配列で指定値までの素数を探すClick(TObject *Sender);
	void __fastcall Cスタイルの配列で100までの素数を探すClick(TObject *Sender);
	void __fastcall 構造体を使う例Click(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
