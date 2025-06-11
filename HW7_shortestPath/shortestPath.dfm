object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 591
  ClientWidth = 1044
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
    Width = 225
    Height = 591
    Align = alLeft
    TabOrder = 0
    object Label3: TLabel
      Left = 16
      Top = 375
      Width = 46
      Height = 21
      Caption = 'source'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Button1: TButton
      Left = 32
      Top = 16
      Width = 145
      Height = 25
      Caption = 'Read Graph txt.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = Button1Click
    end
    object GroupBox1: TGroupBox
      Left = 16
      Top = 47
      Width = 190
      Height = 314
      Caption = 'Randomly Generated'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object Label1: TLabel
        Left = 16
        Top = 28
        Width = 123
        Height = 21
        Caption = 'number of verties'
      end
      object Label2: TLabel
        Left = 16
        Top = 104
        Width = 106
        Height = 21
        Caption = 'range of length'
      end
      object Label4: TLabel
        Left = 16
        Top = 176
        Width = 121
        Height = 21
        Caption = 'set inf if weight >'
      end
      object Edit1: TEdit
        Left = 69
        Top = 55
        Width = 108
        Height = 29
        TabOrder = 0
        Text = '10'
      end
      object Edit2: TEdit
        Left = 69
        Top = 131
        Width = 108
        Height = 29
        TabOrder = 1
        Text = '1000'
      end
      object Button2: TButton
        Left = 32
        Top = 277
        Width = 145
        Height = 25
        Caption = 'Generate the Graph'
        TabOrder = 2
        OnClick = Button2Click
      end
      object RadioButton1: TRadioButton
        Left = 9
        Top = 254
        Width = 113
        Height = 17
        Caption = 'directed'
        TabOrder = 3
      end
      object RadioButton2: TRadioButton
        Left = 93
        Top = 254
        Width = 97
        Height = 17
        Caption = 'undirected'
        TabOrder = 4
      end
      object Edit4: TEdit
        Left = 69
        Top = 203
        Width = 108
        Height = 29
        TabOrder = 5
        Text = '500'
      end
    end
    object Button3: TButton
      Left = 16
      Top = 407
      Width = 190
      Height = 25
      Caption = 'Single Source All Dest.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = Button3Click
    end
    object Edit3: TEdit
      Left = 80
      Top = 372
      Width = 126
      Height = 29
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      Text = '0'
    end
    object Button4: TButton
      Left = 16
      Top = 480
      Width = 190
      Height = 25
      Caption = 'All pairs Shortest Paths'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 16
      Top = 536
      Width = 190
      Height = 25
      Caption = 'Transitive Closure'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      OnClick = Button5Click
    end
    object CheckBox1: TCheckBox
      Left = 16
      Top = 457
      Width = 139
      Height = 17
      Caption = 'trace the dp table'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
    end
  end
  object Panel2: TPanel
    Left = 225
    Top = 0
    Width = 819
    Height = 591
    Align = alClient
    TabOrder = 1
    ExplicitLeft = 1
    ExplicitTop = 1
    ExplicitWidth = 255
    ExplicitHeight = 589
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 817
      Height = 589
      ActivePage = TabSheet3
      Align = alClient
      TabOrder = 0
      ExplicitWidth = 834
      object TabSheet1: TTabSheet
        Caption = 'Adjacency Matrix'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        object StringGrid1: TStringGrid
          Left = 0
          Top = 0
          Width = 809
          Height = 559
          Align = alClient
          TabOrder = 0
          ExplicitLeft = -56
          ExplicitTop = 232
          ExplicitWidth = 320
          ExplicitHeight = 120
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'shortest path of SSAD'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ImageIndex = 1
        ParentFont = False
        object Memo1: TMemo
          Left = 0
          Top = 0
          Width = 809
          Height = 559
          Align = alClient
          Lines.Strings = (
            'Memo1')
          ScrollBars = ssBoth
          TabOrder = 0
        end
      end
      object TabSheet3: TTabSheet
        Caption = 'SSAD trace'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ImageIndex = 2
        ParentFont = False
        object StringGrid2: TStringGrid
          Left = 0
          Top = 0
          Width = 809
          Height = 559
          Align = alClient
          TabOrder = 0
          ExplicitLeft = 1
        end
      end
      object TabSheet4: TTabSheet
        Caption = 'All pairs shortest dist'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ImageIndex = 3
        ParentFont = False
        object StringGrid3: TStringGrid
          Left = 0
          Top = 0
          Width = 809
          Height = 559
          Align = alClient
          TabOrder = 0
          ExplicitLeft = 1
          ExplicitTop = 1
          ExplicitWidth = 807
          ExplicitHeight = 271
        end
      end
      object TabSheet5: TTabSheet
        Caption = 'All pairs path'
        ImageIndex = 5
        object Memo2: TMemo
          Left = 0
          Top = 0
          Width = 809
          Height = 559
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
      object TabSheet7: TTabSheet
        Caption = 'Transitive Closure'
        ImageIndex = 6
        object StringGrid4: TStringGrid
          Left = 0
          Top = 0
          Width = 809
          Height = 559
          Align = alClient
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          ExplicitLeft = 248
          ExplicitTop = 216
          ExplicitWidth = 320
          ExplicitHeight = 120
        end
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 168
    Top = 8
  end
end
