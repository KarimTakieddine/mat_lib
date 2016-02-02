#include <cassert>

template<typename T>
mat_lib::type::Matrix4<T>::Matrix4()
{
	data[0] = Vector4<T>();
	data[1] = Vector4<T>();
	data[2] = Vector4<T>();
	data[3] = Vector4<T>();
}

template<typename T>
mat_lib::type::Matrix4<T>::Matrix4
(
	Vector4<T> const & u
)
{
	data[0] = u;
	data[1] = u;
	data[2] = u;
	data[3] = u;
}

template<typename T>
mat_lib::type::Matrix4<T>::Matrix4
(
	Vector4<T> const & x,
	Vector4<T> const & y,
	Vector4<T> const & z,
	Vector4<T> const & w
)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
	data[3] = w;
}

template<typename T>
mat_lib::type::Matrix4<T>::Matrix4
(
	Matrix4<T> const & m
)
{
	data[0] = m[0];
	data[1] = m[1];
	data[2] = m[2];
	data[3] = m[3];
}

template<typename T>
mat_lib::type::Matrix4<T> & mat_lib::type::Matrix4<T>::operator=
(
	Matrix4<T> const & m
)
{
	data[0] = m[0];
	data[1] = m[1];
	data[2] = m[2];
	data[3] = m[3];
	return *this;
}

template<typename T>
mat_lib::type::Vector4<T> const & mat_lib::type::Matrix4<T>::operator[]
(
	size_t index
) const
{
	assert(index < 4);
	return data[index];
}

template<typename T>
mat_lib::type::Vector4<T> & mat_lib::type::Matrix4<T>::operator[]
(
	size_t index
)
{
	return const_cast<Vector4<T> &>(static_cast<Matrix4<T> const &>(*this)[index]);
}

template<typename T>
T const * mat_lib::type::Matrix4<T>::toPtr() const
{
	return &(data[0].x);
}

template<typename T>
bool mat_lib::type::operator==
(
	Matrix4<T> const & l,
	Matrix4<T> const & r
)
{
	return (l[0] == r[0]) && (l[1] == r[1]) && (l[2] == r[2]) && (l[3] == r[3]);
}

template<typename T>
bool mat_lib::type::operator!=
(
	Matrix4<T> const & l,
	Matrix4<T> const & r
)
{
	return !(l== r);
}

template<typename T>
mat_lib::type::Matrix4<T> mat_lib::type::operator-
(
	Matrix4<T> const & m
)
{
	return Matrix4<T>(-m[0], -m[1], -m[2], -m[3]);
}


template<typename T>
mat_lib::type::Matrix4<T> mat_lib::type::operator-
(
	Matrix4<T> const & l,
	Matrix4<T> const & r
)
{
	return Matrix4<T>(l[0] - r[0], l[1] - r[1], l[2] - r[2], l[3] - r[3]);
}

template<typename T>
mat_lib::type::Matrix4<T> mat_lib::type::operator+
(
	Matrix4<T> const & l,
	Matrix4<T> const & r
)
{
	return Matrix4<T>(l[0] + r[0], l[1] + r[1], l[2] + r[2], l[3] + r[3]);
}

template<typename T>
mat_lib::type::Matrix4<T> mat_lib::type::operator*
(
	T			const & s,
	Matrix4<T>	const & m
)
{
	return Matrix4<T>(s * m[0], s * m[1], s * m[2], s * m[3]);
}

template<typename T>
mat_lib::type::Matrix4<T> mat_lib::type::operator*
(
	Matrix4<T>	const & m,
	T			const & s
)
{
	return s * m;
}

template<typename T>
mat_lib::type::Matrix4<T> mat_lib::type::transpose
(
	Matrix4<T> const & m
)
{
	return
	Matrix4<T>
	(
		Vector4<T>(m[0].x, m[1].x, m[2].x, m[3].x),
		Vector4<T>(m[0].y, m[1].y, m[2].y, m[3].y),
		Vector4<T>(m[0].z, m[1].z, m[2].z, m[3].z),
		Vector4<T>(m[0].w, m[1].w, m[2].w, m[3].w)
	);
}

template<typename T>
mat_lib::type::Matrix4<T> mat_lib::type::operator*
(
	Matrix4<T> const & m,
	Vector4<T> const & v
)
{
	return Matrix4<T>(m[0] * v, m[1] * v, m[2] * v, m[3] * v);
}

template<typename T>
mat_lib::type::Matrix4<T> mat_lib::type::operator*
(
	Matrix4<T> const & l,
	Matrix4<T> const & r
)
{	
	Matrix4<T> t = transpose(r);
	return
	Matrix4<T>
	(
		Vector4<T>(l[0] * t[0], l[0] * t[1], l[0] * t[2], l[0] * t[3]),
		Vector4<T>(l[1] * t[0], l[1] * t[1], l[1] * t[2], l[1] * t[3]),
		Vector4<T>(l[2] * t[0], l[2] * t[1], l[2] * t[2], l[2] * t[3]),
		Vector4<T>(l[3] * t[0], l[3] * t[1], l[3] * t[2], l[3] * t[3])
	);
}

template<typename T>
T mat_lib::type::determinant
(
	Matrix4<T> const & m
)
{
	Matrix3<T> m_00
	(
		Vector3<T>(m[1].y, m[1].z, m[1].w),
		Vector3<T>(m[2].y, m[2].z, m[2].w),
		Vector3<T>(m[3].y, m[3].z, m[3].w)
	);

	Matrix3<T> m_01
	(
		Vector3<T>(m[1].x, m[1].z, m[1].w),
		Vector3<T>(m[2].x, m[2].z, m[2].w),
		Vector3<T>(m[3].x, m[3].z, m[3].w)
	);

	Matrix3<T> m_02
	(
		Vector3<T>(m[1].x, m[1].y, m[1].w),
		Vector3<T>(m[2].x, m[2].y, m[2].w),
		Vector3<T>(m[3].x, m[3].y, m[3].w)
	);

	Matrix3<T> m_03
	(
		Vector3<T>(m[1].x, m[1].y, m[1].z),
		Vector3<T>(m[2].x, m[2].y, m[2].z),
		Vector3<T>(m[3].x, m[3].y, m[3].z)
	);

	return (m[0].x * determinant(m_00)) - (m[0].y * determinant(m_01)) + (m[0].z * determinant(m_02)) - (m[0].w * determinant(m_03));
}

template<typename T>
mat_lib::type::Matrix4<T> mat_lib::type::cofactor
(
	Matrix4<T> const & m
)
{
	Matrix3<T> m_00
	(
		Vector3<T>(m[1].y, m[1].z, m[1].w),
		Vector3<T>(m[2].y, m[2].z, m[2].w),
		Vector3<T>(m[3].y, m[3].z, m[3].w)
	);

	Matrix3<T> m_01
	(
		Vector3<T>(m[1].x, m[1].z, m[1].w),
		Vector3<T>(m[2].x, m[2].z, m[2].w),
		Vector3<T>(m[3].x, m[3].z, m[3].w)
	);

	Matrix3<T> m_02
	(
		Vector3<T>(m[1].x, m[1].y, m[1].w),
		Vector3<T>(m[2].x, m[2].y, m[2].w),
		Vector3<T>(m[3].x, m[3].y, m[3].w)
	);

	Matrix3<T> m_03
	(
		Vector3<T>(m[1].x, m[1].y, m[1].z),
		Vector3<T>(m[2].x, m[2].y, m[2].z),
		Vector3<T>(m[3].x, m[3].y, m[3].z)
	);
	
	Matrix3<T> m_10
	(
		Vector3<T>(m[0].y, m[0].z, m[0].w),
		Vector3<T>(m[2].y, m[2].z, m[2].w),
		Vector3<T>(m[3].y, m[3].z, m[3].w)
	);

	Matrix3<T> m_11
	(
		Vector3<T>(m[0].x, m[0].z, m[0].w),
		Vector3<T>(m[2].x, m[2].z, m[2].w),
		Vector3<T>(m[3].x, m[3].z, m[3].w)
	);

	Matrix3<T> m_12
	(
		Vector3<T>(m[0].x, m[0].y, m[0].w),
		Vector3<T>(m[2].x, m[2].y, m[2].w),
		Vector3<T>(m[3].x, m[3].y, m[3].w)
	);

	Matrix3<T> m_13
	(
		Vector3<T>(m[0].x, m[0].y, m[0].z),
		Vector3<T>(m[2].x, m[2].y, m[2].z),
		Vector3<T>(m[3].x, m[3].y, m[3].z)
	);

	Matrix3<T> m_20
	(
		Vector3<T>(m[0].y, m[0].z, m[0].w),
		Vector3<T>(m[1].y, m[1].z, m[1].w),
		Vector3<T>(m[3].y, m[3].z, m[3].w)
	);

	Matrix3<T> m_21
	(
		Vector3<T>(m[0].x, m[0].z, m[0].w),
		Vector3<T>(m[1].x, m[1].z, m[1].w),
		Vector3<T>(m[3].x, m[3].z, m[3].w)
	);

	Matrix3<T> m_22
	(
		Vector3<T>(m[0].x, m[0].y, m[0].w),
		Vector3<T>(m[1].x, m[1].y, m[1].w),
		Vector3<T>(m[3].x, m[3].y, m[3].w)
	);

	Matrix3<T> m_23
	(
		Vector3<T>(m[0].x, m[0].y, m[0].z),
		Vector3<T>(m[1].x, m[1].y, m[1].z),
		Vector3<T>(m[3].x, m[3].y, m[3].z)
	);

	Matrix3<T> m_30
	(
		Vector3<T>(m[0].y, m[0].z, m[0].w),
		Vector3<T>(m[1].y, m[1].z, m[1].w),
		Vector3<T>(m[2].y, m[2].z, m[2].w)
	);

	Matrix3<T> m_31
	(
		Vector3<T>(m[0].x, m[0].z, m[0].w),
		Vector3<T>(m[1].x, m[1].z, m[1].w),
		Vector3<T>(m[2].x, m[2].z, m[2].w)
	);

	Matrix3<T> m_32
	(
		Vector3<T>(m[0].x, m[0].y, m[0].w),
		Vector3<T>(m[1].x, m[1].y, m[1].w),
		Vector3<T>(m[2].x, m[2].y, m[2].w)
	);

	Matrix3<T> m_33
	(
		Vector3<T>(m[0].x, m[0].y, m[0].z),
		Vector3<T>(m[1].x, m[1].y, m[1].z),
		Vector3<T>(m[2].x, m[2].y, m[2].z)
	);

	return
	Matrix4<T>
	(
		Vector4<T>(determinant(m_00), -determinant(m_01), determinant(m_02), -determinant(m_03)),
		Vector4<T>(-determinant(m_10), determinant(m_11), -determinant(m_12), determinant(m_13)),
		Vector4<T>(determinant(m_20), -determinant(m_21), determinant(m_22), -determinant(m_23)),
		Vector4<T>(-determinant(m_30), determinant(m_31), -determinant(m_32), determinant(m_33))
	);
}

template<typename T>
mat_lib::type::Matrix4<T> mat_lib::type::adjoint
(
	Matrix4<T> const & m
)
{
	return transpose(cofactor(m));
}

template<typename T>
mat_lib::type::Matrix4<T> mat_lib::type::inverse
(
	Matrix4<T> const & m
)
{
	T d = determinant(m);
	assert(d != 0);
	return (1 / d) * adjoint(m);
}