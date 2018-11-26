///////////////////////////////////////////////////////////
//  TransformedObjet3D.cpp
//  Implementation of the Class TransformedObjet3D
//  Created on:      26-oct.-2018 17:42:19
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "TransformedObjet3D.h"

TransformedObjet3D::TransformedObjet3D(const PrimitiveAbs & obj3d, const Point3D & translat, float scal)
	: m_objet3d(obj3d.clone()), m_translation(translat), m_scale(scal)
{
}

TransformedObjet3D::TransformedObjet3D(const TransformedObjet3D & mdd)
	: m_objet3d(mdd.m_objet3d->clone()), m_scale(mdd.m_scale), m_translation(mdd.m_translation)
{
}

TransformedObjet3D::~TransformedObjet3D(){

}

void TransformedObjet3D::addChild(const Objet3DAbs& obj3d){
	// Deleguer a l'objet decore la tache d'ajouter un enfant
	m_objet3d.get()->addChild(obj3d);
}


Objet3DIterator TransformedObjet3D::begin()
{
	return m_objet3d.get()->begin();
}


Objet3DIterator_const TransformedObjet3D::cbegin() const {

	return m_objet3d.get()->cbegin();
}


Objet3DIterator_const TransformedObjet3D::cend() const {

	return m_objet3d.get()->cend();
}


Objet3DAbs* TransformedObjet3D::clone() const 
{
	return m_objet3d.get()->clone();
}


Objet3DIterator TransformedObjet3D::end()
{
	return m_objet3d.get()->end();
}


Point3D TransformedObjet3D::getCenter() const 
{
	return m_objet3d.get()->getCenter() + m_translation;
}


std::size_t TransformedObjet3D::getNbParameters() const 
{
	return m_objet3d.get()->getNbParameters();
}


PrimitiveParams TransformedObjet3D::getParameters() const 
{
	PrimitiveParams newParams = m_objet3d.get()->getParameters();
	for (int i = 0; i < newParams.size(); i++) {
		newParams[i] *= m_scale;
	}
	return newParams;
}


void TransformedObjet3D::moveCenter(const Point3D& delta){
	m_objet3d.get()->moveCenter(delta);
}


void TransformedObjet3D::removeChild(Objet3DIterator_const obj3dIt)
{
	// Deleguer a l'objet decore la tache d'eliminer un enfant
	m_objet3d.get()->removeChild(obj3dIt);
}


void TransformedObjet3D::setCenter(const Point3D& center){

	m_objet3d.get()->setCenter(center);
}


void TransformedObjet3D::setParameter(std::size_t pIndex, float pValue)
{
	m_objet3d.get()->setParameter(pIndex, pValue);
}

float TransformedObjet3D::getScale() const
{
	return m_scale;
}

void TransformedObjet3D::setScale(float scal)
{
	m_scale = scal;
}

Point3D TransformedObjet3D::getTranslation() const
{
	return m_translation;
}

void TransformedObjet3D::setTranslation(const Point3D & translat)
{
	m_translation = translat;
}


std::ostream& TransformedObjet3D::toStream(std::ostream& o) const 
{
	o << "Objet Transforme: OBJET={ " << *m_objet3d 
	  << " }, Translation = " << m_translation << ", Scale = " << m_scale << std::endl;

	return  o;
}