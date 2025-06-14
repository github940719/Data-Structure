object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 531
  ClientWidth = 886
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
    Width = 886
    Height = 531
    ActivePage = stackQueue
    Align = alClient
    TabOrder = 0
    ExplicitWidth = 884
    ExplicitHeight = 523
    object stackQueue: TTabSheet
      Caption = 'Stack / Queue'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 878
        Height = 129
        Align = alTop
        TabOrder = 0
        ExplicitWidth = 876
        object Label1: TLabel
          Left = 96
          Top = 22
          Width = 177
          Height = 21
          Caption = 'element (positive integer)'
        end
        object Edit1: TEdit
          Left = 295
          Top = 19
          Width = 121
          Height = 29
          TabOrder = 0
          Text = '10'
        end
        object Button1: TButton
          Left = 465
          Top = 21
          Width = 242
          Height = 25
          Caption = 'stack : push / queue : enQueue'
          TabOrder = 1
          OnClick = Button1Click
        end
        object Button2: TButton
          Left = 465
          Top = 73
          Width = 242
          Height = 25
          Caption = 'stack : pop / queue : deQueue'
          TabOrder = 2
          OnClick = Button2Click
        end
        object Button3: TButton
          Left = 341
          Top = 73
          Width = 75
          Height = 25
          Caption = 're-run'
          TabOrder = 3
          OnClick = Button3Click
        end
      end
      object Panel4: TPanel
        Left = 0
        Top = 129
        Width = 878
        Height = 372
        Align = alClient
        TabOrder = 1
        ExplicitWidth = 876
        ExplicitHeight = 364
        object PageControl3: TPageControl
          Left = 1
          Top = 1
          Width = 876
          Height = 370
          ActivePage = TabSheet4
          Align = alClient
          TabOrder = 0
          ExplicitWidth = 874
          ExplicitHeight = 362
          object TabSheet3: TTabSheet
            Caption = 'Linked Stack'
            object Memo1: TMemo
              Left = 0
              Top = 0
              Width = 868
              Height = 334
              Align = alClient
              Lines.Strings = (
                'Memo1')
              ScrollBars = ssBoth
              TabOrder = 0
            end
          end
          object TabSheet4: TTabSheet
            Caption = 'Linked Queue'
            ImageIndex = 1
            object Memo4: TMemo
              Left = 0
              Top = 0
              Width = 868
              Height = 334
              Align = alClient
              Lines.Strings = (
                'Memo4')
              ScrollBars = ssBoth
              TabOrder = 0
            end
          end
        end
      end
    end
    object LinkedList: TTabSheet
      Caption = 'Linked List'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ImageIndex = 1
      ParentFont = False
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 878
        Height = 217
        Align = alTop
        TabOrder = 0
        object Label2: TLabel
          Left = 16
          Top = 12
          Width = 177
          Height = 21
          Caption = 'element (positive integer)'
        end
        object Label3: TLabel
          Left = 16
          Top = 92
          Width = 41
          Height = 21
          Caption = 'target'
        end
        object Label4: TLabel
          Left = 16
          Top = 184
          Width = 117
          Height = 21
          Caption = '# of elements (n)'
        end
        object Label5: TLabel
          Left = 296
          Top = 184
          Width = 40
          Height = 21
          Caption = 'range'
        end
        object Edit2: TEdit
          Left = 16
          Top = 39
          Width = 121
          Height = 29
          TabOrder = 0
          Text = '10'
        end
        object Edit3: TEdit
          Left = 16
          Top = 119
          Width = 121
          Height = 29
          TabOrder = 1
          Text = '10'
        end
        object Button4: TButton
          Left = 160
          Top = 39
          Width = 97
          Height = 25
          Caption = 'insert first'
          TabOrder = 2
          OnClick = Button4Click
        end
        object Button5: TButton
          Left = 280
          Top = 39
          Width = 97
          Height = 25
          Caption = 'insert last'
          TabOrder = 3
          OnClick = Button5Click
        end
        object Button6: TButton
          Left = 160
          Top = 119
          Width = 97
          Height = 25
          Caption = 'search'
          TabOrder = 4
          OnClick = Button6Click
        end
        object Button7: TButton
          Left = 280
          Top = 119
          Width = 193
          Height = 25
          Caption = 'search and insert before'
          TabOrder = 5
          OnClick = Button7Click
        end
        object Button8: TButton
          Left = 496
          Top = 119
          Width = 193
          Height = 25
          Caption = 'search and insert after'
          TabOrder = 6
          OnClick = Button8Click
        end
        object Button9: TButton
          Left = 711
          Top = 119
          Width = 145
          Height = 25
          Caption = 'search and delete'
          TabOrder = 7
          OnClick = Button9Click
        end
        object Edit4: TEdit
          Left = 144
          Top = 181
          Width = 66
          Height = 29
          TabOrder = 8
          Text = '10'
        end
        object Edit5: TEdit
          Left = 350
          Top = 181
          Width = 75
          Height = 29
          TabOrder = 9
          Text = '100'
        end
        object Button10: TButton
          Left = 496
          Top = 183
          Width = 225
          Height = 25
          Caption = 'insert n random numbers last'
          TabOrder = 10
          OnClick = Button10Click
        end
        object Button11: TButton
          Left = 398
          Top = 39
          Width = 75
          Height = 25
          Caption = 'reverse'
          TabOrder = 11
          OnClick = Button11Click
        end
        object Button12: TButton
          Left = 496
          Top = 39
          Width = 75
          Height = 25
          Caption = 're-run'
          TabOrder = 12
          OnClick = Button12Click
        end
      end
      object Panel2: TPanel
        Left = 0
        Top = 217
        Width = 878
        Height = 284
        Align = alClient
        TabOrder = 1
        object PageControl2: TPageControl
          Left = 1
          Top = 1
          Width = 876
          Height = 282
          ActivePage = TabSheet1
          Align = alClient
          TabOrder = 0
          object TabSheet1: TTabSheet
            Caption = 'singly linked list'
            object Memo2: TMemo
              Left = 0
              Top = 0
              Width = 868
              Height = 246
              Align = alClient
              Lines.Strings = (
                'Memo2')
              ScrollBars = ssBoth
              TabOrder = 0
            end
          end
          object TabSheet2: TTabSheet
            Caption = 'doubly linked list'
            ImageIndex = 1
            object Memo3: TMemo
              Left = 0
              Top = 0
              Width = 868
              Height = 246
              Align = alClient
              Lines.Strings = (
                'Memo3')
              ScrollBars = ssBoth
              TabOrder = 0
            end
          end
        end
      end
    end
  end
end
