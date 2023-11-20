# 수업시간에 작성한 펜을 MyPen으로 작성하고 코드를 GitHub에 올린 후 링크를 제출하시오.
 1. 내가 직접 코딩한 부분 만 파일 명을 적고, 내용을 복사하여 제출하시오.
 2. 작성 소감을 적는다.

MYPen으로 과제 생성
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/28233a18-e962-46c5-a697-8e24295acd4c)

xaml.h부분
```
#include <winrt/Microsoft.Graphics.Canvas.UI.Xaml.h>
#include <winrt/Microsoft.UI.Input.h>
#include <winrt/Microsoft.UI.Xaml.Input.h>

using namespace winrt::Microsoft::UI;
using namespace winrt::Microsoft::Graphics::Canvas::UI::Xaml;

 bool flag;
 float px, py;
 std::vector<float> vx;
 std::vector<float> vy;
```

xaml.cpp
```
using namespace winrt;
using namespace Microsoft::UI::Xaml;

flag = false;
px = 100;
py = 100;

CanvasControl_PointerReleased 부분
 flag = false;
 px = py = 0.0;
 vx.push_back(px);
 vy.push_back(py);

CanvasControl_PointerPressed 부분
flag = true;

CanvasControl_PointerMoved 부분
 CanvasControl canvas = sender.as<CanvasControl>();
 px = e.GetCurrentPoint(canvas).Position().X;
 py = e.GetCurrentPoint(canvas).Position().Y;
 if (flag) {
     vx.push_back(px);
     vy.push_back(py);
     canvas.Invalidate();
 }

CanvasControl_Draw 부분
int n = vx.size();
for (int i = 1; i < n; i++) {
    if (vx[i] == 0 && vy[i] == 0) {
        i++; continue;
    }
    args.DrawingSession().DrawLine(vx[i - 1], vy[i - 1], vx[i], vy[i], Colors::Yellow(), 32);
    args.DrawingSession().FillEllipse(vx[i - 1], vy[i - 1], 16, 16, Colors::Yellow());
    args.DrawingSession().FillEllipse(vx[i], vy[i], 16, 16, Colors::Yellow());
}

```
xaml부분
```
xmlns:canvas="using:Microsoft.Graphics.Canvas.UI.Xaml

<Grid>
    <canvas:CanvasControl Draw="CanvasControl_Draw"
        PointerReleased="CanvasControl_PointerReleased"
        PointerPressed="CanvasControl_PointerPressed"
        PointerMoved="CanvasControl_PointerMoved"
        ClearColor="CornflowerBlue"
        />
</Grid>

```

## 결과
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/abc06518-6205-418a-b230-68f91ad63fed)

### 소감
처음 펜그리기를 수행하다가 xaml부분에서 canvas:CanvasControl을 적어야 하는데 버츄얼을 적어서 못따라가고 있었지만 교수님께서 직접 알려 주셔서 오류를 해결할수있었습니다. 하나하나 코딩할때 집중해가면서 틀린부분은 없는지 확인하고 수업시간에 집중하여서 코딩해야겠다고 다시한번 느끼게 되었고 
과제를 하면서 다시 혼자 해보니깐 또 안되는 부분이 있어서 주변친구에게 도움을 받아 과제를 해결할수있었습니다. xaml.h부분과 cpp,xaml 이리저리 움직이면서 코드를 작성해서 엄청 헷갈리지만 집중하여서 자신의 코드로 만들어 보겠습니다.
    
