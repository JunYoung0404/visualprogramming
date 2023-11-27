# WinUI3로 펜만들기

1.펜을 만든다.
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/9557befb-3a20-4eb9-aa50-b2f3cef6d30f)

2.펜의 굵기를 슬라이드 바로 조절 할 수 있다.
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/da37dedc-6162-4dd8-9591-04af4128ecfb)

3.펜의 색상을 색상표로 선택 할 수있다.
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/84490246-cb01-405c-b63d-0de25a833fca)

4.슬라이드와 색상표를 버튼을 통해서, Enable 및 Disable 시킬 수 있다.
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/d8d438c6-0f98-4dd3-acef-65b9ff01d79a)

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

# 마지막 줄에 자가 채점 점수
## 1번 성공 +70점
## 2번 성공 +10점
## 3번 성공 +10점
## 4번 성공 +10점

## 총점:100점

