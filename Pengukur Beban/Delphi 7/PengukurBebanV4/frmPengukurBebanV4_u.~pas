unit frmPengukurBebanV4_u;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ExtCtrls, CPort, CPortCtl, TeeProcs, TeEngine, Chart, Series,
  Variants, strutils, mmsystem, Buttons;


type
  TForm1 = class(TForm)
    ComPort: TComPort;
    Memo: TMemo;
    Button_Start: TButton;
    Button_Settings: TButton;
    Edit_Data: TEdit;
    TimbanganV2: TLabel;
    Timer1: TTimer;
    Label1: TLabel;
    Label2: TLabel;
    Button_Clear: TButton;
    Pembacaan: TMemo;
    Data: TLabel;
    Label3: TLabel;
    Chart1: TChart;
    Series1: TLineSeries;
    procedure Button_StartClick(Sender: TObject);
    procedure Button_SettingsClick(Sender: TObject);
    procedure ComPortOpen(Sender: TObject);
    procedure ComPortClose(Sender: TObject);
    procedure ComPortRxChar(Sender: TObject; Count: Integer);
    procedure Timer1Timer(Sender: TObject);
    procedure Button_ClearClick(Sender: TObject);

  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  berat: Double;
  a : integer = 1;

implementation

{$R *.DFM}

function CustomStrToFloat(bro : variant): double;
begin
  if (bro = null) or (Trim(bro) = '') then Result := 0
  else Result := StrToFloat(bro);
end;

function IfNull( const Value, Default : OleVariant ) : OleVariant;
begin
  if Value = NULL then
    Result := Default
  else
    Result := Value;
end;

//Main Line
procedure TForm1.Button_StartClick(Sender: TObject);
begin
  if ComPort.Connected then
    ComPort.Close
  else
    ComPort.Open;
  Chart1.Series[0].AddXY(10, 20, '', clTeeColor);

end;


procedure TForm1.Button_SettingsClick(Sender: TObject);
begin
  ComPort.ShowSetupDialog;
end;


procedure TForm1.ComPortOpen(Sender: TObject);
begin
  Button_Start.Caption := 'Stop';
  Memo.Lines.Append('No.,Timestamp,Berat');
  a := a+1;
  
end;


procedure TForm1.ComPortClose(Sender: TObject);
begin
  if Button_Start <> nil then
    Button_Start.Caption := 'Start';
end;


procedure TForm1.ComPortRxChar(Sender: TObject; Count: Integer);
var str, tstr : String;
  f : textfile;
begin
  assignfile(f,'data.csv'); //bikin file csv dari var 'f'
  rewrite(f); //biar bisa timpa file csv dari var 'f'

  ComPort.ReadStr(str, Count);
  Memo.Text := Memo.Text + inttostr(a)+ ',' + FormatDateTime('hh:nn:ss:zzz',now) + ',' + str;

  Pembacaan.Text := Pembacaan.Text + str;
  SendMessage(Pembacaan.Handle, WM_VSCROLL, SB_BOTTOM, 0);
  Edit_Data.Text := str;

  writeln(f,Memo.text); //isi .csv pake memo
  a := a+1;
  closefile(f); //tutup file csv dari var 'f'

  tstr := trim(str);
  chart1.Series[0].AddXY(a, CustomStrToFloat(tstr),'',clred) ;

end;


procedure TForm1.Timer1Timer(Sender: TObject);
begin
  Label1.Caption:='Date  '+ FormatdateTime('d/mm/yyyy',Date);
  Label2.Caption:='Time  '+ FormatDateTime('hh:nn:ss',Time);
end;

procedure TForm1.Button_ClearClick(Sender: TObject);
begin
  Edit_data.text:='';
  Pembacaan.Text:='';
  Memo.Text:='';
end;






end.
