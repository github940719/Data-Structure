//---------------------------------------------------------------------------

#ifndef powerH
#define powerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TLabel *LabelX;
	TLabel *LabelN;
	TEdit *EditX;
	TPanel *Panel1;
	TEdit *EditN;
	TGroupBox *GroupBox1;
	TCheckBox *CheckBoxRecursion;
	TCheckBox *CheckBoxIteration;
	TCheckBox *CheckBoxFastPower;
	TCheckBox *CheckBoxBitwise;
	TButton *Button1;
	TLabel *LabelRepetition;
	TEdit *EditRepetition;
	TMemo *Memo1;
	TLabel *LabelDecimal;
	TEdit *EditDecimal;
	TPanel *Panel2;
	TPanel *Panel3;
	TLabel *LabelX2;
	TLabel *LabelN2;
	TEdit *EditX2;
	TEdit *EditN2;
	TLabel *LabelRange;
	TEdit *EditRange;
	TButton *ButtonCalRan;
	TGroupBox *GroupBox2;
	TLabel *LabelRepetition2;
	TEdit *EditRepetition2;
	TEdit *EditDecimal2;
	TLabel *LabelDecimal2;
	TMemo *Memo2;
	TButton *ButtonTxt;
	TLabel *Label1;
	TLabel *Label2;
	TOpenDialog *OpenDialog1;
	TGroupBox *GroupBox3;
	void __fastcall Button1Click(TObject *Sender);
    void __fastcall ButtonCalRanClick(TObject *Sender);
	void __fastcall ButtonTxtClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
