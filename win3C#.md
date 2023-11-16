# WinUI3와 Win2D를 활용하여 배너를 만드시오.
## 1. WinUI3와 Win2D를 활용하여 배너를 만드시오.

### 코드

* CanvasControl_Draw 위에 적어주면 된다.
```
float a1, a2 = 400;
```
* CPP 부분 CanvasControl_Draw 새로운 이벤트 처리부분에서 폰트 크기를 수정해주는 부분이다.
```
 CanvasTextFormat format;
 CanvasControl canvas = sender.as <CanvasControl>();
 format.HorizontalAlignment(CanvasHorizontalAlignment::Center);
 format.VerticalAlignment(CanvasVerticalAlignment::Center);
 format.FontSize(72.0f);
 format.FontFamily(L"Segoe UI Semibold");
```
* 배너처럼 글자가 왼쪽에서 오른쪽으로 일정한 속도로 움직여 주는 코드이다.
```
 a1 += 1.0;
 if (a1 > 1000) a1 = 0;
 args.DrawingSession().DrawText(L"I Love ANU", a1,a2, winrt::Microsoft::UI::Colors::Blue(), format);
 canvas.Invalidate();
```

### 결과
https://github.com/JunYoung0404/visualprogramming/assets/50895748/158525e4-bdba-4c51-ad0e-b3eee5b81102

## 2. 두 수를 곱하는 프로그램을 WinUI3와 C#을 활용하여 작성하시오.

### 코드
xaml부분
```
<StackPanel Orientation="Vertical" HorizontalAlignment="Center" VerticalAlignment="Center">
<StackPanel Orientation="Vertical" HorizontalAlignment="Center" VerticalAlignment="Center">
        <TextBox x:Name="a" Width="200" Margin="10"/>
        <TextBox x:Name="b" Width="200" Margin="10"/>
        <Button Content="*" Click="Button_Click" Margin="10"/>
        <TextBox x:Name="c" Width="200" Margin="10" IsReadOnly="True"/>
    </StackPanel>
</StackPanel>
```
cs부분
```
* 헤더파일부분에 추가
using Microsoft.UI.Windowing;

*public 부분에 추가
IntPtr hWnd = WinRT.Interop.WindowNative.GetWindowHandle(this);
var windowId = Win32Interop.GetWindowIdFromWindow(hWnd);
var appWindow = AppWindow.GetFromWindowId(windowId);
appWindow.Title = "계산기"; // 타이틀
appWindow.Move(new PointInt32(100, 100)); // 창 위치
appWindow.Resize(new SizeInt32 { Width = 320, Height = 320 });

*private 부분에 추가
 if (double.TryParse(a.Text, out double v1) &&
     double.TryParse(b.Text, out double v2))
 {
     double r = v1 * v2;
     c.Text = r.ToString();
 }
 else
 {
     c.Text = "잘못된 입력";
 }
```
### 결과 이미지
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/03b0f9b4-6bb0-4152-ba58-aab5771da490)
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/878286e3-c2a9-45fe-896b-7df011ad1ae8)

잘못 입력한 경우

![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/8e7cc197-9262-4107-a281-41237027e3f3)



