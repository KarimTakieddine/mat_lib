#include <cassert>

template<typename T>
mat_lib::type::Vector4<T>::Vector4()
:
x(T()),
y(T()),
z(T()),
w(T())
{ }

template<typename T>
mat_lib::type::Vector4<T>::Vector4
(
	T const & u
)
:
x(u),
y(u),
z(u),
w(u)
{ }

template<typename T>
mat_lib::type::Vector4<T>::Vector4
(
	T const & x,
	T const & y,
	T const & z,
	T const & w
)
:
x(x),
y(y),
z(z),
w(w)
{ }

template<typename T>
mat_lib::type::Vector4<T>::Vector4
(
	Vector4<T> const & v
)
:
x(v.x),
y(v.y),
z(v.z),
w(v.w)
{ }

template<typename T>
mat_lib::type::Vector4<T> & mat_lib::type::Vector4<T>::operator=
(
	Vector4<T> const & v
)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
	return *this;
}

template<typename T>
T const & mat_lib::type::Vector4<T>::operator[]
(
	size_t index
) const
{
	assert(index < 4);
	return (&x)[index];
}

template<typename T>
T & mat_lib::type::Vector4<T>::operator[]
(
	size_t index
)
{
	return const_cast<T &>(static_cast<Vector4<T> const &>(*this)[index]);
}

template<typename T>
T * mat_lib::type::Vector4<T>::toPtr()
{
	return &x;
}

template<typename T>
bool mat_lib::type::operator==
(
	Vector4<T> const & l,
	Vector4<T> const & r
)
{
	return (l.x == r.x) && (l.y == r.y) && (l.z == r.z) && (l.w == r.w);
}

template<typename T>
bool mat_lib::type::operator!=
(
	Vector4<T> const & l,
	Vector4<T> const & r
)
{
	return !(l == r);
}

template<typename T>
mat_lib::type::Vector4<T> mat_lib::type::operator-
(
	Vector4<T> const & v
)
{
	return Vector4<T>(-v.x, -v.y, -v.z, -v.w);
}

template<typename T>
mat_lib::type::Vector4<T> mat_lib::type::operator-
(
	Vector4<T> const & l,
	Vector4<T> const & r
)
{
	return	Vector4<T>(l.x - r.x, l.y - r.y, l.z - r.z, l.w - r.w);
}

template<typename T>
mat_lib::type::Vector4<T> mat_lib::type::operator+
(
	Vector4<T> const & l,
	Vector4<T> const & r
)
{
	return Vector4<T>(l.x + r.x, l.y + r.y, l.z + r.z, l.w + r.w);
}

template<typename T>
mat_lib::type::Vector4<T> mat_lib::type::operator*
(
	T			const & s,
	Vector4<T>	const & v
)
{
	return Vector4<T>(s * v.x, s * v.y, s * v.z, s * v.w);
}

template<typename T>
mat_lib::type::Vector4<T> mat_lib::type::operator*
(
	Vector4<T>	const & v,
	T			const & s
)
{
	return s * v;
}

template<typename T>
T mat_lib::type::operator*
(
	Vector4<T> const & l,
	Vector4<T> const & r
)
{
	return (l.x * r.x) + (l.y * r.y) + (l.z * r.z) + (l.w * r.w);
}