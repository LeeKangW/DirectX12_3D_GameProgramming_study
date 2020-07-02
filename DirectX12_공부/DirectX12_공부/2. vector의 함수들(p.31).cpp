#include<Windows.h> // XMVerifyCPUSupport에 필요
#include<DirectXMath.h>
#include<DirectXPackedVector.h>
#include<iostream>

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

//XMVECTOR 객체를 cout으로 출력하기 위해
//"<<" 연산자를 중복적재한다.

ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v) {
	XMFLOAT3 dest;
	XMStoreFloat3(&dest, v);

	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
	return os;
}

int main() {
	cout.setf(ios_base::boolalpha);

	if (!XMVerifyCPUSupport()) {
		cout << "DirectXMath를 지원하지 않음." << endl;
		return 0;
	}

	XMVECTOR n = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	XMVECTOR v = XMVectorSet(-2.0f, 1.0f, -3.0f, 0.0f);
	XMVECTOR w = XMVectorSet(0.707f, 0.707f, 0.0f, 0.0f);

	//벡터 덧셈 : XMVECTOR operator +
	XMVECTOR a = u + v;

	// 벡터 뺄셈 : XMVECTOR operator -
	XMVECTOR b = u - v;
	
	// 스칼라 곱셈 : XMVECTOR oeprator *
	XMVECTOR c = 10.0f * u;

	// ||u||
	XMVECTOR L = XMVector3Length(u);

	// d = u / ||u||
	XMVECTOR d = XMVector3Normalize(u);

	// 내적
	XMVECTOR s = XMVector3Dot(u, v);

	// 외적
	XMVECTOR e = XMVector3Cross(u, v);

	//proj_n(w) 와 perp_n(w) 를 구한다. ( perp 는 수직을 의미 )
	XMVECTOR projW;
	XMVECTOR perpW;
	XMVector3ComponentsFromNormal(&projW, &perpW, w, n);

	// projW + perpW == w 인가?
	bool equal = XMVector3Equal(projW + perpW, w) != 0;
	bool notEqual = XMVector3NotEqual(projW + perpW, w) != 0;

	// projW 와 perpW 사이의 각도는 반드시 90도 이어야 한다.
	XMVECTOR angleVec = XMVector3AngleBetweenVectors(projW, perpW);
	float angleRadians = XMVectorGetX(angleVec);
	float angleDegrees = XMConvertToDegrees(angleRadians);

	cout << "u  	               = " << u << endl;
	cout << "v  	               = " << v << endl;
	cout << "w  	               = " << w << endl;
	cout << "n  	               = " << n << endl;
	cout << "a = u + v             = " << a << endl;
	cout << "b = u - v             = " << b << endl;
	cout << "c = 10 * u            = " << c << endl;
	cout << "d = u / ||u||         = " << d << endl;
	cout << "e = u X u             = " << e << endl;
	cout << "L = ||u||             = " << L << endl;
	cout << "s = u.v               = " << s << endl;
	cout << "projW                 = " << projW << endl;
	cout << "perpW                 = " << perpW << endl;
	cout << "projW + perpW == w    = " << equal << endl;
	cout << "projW + perpW != w    = " << notEqual << endl;
	cout << "angle                 = " << angleDegrees << endl;

	return 0;
}