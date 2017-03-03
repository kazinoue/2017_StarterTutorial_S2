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
__published:	// IDE で管理されるコンポーネント
	TButton *関数の記述順と呼び出し;
	TLayout *Layout1;
	TMemo *Memo1;
	TButton *値渡しと参照渡し;
	TButton *オーバーロードの例２;
	TButton *returnで抜ける例;
	TButton *オーバーロード処理の例;
	TButton *再帰呼び出しの例;
	void __fastcall 関数の記述順と呼び出しClick(TObject *Sender);
	void __fastcall 値渡しと参照渡しClick(TObject *Sender);
	void __fastcall overload_example( double n );
	void __fastcall overload_example( int n );
	void __fastcall オーバーロードの例２Click(TObject *Sender);
	void __fastcall returnで抜ける例Click(TObject *Sender);
	void __fastcall オーバーロード処理の例Click(TObject *Sender);
	void __fastcall 再帰呼び出しの例Click(TObject *Sender);
    int __fastcall  Recursive( int count );


private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
