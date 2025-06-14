//---------------------------------------------------------------------------

#ifndef knightTourH
#define knightTourH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *EditSize;
	TLabel *LabelSize;
	TPanel *Panel1;
	TGroupBox *GroupBox1;
	TLabel *LabelStartX;
	TLabel *LabelStartY;
	TEdit *EditStartX;
	TEdit *EditStartY;
	TLabel *LabelPS1;
	TButton *Button1;
	TButton *Button2;
	TPanel *Panel2;
	TStringGrid *StringGrid1;
	TPageControl *PageControl;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TLabel *Label3;
	TStringGrid *StringGrid2;
	TTrackBar *TrackBar1;
	TGroupBox *animation;
	TLabel *Label1;
	TCheckBox *CheckBoxRandom;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
