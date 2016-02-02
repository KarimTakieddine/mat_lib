#pragma once
#include "matrix2.hpp"
#include "vector3.hpp"

namespace mat_lib
{
	namespace type
	{
		template<typename T>
		struct Matrix3
		{
			Matrix3();

			explicit Matrix3
			(
				Vector3<T> const & u
			);

			explicit Matrix3
			(
				Vector3<T> const & x,
				Vector3<T> const & y,
				Vector3<T> const & z
			);

			Matrix3
			(
				Matrix3<T> const & m
			);
		
			Matrix3<T> & operator=
			(
				Matrix3<T> const & m
			);

			Vector3<T> const & operator[]
			(
				size_t index
			) const;

			Vector3<T> & operator[]
			(
				size_t index
			);

			inline T const * toPtr() const;

		private:
			Vector3<T> data[3];
		};

		template<typename T>
		inline bool operator==
		(
			Matrix3<T> const & l,
			Matrix3<T> const & r
		);

		template<typename T>
		inline bool operator!=
		(
			Matrix3<T> const & l,
			Matrix3<T> const & r
		);

		template<typename T>
		Matrix3<T> operator-
		(
			Matrix3<T> const & m
		);

		template<typename T>
		Matrix3<T> operator-
		(
			Matrix3<T> const & l,
			Matrix3<T> const & r
		);

		template<typename T>
		Matrix3<T> operator+
		(
			Matrix3<T> const & l,
			Matrix3<T> const & r
		);

		template<typename T>
		Matrix3<T> operator*
		(
			T			const & s,
			Matrix3<T>	const & m
		);

		template<typename T>
		Matrix3<T> operator*
		(	
			Matrix3<T>	const & m,
			T			const & s
		);

		template<typename T>
		Matrix3<T> transpose
		(
			Matrix3<T> const & m
		);

		template<typename T>
		Vector3<T> operator*
		(	
			Matrix3<T> const & m,
			Vector3<T> const & v
		);

		template<typename T>
		Matrix3<T> operator*
		(
			Matrix3<T> const & l,
			Matrix3<T> const & r
		);

		template<typename T>
		T determinant
		(
			Matrix3<T> const & m
		);

		template<typename T>
		Matrix3<T> cofactor
		(
			Matrix3<T> const & m
		);

		template<typename T>
		Matrix3<T> adjoint
		(
			Matrix3<T> const & m
		);

		template<typename T>
		Matrix3<T> inverse
		(
			Matrix3<T> const & m
		);

		typedef Matrix3<float> FMAT3;

		const FMAT3 identity3F =
		FMAT3
		(
			FVEC3(1.0f, 0.0f, 0.0f), 
			FVEC3(0.0f, 1.0f, 0.0f),
			FVEC3(0.0f, 0.0f, 1.0f)
		);
	};
};

#include "matrix3.inl"