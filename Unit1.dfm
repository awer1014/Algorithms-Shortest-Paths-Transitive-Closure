object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Shortest Paths & Transitive Closure Made by W.R_Chen'
  ClientHeight = 589
  ClientWidth = 725
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 233
    Top = 0
    Height = 589
    ExplicitLeft = 392
    ExplicitTop = 264
    ExplicitHeight = 100
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 233
    Height = 589
    ActivePage = TabSheet1
    Align = alLeft
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Input Control'
      object Label2: TLabel
        Left = 16
        Top = 61
        Width = 72
        Height = 13
        Caption = 'range(w(e)) = '
      end
      object Label3: TLabel
        Left = 16
        Top = 101
        Width = 50
        Height = 13
        Caption = 'if(w(e)) > '
      end
      object Label4: TLabel
        Left = 16
        Top = 141
        Width = 36
        Height = 13
        Caption = 'w(e) = '
      end
      object Label5: TLabel
        Left = 16
        Top = 181
        Width = 63
        Height = 13
        Caption = 'Source no. ='
      end
      object Label1: TLabel
        Left = 16
        Top = 21
        Width = 17
        Height = 13
        Caption = 'n ='
      end
      object Button1: TButton
        Left = 134
        Top = 230
        Width = 75
        Height = 25
        Caption = 'Read G'
        TabOrder = 0
        OnClick = Button1Click
      end
      object Edit1: TEdit
        Left = 88
        Top = 18
        Width = 121
        Height = 21
        TabOrder = 1
        Text = '10'
      end
      object Edit2: TEdit
        Left = 88
        Top = 58
        Width = 121
        Height = 21
        TabOrder = 2
        Text = '1000'
      end
      object Edit3: TEdit
        Left = 88
        Top = 98
        Width = 121
        Height = 21
        TabOrder = 3
        Text = '1000'
      end
      object Edit4: TEdit
        Left = 88
        Top = 138
        Width = 121
        Height = 21
        TabOrder = 4
        Text = '999999'
      end
      object CheckBox1: TCheckBox
        Left = 31
        Top = 234
        Width = 97
        Height = 17
        Caption = 'Echo Print G'
        Checked = True
        State = cbChecked
        TabOrder = 5
      end
      object CheckBox2: TCheckBox
        Left = 31
        Top = 257
        Width = 97
        Height = 17
        Caption = 'Undirected G '
        Checked = True
        State = cbChecked
        TabOrder = 6
      end
      object Button3: TButton
        Left = 16
        Top = 330
        Width = 153
        Height = 25
        Caption = 'Single Source All Destinations'
        TabOrder = 7
        OnClick = Button3Click
      end
      object CheckBox3: TCheckBox
        Left = 31
        Top = 280
        Width = 97
        Height = 17
        Caption = 'Print Results'
        Checked = True
        State = cbChecked
        TabOrder = 8
      end
      object Edit5: TEdit
        Left = 88
        Top = 178
        Width = 121
        Height = 21
        TabOrder = 9
        Text = '0'
      end
      object Button4: TButton
        Left = 16
        Top = 369
        Width = 153
        Height = 25
        Caption = 'All Pairs'
        TabOrder = 10
        OnClick = Button4Click
      end
      object Button5: TButton
        Left = 16
        Top = 408
        Width = 153
        Height = 25
        Caption = 'Transitive Closure'
        TabOrder = 11
        OnClick = Button5Click
      end
      object Button2: TButton
        Left = 134
        Top = 276
        Width = 75
        Height = 25
        Caption = 'Generate G'
        TabOrder = 12
        OnClick = Button2Click
      end
    end
  end
  object PageControl2: TPageControl
    Left = 236
    Top = 0
    Width = 489
    Height = 589
    ActivePage = TabSheet2
    Align = alClient
    TabOrder = 1
    object TabSheet2: TTabSheet
      Caption = 'G'#39's adjacent matrix'
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 481
        Height = 561
        Align = alClient
        TabOrder = 0
        RowHeights = (
          24
          24
          24
          24
          24)
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'G in adjacent matrix'
      ImageIndex = 1
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 481
        Height = 561
        Align = alClient
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'SSAD'
      ImageIndex = 2
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 525
      ExplicitHeight = 554
      object StringGrid2: TStringGrid
        Left = 0
        Top = 0
        Width = 481
        Height = 561
        Align = alClient
        TabOrder = 0
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'All Pairs'
      ImageIndex = 3
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 525
      ExplicitHeight = 554
      object StringGrid3: TStringGrid
        Left = 0
        Top = 0
        Width = 481
        Height = 561
        Align = alClient
        TabOrder = 0
      end
    end
    object TabSheet6: TTabSheet
      Caption = 'Transitive Closure'
      ImageIndex = 4
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 525
      ExplicitHeight = 554
      object StringGrid4: TStringGrid
        Left = 0
        Top = 0
        Width = 481
        Height = 561
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 525
        ExplicitHeight = 554
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 64
    Top = 488
  end
end
