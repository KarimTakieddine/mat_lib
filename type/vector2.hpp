#pragma once

namespace mat_lib
{
	namespace type
	{
		template<typename T>
		struct Vector2
		{
			T x, y;

			Vector2();

			explicit Vector2
			(
				T const & u
			);

			explicit Vector2
			(
				T const & x,
				T const & y
			);

			Vector2
			(
				Vector2<T> const & v
			);

			Vector2<T> & operator=
			(
				Vector2<T> const & v
			);

			inline T const & operator[]
			(
				size_t index
			) const;

			inline T & operator[]
			(
				size_t index
			);

			inline T * toPtr() const;
		};

		template<typename T>
		inline bool operator==
		(
			Vector2<T> const & l,
			Vector2<T> const & r
		);

		template<typename T>
		inline bool operator!=
		(
			Vector2<T> const & l,
			Vector2<T> const & r
		);

		template<typename T>
		Vector2<T> operator-
		(
			Vector2<T> const & v
		);

		template<typename T>
		Vector2<T> operator-
		(
			Vector2<T> const & l,
			Vector2<T> const & r
		);

		template<typename T>
		Vector2<T> operator+
		(
			Vector2<T> const & l,
			Vector2<T> const & r
		);

		template<typename T>
		Vector2<T> operator*
		(
			T			const & s,
			Vector2<T>	const & v
		);

		template<typename T>
		Vector2<T> operator*
		(
			Vector2<T>	const & v,
			T			const & s
		);

		template<typename T>
		T operator*
		(
			Vector2<T> const & l,
			Vector2<T> const & r
		);

		typedef Vector2<float> FVEC2;
	};
};

#include "vector2.inl"