#include<Windows.h> // XMVerifyCPUSupport�� �ʿ�
#include<DirectXMath.h>
#include<DirectXPackedVector.h>
#include<iostream>

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

//XMVECTOR ��ü�� cout���� ����ϱ� ����
//"<<" �����ڸ� �ߺ������Ѵ�.

ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v) {
	XMFLOAT3 dest;
	XMStoreFloat3(&dest, v);

	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
	return os;
}

int main() {
	cout.setf(ios_base::boolalpha);

	if (!XMVerifyCPUSupport()) {
		cout << "DirectXMath�� �������� ����." << endl;
		return 0;
	}

	XMVECTOR n = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	XMVECTOR v = XMVectorSet(-2.0f, 1.0f, -3.0f, 0.0f);
	XMVECTOR w = XMVectorSet(0.707f, 0.707f, 0.0f, 0.0f);

	//���� ���� : XMVECTOR operator +
	XMVECTOR a = u + v;

	// ���� ���� : XMVECTOR operator -
	XMVECTOR b = u - v;
	
	// ��Į�� ���� : XMVECTOR oeprator *
	XMVECTOR c = 10.0f * u;

	// ||u||
	XMVECTOR L = XMVector3Length(u);

	// d = u / ||u||
	XMVECTOR d = XMVector3Normalize(u);

	// ����
	XMVECTOR s = XMVector3Dot(u, v);

	// ����
	XMVECTOR e = XMVector3Cross(u, v);

	//proj_n(w) �� perp_n(w) �� ���Ѵ�. ( perp �� ������ �ǹ� )
	XMVECTOR projW;
	XMVECTOR perpW;
	XMVector3ComponentsFromNormal(&projW, &perpW, w, n);

	// projW + perpW == w �ΰ�?
	bool equal = XMVector3Equal(projW + perpW, w) != 0;
	bool notEqual = XMVector3NotEqual(projW + perpW, w) != 0;

	// projW �� perpW ������ ������ �ݵ�� 90�� �̾�� �Ѵ�.
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