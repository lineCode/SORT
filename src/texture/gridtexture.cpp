/*
 * filename :	gridtexture.cpp
 *
 * programmer :	Cao Jiayin
 */

// include the header file
#include "gridtexture.h"

// default constructor
GridTexture::GridTexture():
	m_Color0( 1.0f , 1.0f , 1.0f ),
	m_Color1( 0.0f , 0.0f , 0.0f )
{
	_init();
}

// constructor from two colors
GridTexture::GridTexture( const Spectrum& c0 , const Spectrum& c1 )
{
	m_Color0 = c0;
	m_Color1 = c1;

	_init();
}

// constructor from six float
GridTexture::GridTexture( 	float r0 , float g0 , float b0 , 
							float r1 , float g1 , float b1 ):
	m_Color0( r0 , g0 , b0 ) , m_Color1( r1 , g1 , b1 )
{
	_init();
}

// destructor
GridTexture::~GridTexture()
{
}

// overwrite init method
void GridTexture::_init()
{
	// by default , the width and height if not zero
	// because making width and height none zero costs nothing
	// while makeing them zero forbids showing the texture
	m_iTexWidth = 16;
	m_iTexHeight = 16;

	m_Threshold = 0.9f;

	// register all properties
	_registerAllProperty();
}

// get the color
Spectrum GridTexture::GetColor( int x , int y ) const 
{
	// filter the coorindate first
	_texCoordFilter( x , y );

	// return the color
	int delta_x = ( x - (int)m_iTexWidth / 2 );
	int delta_y = ( y - (int)m_iTexHeight / 2 );

	// the size for the center grid
	float w_size = ( m_iTexWidth * 0.5f * m_Threshold );
	float h_size = ( m_iTexHeight * 0.5f * m_Threshold );

	if( delta_x <= w_size && delta_x > -w_size && 
		delta_y <= h_size && delta_y > -h_size )
		return m_Color1;
	else
		return m_Color0;
}

// register properties
void GridTexture::_registerAllProperty()
{
	_registerProperty( "color0" , new Color0Property( this ) );
	_registerProperty( "color1" , new Color1Property( this ) );
	_registerProperty( "threshold" , new ThresholdProperty( this ) );
}