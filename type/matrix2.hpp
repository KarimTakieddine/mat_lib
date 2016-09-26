/* ----------------------------------------------------------------------------------------------------- *\

Copyright(c) 2016 Karim Takieddine

Permission is hereby granted, free of charge, to any person obtaining a copy of this software
and associated documentation files(the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
and / or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions :

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN
NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

\* ----------------------------------------------------------------------------------------------------- */

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