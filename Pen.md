# 	MFC 기반의 펜 만들기

## 1. 펜의 굵기를 조절 할 수 있도록 하시오.
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/96531ea0-cbec-45d2-8fb0-5260d86fdc03)


```
1. slider도구상자를 추가해준다
2.변수 추가 -> 이름변경 m_Slider
3.글자 포인터를 n으로 변경해준다.
```
## 2. 펜의 색상을 변경할 수 있도록 하시오.
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/6485b54b-5274-410c-8f55-e07cbb4a195a)

```
컬러 버튼에 
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		m_Col=dlg.GetColor();
	}
```
