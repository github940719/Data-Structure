object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 512
  ClientWidth = 818
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
    Width = 233
    Height = 512
    Align = alLeft
    TabOrder = 0
    ExplicitHeight = 504
    object LabelSize: TLabel
      Left = 26
      Top = 24
      Width = 45
      Height = 21
      Caption = 'size = '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 26
      Top = 56
      Width = 105
      Height = 21
      Caption = 'size should > 3'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object EditSize: TEdit
      Left = 77
      Top = 21
      Width = 117
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
    object GroupBox1: TGroupBox
      Left = 24
      Top = 92
      Width = 185
      Height = 168
      Caption = 'Starting Position'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object LabelStartX: TLabel
        Left = 19
        Top = 63
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
      object LabelStartY: TLabel
        Left = 18
        Top = 98
        Width = 27
        Height = 21
        Caption = 'y = '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object LabelPS1: TLabel
        Left = 34
        Top = 133
        Width = 106
        Height = 21
        Caption = '0 <= x, y < size'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object EditStartX: TEdit
        Left = 51
        Top = 63
        Width = 118
        Height = 29
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        Text = '0'
      end
      object EditStartY: TEdit
        Left = 51
        Top = 98
        Width = 118
        Height = 29
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        Text = '0'
      end
      object CheckBoxRandom: TCheckBox
        Left = 18
        Top = 24
        Width = 164
        Height = 25
        Caption = 'random position'
        TabOrder = 2
      end
    end
    object Button1: TButton
      Left = 24
      Top = 281
      Width = 185
      Height = 25
      Caption = 'Generate Knight Tour'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = Button1Click
    end
    object animation: TGroupBox
      Left = 24
      Top = 336
      Width = 185
      Height = 145
      Caption = 'animation'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      object Label1: TLabel
        Left = 35
        Top = 34
        Width = 115
        Height = 21
        Caption = 'animation speed'
      end
      object TrackBar1: TTrackBar
        Left = 18
        Top = 53
        Width = 150
        Height = 45
        TabOrder = 0
      end
      object Button2: TButton
        Left = 18
        Top = 104
        Width = 152
        Height = 25
        Caption = 'Generate Animation'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = Button2Click
      end
    end
  end
  object Panel2: TPanel
    Left = 233
    Top = 0
    Width = 585
    Height = 512
    Align = alClient
    TabOrder = 1
    object PageControl: TPageControl
      Left = 1
      Top = 1
      Width = 583
      Height = 510
      ActivePage = TabSheet2
      Align = alClient
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = 'Knight Tour Memo'
        object StringGrid1: TStringGrid
          Left = 0
          Top = 0
          Width = 575
          Height = 480
          Align = alClient
          TabOrder = 0
          ExplicitWidth = 573
          ExplicitHeight = 472
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'Knight Tour Animation'
        ImageIndex = 1
        object StringGrid2: TStringGrid
          Left = 0
          Top = 0
          Width = 575
          Height = 480
          Align = alClient
          TabOrder = 0
        end
      end
    end
  end
end
