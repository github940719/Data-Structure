object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 512
  ClientWidth = 926
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Panel_input: TPanel
    Left = 0
    Top = 0
    Width = 289
    Height = 512
    Align = alLeft
    TabOrder = 0
    ExplicitHeight = 504
    object Label_size: TLabel
      Left = 8
      Top = 24
      Width = 39
      Height = 17
      Caption = 'size = '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label1: TLabel
      Left = 8
      Top = 176
      Width = 274
      Height = 17
      Caption = 'the above selection is irrelevant when size = 4k'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 8
      Top = 199
      Width = 202
      Height = 17
      Caption = 'default : start at top, move upLeft, '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 61
      Top = 222
      Width = 173
      Height = 17
      Caption = 'and move down when conflict'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Edit_size: TEdit
      Left = 53
      Top = 21
      Width = 52
      Height = 25
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = '3'
    end
    object start: TGroupBox
      Left = 10
      Top = 52
      Width = 71
      Height = 118
      Caption = 'start at'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object RadioRight: TRadioButton
        Left = 3
        Top = 93
        Width = 113
        Height = 17
        Caption = 'right'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object RadioLeft: TRadioButton
        Left = 3
        Top = 70
        Width = 113
        Height = 17
        Caption = 'left'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object RadioTop: TRadioButton
        Left = 3
        Top = 24
        Width = 113
        Height = 17
        Caption = 'top'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object RadioBottom: TRadioButton
        Left = 3
        Top = 47
        Width = 113
        Height = 17
        Caption = 'bottom'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
    end
    object Button: TButton
      Left = 8
      Top = 289
      Width = 243
      Height = 25
      Caption = 'Generate Magic Square'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = ButtonClick
    end
    object checkResult: TMemo
      Left = 8
      Top = 320
      Width = 243
      Height = 177
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      Lines.Strings = (
        'checkResult')
      ParentFont = False
      ScrollBars = ssVertical
      TabOrder = 3
    end
    object selfCheck: TCheckBox
      Left = 8
      Top = 266
      Width = 217
      Height = 17
      Caption = 'output validity in the below memo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
    end
    object direction: TGroupBox
      Left = 87
      Top = 52
      Width = 88
      Height = 118
      Caption = 'direction'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      object RadioDownLeft: TRadioButton
        Left = 3
        Top = 70
        Width = 113
        Height = 17
        Caption = 'downLeft'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object RadioDownRight: TRadioButton
        Left = 3
        Top = 93
        Width = 113
        Height = 17
        Caption = 'downRight'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object RadioUpLeft: TRadioButton
        Left = 3
        Top = 24
        Width = 113
        Height = 17
        Caption = 'upLeft'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object RadioUpRight: TRadioButton
        Left = 3
        Top = 47
        Width = 113
        Height = 17
        Caption = 'upRight'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
    end
    object conflict: TGroupBox
      Left = 181
      Top = 52
      Width = 70
      Height = 118
      Caption = 'conflict'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      object RadioConflictRight: TRadioButton
        Left = 3
        Top = 93
        Width = 113
        Height = 17
        Caption = 'right'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object RadioConflictLeft: TRadioButton
        Left = 3
        Top = 70
        Width = 113
        Height = 17
        Caption = 'left'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object RadioConflictDown: TRadioButton
        Left = 3
        Top = 24
        Width = 113
        Height = 17
        Caption = 'down'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object RadioConflictUp: TRadioButton
        Left = 3
        Top = 47
        Width = 113
        Height = 17
        Caption = 'up'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
    end
  end
  object PanelOutput: TPanel
    Left = 289
    Top = 0
    Width = 637
    Height = 512
    Align = alClient
    TabOrder = 1
    ExplicitWidth = 635
    ExplicitHeight = 504
    object PageControl: TPageControl
      Left = 1
      Top = 1
      Width = 635
      Height = 510
      ActivePage = TabSheet1
      Align = alClient
      TabOrder = 0
      ExplicitWidth = 633
      ExplicitHeight = 502
      object TabSheet1: TTabSheet
        Caption = 'print on memo'
        object MemoOutput: TMemo
          Left = 0
          Top = 0
          Width = 627
          Height = 480
          Align = alClient
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'MemoOutput')
          ParentFont = False
          TabOrder = 0
          ExplicitWidth = 625
          ExplicitHeight = 472
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'print on grid'
        ImageIndex = 1
        object StringGrid1: TStringGrid
          Left = 0
          Top = 0
          Width = 627
          Height = 480
          Align = alClient
          TabOrder = 0
        end
      end
      object TabSheet3: TTabSheet
        Caption = 'print on memo with check'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ImageIndex = 2
        ParentFont = False
        object memoCheck: TMemo
          Left = 0
          Top = 0
          Width = 627
          Height = 480
          Align = alClient
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'memoCheck')
          ParentFont = False
          TabOrder = 0
        end
      end
      object TabSheet4: TTabSheet
        Caption = 'print on grid with check'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ImageIndex = 3
        ParentFont = False
        object StringGrid2: TStringGrid
          Left = 0
          Top = 0
          Width = 627
          Height = 480
          Align = alClient
          TabOrder = 0
        end
      end
    end
  end
end
