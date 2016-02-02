#include <cassert>

template<typename T>
mat_lib::type::Matrix2<T>::Matrix2()
{
	data[0] = mat_lib::type::Vector2<T>();
	data[1] = mat_lib::type::Vector2<T>();
}

template<typename T>
mat_lib::type::Matrix2<T>::Matrix2
(
	Vector2<T> const & u
)
{
	data[0] = u;
	data[1] = u;
}

template<typename T>
mat_lib::type::Matrix2<T>::Matrix2
(
	Vector2<T> const & x,
	Vector2<T> const & y
)
{
	data[0] = x;
	data[1] = y;
}

template<typename T>
mat_lib::type::Matrix2<T>::Matrix2
(
	Matrix2<T> const & m
)
{
	data[0] = m[0];
	data[1] = m[1];
}

template<typename T>
mat_lib::type::Matrix2<T> & mat_lib::type::Matrix2<T>::operator=
(
	Matrix2<T> const & m
)
{
	data[0] = m[0];
	data[1] = m[1];
	return *this;
}

template<typename T>
mat_lib::type::Vector2<T> const & mat_lib::type::Matrix2<T>::operator[]
(
	size_t index
) const
{
	assert(index < 2);
	return data[index];
}

template<typename T>
mat_lib::type::Vector2<T> & mat_lib::type::Matrix2<T>::operator[]
(
	size_t index
)
{
	return const_cast<Vector2<T> &>(static_cast<Matrix2<T> const &>(*this)[index]);
}

template<typename T>
T const * mat_lib::type::Matrix2<T>::toPtr() const
{
	return &(data[0].x);
}

template<typename T>
bool mat_lib::type::operator==
(
	Matrix2<T> const & l,
	Matrix2<T> const & r
)
{
	return (l[0] == r[0]) && (l[1] == r[1]);
}

template<typename T>
bool mat_lib::type::operator!=
(
	Matrix2<T> const & l,
	Matrix2<T> const & r
)
{
	return !(l == r);
}

template<typename T>
mat_lib::type::Matrix2<T> mat_lib::type::operator-
(
	Matrix2<T> const & m
)
{
	return Matrix2<T>(-m[0], -m[1]);
}

template<typename T>
mat_lib::type::Matrix2<T> mat_lib::type::operator-
(
	Matrix2<T> const & l,
	Matrix2<T> const & r
)
{
	return Matrix2<T>(l[0] - r[0], l[1] - r[1]);
}

template<typename T>
mat_lib::type::Matrix2<T> mat_lib::type::operator+
(
	Matrix2<T> const & l,
	Matrix2<T> const & r
)
{
	return Matrix2<T>(l[0] + r[0], l[1] + r[1]);
}

template<typename T>
mat_lib::type::Matrix2<T> mat_lib::type::operator*
(
	T			const & s,
	Matrix2<T>	const & m
)
{
	return Matrix2<T>(s * m[0], s * m[1]);
}

template<typename T>
mat_lib::type::Matrix2<T> mat_lib::type::operator*
(
	Matrix2<T>	const & m,
	T			const & s
)
{
	return s * m;
}

template<typename T>
mat_lib::type::Matrix2<T> mat_lib::type::transpose
(
	Matrix2<T> const & m
)
{
	return
	Matrix2<T>
	(
		Vector2<T>(m[0].x, m[1].x),
		Vector2<T>(m[0].y, m[1].y)
	);
}

template<typename T>
mat_lib::type::Vector2<T> mat_lib::type::operator*
(
	Matrix2<T> const & m,
	Vector2<T> const & v
)
{
	return Vector2<T>(m[0] * v, m[1] * v);
}

template<typename T>
mat_lib::type::Matrix2<T> mat_lib::type::operator*
(
	Matrix2<T> const & l,
	Matrix2<T> const & r
)
{
	Matrix2<T> t = transpose(r);
	return
	Matrix2<T>
	(
		Vector2<T>(l[0] * t[0], l[0] * t[1]),
		Vector2<T>(l[1] * t[0], l[1] * t[1])
	);
}

template<typename T>
T mat_lib::type::determinant
(
	Matrix2<T> const & m
)
{
	return (m[0].x * m[1].y) - (m[0].y * m[1].x);
}

template<typename T>
mat_lib::type::Matrix2<T> mat_lib::type::cofactor
(
	Matrix2<T> const & m
)
{
	return
	Matrix2<T>
	(
		Vector2<T>(m[1].y, -m[1].x),
		Vector2<T>(-m[0].y, m[0].x)
	);
}

template<typename T>
mat_lib::type::Matrix2<T> mat_lib::type::adjoint
(
	Matrix2<T> const & m
)
{
	return transpose(cofactor(m));
}

template<typename T>
mat_lib::type::Matrix2<T> mat_lib::type::inverse
(
	Matrix2<T> const & m
)
{
	T d = determinant(m);
	assert(d != 0);
	return (1 / d) * adjoint(m);
}