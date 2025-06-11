//---------------------------------------------------------------------------

#ifndef expressionH
#define expressionH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TLabel *Label1;
	TEdit *Edit1;
	TPanel *Panel1;
	TLabel *Label2;
	TLabel *Label3;
	TMemo *Memo1;
	TMemo *Memo2;
	TButton *Button2;
	TLabel *Label4;
	TLabel *Label6;
	TEdit *Edit2;
	TButton *Button3;
	TButton *Button4;
	TMemo *Memo3;
	TMemo *Memo4;
	TPanel *Panel2;
	TButton *Button5;
	TButton *Button6;
	TEdit *Edit3;
	TMemo *Memo5;
	TMemo *Memo6;
	TPanel *Panel3;
	TLabel *Label7;
	TLabel *Label5;
	TLabel *Label9;
	TLabel *Label10;
	TMemo *Memo8;
	TMemo *Memo9;
	TMemo *Memo7;
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
