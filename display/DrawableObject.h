/*
 * DrawableObject.h
 *
 *  Created on: Aug 21, 2012
 *      Author: paul
 */

#ifndef DRAWABLEOBJECT_H_
#define DRAWABLEOBJECT_H_

class DrawableObject {
public:
	DrawableObject(char * vert, char * frag);
	virtual ~DrawableObject();
protected:

    GLint program;
    GLint vert_attrib;
    GLint tex_attrib;
    GLint norm_attrib;
    GLint mvp_uniform;
    GLint mv_uniform;
    GLint tex_uniform;
    GLint lightDir_uniform;
    GLint viewDir_uniform;

};

#endif /* DRAWABLEOBJECT_H_ */
