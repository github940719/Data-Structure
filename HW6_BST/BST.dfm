object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 604
  ClientWidth = 900
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
    Height = 604
    Align = alLeft
    TabOrder = 0
    ExplicitHeight = 596
    object GroupBox1: TGroupBox
      Left = 16
      Top = 40
      Width = 217
      Height = 217
      Caption = 'Insertion'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object Label1: TLabel
        Left = 16
        Top = 27
        Width = 56
        Height = 21
        Caption = 'element'
      end
      object Label2: TLabel
        Left = 45
        Top = 112
        Width = 27
        Height = 21
        Caption = 'k = '
      end
      object Label3: TLabel
        Left = 13
        Top = 144
        Width = 59
        Height = 21
        Caption = 'range = '
      end
      object Edit1: TEdit
        Left = 78
        Top = 24
        Width = 131
        Height = 29
        TabOrder = 0
        Text = '10'
      end
      object Button1: TButton
        Left = 16
        Top = 59
        Width = 190
        Height = 25
        Caption = 'Insert Element Into BST'
        TabOrder = 1
        OnClick = Button1Click
      end
      object Edit2: TEdit
        Left = 78
        Top = 109
        Width = 128
        Height = 29
        TabOrder = 2
        Text = '5'
      end
      object Edit3: TEdit
        Left = 78
        Top = 144
        Width = 128
        Height = 29
        TabOrder = 3
        Text = '100'
      end
      object Button2: TButton
        Left = 16
        Top = 179
        Width = 190
        Height = 25
        Caption = 'Insert k random numbers'
        TabOrder = 4
        OnClick = Button2Click
      end
    end
    object GroupBox2: TGroupBox
      Left = 16
      Top = 330
      Width = 217
      Height = 105
      Caption = 'Deletion'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object Label4: TLabel
        Left = 16
        Top = 32
        Width = 56
        Height = 21
        Caption = 'element'
      end
      object Edit4: TEdit
        Left = 78
        Top = 32
        Width = 123
        Height = 29
        TabOrder = 0
        Text = '5'
      end
      object Button3: TButton
        Left = 15
        Top = 67
        Width = 185
        Height = 25
        Caption = 'Delete Element from BST'
        TabOrder = 1
        OnClick = Button3Click
      end
    end
    object RadioButton1: TRadioButton
      Left = 16
      Top = 17
      Width = 113
      Height = 17
      Caption = 'Recursion'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object RadioButton2: TRadioButton
      Left = 135
      Top = 17
      Width = 113
      Height = 17
      Caption = 'Iteration'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
    object GroupBox3: TGroupBox
      Left = 16
      Top = 263
      Width = 217
      Height = 61
      Caption = 'Search'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      object Label5: TLabel
        Left = 13
        Top = 27
        Width = 56
        Height = 21
        Caption = 'element'
      end
      object Edit5: TEdit
        Left = 75
        Top = 24
        Width = 61
        Height = 29
        TabOrder = 0
        Text = '15'
      end
      object Button4: TButton
        Left = 142
        Top = 27
        Width = 69
        Height = 25
        Caption = 'Search'
        TabOrder = 1
        OnClick = Button4Click
      end
    end
    object GroupBox4: TGroupBox
      Left = 16
      Top = 441
      Width = 217
      Height = 112
      Caption = 'Traversal'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      object Label6: TLabel
        Left = 13
        Top = 85
        Width = 198
        Height = 21
        Caption = 'press traversal can draw BST'
      end
      object Button5: TButton
        Left = 16
        Top = 23
        Width = 89
        Height = 25
        Caption = 'PreOrder'
        TabOrder = 0
        OnClick = Button5Click
      end
      object Button6: TButton
        Left = 111
        Top = 23
        Width = 89
        Height = 25
        Caption = 'InOrder'
        TabOrder = 1
        OnClick = Button6Click
      end
      object Button7: TButton
        Left = 16
        Top = 54
        Width = 89
        Height = 25
        Caption = 'PostOrder'
        TabOrder = 2
        OnClick = Button7Click
      end
      object Button8: TButton
        Left = 111
        Top = 54
        Width = 90
        Height = 25
        Caption = 'LevelOrder'
        TabOrder = 3
        OnClick = Button8Click
      end
    end
    object Button9: TButton
      Left = 77
      Top = 559
      Width = 75
      Height = 25
      Caption = 'Re-Run'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      OnClick = Button9Click
    end
  end
  object PageControl1: TPageControl
    Left = 257
    Top = 0
    Width = 643
    Height = 604
    ActivePage = TabSheet2
    Align = alClient
    TabOrder = 1
    ExplicitWidth = 641
    ExplicitHeight = 596
    object TabSheet1: TTabSheet
      Caption = 'Print BST'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 635
        Height = 574
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
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Draw BST'
      ImageIndex = 1
      object PaintBox1: TPaintBox
        Left = 0
        Top = 0
        Width = 635
        Height = 574
        Align = alClient
        ExplicitLeft = 264
        ExplicitTop = 216
        ExplicitWidth = 105
        ExplicitHeight = 105
      end
    end
  end
end
