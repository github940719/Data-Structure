object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 598
  ClientWidth = 964
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
    Width = 161
    Height = 598
    Align = alLeft
    TabOrder = 0
    ExplicitHeight = 590
    object Label1: TLabel
      Left = 16
      Top = 144
      Width = 56
      Height = 21
      Caption = 'element'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 16
      Top = 171
      Width = 121
      Height = 29
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = '10'
    end
    object Button1: TButton
      Left = 16
      Top = 277
      Width = 121
      Height = 25
      Caption = 'insert into AVL'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 16
      Top = 316
      Width = 121
      Height = 25
      Caption = 'delete from AVL'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 16
      Top = 400
      Width = 121
      Height = 25
      Caption = 're-run'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 16
      Top = 360
      Width = 121
      Height = 25
      Caption = 'draw AVL'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnClick = Button4Click
    end
  end
  object Panel2: TPanel
    Left = 161
    Top = 0
    Width = 803
    Height = 598
    Align = alClient
    TabOrder = 1
    ExplicitWidth = 801
    ExplicitHeight = 590
    object PaintBox1: TPaintBox
      Left = 1
      Top = 1
      Width = 801
      Height = 596
      Align = alClient
      ExplicitLeft = 0
      ExplicitTop = 2
      ExplicitWidth = 769
    end
  end
end
