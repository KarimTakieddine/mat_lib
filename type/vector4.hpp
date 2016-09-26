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

			inline T const * toPtr() const;
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