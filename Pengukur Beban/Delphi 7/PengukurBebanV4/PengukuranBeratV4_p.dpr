program PengukuranBeratV4_p;

uses
  Forms,
  frmPengukurBebanV4_u in 'frmPengukurBebanV4_u.pas' {Form1};

{$R *.RES}

begin
  Application.Initialize;
  Application.Title := 'TComPort ver. 2.10 example';
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
