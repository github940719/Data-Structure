object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 725
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 725
    Height = 441
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 0
    ExplicitWidth = 723
    ExplicitHeight = 433
    object TabSheet1: TTabSheet
      Caption = 'x^n'
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 209
        Height = 411
        Align = alLeft
        TabOrder = 0
        ExplicitHeight = 403
        object LabelN: TLabel
          Left = 72
          Top = 58
          Width = 28
          Height = 21
          Caption = 'n = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelX: TLabel
          Left = 74
          Top = 26
          Width = 26
          Height = 21
          Caption = 'x = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelRepetition: TLabel
          Left = 14
          Top = 93
          Width = 86
          Height = 21
          Caption = 'repetition = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelDecimal: TLabel
          Left = 30
          Top = 128
          Width = 73
          Height = 21
          Caption = 'decimal = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object EditX: TEdit
          Left = 106
          Top = 23
          Width = 89
          Height = 29
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          Text = '2'
        end
        object EditN: TEdit
          Left = 106
          Top = 58
          Width = 89
          Height = 29
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          Text = '30'
        end
        object GroupBox1: TGroupBox
          Left = 14
          Top = 163
          Width = 179
          Height = 135
          Caption = 'algorithm'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          object CheckBoxRecursion: TCheckBox
            Left = 16
            Top = 32
            Width = 136
            Height = 17
            Caption = 'naive recursion'
            TabOrder = 0
          end
          object CheckBoxIteration: TCheckBox
            Left = 16
            Top = 55
            Width = 136
            Height = 17
            Caption = 'naive iteration'
            TabOrder = 1
          end
          object CheckBoxFastPower: TCheckBox
            Left = 16
            Top = 78
            Width = 136
            Height = 17
            Caption = 'fast power'
            TabOrder = 2
          end
          object CheckBoxBitwise: TCheckBox
            Left = 16
            Top = 101
            Width = 136
            Height = 17
            Caption = 'bitwise'
            TabOrder = 3
          end
        end
        object Button1: TButton
          Left = 14
          Top = 312
          Width = 179
          Height = 25
          Caption = 'Calculate x^n'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          OnClick = Button1Click
        end
        object EditRepetition: TEdit
          Left = 106
          Top = 93
          Width = 89
          Height = 29
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          Text = '10000000'
        end
        object EditDecimal: TEdit
          Left = 106
          Top = 128
          Width = 89
          Height = 29
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 5
          Text = '10'
        end
      end
      object Memo1: TMemo
        Left = 209
        Top = 0
        Width = 508
        Height = 411
        Align = alClient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        Lines.Strings = (
          'Memo1')
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 1
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'polynomial'
      ImageIndex = 1
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 225
        Height = 411
        Align = alLeft
        TabOrder = 0
        object LabelX2: TLabel
          Left = 46
          Top = 23
          Width = 62
          Height = 21
          Caption = 'max_x = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelRepetition2: TLabel
          Left = 22
          Top = 50
          Width = 86
          Height = 21
          Caption = 'repetition = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelDecimal2: TLabel
          Left = 35
          Top = 85
          Width = 73
          Height = 21
          Caption = 'decimal = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object EditX2: TEdit
          Left = 114
          Top = 15
          Width = 97
          Height = 29
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          Text = '2'
        end
        object GroupBox2: TGroupBox
          Left = 16
          Top = 120
          Width = 195
          Height = 134
          Caption = 'random coef'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          object LabelRange: TLabel
            Left = 8
            Top = 28
            Width = 92
            Height = 21
            Caption = 'coef range = '
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
          end
          object LabelN2: TLabel
            Left = 72
            Top = 63
            Width = 28
            Height = 21
            Caption = 'n = '
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
          end
          object EditRange: TEdit
            Left = 103
            Top = 28
            Width = 82
            Height = 29
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            Text = '100'
          end
          object ButtonCalRan: TButton
            Left = 11
            Top = 98
            Width = 174
            Height = 25
            Caption = 'Calculate (random coef)'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            OnClick = ButtonCalRanClick
          end
          object EditN2: TEdit
            Left = 103
            Top = 63
            Width = 81
            Height = 29
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
            TabOrder = 2
            Text = '30'
          end
        end
        object EditRepetition2: TEdit
          Left = 114
          Top = 50
          Width = 97
          Height = 29
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          Text = '10000000'
        end
        object EditDecimal2: TEdit
          Left = 114
          Top = 85
          Width = 97
          Height = 29
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          Text = '10'
        end
        object GroupBox3: TGroupBox
          Left = 16
          Top = 260
          Width = 195
          Height = 125
          Caption = 'read txt. to get coef'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          object Label1: TLabel
            Left = 11
            Top = 74
            Width = 159
            Height = 21
            Caption = 'txt. should contain coef'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
          end
          object Label2: TLabel
            Left = 11
            Top = 93
            Width = 177
            Height = 21
            Caption = 'a0, a1, ..., an (a coef a line)'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
          end
          object ButtonTxt: TButton
            Left = 11
            Top = 35
            Width = 174
            Height = 25
            Caption = 'Calculate (read coef  txt.)'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnClick = ButtonTxtClick
          end
        end
      end
      object Panel3: TPanel
        Left = 225
        Top = 0
        Width = 492
        Height = 411
        Align = alClient
        TabOrder = 1
        object Memo2: TMemo
          Left = 1
          Top = 1
          Width = 490
          Height = 409
          Align = alClient
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo2')
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
        end
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 96
    Top = 296
  end
end
