/*
 * Hexagon.cpp
 *
 *  Created on: Aug 21, 2012
 *      Author: paul
 */
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include "kazmath.h"
#include "Hexagon.h"

Hexagon::Hexagon(char * vert, char * frag):DrawableObject(vert, frag){
	// TODO Auto-generated constructor stub

}

Hexagon::~Hexagon() {
	// TODO Auto-generated destructor stub
}

void Hexagon::draw() {
    glUseProgram(program);

//    glUniformMatrix4fv(mvp_uniform, 1, GL_FALSE, (GLfloat *) combined);
//    glUniformMatrix4fv(mv_uniform, 1, GL_FALSE, (GLfloat *) mv);
//
//    glUniform1i(tex_uniform, 0);
//
//    glUniform3f(viewDir_uniform,viewDir.x,viewDir.y,viewDir.z);
//    glUniform3f(lightDir_uniform,lightDir.x,lightDir.y,lightDir.z);
//
//    glEnableVertexAttribArray(vert_attrib);
//    glBindBuffer(GL_ARRAY_BUFFER, obj->vbo_vert);
//    glVertexAttribPointer(obj->vert_attrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
//
//    glEnableVertexAttribArray(norm_attrib);
//    glBindBuffer(GL_ARRAY_BUFFER, obj->vbo_norm);
//    glVertexAttribPointer(obj->norm_attrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
//
//    glEnableVertexAttribArray(tex_attrib);
//    glBindBuffer(GL_ARRAY_BUFFER, obj->vbo_tex);
//    glVertexAttribPointer(obj->tex_attrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
//
//    glDrawArrays(GL_TRIANGLES, 0, num_verts);
//
//    glDisableVertexAttribArray(obj->tex_attrib);
//    glDisableVertexAttribArray(obj->vert_attrib);
//    glDisableVertexAttribArray(obj->norm_attrib);

}

