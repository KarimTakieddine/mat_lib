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

			inline T const * toPtr() const;
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