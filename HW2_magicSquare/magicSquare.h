//---------------------------------------------------------------------------

#ifndef magicSquareH
#define magicSquareH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label_size;
	TEdit *Edit_size;
	TPanel *Panel_input;
	TRadioButton *RadioLeft;
	TRadioButton *RadioRight;
	TRadioButton *RadioTop;
	TGroupBox *start;
	TButton *Button;
	TMemo *checkResult;
	TCheckBox *selfCheck;
	TPanel *PanelOutput;
	TMemo *MemoOutput;
	TPageControl *PageControl;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TStringGrid *StringGrid1;
	TTabSheet *TabSheet3;
	TMemo *memoCheck;
	TTabSheet *TabSheet4;
	TStringGrid *StringGrid2;
	TLabel *Label1;
	TLabel *Label2;
	TRadioButton *RadioBottom;
	TGroupBox *direction;
	TRadioButton *RadioDownLeft;
	TRadioButton *RadioDownRight;
	TRadioButton *RadioUpLeft;
	TRadioButton *RadioUpRight;
	TGroupBox *conflict;
	TRadioButton *RadioConflictRight;
	TRadioButton *RadioConflictLeft;
	TRadioButton *RadioConflictDown;
	TRadioButton *RadioConflictUp;
	TLabel *Label3;
	void __fastcall ButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
