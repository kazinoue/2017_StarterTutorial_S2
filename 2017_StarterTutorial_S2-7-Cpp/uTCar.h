//---------------------------------------------------------------------------

#ifndef uTCarH
#define uTCarH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>


// クラスの例
class TCar {
protected: // protected 宣言は、クラス内と派生クラスから扱える
	String Manufacture; // ベンダー名
	String SeriesName;  // 車種名
	String Color;       // 色
	int HorsePower;     // 馬力

public:
	// コンストラクタ：オーバーロードにより複数の方法で生成できる
	TCar();
	TCar( String Manfacture, String SeriesName, int HorsePower, String Color = L"" );

	// デストラクタ：基底クラスのデストラクタは virtual 宣言しておく
	// これは派生クラスのデストラクタが確実に呼ばれるための処理
	virtual ~TCar();

	// アクセル操作。
	// virtual 宣言しているので派生クラスでオーバーライド可能
	virtual void AccelOn();

	void BreakOn();
};

// クラス継承の例
// TPoliceCar = TCarを継承した子クラス
class TPoliceCar : public TCar {
protected:
	bool statusPatoLight;   // パトライトの状態
	bool statusSpeedRadar;  // スピードレーダーの状態

public:
	TPoliceCar();
	TPoliceCar( String Manfacture, String SeriesName, int HorsePower );
	~TPoliceCar();

	void RedLightOn();		// 赤色灯をつける
	void RedLightOff();  	// 赤色灯を消す
	void SirenOn(); 	   	// サイレンを鳴らす
	void SirenOff();    	// サイレンを消す
};

// クラス継承の例
// THyblidCar = TCar を継承した子クラス
class THyblidCar : public TCar {
public:
	void AccelOn(); // アクセル操作
	void BreakOn();
};


struct TStructCar {
// struct でクラスを定義した場合は
// 明示的に protected, private 宣言しない限り、すべて public となる

	String Manufacture; // ベンダー名
	String SeriesName;  // 車種名
	String Color;       // 色
	int HorsePower;     // 馬力

	// コンストラクタ：オーバーライドにより複数の方法で生成できる
	TStructCar();
	TStructCar( String Manfacture, String SeriesName, int HorsePower, String Color = L"" );

	// デストラクタ：基底クラスのデストラクタは virtual 宣言しておく
	// これは派生クラスのデストラクタが確実に呼ばれるための処理
	virtual ~TStructCar();

	// アクセル操作。
	// virtual 宣言しているので派生クラスでオーバーライド可能
	virtual void AccelOn();

};


#endif

