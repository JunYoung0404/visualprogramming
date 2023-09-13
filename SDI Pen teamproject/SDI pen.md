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
void CPenView::OnMouseMove(UINT nFlags, CPoint point)
{
	
	if (nFlags == MK_LBUTTON) {
		CPenDoc* pDoc = GetDocument();
		CLine* pLine = new CLine(opnt, point,Size,Col);  // 고정되어있는 숫자를 Size로 바꿔준다.
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


