object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 447
  ClientWidth = 650
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 129
    Height = 447
    Align = alLeft
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 16
      Width = 49
      Height = 21
      Caption = 'size (n)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 16
      Top = 43
      Width = 89
      Height = 29
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = '5'
    end
    object Button1: TButton
      Left = 16
      Top = 88
      Width = 89
      Height = 25
      Caption = 'nQueen'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = Button1Click
    end
    object CheckBox1: TCheckBox
      Left = 16
      Top = 128
      Width = 97
      Height = 33
      Caption = 'string grid'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
  end
  object Panel2: TPanel
    Left = 129
    Top = 0
    Width = 521
    Height = 447
    Align = alClient
    TabOrder = 1
    ExplicitLeft = 1
    ExplicitTop = 1
    ExplicitWidth = 127
    ExplicitHeight = 445
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 519
      Height = 445
      ActivePage = TabSheet3
      Align = alClient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = '1-D array'
        object Memo1: TMemo
          Left = 0
          Top = 0
          Width = 511
          Height = 409
          Align = alClient
          Lines.Strings = (
            'Memo1')
          ScrollBars = ssBoth
          TabOrder = 0
        end
      end
      object TabSheet2: TTabSheet
        Caption = '2-D array'
        ImageIndex = 1
        object Memo2: TMemo
          Left = 0
          Top = 0
          Width = 511
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
      object TabSheet3: TTabSheet
        Caption = 'String Grid'
        ImageIndex = 2
        object StringGrid1: TStringGrid
          Left = 0
          Top = 0
          Width = 511
          Height = 409
          Align = alClient
          TabOrder = 0
          ExplicitLeft = 96
          ExplicitTop = 144
          ExplicitWidth = 320
          ExplicitHeight = 120
        end
      end
    end
  end
end
