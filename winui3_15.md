# WinUI3에서 펜 프로그램의 작성과 (데이터를 저장하고 읽어오기 기능의 추가)

WinUI3에서 펜 프로그램의 작성과 저장을 구현하시오.
1. 펜을 만든다.
   
2. 굵기를 조절할 수 있다.
   
3. 색상을 선택할 수 있다.
   
4. 슬라이더바와 칼라선택 창을 보이거나 지울 수 있다.

추가내용

5. 데이터를 저장할 수 있다.

6. 데이터를 읽을 수 있다.

### 채점기준
1. 교과서를 따라 해서 성공하였다. -> 성공하였습니다.
   
2. 교과서에 다른 특징을 추가하였다. (설명을 추가해 주세요.)
   
저는 각 Write,Read,Clear버튼에 테투리와 안의 색상을 추가해 보았습니다.
ControlTemplate 속성을 사용하여 간단한 스타일을 적용 할 수 있고 본 코드는
버튼의 배경색, 테두리 색상, 테두리 두께, 내부 여백 등을 수정할 수 있습니다.
 ```
<Button x:Name="myWrite" Click="myWrite_Click" >
    <Button.Template>
        <ControlTemplate TargetType="Button">
            <Border Background="LightBlue" BorderBrush="DarkBlue" BorderThickness="2" Padding="10" CornerRadius="5">
                <ContentPresenter HorizontalAlignment="Center" VerticalAlignment="Center"/>
             </Border>
        </ControlTemplate>
    </Button.Template>
    Write
</Button>
```
4. 저장하고 읽는 것을 교과서 보다 향상 시켰다.

처음에는 저장과읽고 삭제가 엄청 느렸었는데 저는 누르면 즉시 반영하도록 만들어 보았습니다. 
CanvasControl_Draw부분에 Invalidate();를 추가하여 누르면 즉시 반영되도록 향상 시켜보았습니다.
```
canvas.Invalidate(); // 추가
```
# 1~4번 코드설명
## CPP
cpp헤더부분
```
using namespace winrt;
using namespace Microsoft::UI::Xaml;
```

cpp MainWindow부분
```
 flag = false;
 px = 100;
 py = 100;
 mySize = 16;
 IsChecked = true;
```
cpp 중간 부분
```
struct  winrt::Windows::UI::Color myCol = winrt::Microsoft::UI::Colors::Green();
```

ColorPicker_Click부분
```
 if (IsChecked)
 {
     IsChecked = FALSE;
     ColorPicker().Label(L"Disable");

     slider().Visibility(Visibility::Collapsed);
     colorPanel().Visibility(Visibility::Collapsed);
 }
 else
 {
     IsChecked = TRUE;
     ColorPicker().Label(L"Enable");

     slider().Visibility(Visibility::Visible);
     colorPanel().Visibility(Visibility::Visible);
 }
```
ColorPicker_ColorChanged
```
myCol = args.NewColor();
```
CanvasControl_PointerPressed
```
flag = true;
```
CanvasControl_PointerReleased
```
  flag = false;
  px = py = 0.0;
  vx.push_back(px);
  vy.push_back(py);
  col.push_back(myCol);
  size.push_back(mySize);
```

CanvasControl_PointerMoved
```
 CanvasControl canvas = sender.as<CanvasControl>();
 px = e.GetCurrentPoint(canvas).Position().X;
 py = e.GetCurrentPoint(canvas).Position().Y;
 if (flag) {
     vx.push_back(px);
     vy.push_back(py);
     col.push_back(myCol);
     size.push_back(mySize);
     canvas.Invalidate();
 }
```
 CanvasControl_Draw
 ```
 CanvasControl canvas = sender.as<CanvasControl>();
int n = vx.size();
if (n <= 2) return;

for (int i = 1; i < n; i++) {
    if (vx[i] == 0.0 && vy[i] == 0.0) {
        i++; continue;
    }
    args.DrawingSession().DrawLine(vx[i - 1], vy[i - 1], vx[i], vy[i], col[i], size[i]);
    args.DrawingSession().FillCircle(vx[i - 1], vy[i - 1], size[i] / 2, col[i]);
    args.DrawingSession().FillCircle(vx[i], vy[i], size[i] / 2, col[i]);
}
```
## xaml.h
헤더부분
```
#include <winrt/Microsoft.Graphics.Canvas.UI.Xaml.h>
#include <winrt/Microsoft.UI.Xaml.Input.h>
#include <winrt/Microsoft.UI.Input.h>

using namespace winrt::Microsoft::UI;
using namespace winrt::Microsoft::Graphics::Canvas::UI::Xaml;
```
struct MainWindow : MainWindowT<MainWindow>부분
```
 bool flag;
 bool IsChecked;
 float px;
 float py;
 float mySize;
 std::vector<float> vx;
 std::vector<float> vy;
 std::vector<struct winrt::Windows::UI::Color> col;
 std::vector<float> size;
```

## xaml부분
헤더부분
```
xmlns:canvas="using:Microsoft.Graphics.Canvas.UI.Xaml"
```
Grid 부분
```
<Grid.RowDefinitions>
    <RowDefinition Height="60"/>
    <RowDefinition Height="590"/>
</Grid.RowDefinitions>
<Grid.ColumnDefinitions>
    <ColumnDefinition Width="600"/>
    <ColumnDefinition Width="400"/>
</Grid.ColumnDefinitions>

<StackPanel Orientation="Horizontal" HorizontalAlignment="Center" VerticalAlignment="Center">
    <Slider x:Name="slider" AutomationProperties.Name="simpleSlider" Width="200" Grid.Column="0" Grid.Row="0" ValueChanged="Slider_ValueChanged"/>
</StackPanel>

<canvas:CanvasControl Grid.Column="0" Grid.Row="1"
                      PointerPressed="CanvasControl_PointerPressed"
                      PointerReleased="CanvasControl_PointerReleased"
                      PointerMoved="CanvasControl_PointerMoved"
                      Draw="CanvasControl_Draw"
                      ClearColor="CornflowerBlue"/>

<AppBarToggleButton Grid.Column="1" Grid.Row="0"
                    x:Name="ColorPicker" Icon="Shuffle" IsChecked="True"
                    Label="Enable" Click="ColorPicker_Click"/>

<Border Grid.Column="1" Grid.Row="1" x:Name="colorPanel" Visibility="Visible">
    <ColorPicker
        ColorChanged="ColorPicker_ColorChanged"
        ColorSpectrumShape="Ring"
        IsMoreButtonVisible="False"
        IsColorSliderVisible="True"
        IsColorChannelTextInputVisible="True"
        IsHexInputVisible="True"
        IsAlphaEnabled="False"
        IsAlphaSliderVisible="True"
        IsAlphaTextInputVisible="True"/>
</Border>
```

# 5~6번 코드설명
## xaml
```
<Button x:Name="myWrite" Click="myWrite_Click">Write</Button>
<Button x:Name="myRead" Click="myRead_Click">Read</Button>
<Button x:Name="myClear" Click="myClear_Click">Clear</Button>
```
## CPP
myWrite_Click부분
```
 // Open for write
 FILE* fw;
 errno_t err;
 err = fopen_s(&fw, "C:/Users/PC/source/repos/my.txt", "w");// +, ccs = UTF - 8");
 if (err == 0)
 {
     MessageBox(NULL, L"The file was opened\n", L"hi1", NULL);
     int num = vx.size();
     fprintf_s(fw, "%d\n", num);
     for (int i = 0; i < num; i++) {
         fprintf_s(fw, "%f %f %hhu %hhu %hhu %hhu %f\n", vx[i], vy[i],
             col[i].A, col[i].B, col[i].G, col[i].R, size[i]);
     }
     fclose(fw);
     vx.clear();
     vy.clear();
     col.clear();
     size.clear();
 }
 else  MessageBox(NULL, L"The file was not opened\n", L"hi2", NULL);
```
myRead_Click
```
// Open for write
FILE* fr;
errno_t err;
err = fopen_s(&fr, "C:/Users/PC/source/repos/my.txt", "r");// +, ccs = UTF - 8");
if (err == 0)
{
    MessageBox(NULL, L"The file was opened\n", L"hi1", NULL);
    int num;

    float vx1, vy1, size1;
    unsigned char colA, colB, colG, colR;

    fscanf_s(fr, "%d", &num);
    for (int i = 0; i < num; i++) {
        fscanf_s(fr, "%f %f %hhu %hhu %hhu %hhu %f ", &vx1, &vy1, &colA, &colB, &colG, &colR, &size1);
        vx.push_back(vx1);
        vy.push_back(vy1);
        myCol.A = colA;
        myCol.B = colB;
        myCol.G = colG;
        myCol.R = colR;
        col.push_back(myCol);
        size.push_back(size1);
    }
    fclose(fr);
    MessageBox(NULL, L"The file closed\n", L"hi1", NULL);
    CanvasControl_PointerReleased(NULL, NULL);
}
else  MessageBox(NULL, L"The file was not opened\n", L"hi2", NULL);
```
myClear_Click부분
```
 vx.clear();
 vy.clear();
 col.clear();
 size.clear();
 flag = false;
 px = 100;
 py = 100;
 mySize = 16;
```
## Clear를 즉시 지우기 위한 코드
CanvasControl_Draw부분
```
canvas.Invalidate(); // 추가
```

# 실행결과 이미지 1~4
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/aeead8f3-8e4b-429a-a075-ce931ca20348)
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/a8158f1b-38eb-4cc4-9dc6-31dbd7733681)

## 저장
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/f3da598d-af75-4ae8-a1fc-4150c3172183)

## 불러오기
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/9500bd7d-d081-47ee-8be6-20e9cc3889ea)
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/a3db0776-6d39-4853-9fc8-4624584380fc)


## 즉시 삭제하기
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/87eaa4d2-5cff-41f8-a048-2e1a31a1585f)
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/8d47c194-120c-47f3-8c22-d97c625aad83)


