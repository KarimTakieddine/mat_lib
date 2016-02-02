#pragma once
#include "matrix3.hpp"
#include "vector4.hpp"

namespace mat_lib
{
	namespace type
	{
		template<typename T>
		struct Matrix4
		{
			Matrix4();

			explicit Matrix4
			(
				Vector4<T> const & u
			);

			explicit Matrix4
			(
				Vector4<T> const & x,
				Vector4<T> const & y,
				Vector4<T> const & z,
				Vector4<T> const & w
			);

			Matrix4
			(
				Matrix4<T> const & m
			);

			Matrix4<T> & operator=
			(
				Matrix4<T> const & m
			);

			Vector4<T> const & operator[]
			(
				size_t index
			) const;

			Vector4<T> & operator[]
			(
				size_t index	
			);

			inline T const * toPtr() const;

		private:
			Vector4<T> data[4];
		};

		template<typename T>
		inline bool operator==
		(
			Matrix4<T> const & l,
			Matrix4<T> const & r
		);

		template<typename T>
		inline bool operator!=
		(
			Matrix4<T> const & l,
			Matrix4<T> const & r
		);

		template<typename T>
		Matrix4<T> operator-
		(
			Matrix4<T> const & m
		);

		template<typename T>
		Matrix4<T> operator-
		(
			Matrix4<T> const & l,
			Matrix4<T> const & r
		);

		template<typename T>
		Matrix4<T> operator+
		(
			Matrix4<T> const & l,
			Matrix4<T> const & r
		);

		template<typename T>
		Matrix4<T> operator*
		(
			T			const & s,
			Matrix4<T>	const & m
		);

		template<typename T>
		Matrix4<T> operator*
		(
			Matrix4<T>	const & m,
			T			const & s
		);

		template<typename T>
		Matrix4<T> transpose
		(
			Matrix4<T> const & m
		);

		template<typename T>
		Matrix4<T> operator*
		(
			Matrix4<T> const & m,
			Vector4<T> const & v
		);
	
		template<typename T>
		Matrix4<T> operator*
		(
			Matrix4<T> const & l,
			Matrix4<T> const & r
		);

		template<typename T>
		T determinant
		(
			Matrix4<T> const & m
		);

		template<typename T>
		Matrix4<T> cofactor
		(
			Matrix4<T> const & m
		);

		template<typename T>
		Matrix4<T> adjoint
		(
			Matrix4<T> const & m
		);

		template<typename T>
		Matrix4<T> inverse
		(
			Matrix4<T> const & m
		);

		typedef Matrix4<float> FMAT4;

		const FMAT4 identity4F =
		FMAT4
		(
			FVEC4(1.0f, 0.0f, 0.0f, 0.0f), 
			FVEC4(0.0f, 1.0f, 0.0f, 0.0f),
			FVEC4(0.0f, 0.0f, 1.0f, 0.0f),
			FVEC4(0.0f, 0.0f, 0.0f, 1.0f)
		);
	};
};

#include "matrix4.inl"