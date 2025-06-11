object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 555
  ClientWidth = 673
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 673
    Height = 555
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 0
    ExplicitWidth = 671
    ExplicitHeight = 547
    object TabSheet1: TTabSheet
      Caption = 'Given Infix'
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 665
        Height = 525
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 663
        ExplicitHeight = 517
        object Label4: TLabel
          Left = 192
          Top = 32
          Width = 48
          Height = 21
          Caption = 'infix = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label6: TLabel
          Left = 175
          Top = 151
          Width = 65
          Height = 21
          Caption = 'postfix = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label5: TLabel
          Left = 182
          Top = 81
          Width = 58
          Height = 21
          Caption = 'prefix = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Memo4: TMemo
          Left = 246
          Top = 148
          Width = 387
          Height = 53
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo4')
          ParentFont = False
          TabOrder = 0
        end
        object Memo3: TMemo
          Left = 246
          Top = 78
          Width = 387
          Height = 51
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo3')
          ParentFont = False
          TabOrder = 1
        end
        object Edit2: TEdit
          Left = 246
          Top = 29
          Width = 387
          Height = 29
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          Text = 'A*B^C+D'
        end
        object Button4: TButton
          Left = 38
          Top = 150
          Width = 121
          Height = 25
          Caption = 'Infix to Postfix'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          OnClick = Button4Click
        end
        object Button3: TButton
          Left = 38
          Top = 80
          Width = 121
          Height = 25
          Caption = 'Infix to Prefix'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          OnClick = Button3Click
        end
      end
      object Memo8: TMemo
        Left = 38
        Top = 240
        Width = 595
        Height = 241
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        Lines.Strings = (
          'Memo8')
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 1
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Given Prefix'
      ImageIndex = 1
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 665
        Height = 525
        Align = alClient
        TabOrder = 0
        object Label1: TLabel
          Left = 174
          Top = 24
          Width = 58
          Height = 21
          Caption = 'prefix = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label2: TLabel
          Left = 184
          Top = 73
          Width = 48
          Height = 21
          Caption = 'infix = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label3: TLabel
          Left = 167
          Top = 141
          Width = 65
          Height = 21
          Caption = 'postfix = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Edit1: TEdit
          Left = 238
          Top = 21
          Width = 403
          Height = 29
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          Text = '+*A^BCD'
        end
        object Button1: TButton
          Left = 30
          Top = 72
          Width = 121
          Height = 25
          Caption = 'Prefix to Infix'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = Button1Click
        end
        object Memo1: TMemo
          Left = 238
          Top = 70
          Width = 403
          Height = 51
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo1')
          ParentFont = False
          TabOrder = 2
        end
        object Memo2: TMemo
          Left = 238
          Top = 138
          Width = 403
          Height = 55
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo2')
          ParentFont = False
          TabOrder = 3
        end
        object Button2: TButton
          Left = 30
          Top = 140
          Width = 121
          Height = 25
          Caption = 'Prefix to Postfix'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          OnClick = Button2Click
        end
        object Memo9: TMemo
          Left = 30
          Top = 240
          Width = 611
          Height = 257
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo9')
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 5
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Given Postfix'
      ImageIndex = 2
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 665
        Height = 525
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 663
        ExplicitHeight = 517
        object Label7: TLabel
          Left = 182
          Top = 149
          Width = 58
          Height = 21
          Caption = 'prefix = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label9: TLabel
          Left = 192
          Top = 76
          Width = 48
          Height = 21
          Caption = 'infix = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Label10: TLabel
          Left = 175
          Top = 27
          Width = 65
          Height = 21
          Caption = 'postfix = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object Button6: TButton
          Left = 40
          Top = 75
          Width = 121
          Height = 25
          Caption = 'Postfix to Infix'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = Button6Click
        end
        object Memo6: TMemo
          Left = 246
          Top = 146
          Width = 379
          Height = 55
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo6')
          ParentFont = False
          TabOrder = 1
        end
        object Memo5: TMemo
          Left = 246
          Top = 73
          Width = 379
          Height = 56
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo5')
          ParentFont = False
          TabOrder = 2
        end
        object Edit3: TEdit
          Left = 246
          Top = 24
          Width = 379
          Height = 29
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          Text = 'ABC^*D+'
        end
        object Button5: TButton
          Left = 40
          Top = 148
          Width = 121
          Height = 25
          Caption = 'Postfix to Prefix'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          OnClick = Button5Click
        end
        object Memo7: TMemo
          Left = 40
          Top = 252
          Width = 585
          Height = 245
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          Lines.Strings = (
            'Memo7')
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 5
        end
      end
    end
  end
end
