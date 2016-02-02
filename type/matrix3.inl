#include <cassert>

template<typename T>
mat_lib::type::Matrix3<T>::Matrix3()
{
	data[0] = Vector3<T>();
	data[1] = Vector3<T>();
	data[2] = Vector3<T>();
}

template<typename T>
mat_lib::type::Matrix3<T>::Matrix3
(
	Vector3<T> const & u
)
{
	data[0] = u;
	data[1] = u;
	data[2] = u;
}

template<typename T>
mat_lib::type::Matrix3<T>::Matrix3
(
	Vector3<T> const & x,
	Vector3<T> const & y,
	Vector3<T> const & z
)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
}

template<typename T>
mat_lib::type::Matrix3<T>::Matrix3
(
	Matrix3<T> const & m
)
{
	data[0] = m[0];
	data[1] = m[1];
	data[2] = m[2];
}

template<typename T>
mat_lib::type::Matrix3<T> & mat_lib::type::Matrix3<T>::operator=
(
	Matrix3<T> const & m
)
{
	data[0] = m[0];
	data[1] = m[1];
	data[2] = m[2];
	return *this;
}

template<typename T>
mat_lib::type::Vector3<T> const & mat_lib::type::Matrix3<T>::operator[]
(
	size_t index
) const
{
	assert(index < 3);
	return data[index];
}

template<typename T>
mat_lib::type::Vector3<T> & mat_lib::type::Matrix3<T>::operator[]
(
	size_t index
)
{
	return const_cast<Vector3<T> &>(static_cast<Matrix3<T> const &>(*this)[index]);
}

template<typename T>
T const * mat_lib::type::Matrix3<T>::toPtr() const
{
	return &(data[0].x);
}

template<typename T>
bool mat_lib::type::operator==
(
	Matrix3<T> const & l,
	Matrix3<T> const & r
)
{
	return (l[0] == r[0]) && (l[1] == r[1]) && (l[2] == r[2]);
}

template<typename T>
bool mat_lib::type::operator!=
(
	Matrix3<T> const & l,
	Matrix3<T> const & r
)
{
	return !(l == r);
}

template<typename T>
mat_lib::type::Matrix3<T> mat_lib::type::operator-
(
	Matrix3<T> const & m
)
{
	return Matrix3<T>(-m[0], -m[1], -m[2]);
}

template<typename T>
mat_lib::type::Matrix3<T> mat_lib::type::operator-
(
	Matrix3<T> const & l,
	Matrix3<T> const & r
)
{
	return Matrix3<T>(l[0] - r[0], l[1] - r[1], l[2] - r[2]);
}

template<typename T>
mat_lib::type::Matrix3<T> mat_lib::type::operator+
(
	Matrix3<T> const & l,
	Matrix3<T> const & r
)
{
	return Matrix3<T>(l[0] + r[0], l[1] + r[1], l[2] + r[2]);
}

template<typename T>
mat_lib::type::Matrix3<T> mat_lib::type::operator*
(
	T			const & s,
	Matrix3<T>	const & m
)
{
	return Matrix3<T>(s * m[0], s * m[1], s * m[2]);
}

template<typename T>
mat_lib::type::Matrix3<T> mat_lib::type::operator*
(	
	Matrix3<T>	const & m,
	T			const & s
)
{
	return s * m;
}

template<typename T>
mat_lib::type::Matrix3<T> mat_lib::type::transpose
(
	Matrix3<T> const & m
)
{
	return
	Matrix3<T>
	(
		Vector3<T>(m[0].x, m[1].x, m[2].x),
		Vector3<T>(m[0].y, m[1].y, m[2].y),
		Vector3<T>(m[0].z, m[1].z, m[2].z)
	);
}

template<typename T>
mat_lib::type::Vector3<T> mat_lib::type::operator*
(
	Matrix3<T> const & m,
	Vector3<T> const & v
)
{
	return Vector3<T>(m[0] * v, m[1] * v, m[2] * v);
}

template<typename T>
mat_lib::type::Matrix3<T> mat_lib::type::operator*
(
	Matrix3<T> const & l,
	Matrix3<T> const & r
)
{
	Matrix3<T> t = transpose(r);
	return
	Matrix3<T>
	(
		Vector3<T>(l[0] * t[0], l[0] * t[1], l[0] * t[2]),
		Vector3<T>(l[1] * t[0], l[1] * t[1], l[1] * t[2]),
		Vector3<T>(l[1] * t[0], l[1] * t[1], l[2] * t[2])
	);
}

template<typename T>
T mat_lib::type::determinant
(
	Matrix3<T> const & m
)
{
	Matrix2<T> m_00
	(
		Vector2<T>(m[1].y, m[1].z),
		Vector2<T>(m[2].y, m[2].z)
	);

	Matrix2<T> m_01
	(
		Vector2<T>(m[1].x, m[1].z),
		Vector2<T>(m[2].x, m[2].z)
	);

	Matrix2<T> m_02
	(
		Vector2<T>(m[1].x, m[1].y),
		Vector2<T>(m[2].x, m[2].y)
	);

	return (m[0].x * determinant(m_00)) - (m[0].y * determinant(m_01)) + (m[0].z * determinant(m_02));
}

template<typename T>
mat_lib::type::Matrix3<T> mat_lib::type::cofactor
(
	Matrix3<T> const & m
)
{
	Matrix2<T> m_00
	(
		Vector2<T>(m[1].y, m[1].z),
		Vector2<T>(m[2].y, m[2].z)
	);

	Matrix2<T> m_01
	(
		Vector2<T>(m[1].x, m[1].z),
		Vector2<T>(m[2].x, m[2].z)
	);

	Matrix2<T> m_02
	(
		Vector2<T>(m[1].x, m[1].y),
		Vector2<T>(m[2].x, m[2].y)
	);

	Matrix2<T> m_10
	(
		Vector2<T>(m[0].y, m[0].z),
		Vector2<T>(m[2].y, m[2].z)
	);

	Matrix2<T> m_11
	(
		Vector2<T>(m[0].x, m[0].z),
		Vector2<T>(m[2].x, m[2].z)
	);

	Matrix2<T> m_12
	(
		Vector2<T>(m[0].x, m[0].y),
		Vector2<T>(m[2].x, m[2].y)
	);

	Matrix2<T> m_20
	(
		Vector2<T>(m[0].y, m[0].z),
		Vector2<T>(m[1].y, m[1].z)
	);

	Matrix2<T> m_21
	(
		Vector2<T>(m[0].x, m[0].z),
		Vector2<T>(m[1].x, m[1].z)
	);

	Matrix2<T> m_22
	(
		Vector2<T>(m[0].x, m[0].y),
		Vector2<T>(m[1].x, m[1].y)
	);

	return
	Matrix3<T>
	(
		Vector3<T>(determinant(m_00), -determinant(m_01), determinant(m_02)),
		Vector3<T>(-determinant(m_10), determinant(m_11), -determinant(m_12)),
		Vector3<T>(determinant(m_20), -determinant(m_21), determinant(m_22))
	);
}

template<typename T>
mat_lib::type::Matrix3<T> mat_lib::type::adjoint
(
	Matrix3<T> const & m
)
{
	return transpose(cofactor(m));
}

template<typename T>
mat_lib::type::Matrix3<T> mat_lib::type::inverse
(
	Matrix3<T> const & m
)
{
	T d = determinant(m);
	assert(d != 0);
	return (1 / d) * adjoint(m);
}