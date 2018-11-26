#if !defined(EA_8099F38C_C8A3_47d0_948F_c38A0B83FFB2__INCLUDED_)
#define EA_8099F38C_C8A3_47d0_948F_c38A0B83FFB2__INCLUDED_

#include "PrimitiveAbs.h"

class Torus : public PrimitiveAbs
{

public:
	Torus(const Point3D& pt, float R, float r);
	virtual ~Torus();
	virtual Torus* clone() const;

	virtual std::size_t getNbParameters() const;
	virtual PrimitiveParams getParameters() const;
	virtual void setParameter(std::size_t pIndex, float pValue);

private:
	virtual std::ostream& toStream(std::ostream& o) const;

	float m_dimensions[4];
};
#endif // !defined(EA_8099F38C_C8A3_47d0_948F_c38A0B83FFB2__INCLUDED_)
