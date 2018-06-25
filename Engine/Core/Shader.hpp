//
//  Shader.hpp
//  Odyssey
//
//  Created by Dexter Burk on 6/24/18.
//  Copyright © 2018 Dexter Burk. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

using namespace std;
using namespace glm;

class Shader {
    unsigned int programID;
public:
    Shader(const char* vertex, const char* fragmnent);
    
    void bind(bool use);
    
    void s_matrix(const char* uniform, mat4 matrix);
    
    void s_vector(const char* uniform, vec4 vector);
    void s_vector(const char* uniform, vec3 vector);
    void s_vector(const char* uniform, vec2 vector);
    
    void s_float(const char* uniform, float value);
private:
    string read(const char* file);
    unsigned int shader(const char* glsl, GLenum type);
    
    unsigned int location(const char* uniform);
};

#endif
