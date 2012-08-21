/*
 * Hexagon.h
 *
 *  Created on: Aug 21, 2012
 *      Author: paul
 */

#ifndef HEXAGON_H_
#define HEXAGON_H_

#include "DrawableObject.h"

class Hexagon: public DrawableObject {
public:
	Hexagon();
	virtual ~Hexagon();
	kmMat4 * getModelMatrix();
	GLfloat * getVertexData();
	GLfloat * getColorData();
private:
	kmMat4 model;
};

#endif /* HEXAGON_H_ */
