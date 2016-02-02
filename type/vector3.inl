#include <cassert>

template<typename T>
mat_lib::type::Vector3<T>::Vector3()
:
x(T()),
y(T()),
z(T())
{ }

template<typename T>
mat_lib::type::Vector3<T>::Vector3
(
	T const & u
)
:
x(s),
y(s),
z(s)
{ }

template<typename T>
mat_lib::type::Vector3<T>::Vector3
(
	T const & x,
	T const & y,
	T const & z
)
:
x(x),
y(y),
z(z)
{ }

template<typename T>
mat_lib::type::Vector3<T>::Vector3
(
	Vector3<T> const & v
)
:
x(v.x),
y(v.y),
z(v.z)
{ }

template<typename T>
mat_lib::type::Vector3<T> & mat_lib::type::Vector3<T>::operator=
(
	Vector3<T> const & v
)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

template<typename T>
T const & mat_lib::type::Vector3<T>::operator[]
(
	size_t index
) const
{
	assert(index < 3);
	return (&x)[index];
}

template<typename T>
T & mat_lib::type::Vector3<T>::operator[]
(
	size_t index
)
{
	return const_cast<T &>(static_cast<Vector3<T> const &>(*this)[index]);
}

template<typename T>
T const * mat_lib::type::Vector3<T>::toPtr() const
{
	return &x;
}

template<typename T>
bool mat_lib::type::operator==
(
	Vector3<T> const & l,
	Vector3<T> const & r
)
{
	return (l.x == r.x) && (l.y == r.y) && (l.z == r.z);
}

template<typename T>
bool mat_lib::type::operator!=
(
	Vector3<T> const & l,
	Vector3<T> const & r
)
{
	return !(l == r);
}

template<typename T>
mat_lib::type::Vector3<T> mat_lib::type::operator-
(
	Vector3<T> const & v
)
{
	return Vector3<T>(-v.x, -v.y, -v.z);
}

template<typename T>
mat_lib::type::Vector3<T> mat_lib::type::operator-
(
	Vector3<T> const & l,
	Vector3<T> const & r
)
{
	return Vector3<T>(l.x - r.x, l.y - r.y, l.z - r.z);
}

template<typename T>
mat_lib::type::Vector3<T> mat_lib::type::operator+
(
	Vector3<T> const & l,
	Vector3<T> const & r
)
{
	return Vector3<T>(l.x + r.x, l.y + r.y, l.z + r.z);
}

template<typename T>
mat_lib::type::Vector3<T> mat_lib::type::operator*
(
	T			const & s,
	Vector3<T>	const & v	
)
{
	return Vector3<T>(s * v.x, s * v.y, s * v.z);
}

template<typename T>
mat_lib::type::Vector3<T> mat_lib::type::operator*
(
	Vector3<T>	const & v,
	T			const & s	
)
{
	return s * v;
}

template<typename T>
T mat_lib::type::operator*
(
	Vector3<T>	const & l,
	Vector3<T>	const & r
)
{
	return (l.x * r.x) + (l.y * r.y) + (l.z * r.z);
}