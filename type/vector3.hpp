#pragma once

namespace mat_lib
{
	namespace type
	{
		template<typename T>
		struct Vector3
		{
			T x, y, z;

			Vector3();

			explicit Vector3
			(
				T const & u
			);

			explicit Vector3
			(
				T const & x,
				T const & y,
				T const & z
			);

			Vector3
			(
				Vector3<T> const & v
			);

			Vector3<T> & operator=
			(
				Vector3<T> const & v
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
			Vector3<T> const & l,
			Vector3<T> const & r
		);

		template<typename T>
		inline bool operator!=
		(
			Vector3<T> const & l,
			Vector3<T> const & r
		);

		template<typename T>
		Vector3<T> operator-
		(
			Vector3<T> const & v
		);

		template<typename T>
		Vector3<T> operator-
		(
			Vector3<T> const & l,
			Vector3<T> const & r
		);

		template<typename T>
		Vector3<T> operator+
		(
			Vector3<T> const & l,
			Vector3<T> const & r
		);

		template<typename T>
		Vector3<T> operator*
		(
			T			const & s,
			Vector3<T>	const & v
		);

		template<typename T>
		Vector3<T> operator*
		(
			Vector3<T>	const & v,
			T			const & s
		);

		template<typename T>
		T operator*
		(
			Vector3<T> const & l,
			Vector3<T> const & r
		);

		typedef Vector3<float> FVEC3;
	};
};

#include "vector3.inl"