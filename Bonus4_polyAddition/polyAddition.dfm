object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 526
  ClientWidth = 943
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
    Width = 249
    Height = 526
    Align = alLeft
    TabOrder = 0
    ExplicitHeight = 518
    object GroupBox1: TGroupBox
      Left = 16
      Top = 16
      Width = 209
      Height = 193
      Caption = 'manually add term'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object Label1: TLabel
        Left = 16
        Top = 34
        Width = 71
        Height = 21
        Caption = 'coefficient'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 16
        Top = 69
        Width = 64
        Height = 21
        Caption = 'exponent'
      end
      object Edit1: TEdit
        Left = 102
        Top = 31
        Width = 91
        Height = 29
        TabOrder = 0
        Text = '10'
      end
      object Edit2: TEdit
        Left = 102
        Top = 66
        Width = 91
        Height = 29
        TabOrder = 1
        Text = '2'
      end
      object Button1: TButton
        Left = 16
        Top = 112
        Width = 177
        Height = 25
        Caption = 'add to polynomial A'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnClick = Button1Click
      end
      object Button2: TButton
        Left = 16
        Top = 143
        Width = 177
        Height = 25
        Caption = 'add to polynomial B'
        TabOrder = 3
        OnClick = Button2Click
      end
    end
    object GroupBox2: TGroupBox
      Left = 16
      Top = 224
      Width = 209
      Height = 201
      Caption = 'randomly add term'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object Label3: TLabel
        Left = 16
        Top = 39
        Width = 66
        Height = 21
        Caption = 'max expo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 16
        Top = 74
        Width = 118
        Height = 21
        Caption = 'max range (+ / -)'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Button3: TButton
        Left = 16
        Top = 152
        Width = 177
        Height = 25
        Caption = 'random poly A and B'
        TabOrder = 0
        OnClick = Button3Click
      end
      object Edit3: TEdit
        Left = 102
        Top = 39
        Width = 91
        Height = 29
        TabOrder = 1
        Text = '5'
      end
      object Edit4: TEdit
        Left = 102
        Top = 101
        Width = 91
        Height = 29
        TabOrder = 2
        Text = '10'
      end
    end
    object Button4: TButton
      Left = 56
      Top = 440
      Width = 121
      Height = 25
      Caption = 'C = A + B'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 56
      Top = 480
      Width = 121
      Height = 25
      Caption = 'Re-Run'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = Button5Click
    end
  end
  object PageControl1: TPageControl
    Left = 249
    Top = 0
    Width = 694
    Height = 526
    Align = alClient
    TabOrder = 1
    ExplicitWidth = 692
    ExplicitHeight = 518
  end
  object Panel2: TPanel
    Left = 249
    Top = 0
    Width = 694
    Height = 526
    Align = alClient
    TabOrder = 2
    ExplicitWidth = 692
    ExplicitHeight = 518
    object Memo1: TMemo
      Left = 1
      Top = 1
      Width = 692
      Height = 524
      Align = alClient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      Lines.Strings = (
        'Memo1')
      ParentFont = False
      TabOrder = 0
      ExplicitWidth = 690
      ExplicitHeight = 516
    end
  end
end
