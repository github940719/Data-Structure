object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 640
  ClientWidth = 998
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
    Width = 241
    Height = 640
    Align = alLeft
    TabOrder = 0
    ExplicitHeight = 526
    object GroupBox1: TGroupBox
      Left = 18
      Top = 8
      Width = 201
      Height = 249
      Caption = 'run once'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object Label1: TLabel
        Left = 16
        Top = 32
        Width = 37
        Height = 21
        Caption = '|V| = '
      end
      object Label2: TLabel
        Left = 16
        Top = 111
        Width = 182
        Height = 33
        Caption = '(low) edge density (high)'
      end
      object Label6: TLabel
        Left = 16
        Top = 72
        Width = 59
        Height = 21
        Caption = 'range = '
      end
      object CheckBox1: TCheckBox
        Left = 16
        Top = 176
        Width = 75
        Height = 26
        Caption = 'Kruskal'
        TabOrder = 0
      end
      object Edit1: TEdit
        Left = 80
        Top = 29
        Width = 105
        Height = 29
        TabOrder = 1
        Text = '10'
      end
      object TrackBar1: TTrackBar
        Left = 3
        Top = 138
        Width = 182
        Height = 28
        TabOrder = 2
      end
      object CheckBox2: TCheckBox
        Left = 110
        Top = 172
        Width = 59
        Height = 33
        Caption = 'Prim'
        TabOrder = 3
      end
      object Button1: TButton
        Left = 48
        Top = 211
        Width = 89
        Height = 25
        Caption = 'run once'
        TabOrder = 4
        OnClick = Button1Click
      end
      object Edit5: TEdit
        Left = 77
        Top = 64
        Width = 108
        Height = 29
        TabOrder = 5
        Text = '100'
      end
    end
    object GroupBox2: TGroupBox
      Left = 18
      Top = 263
      Width = 201
      Height = 322
      Caption = 'compare running time'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object Label3: TLabel
        Left = 16
        Top = 40
        Width = 75
        Height = 21
        Caption = 'starting |V|'
      end
      object Label4: TLabel
        Left = 16
        Top = 128
        Width = 59
        Height = 21
        Caption = 'step size'
      end
      object Label5: TLabel
        Left = 16
        Top = 171
        Width = 61
        Height = 21
        Caption = '# of data'
      end
      object Label7: TLabel
        Left = 33
        Top = 80
        Width = 44
        Height = 21
        Caption = 'range '
      end
      object Label8: TLabel
        Left = 16
        Top = 209
        Width = 172
        Height = 21
        Caption = '(low) edge density (high)'
      end
      object Edit2: TEdit
        Left = 97
        Top = 37
        Width = 88
        Height = 29
        TabOrder = 0
        Text = '1000'
      end
      object Edit3: TEdit
        Left = 97
        Top = 128
        Width = 88
        Height = 29
        TabOrder = 1
        Text = '1000'
      end
      object Edit4: TEdit
        Left = 97
        Top = 168
        Width = 88
        Height = 29
        TabOrder = 2
        Text = '8'
      end
      object Button2: TButton
        Left = 32
        Top = 278
        Width = 137
        Height = 25
        Caption = 'run and compare'
        TabOrder = 3
        OnClick = Button2Click
      end
      object Edit6: TEdit
        Left = 97
        Top = 83
        Width = 88
        Height = 29
        TabOrder = 4
        Text = '100000'
      end
      object TrackBar2: TTrackBar
        Left = 3
        Top = 236
        Width = 182
        Height = 28
        TabOrder = 5
      end
    end
  end
  object PageControl1: TPageControl
    Left = 241
    Top = 0
    Width = 757
    Height = 640
    ActivePage = TabSheet2
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'dist matrix'
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 749
        Height = 604
        Align = alClient
        TabOrder = 0
        ExplicitLeft = -56
        ExplicitTop = 104
        ExplicitWidth = 320
        ExplicitHeight = 120
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'MST chosen edge'
      ImageIndex = 1
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 749
        Height = 604
        Align = alClient
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'running time chart'
      ImageIndex = 2
      object Chart1: TChart
        Left = 0
        Top = 0
        Width = 749
        Height = 604
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
      end
    end
  end
end
