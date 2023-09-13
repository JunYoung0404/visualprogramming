# 비쥬얼프로그래밍 팀 프로젝트
### 프로젝트명 : SDI 기반으로 펜을 만들고 읽고 저장할 수 있도록 하시오.
### 프로젝트 내용 : 
SDI 기반으로 펜을 만들고 읽고 저장할 수 있도록 하시오.

펜의 굵기는 16으로 하고, 펜의 색상은 푸른색으로 한다.

1. 메뉴에서 굵기를 선정할 수 있다.

2. 칼라를 선택할 수 있다.
### 팀 구성 

|학년|학과|이름|
|------|---|---|
|3|컴퓨터공학과|✔김준영|
|3|컴퓨터공학과|추승범|
|3|생약자원학과|진민규|

1.메뉴에서 굵기를 선정할 수 있다.
--------------------------------
##### 메뉴에서 1 을 선택했을때 

![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/46f83aa0-6fd6-490f-a727-d56854f46b94)

##### 메뉴에서 4 을 선택했을때 

![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/0136654d-fbe7-4141-8b19-55e4edc35b95)

##### 메뉴에서 8 을 선택했을때 

![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/9527bdb8-c064-40dc-baa6-24fa4990336a)

##### 메뉴에서 16 을 선택했을때 

![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/feec8e85-b8b0-4c7b-945d-5a204fb30fb7)

##### 메뉴에서 32 을 선택했을때 

![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/3f44f2d0-b396-48c7-a193-e19f32b9ae16)

### 코드
```
void CPenView::OnSize1()
{
	Size = 1; //원하는 굵기의 숫자를 적어준다.

}

void CPenView::OnSize4()
{
	Size = 4; //원하는 굵기의 숫자를 적어준다.

}

void CPenView::OnSize8()
{
	Size = 8; //원하는 굵기의 숫자를 적어준다.

}

void CPenView::OnSize16()
{
	Size = 16; //원하는 굵기의 숫자를 적어준다.

}

void CPenView::OnSize32()
{
	Size = 32; //원하는 굵기의 숫자를 적어준다.

```

2.칼라를 선택할 수 있다.
--------------------------------
##### select 색상 선택 기능 
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/0d61436f-13ba-43c3-9187-40a71c2fa341)

![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/8170e385-cd5a-4f15-b8e7-8d343c8e5472)

##### 여러가지 색상 표시
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/233b37d5-9183-4d0d-b850-36a703346941)


### 코드
```
void CPenView::OnMouseMove(UINT nFlags, CPoint point)
{
	
	if (nFlags == MK_LBUTTON) {
		CPenDoc* pDoc = GetDocument();
		CLine* pLine = new CLine(opnt, point,Size,Col); // RGB 부분을 Col로 바꿔준다.
		pDoc->m_oa.Add(pLine);
		Invalidate(FALSE);
	}
	opnt = point;
	CView::OnMouseMove(nFlags, point);
	
}


void CPenView::OnSelectColor()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		Col = dlg.GetColor();
		
	}
}
```

## 펜의 굵기는 16으로 하고, 펜의 색상은 푸른색으로 하고 저장 할 수 있도록 한다.

##### 펜 굵기 16, 색상 푸른색 선택
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/30bed584-e3c1-4e8a-b7a0-e198dacff211)

##### 다른이름으로 "2팀"으로 저장
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/c3e68c98-3692-4a41-acd8-76da81cb488b)

##### 저장 완료
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/8dc3d434-6f70-4ab9-a25c-31f96e57a778)



# 소감

### 김준영 

저번과는 다르게 그림판에 직접 select를 지정하고 그안에있는 메뉴를 내마음대로 추가해 보는것이 너무 신기했습니다. 조금만 더 배우고 익숙해지면 더 창의적인 프로그램도 만들어 볼 수 있다는 생각이 들었습니다. 초기에는 쉽게 따라갔지만, 난이도가 점점 올라가면서 어려워지는 것을 느꼈습니다. 그러나 다행히 교수님께서 중간중간 못 따라간 학생들을 파악해주시고 직접 알려주시러 와 주셨기 때문에 막힘 없이 수업을 이어나갈 수 있었습니다. 4일 동안 정말 많은 것을 배운 것 같습니다. 이제 이를 잘 정리하고 나만의 것으로 만들어 팀 프로젝트에 열심히 기여하겠습니다. 감사합니다.


### 추승범 

지금까지는 비교적 따라 하기 쉬운 방식으로 MFC를 dialog로 동작하는 코드를 배웠는데 이번 시간에 배운 단일문서기반의 MFC는 수업을 따라가는 것이 약간 힘들었습니다. 사용자 정의 헤더도 만들어야하고 doc나 view에 따로 코딩을 하는 것도 처음이라 조금 헤맸지만 끝나고 완성된 그림판을 보며 나도 이젠 MFC를 이용하여 뭔가 만들 수 있게 되었다는 것에 기분이 좋았습니다. 교수님께서 오늘 했던 그림판 만들기는 어려워서 학생들을 많이 기다려주시고 이끌어주셔서 성공적으로 완성했던 것 같습니다. 앞으로도 남은 학기동안 더 열심히 MFC를 공부해서 나만의 창의적이고 실용성 있는 프로그램을 만들어보고 싶습니다.

### 진민규

MFC는 대화상자기반 dialog와 하나의 창을 사용하는 SDI와 여러개의 창을 사용하는 MDI가 있다 그중에서도 오늘 수업에서는 단일윈도우인 SDI를 사용해 그림판과 더 나아가 펜의 색상과 굵기와 저장을 할수 있는 것을 만들어 보았습니다. 
여태까지 dialog를 이용해 도구를 끌어당겨 도구 안에 코드를 작성해 작동하는 방식은 유니티와 비슷하다고 생각했는데 오늘 SDI는 C++를 사용해 new 키워드를 사용해 객체를 생성하고 또 생성자로 만들어 생성될 때 마다 값이 변경되고 Doc를 불러오는 GetDocument() 함수를 이용해 doc를 불러오고 생성자를 사용해 값을 저장할 때 는 굉장히 많이 쓰이고 다른 코드들에서도 많이 보일 것 같은 부분 같고 이해하기 조금 어려운 부분이라 공부를 더 해야겠다고 생각했습니다. 그래도 이런 작은 코드 조각들이 모여서 그림판 하나를 완성해 보니깐 MFC의 기능들에 대해서도 많이 공부하고 코드를 많이 공부하면 윈도우에 있는 기본 프로그램들은 손쉽게 만들 수 있을 것 같습니다. 앞으로도 열심히 공부하겠습니다! 감사합니다.




