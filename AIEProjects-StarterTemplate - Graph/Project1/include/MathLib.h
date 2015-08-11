#ifndef _MATHLIB_H
#define _MATHLIB_H


class Vector2
{
public:
	Vector2();
	Vector2(float a_x, float a_y);
	~Vector2();

	Vector2 VecFlo(Vector2 a, float Float);
	float FloVec(Vector2 a, float Float);
	float Dot(Vector2 a_1, Vector2 a_2);
	float Magnitude();
	Vector2 Normalised();


	bool EqualVector(Vector2 v1, Vector2 v2);

//	bool operator<(const Vector2& v2) const;

	Vector2 operator+(const Vector2& v2) const;
	Vector2& operator+=(const Vector2& v2);

	Vector2 operator-(const Vector2& v2) const;
	Vector2& operator-=(const Vector2& v2);

	Vector2 operator/(const Vector2& v2)const;
	Vector2& operator/=(const Vector2& v2);

	Vector2 operator*(const Vector2& v2)const;
	Vector2& operator*=(const Vector2& v2);

	Vector2 operator*(float rhs) const;

	float x;
	float y;

};


class Vector3
{
public:
	Vector3();
	Vector3(float a_x, float a_y, float a_z);
	~Vector3();

	Vector3 operator+(const Vector3& v3) const;
	Vector3& operator+=(const Vector3& v3);
	Vector3 operator-(const Vector3& v3) const;
	Vector3& operator-=(const Vector3& v3);
	Vector3 operator/(const Vector3& v3)const;
	Vector3& operator/=(const Vector3& v3);
	Vector3 operator*(const Vector3& v3)const;
	Vector3& operator*=(const Vector3& v3);
	Vector3 operator*(const float& f1)const;


	Vector3 VecFlo(Vector3 a, float Float);
	float FloVec(Vector3 a, float Float);

	float Dot(Vector3 a_1, Vector3 a_2);
	Vector3 Cross(Vector3 a_1, Vector3 a_2);
	float Magnitude();
	Vector3 Normalised();

	float x;
	float y;
	float z;

};

class Vector4
{
public:
	Vector4();
	Vector4(float a_x, float a_y, float a_z, float a_q);
	~Vector4();

	Vector4 operator+(const Vector4& v4) const;
	Vector4& operator+=(const Vector4& v4);
	Vector4 operator-(const Vector4& v4) const;
	Vector4& operator-=(const Vector4& v4);
	Vector4 operator/(float v4)const;
	Vector4& operator/=(const Vector4& v4);
	Vector4 operator*(float v4)const;
	Vector4& operator*=(const Vector4& v4);

	Vector4 VecFlo(Vector4 a, float Float);
	float FloVec(Vector4 a, float Float);

	float Dot(Vector4 a_1, Vector4 a_2, Vector4 a_z, Vector4 a_q);
	Vector4 Cross(Vector4 a_1, Vector4 a_2, Vector4 a_z, Vector4 a_q);
	float Magnitude(Vector4 a);
	Vector4 Normalised(Vector4 a, float magnitude);

	float x;
	float y;
	float z;
	float q;

};



class Matrix2
{
public:
	Matrix2();
	Matrix2(float a11, float a12, float a21, float a22);
	~Matrix2();

	Matrix2 operator+(Matrix2 m2)const;
	Matrix2 operator-(Matrix2 m2)const;
	Matrix2 operator*(Matrix2 m2)const;

	Vector2 operator*(Vector2 v3)const;


	Matrix2 Transpose(Matrix2 m2);

	Matrix2 Translation(float x);
	Matrix2 Rotation(float r);
	Matrix2 Scale(float x);


	float a11;
	float a12;
	float a21;
	float a22;

};

class Matrix3
{
public:
	Matrix3();
	Matrix3(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33);
	~Matrix3();

	Matrix3 operator+(Matrix3 m3)const;
	Matrix3 operator-(Matrix3 m3)const;
	Matrix3 operator*(Matrix3 m3)const;
	Matrix3 operator*=(Matrix3 m3)const;

	Vector3 operator*(Vector3 v3)const;
	Matrix3 operator*(float f1)const;


	Matrix3 Transpose(Matrix3 m3);


	Matrix3 Translation(Vector3 pos);
	Matrix3 Rotation(float r);
	Matrix3 Scale(Vector3 pos);
	Matrix3 ChangeRotation(Matrix3 pos, float r);

	float* GetMatrix();
	union
	{
		struct
		{
			float Mat[3][3];
		};
		struct
		{
			float a11;
			float a12;
			float a13;
			float a21;
			float a22;
			float a23;
			float a31;
			float a32;
			float a33;
		};
	};
};

class Matrix4
{
public:
	Matrix4();
	Matrix4(float b11, float b12, float b13, float b14, float b21, float b22, float b23, float b24, float b31, float b32, float b33, float b34, float b41, float b42, float b43, float b44);
	~Matrix4();

	Matrix4 operator+(Matrix4 m4)const;
	Matrix4 operator-(Matrix4 m4)const;
	Matrix4 operator*(Matrix4 m4)const;
	Matrix4 operator/(Matrix4 m4)const;

	Matrix4 Transpose(Matrix4 m4);


	Matrix4 Translation(float x, float y, float z);
	Matrix4 Rotation(float r);
	Matrix4 Scale(float x, float y, float z);


	float a11;
	float a12;
	float a13;
	float a14;
	float a21;
	float a22;
	float a23;
	float a24;
	float a31;
	float a32;
	float a33;
	float a34;
	float a41;
	float a42;
	float a43;
	float a44;

};









#endif // _MATHLIB_H