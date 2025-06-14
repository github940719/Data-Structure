object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 568
  ClientWidth = 861
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
    Width = 257
    Height = 568
    Align = alLeft
    TabOrder = 0
    ExplicitHeight = 560
    object GroupBox1: TGroupBox
      Left = 16
      Top = 16
      Width = 225
      Height = 81
      Caption = 'Load the Maze'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object Button1: TButton
        Left = 40
        Top = 32
        Width = 145
        Height = 33
        Caption = 'Load the Maze'
        TabOrder = 0
        OnClick = Button1Click
      end
    end
    object Button2: TButton
      Left = 54
      Top = 361
      Width = 145
      Height = 40
      Caption = 'Print the Tour'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = Button2Click
    end
    object GroupBox2: TGroupBox
      Left = 15
      Top = 103
      Width = 225
      Height = 233
      Caption = 'Random Generation'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      object Label1: TLabel
        Left = 16
        Top = 35
        Width = 76
        Height = 21
        Caption = 'size of X = '
      end
      object Label2: TLabel
        Left = 16
        Top = 67
        Width = 76
        Height = 21
        Caption = 'size of Y = '
      end
      object Label3: TLabel
        Left = 16
        Top = 107
        Width = 48
        Height = 21
        Caption = 'start at'
      end
      object Label4: TLabel
        Left = 159
        Top = 107
        Width = 7
        Height = 21
        Caption = ', '
      end
      object Label5: TLabel
        Left = 16
        Top = 142
        Width = 43
        Height = 21
        Caption = 'end at'
      end
      object Label6: TLabel
        Left = 159
        Top = 142
        Width = 7
        Height = 21
        Caption = ', '
      end
      object Label7: TLabel
        Left = 175
        Top = 105
        Width = 9
        Height = 21
        Caption = '1'
      end
      object Label8: TLabel
        Left = 175
        Top = 142
        Width = 35
        Height = 21
        Caption = 'sizeY'
      end
      object EditSizeX: TEdit
        Left = 98
        Top = 32
        Width = 111
        Height = 29
        TabOrder = 0
        Text = '15'
      end
      object EditSizeY: TEdit
        Left = 98
        Top = 67
        Width = 111
        Height = 29
        TabOrder = 1
        Text = '15'
      end
      object EditStartX: TEdit
        Left = 74
        Top = 102
        Width = 79
        Height = 29
        TabOrder = 2
        Text = '1'
      end
      object EditEndX: TEdit
        Left = 74
        Top = 142
        Width = 79
        Height = 29
        TabOrder = 3
        Text = '15'
      end
    end
    object Button3: TButton
      Left = 56
      Top = 287
      Width = 145
      Height = 33
      Caption = 'Generate the Maze'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = Button3Click
    end
    object GroupBox3: TGroupBox
      Left = 16
      Top = 407
      Width = 224
      Height = 138
      Caption = 'Animation'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      object Label9: TLabel
        Left = 15
        Top = 37
        Width = 43
        Height = 21
        Caption = 'Speed'
      end
      object TrackBar1: TTrackBar
        Left = 64
        Top = 32
        Width = 150
        Height = 45
        TabOrder = 0
      end
      object Button4: TButton
        Left = 42
        Top = 83
        Width = 143
        Height = 41
        Caption = 'Animation'
        TabOrder = 1
        OnClick = Button4Click
      end
    end
  end
  object Panel2: TPanel
    Left = 257
    Top = 0
    Width = 604
    Height = 568
    Align = alClient
    TabOrder = 1
    ExplicitWidth = 602
    ExplicitHeight = 560
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 602
      Height = 566
      ActivePage = TabSheet2
      Align = alClient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      ExplicitWidth = 600
      ExplicitHeight = 558
      object TabSheet1: TTabSheet
        Caption = 'print on Memo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        object Memo1: TMemo
          Left = 0
          Top = 0
          Width = 594
          Height = 530
          Align = alClient
          Lines.Strings = (
            'Memo1')
          ScrollBars = ssBoth
          TabOrder = 0
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'print on String Grid'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ImageIndex = 1
        ParentFont = False
        object StringGrid: TStringGrid
          Left = 0
          Top = 0
          Width = 594
          Height = 530
          Align = alClient
          TabOrder = 0
          OnDrawCell = StringGridDrawCell
          ExplicitWidth = 592
          ExplicitHeight = 522
        end
      end
      object TabSheet3: TTabSheet
        Caption = 'Animation'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ImageIndex = 2
        ParentFont = False
        object StringGrid1: TStringGrid
          Left = 0
          Top = 0
          Width = 594
          Height = 530
          Align = alClient
          TabOrder = 0
          OnDrawCell = StringGrid1DrawCell
        end
      end
    end
  end
  object OpenDialog: TOpenDialog
    Left = 208
    Top = 56
  end
end
