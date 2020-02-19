#include"Matrix.h"

using namespace std;

void W(float &x, float &y)
{
	x = -3.2f * x + 6.4f;
	y = -3.6f * y + 0.72f;
}

float LenVec(Matrix x1)
{
	return sqrt(pow(x1.GetElement(0, 0), 2) + pow(x1.GetElement(1, 0), 2));
}

void main()
{
	Matrix H(2, 2);
	H.SetMatrix(matrix{ {3.2f, 0} ,{0, 3.6f}});
	H.Inverse();

	Matrix X(2, 1), W_X(2, 1), X2;
	float x = 0, y = 0;

	X.SetElement(0, 0, x);
	X.SetElement(1, 0, y);

	W(x, y);
	W_X.SetElement(0, 0, x);
	W_X.SetElement(1, 0, y);

	X2 = X + (H * W_X);

	while (LenVec(X2 - X) < 0.0001f)
	{
		X.SetElement(0, 0, X2.GetElement(0, 0));
		X.SetElement(1, 0, X2.GetElement(1, 0));

		x = X.GetElement(0, 0);
		y = X.GetElement(1, 0);
		W(x, y);
		W_X.SetElement(0, 0, x);
		W_X.SetElement(1, 0, y);

		X2 = X + (H * W_X);
	}

	cout << endl;
	cout << "[" << X2.GetElement(0, 0) << ";" << X2.GetElement(1, 0) << "]" << endl;

	system("pause");
}