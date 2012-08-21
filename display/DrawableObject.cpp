/*
 * DrawableObject.cpp
 *
 *  Created on: Aug 21, 2012
 *      Author: paul
 */
#include <iostream>
#include <exception>
extern "C" {
#include "support.h"
}
#include "DrawableObject.h"

class drawableObjectCreationException: public std::exception {
	std::string extra;
public:
	drawableObjectCreationException(std::string m):extra(m){};
	~drawableObjectCreationException() throw() {};

	virtual const char* what() const throw () {
		std::string result("drawableObjectCreationException:");
		result.append(extra);
		return result.c_str();
	}
};

DrawableObject::DrawableObject(char * vertShader, char * fragShader) {
	GLint link_ok = GL_FALSE;

	GLuint vs, fs;
	if ((vs = create_shader(vertShader, GL_VERTEX_SHADER)) == 0)
		throw new drawableObjectCreationException("");
	if ((fs = create_shader(fragShader, GL_FRAGMENT_SHADER)) == 0)
		throw new drawableObjectCreationException("");

	program = glCreateProgram();
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &link_ok);
	if (!link_ok) {
		print_log(program);
		throw new drawableObjectCreationException("glLinkProgram");
	}

	vert_attrib = getShaderLocation(shaderAttrib, program, "vertex_attrib");
	tex_attrib = getShaderLocation(shaderAttrib, program, "uv_attrib");
	norm_attrib = getShaderLocation(shaderAttrib, program, "norm_attrib");
	mvp_uniform = getShaderLocation(shaderUniform, program, "mvp_uniform");
	mv_uniform = getShaderLocation(shaderUniform, program, "mv_uniform");
	tex_uniform = getShaderLocation(shaderUniform, program, "u_texture");
	lightDir_uniform = getShaderLocation(shaderUniform, program, "u_lightDir");
	viewDir_uniform = getShaderLocation(shaderUniform, program, "u_viewDir");

}

DrawableObject::~DrawableObject() {
	// TODO Auto-generated destructor stub
}

