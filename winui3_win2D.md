# WinUI3 에서 Win2D를 활용하여 5가지 이상의 도형이나 글씨를 구현하시오.


# 결과이미지
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/e8ea8920-aea9-413e-af4b-b7241cfd65da)

# 색상 설정 코드
```
using namespace winrt::Microsoft::Graphics::Canvas::UI::Xaml;
struct winrt::Windows::UI::Color col = winrt::Microsoft::UI::Colors::Green();
struct winrt::Windows::UI::Color cso = winrt::Microsoft::UI::Colors::LightPink();
struct winrt::Windows::UI::Color ga = winrt::Microsoft::UI::Colors::DarkOrange();
struct winrt::Windows::UI::Color co = winrt::Microsoft::UI::Colors::Gold();
struct winrt::Windows::UI::Color gaa = winrt::Microsoft::UI::Colors::MediumPurple();
namespace winrt::App1::implementation

```
### 설명
각 색상을 다르게 해주기위해 새로운 이름으로 각각 다른 색상을 지정해주었습니다.

# 새로운 도형 및 텍스트박스 생성 코드
```
args.DrawingSession().DrawEllipse(px, py, 80, 60, col, 8);
args.DrawingSession().DrawText(L"Hello!", px - 25, py - 15,
    winrt::Microsoft::UI::Colors::Yellow());

args.DrawingSession().DrawCircle(150, 150, 100, cso, 5);

args.DrawingSession().FillRoundedRectangle(400, 400, 100,200,20,20,co);

args.DrawingSession().FillEllipse(500, 150, 200, 50, gaa);
args.DrawingSession().FillCircle(500, 150, 100, gaa);
args.DrawingSession().DrawText(L"ANU", 480, 140,
    winrt::Microsoft::UI::Colors::Coral());

args.DrawingSession().FillCircle(700, 400, 100, ga);
args.DrawingSession().DrawText(L"안동대학교", 650,400,
    winrt::Microsoft::UI::Colors::Blue());

args.DrawingSession().DrawText(L"WinUI3", 900, 500,
    winrt::Microsoft::UI::Colors::AntiqueWhite());
```
### 설명
도형은 안을 꽉채운 것을 나타내 주기위해 fill도형들을 사용해 주었고 선만 나타내는 Draw도형들도 사용해 주었습니다. 그리고 Ellipse와Circle을 사용하여 UFO모양 도형을 만들어 보았고 그 안에 "ANU"라는 텍스트도 같이 적용해 보았고 
0텍스트 박스혼자만 사용하여 글씨도 나타내 보았습니다.



# 남은 대학생활의 각오
컴퓨터공학과에서 대학생활을 보내면서 전공에 대한 공부를 집중적으로 하여 나만의 미래를 위해 더 열정적으로 열심히 공부하고, 새로운 지식과 기술을 습득하여 자기 계발에 힘쓰겠습니다 예를 들어 WinUi3, c++ 등과 같은 전공지식을 수업 시간에 열심히 듣고 혼자 예습복습을 하면서 개인 공부하고 모르는 것이 생겻을때는 친구,교수님에게 열정적으로 물어보면서 지식을 습득해 나아가겟습니다. 또한 영어공부를 열심히하여 높은 토익점수도 취득하고 4학년때 취득할수있는 정보처리 기사 공부도 틈틈히 공부 하면서 자격증 취득에 힘쓰겟습니다.  그리고 의사소통 또한 저는 중요하다고 생각하여 친구, 선후배들과 소통 협력을 통해 다양한 경험을 쌓으며 서로의 경험과 아이디어를 나누어 새로운 의사소통 능력을 기르겠습니다.
