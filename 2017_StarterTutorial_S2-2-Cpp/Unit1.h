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
__published:	// IDE で管理されるコンポーネント
	TMemo *Memo1;
	TButton *変数宣言に関するテスト;
	TButton *日付時刻の取り扱いのテスト;
	TButton *型変換のテスト;
	TButton *Button1;
	void __fastcall 変数宣言に関するテストClick(TObject *Sender);
	void __fastcall 日付時刻の取り扱いのテストClick(TObject *Sender);
	void __fastcall 型変換のテストClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
