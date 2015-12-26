#include <cassert>

template<typename T>
mat_lib::type::Vector2<T>::Vector2()
:
x(T()),
y(T())
{ }

template<typename T>
mat_lib::type::Vector2<T>::Vector2
(
	T const & u
)
:
x(u),
y(u)
{ }

template<typename T>
mat_lib::type::Vector2<T>::Vector2
(
	T const & x,
	T const & y
)
:
x(x),
y(y)
{ }

template<typename T>
mat_lib::type::Vector2<T>::Vector2
(
	Vector2<T> const & v
)
:
x(v.x),
y(v.y)
{ }

template<typename T>
mat_lib::type::Vector2<T> & mat_lib::type::Vector2<T>::operator=
(
	Vector2<T> const & v
)
{
	x = v.x;
	y = v.y;
	return *this;
}

template<typename T>
T const & mat_lib::type::Vector2<T>::operator[]
(
	size_t index
) const
{
	assert(index < 2);
	return (&x)[index];
}

template<typename T>
T & mat_lib::type::Vector2<T>::operator[]
(
	size_t index
)
{
	return const_cast<T &>(static_cast<Vector2<T> const &>(*this)[index]);
}

template<typename T>
T * mat_lib::type::Vector2<T>::toPtr()
{
	return &x;
}

template<typename T>
bool mat_lib::type::operator==
(
	Vector2<T> const & l,
	Vector2<T> const & r
)
{
	return (l.x == r.x) && (l.y == r.y);
}

template<typename T>
bool mat_lib::type::operator!=
(
	Vector2<T> const & l,
	Vector2<T> const & r
)
{
	return !(l == r);
}

template<typename T>
mat_lib::type::Vector2<T> mat_lib::type::operator-
(
	Vector2<T> const & v
)
{
	return Vector2<T>(-v.x, -v.y);
}

template<typename T>
mat_lib::type::Vector2<T> mat_lib::type::operator-
(
	Vector2<T> const & l,
	Vector2<T> const & r
)
{
	return Vector2<T>(l.x - r.x, l.y - r.y);
}

template<typename T>
mat_lib::type::Vector2<T> mat_lib::type::operator+
(
	Vector2<T> const & l,
	Vector2<T> const & r
)
{
	return Vector2<T>(l.x + r.x, l.y + r.y);
}

template<typename T>
mat_lib::type::Vector2<T> mat_lib::type::operator*
(
	T			const & s,
	Vector2<T>	const & v
)
{
	return Vector2<T>(s * v.x, s * v.y);
}

template<typename T>
mat_lib::type::Vector2<T> mat_lib::type::operator*
(
	Vector2<T>	const & v,
	T			const & s
)
{
	return s * v;
}

template<typename T>
T mat_lib::type::operator*
(
	Vector2<T> const & l,
	Vector2<T> const & r
)
{
	return (l.x * r.x) + (l.y * r.y);
}