#include <iostream>
#include "MathLib.h"


//-------------------------------------------------------------------------//
//--------//	Vector 2D	//---------------------------------------------//
//-------------------------------------------------------------------------//

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}
Vector2::Vector2(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}
Vector2::~Vector2()
{

}

bool Vector2::EqualVector(Vector2 v1, Vector2 v2)
{
	if ((v1.x = v2.x) && (v1.y = v2.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//	bool Vector2::operator==(const Vector2& v2)const
//	{
//		if ((x = v2.x) && (y = v2.y))
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}

//bool Vector2::operator<(const Vector2& v2) const
//{
//	if ((x < v2.x) && (y < v2.y))
//		return true;
//	else
//		return false;
//}
Vector2 Vector2::operator+(const Vector2& v2)const
{
	Vector2 newVec;
	newVec.x = x + v2.x;
	newVec.y = y + v2.y;
	return newVec;
}
Vector2& Vector2::operator+=(const Vector2& v2)
{
	x += v2.x;
	y += v2.y;
	return *this;
}
Vector2 Vector2::operator-(const Vector2& v2)const
{
	Vector2 newVec;
	newVec.x = x - v2.x;
	newVec.y = y - v2.y;
	return newVec;
}
Vector2& Vector2::operator-=(const Vector2& v2)
{
	x -= v2.x;
	y -= v2.y;
	return *this;
}

Vector2 Vector2::operator/(const Vector2& v2)const
{
	Vector2 newVec;
	newVec.x = x / v2.x;
	newVec.y = y / v2.y;
	return newVec;
	//return Vector2(x / v2, y / v2);
}
Vector2& Vector2::operator/=(const Vector2& v2)
{
	x /= v2.x;
	y /= v2.y;
	return *this;
}
Vector2 Vector2::operator*(const Vector2& v2)const
{
	Vector2 newVec;
	newVec.x = x * v2.x;
	newVec.y = y * v2.y;
	return newVec;
	//return Vector2(x * v2, y * v2);
}
Vector2& Vector2::operator*=(const Vector2& v2)
{
	x *= v2.x;
	y *= v2.y;
	return *this;
}

Vector2 Vector2::VecFlo(Vector2 a, float Float)
{
	a.x *= Float;
	a.y *= Float;
	return a;
}
float Vector2::FloVec(Vector2 a, float Float)
{
	float a1 = Float * a.x;
	float a2 = Float * a.y;
	return (Float * a.x) + (Float * a.y);

}
float Dot(Vector2 a_1, Vector2 a_2)
{
	return (a_1.x*a_2.x) + (a_1.y*a_2.y);
}
float Vector2::Magnitude()
{
	return sqrt((x * x) + (y * y));
}
Vector2 Normalised(Vector2 a)
{
	a.x /= a.Magnitude();
	a.y /= a.Magnitude();
	return a;
}


//-------------------------------------------------------------------------//
//--------//	Vector 3D	//---------------------------------------------//
//-------------------------------------------------------------------------//


Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}
Vector3::Vector3(float a_x, float a_y, float a_z)
{
	x = a_x;
	y = a_y;
	z = a_z;
}
Vector3::~Vector3()
{

}


Vector3 Vector3::operator+(const Vector3& v3)const
{
	Vector3 newVec;
	newVec.x = x + v3.x;
	newVec.y = y + v3.y;
	newVec.z = z + v3.z;
	return newVec;
}

Vector3& Vector3::operator+=(const Vector3& v3)
{
	x += v3.x;
	y += v3.y;
	z += v3.z;
	return *this;
}
Vector3 Vector3::operator-(const Vector3& v3)const
{
	Vector3 newVec;
	newVec.x = x - v3.x;
	newVec.y = y - v3.y;
	newVec.z = z - v3.z;
	return newVec;
}
Vector3& Vector3::operator-=(const Vector3& v3)
{
	x -= v3.x;
	y -= v3.y;
	z -= v3.z;
	return *this;
}

Vector3 Vector3::operator/(const Vector3& v3)const
{
	Vector3 newVec;
	newVec.x = x / v3.x;
	newVec.y = y / v3.y;
	newVec.z = z / v3.z;
	return newVec;
	//return Vector3(x / v3, y / v3, z / v3);
}
Vector3& Vector3::operator/=(const Vector3& v3)
{
	x /= v3.x;
	y /= v3.y;
	z /= v3.z;
	return *this;
}
Vector3 Vector3::operator*(const Vector3& v3)const
{
	Vector3 newVec(x * v3.x,
		y * v3.y,
		z * v3.z);
	return newVec;
	//return Vector3(x * v3, y * v3, z * v3);
}
Vector3& Vector3::operator*=(const Vector3& v3)
{
	x *= v3.x;
	y *= v3.y;
	z *= v3.z;
	return *this;


}
Vector3 Vector3::operator*(const float& f1)const
{
	Vector3 newVec(x * f1,
		y * f1,
		z * f1);
	return newVec;
	//return Vector3(x * v3, y * v3, z * v3);
}

Vector3 Vector3::VecFlo(Vector3 a, float Float)
{
	a.x *= Float;
	a.y *= Float;
	a.z *= Float;
	return a;
	//return a * Float;
}
float Vector3::FloVec(Vector3 a, float Float)
{
	return Float * a.x + Float * a.y + Float * a.z;
}


float Vector3::Dot(Vector3 a_1, Vector3 a_2)
{
	float dot = (a_1.x*a_2.x) + (a_1.y*a_2.y) + (a_1.z*a_2.z);
	return dot;
}
Vector3 Vector3::Cross(Vector3 a_1, Vector3 a_2)
{
	Vector3 cross((a_1.y*a_2.z) - (a_1.z*a_2.y), (a_1.z*a_2.x) - (a_1.x*a_2.z), (a_1.x*a_2.y) - (a_1.y*a_2.x));
	return cross;
}
float Vector3::Magnitude()
{
	return sqrt(x*x + y*y + z*z);
}
Vector3 Vector3::Normalised()
{
	float magnitude = Magnitude();
	x /= magnitude;
	y /= magnitude;
	z /= magnitude;

	return *this;
}



//-------------------------------------------------------------------------//
//--------//	Vector 4D	//---------------------------------------------//
//-------------------------------------------------------------------------//


Vector4::Vector4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	q = 0.0f;
}
Vector4::Vector4(float a_x, float a_y, float a_z, float a_q)
{
	x = a_x;
	y = a_y;
	z = a_z;
	q = a_q;
}
Vector4::~Vector4()
{

}


Vector4 Vector4::operator+(const Vector4& v4)const
{
	Vector4 newVec;
	newVec.x = x + v4.x;
	newVec.y = y + v4.y;
	newVec.z = z + v4.z;
	newVec.q = q + v4.q;
	return newVec;
}
Vector4& Vector4::operator+=(const Vector4& v4)
{
	x += v4.x;
	y += v4.y;
	z += v4.z;
	q += v4.q;
	return *this;
}
Vector4 Vector4::operator-(const Vector4& v4)const
{
	Vector4 newVec;
	newVec.x = x - v4.x;
	newVec.y = y - v4.y;
	newVec.z = z - v4.z;
	newVec.q = q - v4.q;
	return newVec;
}
Vector4& Vector4::operator-=(const Vector4& v4)
{
	x -= v4.x;
	y -= v4.y;
	z -= v4.z;
	q -= v4.q;
	return *this;
}

Vector4 Vector4::operator/(float v4)const
{
	return Vector4(x / v4, y / v4, z / v4, q / v4);
}
Vector4& Vector4::operator/=(const Vector4& v4)
{
	x /= v4.x;
	y /= v4.y;
	z /= v4.z;
	q /= v4.q;
	return *this;
}
Vector4 Vector4::operator*(float v4)const
{
	return Vector4(x * v4, y * v4, z * v4, q * v4);
}
Vector4& Vector4::operator*=(const Vector4& v4)
{
	x *= v4.x;
	y *= v4.y;
	z *= v4.z;
	q *= v4.q;
	return *this;
}


Vector4 Vector4::VecFlo(Vector4 a, float Float)
{
	return a * Float;
}
float Vector4::FloVec(Vector4 a, float Float)
{
	return Float * a.x + Float * a.y + Float * a.z + Float * a.q;
}


float Dot(Vector4 a_1, Vector4 a_2, Vector4 a_z)
{
	float dot = (a_1.x*a_2.x) + (a_1.y*a_2.y) + (a_1.z*a_2.z) + (a_1.q*a_2.q);
	return dot;
}
//-----------Later

Vector4 Cross(Vector4 a_1, Vector4 a_2, Vector4 a_z, Vector4 a_q)
{
	Vector4 cross((a_1.y*a_2.z) - (a_1.z*a_2.y), (a_1.z*a_2.x) - (a_1.x*a_2.z), (a_1.x*a_2.y) - (a_1.y*a_2.x), 1);
	return cross;
}

float Magnitude(Vector4 a)
{
	return sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z) + (a.q * a.q));
}
Vector4 Normalised(Vector4 a, float magnitude)
{
	a.x /= magnitude;
	a.y /= magnitude;
	a.z /= magnitude;
	a.q /= magnitude;

	return a;
}

Vector2 Vector2::operator*(float rhs) const
{
	return Vector2(x*rhs, y*rhs);
}

//-------------------------------------------------------------------------//
//--------//	Matrix 2D	//---------------------------------------------//
//-------------------------------------------------------------------------//





Matrix2::Matrix2()
{
	a11 = 1.0f;
	a12 = 0.0f;
	a21 = 0.0f;
	a22 = 1.0f;
}
Matrix2::Matrix2(float b11, float b12, float b21, float b22)
{

	a11 = b11;
	a12 = b12;
	a21 = b21;
	a22 = b22;
}
Matrix2::~Matrix2()
{

}

Matrix2 Matrix2::operator+(Matrix2 m2)const
{
	Matrix2 b((a11 + m2.a11), (a12 + m2.a12),
		(a21 + m2.a21), (a22 + m2.a22));
	return b;
}
Matrix2 Matrix2::operator-(Matrix2 m2)const
{
	Matrix2 b((a11 - m2.a11), (a12 - m2.a12),
		(a21 - m2.a21), (a22 - m2.a22));
	return b;
}
Matrix2 Matrix2::operator*(Matrix2 m2)const
{
	Matrix2 b((a11 * m2.a11) + (a12 * m2.a21), (a11 * m2.a12) + (a12 * m2.a22),
		(a21 * m2.a11) + (a22 * m2.a21), (a21 * m2.a12) + (a22 * m2.a22));
	return b;
}

Vector2 Matrix2::operator*(Vector2 v2)const
{
	Vector2 b((a11 * v2.x) + (a12 * v2.y),
		(a21 * v2.x) + (a22 * v2.y));



	return b;

}


Matrix2 Matrix2::Transpose(Matrix2 m2)
{
	Matrix2 b(m2.a11, m2.a21,
		m2.a12, m2.a22);
	return b;

}

Matrix2 Matrix2::Translation(float x)
{
	Matrix2 translation(1.0f, x,
		0.0f, 1.0f);
	return translation;
}
Matrix2 Matrix2::Rotation(float r)
{
	Matrix2 rotate(cos(r), -sin(r),
		sin(r), cos(0));
	return rotate;
}
Matrix2 Matrix2::Scale(float x)
{
	Matrix2 scale(x, 0.0f,
		0.0f, 1.0f);
	return scale;
}


//-------------------------------------------------------------------------//
//--------//	Matrix 3D	//---------------------------------------------//
//-------------------------------------------------------------------------//

Matrix3::Matrix3()
{
	Mat[0][0] = 1.0f;
	Mat[1][0] = 0.0f;
	Mat[2][0] = 0.0f;
	Mat[0][1] = 0.0f;
	Mat[1][1] = 1.0f;
	Mat[2][1] = 0.0f;
	Mat[0][2] = 0.0f;
	Mat[1][2] = 0.0f;
	Mat[2][2] = 1.0f;
}
Matrix3::Matrix3(float b11, float b12, float b13, float b21, float b22, float b23, float b31, float b32, float b33)
{
	a11 = b11;
	a12 = b12;
	a13 = b13;
	a21 = b21;
	a22 = b22;
	a23 = b23;
	a31 = b31;
	a32 = b32;
	a33 = b33;

	//Mat[0][0] = b11;
	//Mat[1][0] = b12;
	//Mat[2][0] = b13;
	//Mat[0][1] = b21;
	//Mat[1][1] = b22;
	//Mat[2][1] = b23;
	//Mat[0][2] = b31;
	//Mat[1][2] = b32;
	//Mat[2][2] = b33;

}
Matrix3::~Matrix3()
{

}

Matrix3 Matrix3::operator+(Matrix3 m3)const
{
	Matrix3 b((Mat[0][0] + m3.Mat[0][0]), (Mat[1][0] + m3.Mat[1][0]), (Mat[2][0] + m3.Mat[2][0]),
		(Mat[0][1] + m3.Mat[0][1]), (Mat[1][1] + m3.Mat[1][1]), (Mat[2][1] + m3.Mat[2][1]),
		(Mat[0][2] + m3.Mat[0][2]), (Mat[1][2] + m3.Mat[1][2]), (Mat[2][2] + m3.Mat[2][2]));
	return b;
}
Matrix3 Matrix3::operator-(Matrix3 m3)const
{
	Matrix3 b((Mat[0][0] - m3.Mat[0][0]), (Mat[1][0] - m3.Mat[1][0]), (Mat[2][0] - m3.Mat[2][0]),
		(Mat[0][1] - m3.Mat[0][1]), (Mat[1][1] - m3.Mat[1][1]), (Mat[2][1] - m3.Mat[2][1]),
		(Mat[0][2] - m3.Mat[0][2]), (Mat[1][2] - m3.Mat[1][2]), (Mat[2][2] - m3.Mat[2][2]));
	return b;
}
Matrix3 Matrix3::operator*(Matrix3 m3)const
{
	Matrix3 b((a11 * m3.a11) + (a12 * m3.a21) + (a13 * m3.a31), (a11 * m3.a12) + (a12 * m3.a22) + (a13 * m3.a32), (a11 * m3.a13) + (a12 * m3.a23) + (a13 * m3.a33),
		(a21 * m3.a11) + (a22 * m3.a21) + (a23 * m3.a31), (a21 * m3.a12) + (a22 * m3.a22) + (a23 * m3.a32), (a21 * m3.a13) + (a22 * m3.a23) + (a23 * m3.a33),
		(a31 * m3.a11) + (a32 * m3.a21) + (a33 * m3.a31), (a31 * m3.a12) + (a32 * m3.a22) + (a33 * m3.a32), (a31 * m3.a13) + (a32 * m3.a23) + (a33 * m3.a33));
	return b;
}


Vector3 Matrix3::operator*(Vector3 v3)const
{
	Vector3 b((a11 * v3.x) + (a12 * v3.y) + (a13 * v3.z),
		(a21 * v3.x) + (a22 * v3.y) + (a23 * v3.z),
		(a31 * v3.x) + (a32 * v3.y) + (a33 * v3.z));


	return b;

}
Matrix3 Matrix3::operator*(float f1)const
{
	Matrix3 b((a11 * f1), (a12 * f1), (a13 * f1),
		(a21 * f1), (a22 * f1), (a23 * f1),
		(a31 * f1), (a32 * f1), (a33 * f1));


	return b;

}
Matrix3 Matrix3::Transpose(Matrix3 m3)
{
	Matrix3 b(m3.a11, m3.a21, m3.a31,
		m3.a12, m3.a22, m3.a32,
		m3.a13, m3.a23, m3.a33);
	return b;
}

Matrix3 Matrix3::Translation(Vector3 pos)
{
	Matrix3 translation(1.0f, 0.0f, pos.x,
		0.0f, 1.0f, pos.y,
		0.0f, 0.0f, 1.0f);
	return translation;
}
Matrix3 Matrix3::Rotation(float r)
{
	Matrix3 rotate(cos(r), -sin(r), 0.0f,
		sin(r), cos(r), 0.0f,
		0.0f, 0.0f, 1.0f);
	return rotate;
}

Matrix3 Matrix3::ChangeRotation(Matrix3 pos, float r)
{
	return (pos * Rotation(r));
}

Matrix3 Matrix3::Scale(Vector3 pos)
{
	Matrix3 scale(pos.x, 0.0f, 0.0f,
		0.0f, pos.y, 0.0f,
		0.0f, 0.0f, 1.0f);
	return scale;
}

float *Matrix3::GetMatrix()
{
	return *Mat;
}





//-------------------------------------------------------------------------//
//--------//	Matrix 4D	//---------------------------------------------//
//-------------------------------------------------------------------------//

Matrix4::Matrix4()
{
	a11 = 1.0f;
	a12 = 0.0f;
	a13 = 0.0f;
	a14 = 0.0f;
	a21 = 0.0f;
	a22 = 1.0f;
	a23 = 0.0f;
	a24 = 0.0f;
	a31 = 0.0f;
	a32 = 0.0f;
	a33 = 1.0f;
	a34 = 0.0f;
	a41 = 0.0f;
	a42 = 0.0f;
	a43 = 0.0f;
	a44 = 1.0f;

}
Matrix4::Matrix4(float b11, float b12, float b13, float b14, float b21, float b22, float b23, float b24, float b31, float b32, float b33, float b34, float b41, float b42, float b43, float b44)
{
	a11 = b11;
	a12 = b12;
	a13 = b13;
	a14 = b14;
	a21 = b21;
	a22 = b22;
	a23 = b23;
	a24 = b24;
	a31 = b31;
	a32 = b32;
	a33 = b33;
	a34 = b34;
	a41 = b41;
	a42 = b42;
	a43 = b43;
	a44 = b44;
}
Matrix4::~Matrix4()
{

}

Matrix4 Matrix4::operator+(Matrix4 m4)const
{
	Matrix4 b((a11 + m4.a11), (a12 + m4.a12), (a13 + m4.a13), (a14 + m4.a14),
		(a21 + m4.a21), (a22 + m4.a22), (a23 + m4.a23), (a24 + m4.a24),
		(a31 + m4.a31), (a32 + m4.a32), (a33 + m4.a33), (a34 + m4.a34),
		(a41 + m4.a41), (a42 + m4.a42), (a43 + m4.a43), (a44 + m4.a44));
	return b;
}
Matrix4 Matrix4::operator-(Matrix4 m4)const
{
	Matrix4 b((a11 - m4.a11), (a12 - m4.a12), (a13 - m4.a13), (a14 - m4.a14),
		(a21 - m4.a21), (a22 - m4.a22), (a23 - m4.a23), (a24 - m4.a24),
		(a31 - m4.a31), (a32 - m4.a32), (a33 - m4.a33), (a34 - m4.a34),
		(a41 - m4.a41), (a42 - m4.a42), (a43 - m4.a43), (a44 - m4.a44));
	return b;
}
Matrix4 Matrix4::operator*(Matrix4 m4)const
{
	Matrix4 b((a11 * m4.a11) + (a12 * m4.a21) + (a13 * m4.a31) + (a14 * m4.a41), (a11 * m4.a12) + (a12 * m4.a22) + (a13 * m4.a32) + (a14 * m4.a42), (a11 * m4.a13) + (a12 * m4.a23) + (a13 * m4.a33) + (a14 * m4.a43), (a11 * m4.a14) + (a12 * m4.a24) + (a13 * m4.a34) + (a14 * m4.a44),
		(a21 * m4.a11) + (a22 * m4.a21) + (a23 * m4.a31) + (a24 * m4.a41), (a21 * m4.a12) + (a22 * m4.a22) + (a23 * m4.a32) + (a24 * m4.a42), (a21 * m4.a13) + (a22 * m4.a23) + (a23 * m4.a33) + (a24 * m4.a43), (a21 * m4.a14) + (a22 * m4.a24) + (a23 * m4.a34) + (a24 * m4.a44),
		(a31 * m4.a11) + (a32 * m4.a21) + (a33 * m4.a31) + (a34 * m4.a41), (a31 * m4.a12) + (a32 * m4.a22) + (a33 * m4.a32) + (a34 * m4.a42), (a31 * m4.a13) + (a32 * m4.a23) + (a33 * m4.a33) + (a34 * m4.a43), (a31 * m4.a14) + (a32 * m4.a24) + (a33 * m4.a34) + (a34 * m4.a44),
		(a41 * m4.a11) + (a42 * m4.a21) + (a43 * m4.a31) + (a44 * m4.a41), (a41 * m4.a12) + (a42 * m4.a22) + (a43 * m4.a32) + (a44 * m4.a42), (a41 * m4.a13) + (a42 * m4.a23) + (a43 * m4.a33) + (a44 * m4.a43), (a41 * m4.a14) + (a42 * m4.a24) + (a43 * m4.a34) + (a44 * m4.a44));
	return b;
}

Matrix4 Matrix4::Transpose(Matrix4 m4)
{
	Matrix4 b(m4.a11, m4.a21, m4.a31, m4.a41,
		m4.a12, m4.a22, m4.a32, m4.a42,
		m4.a13, m4.a23, m4.a33, m4.a43,
		m4.a14, m4.a24, m4.a34, m4.a44);
	return b;
}


Matrix4 Matrix4::Translation(float x, float y, float z)
{
	Matrix4 translation(1.0f, 0.0f, 0.0f, x,
		0.0f, 1.0f, 0.0f, y,
		0.0f, 0.0f, 1.0f, z,
		0.0f, 0.0f, 0.0f, 1.0f);
	return translation;
}

Matrix4 Matrix4::Rotation(float r)
{
	Matrix4 rotate(cos(r), -sin(r), 0.0f, 0.0f,
		sin(r), cos(0), 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
	return rotate;
}


Matrix4 Matrix4::Scale(float x, float y, float z)
{
	Matrix4 scale(x, 0.0f, 0.0f, 0.0f,
		0.0f, y, 0.0f, 0.0f,
		0.0f, 0.0f, z, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
	return scale;
}


