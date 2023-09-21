# MFC 기반 프로젝트에서 Modeless 다이얼로그를 만드시오.

## 모덜리스 다이얼로그
흔히 모덜리스, 모달리스 혹은 모드리스라고 부르며, 모달과 반대되는 개념으로 생각하면 쉽다.

모덜리스는 대화 상자(dialog)가 실행되더라도 기존 화면을 제어할 수 있는 방식을 뜻 하고 웹 사이트의 알림 메시지 등으로 생각하면 도움이 된다.

## 구현방법

![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/1feeb404-9d84-4ef1-bdfe-199ac0cb1443)
```
부모창에 LIST BOX를 만들어준다.
도구상자에서 버튼을 가져온다.
우 클릭후 제어 변수 추가에 이름:m_List로 변경해준다.
```

![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/1c03b4ff-8f4b-41cc-9151-c088b0ee0af9)
```
리스스 뷰 클릭 후 Dialog 우 클릭 삽입하여 자식 다이얼로그 생성
우클릭 클래스 추가 클래스 이름"CModeless"변경
Edit Control추가
버튼 추가
```

![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/21954866-df33-4737-9e21-ec089bde1d43)

```
자식 다이얼로그에 Edit Control 우클릭후 변수 추가
범주"값"으로 변경
이름 "m_Str"로 변경
```

![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/3acc57fa-60ec-4858-ad9b-fb4d8ae5b281)

```
부모창에서 버튼 더블클릭 후
#include"CModeless.h" // 헤더파일 추가
void CMy11Dlg::OnBnClickedButton1()
{
	CModeless* p = new CModeless(); //새로운 객체 생성
	p->Create(IDD_DIG_MODELESS); //포인터로 접근
	p->ShowWindow(SW_SHOW); //포인터로 ShoWindow에접근

}

```

![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/7ade837b-bfca-4e84-abfd-accc8899ebbc)

```
자식창에서 버튼 더블클릭 후
#include"My11Dlg.h" // 헤더파일 추가
void CModeless::OnBnClickedButton1()
{
	UpdateData(true); 
	CMy11Dlg* p = (CMy11Dlg*)GetParent(); // 형변환
	p->m_List.AddString(m_Str); 
}

```


