//---------------------------------------------------------------------------

#ifndef shortestPathH
#define shortestPathH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TButton *Button1;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TEdit *Edit1;
	TLabel *Label2;
	TEdit *Edit2;
	TButton *Button2;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TButton *Button3;
	TLabel *Label3;
	TEdit *Edit3;
	TButton *Button4;
	TButton *Button5;
	TTabSheet *TabSheet4;
	TOpenDialog *OpenDialog1;
	TStringGrid *StringGrid1;
	TLabel *Label4;
	TEdit *Edit4;
	TMemo *Memo1;
	TTabSheet *TabSheet5;
	TTabSheet *TabSheet7;
	TStringGrid *StringGrid2;
	TStringGrid *StringGrid3;
	TMemo *Memo2;
	TCheckBox *CheckBox1;
	TStringGrid *StringGrid4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
