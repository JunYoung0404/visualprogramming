# 	MFC 기반의 펜 만들기

## 1. 펜의 굵기를 조절 할 수 있도록 하시오.
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/96531ea0-cbec-45d2-8fb0-5260d86fdc03)
## 코드

```
void CMFCApplication8Dlg::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
n = m_Slider.GetPos();
*pResult = 0;
}
```
## 설명
1. slider도구상자를 추가해준다
2. 변수 추가 -> 이름변경 m_Slider
3. 글자 포인터를 n으로 변경해준다.
4. 슬라이더버튼 이벤트 n = m_Slider.GetPos(); 추가
5. 정수 변수 int = n;을 선언


## 2. 펜의 색상을 변경할 수 있도록 하시오.
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/6485b54b-5274-410c-8f55-e07cbb4a195a)
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/7434e122-c775-4c16-8a85-1cf8fde99050)

## 코드
```
CPoint opnt;
COLORREF m_Col;
void CMFCApplication8Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nFlags & MK_LBUTTON) {
		CClientDC dc(this);//this 는 현제 객체를 나타내는 포인터다
		CPen pen(PS_SOLID, 8, m_Col);
		dc.SelectObject(&pen);
		dc.MoveTo(opnt);
		dc.LineTo(point);
	}
	opnt = point;
	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFCApplication8Dlg::OnBnClickedButton1()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		m_Col=dlg.GetColor();
	}

}
```
## 설명
1. COLORREF m_Col;추가
2. RGB부분에 m_Col입력
3. 칼라버튼에
CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		m_Col=dlg.GetColor();
	}
추가


#### 소감
처음 mfc를 배울 때 조금 어려워 보였는데 점점 흥미가 생기고 있고 어려워서 못 따라가고 있으면 교수님께서 직접 와서 바로바로 알려주셔서 정말 좋았습니다.
펜을 직접 만들어 보고 색상과 굵기를 직접 조절하는 것을 만들어 보면서 다른 것도 만들어 보고 싶다는 생각이 들었습니다.
오늘 배운 코드를 나중에 외워야지라는 생각을 버리고 오늘 끝낸다는 생각으로 공부하겠습니다. 감사합니다.
