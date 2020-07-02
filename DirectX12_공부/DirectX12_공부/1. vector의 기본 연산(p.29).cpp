#include<Windows.h> // XMVerifyCPUSupport에 필요
#include<DirectXMath.h>
#include<DirectXPackedVector.h>
#include<iostream>

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

// XMVECTOR 객체를 cout으로 출력하기 위해
// << 연산자를 중복적재한다.

ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v) {
	XMFLOAT3 dest;
	XMStoreFloat3(&dest, v);

	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
	return os;
}

int main() {
	cout.setf(ios_base::boolalpha);

	// SSE2를 지원하는지 (Pentium4,AMD K8 이상) 확인한다.
	if (!XMVerifyCPUSupport()) {
		cout << "DirectXMath를 지원하지 않음." << endl;
		return 0;
	}

	XMVECTOR p = XMVectorZero();
	XMVECTOR q = XMVectorSplatOne();
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	XMVECTOR v = XMVectorReplicate(-2.0f);
	XMVECTOR w = XMVectorSplatZ(u);

	cout << "p=" << p << endl;
	cout << "q=" << q << endl;
	cout << "u=" << u << endl;
	cout << "v=" << v << endl;
	cout << "w=" << w << endl;
}