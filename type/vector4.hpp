#pragma once

namespace mat_lib
{
	namespace type
	{
		template<typename T>
		struct Vector4
		{
			T x, y, z, w;

			Vector4();

			explicit Vector4
			(
				T const & u
			);

			explicit Vector4
			(
				T const & x,
				T const & y,
				T const & z,
				T const & w
			);

			Vector4
			(
				Vector4<T> const & v
			);

			Vector4<T> & operator=
			(
				Vector4<T> const & v
			);

			inline T const & operator[]
			(
				size_t index
			) const;

			inline T & operator[]
			(
				size_t index
			);

			inline T * toPtr();
		};

		template<typename T>
		inline bool operator==
		(
			Vector4<T> const & l,
			Vector4<T> const & r
		);

		template<typename T>
		inline bool operator!=
		(
			Vector4<T> const & l,
			Vector4<T> const & r
		);

		template<typename T>
		Vector4<T> operator-
		(
			Vector4<T> const & v
		);

		template<typename T>
		Vector4<T> operator-
		(
			Vector4<T> const & l,
			Vector4<T> const & r
		);

		template<typename T>
		Vector4<T> operator+
		(
			Vector4<T> const & l,
			Vector4<T> const & r
		);

		template<typename T>
		Vector4<T> operator*
		(
			T			const & s,
			Vector4<T>	const & v
		);

		template<typename T>
		Vector4<T> operator*
		(
			Vector4<T>	const & v,
			T			const & s
		);

		template<typename T>
		T operator*
		(
			Vector4<T> const & l,
			Vector4<T> const & r
		);

		typedef Vector4<float> FVEC4;
	};
};

#include "vector4.inl"