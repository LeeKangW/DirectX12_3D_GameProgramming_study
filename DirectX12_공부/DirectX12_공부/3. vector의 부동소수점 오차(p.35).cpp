// 부동소수점의 수치 오차는 누적된다.
#include<Windows.h>
#include<DirectXMath.h>
#include<DirectXPackedVector.h>
#include<iostream>

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

int main() {
	cout.precision(8);

	// SSE2를 지원하는지 확인
	if (!XMVerifyCPUSupport()) {
		cout << "DirectXMath를 지원하지 않음." << endl;
		return 0;
	}

	XMVECTOR u = XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f);
	XMVECTOR n = XMVector3Normalize(u);
	
	float LU = XMVectorGetX(XMVector3Length(n));

	//수학적으로는 길이가 반드시 1이어야 한다. 수치적으로 그럴까?
	cout << LU << endl;
	if (LU == 1.0f)
		cout << "길이 1" << endl;
	else
		cout << "길이 1 아님" << endl;

	//1을 임의의 지수로 거듭제곱해도 여전히 1이어야 한다. 실제로 그럴까?
	float powLU = powf(LU, 1.0e6f);
	cout << "LU^(10^6) = " << powLU << endl;

	// 두 수가 같은지 판정은 Epsilon을 이용하여 두 수 거리가 Epsilon보다 작으면 근사적으로 상등이다.
	// 를 이용해 판정한다.
}