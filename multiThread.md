# 멀티테스킹의 구현
## 10개의 정수값의 최솟값을 구하는 프로그램을 멀티쓰레드를 응용하여 구현하시오.

# 결과이미지
![image](https://github.com/JunYoung0404/visualprogramming/assets/50895748/e407c275-08fa-407e-825f-6f6c46055667)
# 코드
```
pData->min = pData->array[0];
for (int i = 1; i < 10; i++) {
	if (pData->array[i] < pData->min)
		pData->min = pData->array[i];
}
 	::PostMessage(pData->NotifyWindow, WM_MIN, 0, 0);
return 0;
```
### 설명
최솟값을 구해야 하기 떄문에 max를 min으로 바꿔주고 10개의 정수값을 구해야하기때문에 i<10작다라고 표시해 준다

# 코드
```
void CMyView::OnFindmin()
{
	data.array[0]=1;
	data.array[1]=2;
	data.array[2]=3;
	data.array[3]=4;
	data.array[4]=5;
	data.array[5]=6;
	data.array[6]=7;
	data.array[7]=8;
	data.array[8]=9;
	data.array[9]=10;
	data.min=0;
	data.NotifyWindow = m_hWnd;
	AfxBeginThread(MyThread, &data);
}
```
### 설명
10개의 정수 최소값을 구해야하기때문에 배열을 10개 만들어준다.

# 코드
```
LRESULT CMyView::OnMinFound(WPARAM wParam, LPARAM lParam)
{
	CMyDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CString msg;
	msg.Format(L"MIN of the array = %d", data.min);
	pDoc->str = msg;
	TerminateThread(Thread, 0);
	Invalidate();
	return 0L;
}
```
### 설명
문구 출력에 data.min을 사용하여 최소값을 출력해준다.

# 소감
수업시간에 배운 멀티스레드로 최대값을 구하는것을 해보았는데 최대값과 반대로 max를 min으로 바꾸어 주고 배열의 갯수와 부등호를 바꿔주니깐 쉽게 변경할수있었던것 같습니다. 카페에서 배운 멀티태스킹과 멀티스래드를 이용하여 여러가지 일을 많이 할수있느것을 배웠고 cmd에서 msconfig르 이용하면
현재 컴퓨터에서 어떤 프로그램이 cpu를 잡아먹은것을 보고 불필요한 프로그램을 꺼주면 보다 효율적으로 cpu를 사용할수있을것이라고 생각하였습니다. cpu를 보다 효율적으로 사용하면 컴퓨터 속도가 조금더 빨라질것 같다는 생각을 하엿고 수명이 연장될것같습니다. 멀티스레드 까지 배우면서 다음 winui3가 기대되는것 같습니다.
   

