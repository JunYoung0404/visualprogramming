# 	MFC에서 제일 간단한 멀티테스킹 예제를 구현하시오.

## 1. 'A'버튼을 누르면 "안녕하세요!!"라는 문구가 화면에 출력됩니다.
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/dfc7e360-e872-4381-8f5c-01153b7ea62f)

## 코드

```
if (pMsg->message == WM_KEYDOWN) {
		if (pMsg->wParam == 'A') {
	MessageBox(L"안녕하세요!!");
		}
}
```
## 설명
1. 키를 눌렀을때 이벤트가 발생해야 하므로 WM_KEYDOWN을 사용해준다.
2. 만약 A를 눌렀을때
3. 메세지 박스에 "안녕하세요!!"가 출력되도록 한다. L은 유니코드이다.

## 2. 'B'버튼을 누르면 랜덤위치로 사각형을 화면에 출력해줍니다.
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/a2442462-9158-4241-98d7-fb7e1b9acf9b)



## 코드
```
if (pMsg->wParam == 'B') {
			 CClientDC dc(this);

			 
			 CRect clientRect;
			 GetClientRect(&clientRect);

			 
			 int width = 60; 
			 int height = 40; 
			 int x = rand() % (clientRect.Width() - width) + 1; 
			 int y = rand() % (clientRect.Height() - height) + 1; 

			 
			 dc.Rectangle(x, y, x + width, y + height);
		
```
## 설명
1. B를 누른게 참이면
2. 랜덤한 위치를 생성해준다.
3. dc객체를 사용하여 x,y좌표에 시작하는 사각형을 그려준다.
4. CClientDC dc(this)는 dc를 정의해준다.
5. CRect clientRect,GetClientRect(&clientRect)  윈도우 클라이언트 영역의 가로와 세로 크기를 얻는다.
6. int 부분은 사각형의 크기와 위치를 설정합니다.


#### 소감 및 후반기 수업에 대한 각오!
처음 멀티태스킹을 하려다 보니 어려웠는데 수업시간에 배운것과 교수님이 설명해주신 멀티쓰레드를 잘 이용해보고 모르는것은 Chat gpt와 카페를 찾아가보면서 공부해보니 다른 예제를 만들어볼수있었습니다. 다음번에는 버튼을 클릭하면 다른 이벤트가 처리될수있도록 공부해보겠습니다. 
 중간고사도 쳤고 사람이 조금 방심해질 수 있다고 생각합니다. 게임도 하고 싶고 유튜브도 많이 보고 싶고 잡생각도 많이 날 수 있고 하지만 이렇게 중간고사 끝났다고 놀고만 있지 않고 아직 기말고사도 남았으니 MFC 수업에 조금 더 집중하고 열심히 공부할 수 있도록 노력하겠습니다.
