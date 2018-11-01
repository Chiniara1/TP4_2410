//A TESTER

#include "Torus.h"


Torus::Torus(const Point3D& pt, float R, float r, float theta, float phi)
	: PrimitiveAbs(pt)
{
	if (R < 0.0 || r < 0.0 || theta < 0.0 || theta > 360.0 || phi < 0.0 || phi > 360.0)
		throw std::range_error("Invalid dimension value for Torus. Must be larger than 0");
	m_dimensions[0] = R;
	m_dimensions[1] = r;
	m_dimensions[2] = theta;
	m_dimensions[3] = phi;
}

Torus::~Torus() {
}

Torus * Torus::clone() const
{
	Torus* newTorus = new Torus(getCenter(), m_dimensions[0], m_dimensions[1], m_dimensions[2], m_dimensions[3]);

	return newTorus;
}

std::size_t Torus::getNbParameters() const {

	return 4;
}

PrimitiveParams Torus::getParameters() const
{
	PrimitiveParams params = PrimitiveParams();
	params.push_back(m_dimensions[0]);
	params.push_back(m_dimensions[1]);
	params.push_back(m_dimensions[2]);
	params.push_back(m_dimensions[3]);
	return params;
}

void Torus::setParameter(std::size_t pIndex, float pValue) {
	if (pIndex < 0 || pIndex > 3)
		throw std::range_error("Invalid parameter index for Torus. Must be between 0 and 2");

	if (pValue<0.0)
		throw std::range_error("Invalid dimension value for Torus. Must be larger than 0");

	m_dimensions[pIndex] = pValue;
}

std::ostream & Torus::toStream(std::ostream & o) const
{
	return o << "Torus:      center = " << m_center
		<< "; R = " << m_dimensions[0]
		<< "; r = " << m_dimensions[1]
		<< "; theta = " << m_dimensions[2] 
		<< "; phi = " << m_dimensions[3] << ";";
}