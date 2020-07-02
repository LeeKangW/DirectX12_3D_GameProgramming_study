// �ε��Ҽ����� ��ġ ������ �����ȴ�.
#include<Windows.h>
#include<DirectXMath.h>
#include<DirectXPackedVector.h>
#include<iostream>

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

int main() {
	cout.precision(8);

	// SSE2�� �����ϴ��� Ȯ��
	if (!XMVerifyCPUSupport()) {
		cout << "DirectXMath�� �������� ����." << endl;
		return 0;
	}

	XMVECTOR u = XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f);
	XMVECTOR n = XMVector3Normalize(u);
	
	float LU = XMVectorGetX(XMVector3Length(n));

	//���������δ� ���̰� �ݵ�� 1�̾�� �Ѵ�. ��ġ������ �׷���?
	cout << LU << endl;
	if (LU == 1.0f)
		cout << "���� 1" << endl;
	else
		cout << "���� 1 �ƴ�" << endl;

	//1�� ������ ������ �ŵ������ص� ������ 1�̾�� �Ѵ�. ������ �׷���?
	float powLU = powf(LU, 1.0e6f);
	cout << "LU^(10^6) = " << powLU << endl;

	// �� ���� ������ ������ Epsilon�� �̿��Ͽ� �� �� �Ÿ��� Epsilon���� ������ �ٻ������� ����̴�.
	// �� �̿��� �����Ѵ�.
}