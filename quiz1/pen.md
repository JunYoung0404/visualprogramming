# 퀴즈시험
> 1.펜의 굵기를 선택할 수 있다.
> 
> 2.펜의 색상을 선택할 수 있다.
>
> 3.저장할 수 있다.
> 
> 4.읽을 수 있다.
>
> 5.콘텍스트 메뉴로 굵기와 색상을 선택할 수 있다.
> 
> 6.키보드 1~9까지 누르면 펜의 굵기를 바꿀 수 있다.


## MFC를 활용하여 펜을 작성하시오

## 1.펜의 굵기를 선택할 수 있다.
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/0416965e-376f-4f46-8a31-02058e8d74dc)

```
void CPenView::OnSize1()
{
	Size = 1;
	
}
void CPenView::OnSize4()
{
	Size = 4;
}
void CPenView::OnSize8()
{
	Size = 8;
}
void CPenView::OnSize16()
{
	
	Size = 16;
}
void CPenView::OnSize32()
{
	
	Size = 32;
}
```
## 2.펜의 색상을 선택할 수 있다.
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/26c09a15-b8b8-4aa3-857f-44ab474a4d1a)

```
void CPenView::OnSelectColor()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		Col = dlg.GetColor();
	}
}
```

## 3.저장할 수 있다.
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/f88727b8-5209-4e9e-8284-93c5c7f3d767)


## 4.읽을 수 있다.
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/869e53ad-cb61-4780-a063-37147300db29)

## 5.콘텍스트 메뉴로 굵기와 색상을 선택할 수 있다.
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/f3747c6f-c889-473d-a01d-ef574a648b72)


## 6.키보드 1~9까지 누르면 펜의 굵기를 바꿀 수 있다.
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/9685947d-84bd-4bc5-83f2-036a41ede62f)
```
BOOL CPenView::PreTranslateMessage(MSG* pMsg)
{
		
		if (pMsg->message == WM_KEYDOWN) {
	        if (pMsg->wParam == '1') { Size = 1; }
			if (pMsg->wParam == '2') { Size = 2; }
			if (pMsg->wParam == '3') { Size = 3; }
			if (pMsg->wParam == '4') { Size = 4; }
			if (pMsg->wParam == '5') { Size = 5; }
			if (pMsg->wParam == '6') { Size = 6; }
			if (pMsg->wParam == '7') { Size = 7; }
			if (pMsg->wParam == '8') { Size = 8; }
			if (pMsg->wParam == '9') { Size = 9; }
		}
	return CView::PreTranslateMessage(pMsg);
}
```

