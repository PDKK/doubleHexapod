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
	Hexagon(char * vert, char * frag);
	virtual ~Hexagon();
	void draw();
};

#endif /* HEXAGON_H_ */
