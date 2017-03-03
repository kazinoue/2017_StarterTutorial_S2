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


// �N���X�̗�
class TCar {
protected: // protected �錾�́A�N���X���Ɣh���N���X���爵����
	String Manufacture; // �x���_�[��
	String SeriesName;  // �Ԏ햼
	String Color;       // �F
	int HorsePower;     // �n��

public:
	// �R���X�g���N�^�F�I�[�o�[���[�h�ɂ�蕡���̕��@�Ő����ł���
	TCar();
	TCar( String Manfacture, String SeriesName, int HorsePower, String Color = L"" );

	// �f�X�g���N�^�F���N���X�̃f�X�g���N�^�� virtual �錾���Ă���
	// ����͔h���N���X�̃f�X�g���N�^���m���ɌĂ΂�邽�߂̏���
	virtual ~TCar();

	// �A�N�Z������B
	// virtual �錾���Ă���̂Ŕh���N���X�ŃI�[�o�[���C�h�\
	virtual void AccelOn();

	void BreakOn();
};

// �N���X�p���̗�
// TPoliceCar = TCar���p�������q�N���X
class TPoliceCar : public TCar {
protected:
	bool statusPatoLight;   // �p�g���C�g�̏��
	bool statusSpeedRadar;  // �X�s�[�h���[�_�[�̏��

public:
	TPoliceCar();
	TPoliceCar( String Manfacture, String SeriesName, int HorsePower );
	~TPoliceCar();

	void RedLightOn();		// �ԐF��������
	void RedLightOff();  	// �ԐF��������
	void SirenOn(); 	   	// �T�C������炷
	void SirenOff();    	// �T�C����������
};

// �N���X�p���̗�
// THyblidCar = TCar ���p�������q�N���X
class THyblidCar : public TCar {
public:
	void AccelOn(); // �A�N�Z������
	void BreakOn();
};


struct TStructCar {
// struct �ŃN���X���`�����ꍇ��
// �����I�� protected, private �錾���Ȃ�����A���ׂ� public �ƂȂ�

	String Manufacture; // �x���_�[��
	String SeriesName;  // �Ԏ햼
	String Color;       // �F
	int HorsePower;     // �n��

	// �R���X�g���N�^�F�I�[�o�[���C�h�ɂ�蕡���̕��@�Ő����ł���
	TStructCar();
	TStructCar( String Manfacture, String SeriesName, int HorsePower, String Color = L"" );

	// �f�X�g���N�^�F���N���X�̃f�X�g���N�^�� virtual �錾���Ă���
	// ����͔h���N���X�̃f�X�g���N�^���m���ɌĂ΂�邽�߂̏���
	virtual ~TStructCar();

	// �A�N�Z������B
	// virtual �錾���Ă���̂Ŕh���N���X�ŃI�[�o�[���C�h�\
	virtual void AccelOn();

};


#endif

