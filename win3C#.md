# 두 수를 곱하는 프로그램을 WinUI3와 C#을 활용하여 작성하시오.

## 코드
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
## 결과 이미지
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/03b0f9b4-6bb0-4152-ba58-aab5771da490)
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/878286e3-c2a9-45fe-896b-7df011ad1ae8)

잘못 입력한 경우
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/8e7cc197-9262-4107-a281-41237027e3f3)



