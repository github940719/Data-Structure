object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 663
  ClientWidth = 1050
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
    Width = 281
    Height = 663
    Align = alLeft
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    ExplicitHeight = 655
    object Label1: TLabel
      Left = 16
      Top = 13
      Width = 121
      Height = 21
      Caption = 'initial len of array'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 16
      Top = 48
      Width = 125
      Height = 21
      Caption = 'range of elements'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 16
      Top = 86
      Width = 67
      Height = 21
      Caption = 'repetition'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 16
      Top = 121
      Width = 59
      Height = 21
      Caption = 'step size'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 16
      Top = 156
      Width = 98
      Height = 21
      Caption = 'data points (x)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 162
      Top = 13
      Width = 103
      Height = 29
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = '1000'
    end
    object Edit2: TEdit
      Left = 162
      Top = 48
      Width = 103
      Height = 29
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      Text = '100000'
    end
    object Edit3: TEdit
      Left = 162
      Top = 86
      Width = 103
      Height = 29
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      Text = '10'
    end
    object Edit4: TEdit
      Left = 162
      Top = 121
      Width = 103
      Height = 29
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      Text = '2000'
    end
    object Edit5: TEdit
      Left = 162
      Top = 156
      Width = 103
      Height = 29
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      Text = '5'
    end
    object GroupBox1: TGroupBox
      Left = 16
      Top = 191
      Width = 249
      Height = 226
      Caption = 'sorting algorithm'
      TabOrder = 5
      object CheckBox1: TCheckBox
        Left = 3
        Top = 32
        Width = 122
        Height = 17
        Caption = 'selection sort'
        TabOrder = 0
      end
      object CheckBox2: TCheckBox
        Left = 131
        Top = 32
        Width = 110
        Height = 17
        Caption = 'bubble sort'
        TabOrder = 1
      end
      object CheckBox3: TCheckBox
        Left = 3
        Top = 55
        Width = 122
        Height = 24
        Caption = 'insertion sort'
        TabOrder = 2
      end
      object CheckBox4: TCheckBox
        Left = 3
        Top = 190
        Width = 190
        Height = 19
        Caption = 'merge sort (recursion)'
        TabOrder = 3
      end
      object CheckBox5: TCheckBox
        Left = 3
        Top = 135
        Width = 182
        Height = 26
        Caption = 'merge sort (iteration)'
        TabOrder = 4
      end
      object CheckBox7: TCheckBox
        Left = 3
        Top = 108
        Width = 182
        Height = 27
        Caption = 'quick sort (iteration)'
        TabOrder = 5
      end
      object CheckBox8: TCheckBox
        Left = 131
        Top = 55
        Width = 97
        Height = 26
        Caption = 'heap sort'
        TabOrder = 6
      end
      object CheckBox9: TCheckBox
        Left = 3
        Top = 85
        Width = 97
        Height = 17
        Caption = 'radix sort'
        TabOrder = 7
      end
      object CheckBox10: TCheckBox
        Left = 131
        Top = 87
        Width = 115
        Height = 17
        Caption = 'counting sort'
        TabOrder = 8
      end
    end
    object Button1: TButton
      Left = 162
      Top = 423
      Width = 75
      Height = 25
      Caption = 'run'
      TabOrder = 6
      OnClick = Button1Click
    end
    object Memo1: TMemo
      Left = 16
      Top = 454
      Width = 249
      Height = 195
      Lines.Strings = (
        'Memo1')
      ScrollBars = ssVertical
      TabOrder = 7
    end
    object CheckBox6: TCheckBox
      Left = 19
      Top = 358
      Width = 182
      Height = 17
      Caption = 'quick sort (recursion)'
      TabOrder = 8
    end
    object CheckBox11: TCheckBox
      Left = 32
      Top = 423
      Width = 97
      Height = 25
      Caption = 'ech print'
      TabOrder = 9
    end
  end
  object Panel2: TPanel
    Left = 281
    Top = 0
    Width = 769
    Height = 663
    Align = alClient
    TabOrder = 1
    ExplicitWidth = 767
    ExplicitHeight = 655
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 767
      Height = 661
      ActivePage = TabSheet2
      Align = alClient
      TabOrder = 0
      ExplicitWidth = 765
      ExplicitHeight = 653
      object TabSheet1: TTabSheet
        Caption = 'Chart'
        object Chart1: TChart
          Left = 0
          Top = 0
          Width = 759
          Height = 631
          Title.Text.Strings = (
            'TChart')
          Align = alClient
          TabOrder = 0
          DefaultCanvas = 'TGDIPlusCanvas'
          ColorPaletteIndex = 13
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'Data'
        ImageIndex = 1
        object Label6: TLabel
          Left = 16
          Top = 29
          Width = 61
          Height = 21
          Caption = 'selection'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label7: TLabel
          Left = 160
          Top = 29
          Width = 48
          Height = 21
          Caption = 'bubble'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label8: TLabel
          Left = 305
          Top = 29
          Width = 61
          Height = 21
          Caption = 'insertion'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label9: TLabel
          Left = 305
          Top = 298
          Width = 34
          Height = 21
          Caption = 'heap'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label10: TLabel
          Left = 456
          Top = 298
          Width = 34
          Height = 21
          Caption = 'radix'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label11: TLabel
          Left = 608
          Top = 292
          Width = 61
          Height = 21
          Caption = 'counting'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label12: TLabel
          Left = 456
          Top = 29
          Width = 122
          Height = 21
          Caption = 'merge (recurtion)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label13: TLabel
          Left = 609
          Top = 29
          Width = 117
          Height = 21
          Caption = 'merge (iteration)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label14: TLabel
          Left = 16
          Top = 298
          Width = 114
          Height = 21
          Caption = 'quick (recurtion)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label15: TLabel
          Left = 160
          Top = 298
          Width = 109
          Height = 21
          Caption = 'quick (iteration)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Memo2: TMemo
          Left = 16
          Top = 56
          Width = 129
          Height = 190
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo2')
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 0
        end
        object Memo3: TMemo
          Left = 160
          Top = 56
          Width = 129
          Height = 190
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo2')
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 1
        end
        object Memo4: TMemo
          Left = 305
          Top = 56
          Width = 137
          Height = 190
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo2')
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 2
        end
        object Memo5: TMemo
          Left = 456
          Top = 56
          Width = 137
          Height = 190
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo2')
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 3
        end
        object Memo6: TMemo
          Left = 608
          Top = 56
          Width = 137
          Height = 190
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo2')
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 4
        end
        object Memo7: TMemo
          Left = 16
          Top = 325
          Width = 129
          Height = 190
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo2')
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 5
        end
        object Memo8: TMemo
          Left = 160
          Top = 325
          Width = 129
          Height = 190
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo2')
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 6
        end
        object Memo9: TMemo
          Left = 305
          Top = 325
          Width = 137
          Height = 190
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo2')
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 7
        end
        object Memo10: TMemo
          Left = 456
          Top = 325
          Width = 137
          Height = 190
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo2')
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 8
        end
        object Memo11: TMemo
          Left = 607
          Top = 325
          Width = 137
          Height = 190
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo2')
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 9
        end
      end
    end
  end
end
