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

# 실행화면
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/a98fcc5b-e1c6-438e-b8a9-3fdd1cfa5e8b)


# 소감
MFC에서 모델리스 다이얼로그를 배워보았는데 처음에는 너무 복잡해서 따라가기 조금 힘들었지만 집중을 열심히하고 못 따라간 학생이 있으면 교수님께서 직접 물어봐주시고 직접 알려주셔서 보다 쉽게 따라갈수있엇습니다. 부모창과 자식창을 왔다갔다 하면서 헤더파일을 연결하고 변수 추가 및 클래스 추가를 하면서 MFC에대해 조금 익숙해 진거 같습니다.3번씩 따라해보면서 처음에는 블로그를 참고하지 안하면 만들지 못 하였지만 계속 반복하다 보니깐 혼자서 스스로 할수있었습니다. 앞으로 어떤 MFC를 배울지 기대가 될것같습니다. 뒤쳐지지 않게 꾸준히 공부하고 노력하겠습니다. 감사합니다.
