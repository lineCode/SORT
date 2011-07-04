/*
 * filename :	lambert.cpp
 *
 * programmer :	Cao Jiayin
 */

// include the header file
#include "lambert.h"
#include "utility/define.h"
#include "geometry/vector.h"

// to be deleted
#include "managers/logmanager.h"

// evaluate bxdf
Spectrum Lambert::f( const Vector& wo , const Vector& wi ) const
{
	return R * INV_PI;
}

// sample a direction randomly
Spectrum Lambert::Sample_f( const Vector& wo , Vector& wi , float* pdf ) const
{
	LOG_ERROR<<"Not implemented."<<CRASH;

	return Spectrum();
}

