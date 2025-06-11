//---------------------------------------------------------------------------

#ifndef rat_in_mazeH
#define rat_in_mazeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TGroupBox *GroupBox1;
	TButton *Button1;
	TOpenDialog *OpenDialog;
	TButton *Button2;
	TPanel *Panel2;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TMemo *Memo1;
	TStringGrid *StringGrid;
	TGroupBox *GroupBox2;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EditSizeX;
	TEdit *EditSizeY;
	TLabel *Label3;
	TEdit *EditStartX;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *EditEndX;
	TLabel *Label6;
	TButton *Button3;
	TLabel *Label7;
	TLabel *Label8;
	TTrackBar *TrackBar1;
	TGroupBox *GroupBox3;
	TLabel *Label9;
	TButton *Button4;
	TStringGrid *StringGrid1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall StringGridDrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall StringGrid1DrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
		  TRect &Rect, TGridDrawState State);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
