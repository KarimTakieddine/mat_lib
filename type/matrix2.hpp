#pragma once
#include "vector2.hpp"

namespace mat_lib
{
	namespace type
	{
		template<typename T>
		struct Matrix2
		{
			Matrix2();

			explicit Matrix2
			(
				Vector2<T> const & u
			);

			explicit Matrix2
			(
				Vector2<T> const & x,
				Vector2<T> const & y
			);

			Matrix2
			(
				Matrix2<T> const & m
			);

			Matrix2 & operator=
			(
				Matrix2<T> const & m
			);

			Vector2<T> const & operator[]
			(
				size_t index
			) const;

			Vector2<T> & operator[]
			(
				size_t index
			);

			inline T const * toPtr() const;

		private:
			Vector2<T> data[2];
		};

		template<typename T>
		inline bool operator==
		(
			Matrix2<T> const & l,
			Matrix2<T> const & r
		);

		template<typename T>
		inline bool operator!=
		(
			Matrix2<T> const & l,
			Matrix2<T> const & r
		);

		template<typename T>
		Matrix2<T> operator-
		(
			Matrix2<T> const & m
		);

		template<typename T>
		Matrix2<T> operator-
		(
			Matrix2<T> const & l,
			Matrix2<T> const & r
		);

		template<typename T>
		Matrix2<T> operator+
		(
			Matrix2<T> const & l,
			Matrix2<T> const & r
		);

		template<typename T>
		Matrix2<T> operator*
		(
			T			const & s,
			Matrix2<T>	const & m
		);

		template<typename T>
		Matrix2<T> operator*
		(
			Matrix2<T>	const & m,
			T			const & s
		);

		template<typename T>
		Matrix2<T> transpose
		(
			Matrix2<T> const & m
		);

		template<typename T>
		Vector2<T> operator*
		(
			Matrix2<T> const & m,
			Vector2<T> const & v
		);

		template<typename T>
		Matrix2<T> operator*
		(
			Matrix2<T> const & l,
			Matrix2<T> const & r
		);

		template<typename T>
		T determinant
		(
			Matrix2<T> const & m
		);

		template<typename T>
		Matrix2<T> cofactor
		(
			Matrix2<T> const & m
		);

		template<typename T>
		Matrix2<T> adjoint
		(
			Matrix2<T> const & m
		);

		template<typename T>
		Matrix2<T> inverse
		(
			Matrix2<T> const & m
		);

		typedef Matrix2<float> FMAT2;

		const FMAT2 identity2F =
		FMAT2
		(
			FVEC2(1.0f, 0.0f), 
			FVEC2(0.0f, 1.0f)
		);
	};
};

#include "matrix2.inl"