/*! ========================================================================
** Extended Template and Library
** Utility Curve Template Class Implementations
** $Id: _curve_func.h 334 2007-03-16 00:37:48Z dooglus $
**
** Copyright (c) 2002 Robert B. Quattlebaum Jr.
**
** This package is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License as
** published by the Free Software Foundation; either version 2 of
** the License, or (at your option) any later version.
**
** This package is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** General Public License for more details.
**
** === N O T E S ===========================================================
**
** This is an internal header file, included by other ETL headers.
** You should not attempt to use it directly.
**
** ========================================================================= */

/* === S T A R T =========================================================== */

#ifndef __ETL__CURVE_FUNC_H
#define __ETL__CURVE_FUNC_H

/* === H E A D E R S ======================================================= */

#include <functional>

/* -- C L A S S E S --------------------------------------------------------- */

template <class T, class K=float>
struct affine_combo
{
	T operator()(const T &a,const T &b,const K &t)const
	{
		return T( (b-a)*t+a );
	}

	T reverse(const T &x, const T &b, const K &t)const
	{
		return T( (x-t*b)*(static_cast<K>(1)/(static_cast<K>(1)-t)) );
	}
};

template <class T, class K=float>
struct distance_func : public std::binary_function<T, T, K>
{
	K operator()(const T &a,const T &b)const
	{
		T delta=b-a;
		return static_cast<K>(delta*delta);
	}

	K cook(const K &x)const { return x*x; }
	K uncook(const K &x)const { return sqrt(x); }

};

/* -- E N D ----------------------------------------------------------------- */

#endif
