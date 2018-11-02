///////////////////////////////////////////////////////////
//  Objet3DComposite.cpp
//  Implementation of the Class Objet3DComposite
//  Created on:      25-oct.-2018 20:40:33
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Objet3DComposite.h"


Objet3DComposite::Objet3DComposite(){

}

Objet3DComposite::Objet3DComposite(const Objet3DComposite & mdd)
{
	for (int i = 0; i < mdd.m_objetContainer.size(); i++) {
		addChild(*mdd.m_objetContainer[i]);
	}
}

Objet3DComposite::~Objet3DComposite(){
}

Objet3DComposite * Objet3DComposite::clone() const
{
	return new Objet3DComposite(*this);
}

void Objet3DComposite::addChild(const Objet3DAbs& obj3d)
{
	Objet3DAbs* ptr = obj3d.clone();
	m_objetContainer.push_back((Objet3DPtr)ptr);

	//std::unique_ptr<Objet3DAbs> objetPtr (obj3d.clone());
	//m_objetContainer.push_back(objetPtr);
}

Objet3DIterator Objet3DComposite::begin(){

	return m_objetContainer.begin();
}

Objet3DIterator_const Objet3DComposite::cbegin() const {

	return m_objetContainer.cbegin();
}

Objet3DIterator_const Objet3DComposite::cend() const {

	return m_objetContainer.cend();
}

Objet3DIterator Objet3DComposite::end(){

	return m_objetContainer.end();
}

Point3D Objet3DComposite::getCenter() const {
	
	return computeCenter();
}

std::size_t Objet3DComposite::getNbParameters() const 
{
	return 0;
}

PrimitiveParams Objet3DComposite::getParameters() const {

	return  PrimitiveParams();
}

void Objet3DComposite::removeChild(Objet3DIterator_const obj3dIt)
{
	m_objetContainer.erase(obj3dIt);
}

void Objet3DComposite::moveCenter(const Point3D & delta)
{
	for (int i = 0; i < m_objetContainer.size(); i++) {
		m_objetContainer[i]->moveCenter(delta);
	}
}

void Objet3DComposite::setCenter(const Point3D& center){

	Point3D oldCenter = getCenter();
	Point3D delta =  center - oldCenter;
	moveCenter(delta);
}

void Objet3DComposite::setParameter(std::size_t pIndex, float pValue){

}

Point3D Objet3DComposite::computeCenter() const
{
	// Calcul la moyenne des centres de tous les enfants
	// S'il n'y a pas d'enfant, initialise a (0,0,0)
	Point3D moyenne = Point3D(0, 0, 0);
	for (int i = 0; i < m_objetContainer.size(); i++) {
		moyenne += m_objetContainer[i]->getCenter();
	}
	moyenne /= m_objetContainer.size();
	return moyenne;
}

// Variable statique permettant de stocker le niveau d'indentation
std::size_t Objet3DComposite::outputIndent = 0;

std::ostream& indentation(std::ostream& o, std::size_t indentLevel)
{
	for (auto iindent = 0; iindent < indentLevel; ++iindent)
		o << "\t";
	return o;
}

std::ostream & Objet3DComposite::toStream(std::ostream & o) const
{
	o << "Composite: center = " << computeCenter() << ": {" << std::endl;
	++outputIndent;
	for (auto it = cbegin(); it != cend(); ++it)
		indentation(o, outputIndent) << *it << std::endl;
	--outputIndent;
	indentation(o, outputIndent) << "}";

	return o;
}
