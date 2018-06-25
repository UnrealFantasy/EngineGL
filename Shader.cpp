//
//  Shader.cpp
//  Odyssey
//
//  Created by Dexter Burk on 6/24/18.
//  Copyright © 2018 Dexter Burk. All rights reserved.
//

#include "Shader.hpp"

#include <fstream>

Shader::Shader(const char* vertex, const char* fragment)
{
    programID = glCreateProgram();
    
    glAttachShader(programID, shader(vertex, GL_VERTEX_SHADER));
    glAttachShader(programID, shader(fragment, GL_FRAGMENT_SHADER));
    
    glLinkProgram(programID);
    glValidateProgram(programID);
}

void Shader::bind(bool use)
{
    if(use)
        glUseProgram(programID);
    else
        glUseProgram(0);
}

void Shader::s_matrix(const char* uniform, mat4 matrix)
{
    glUniformMatrix4fv(location(uniform), 1, GL_FALSE, &matrix[0][0]);
}

void Shader::s_vector(const char* uniform, vec4 vector)
{
    glUniform4f(location(uniform), vector.x, vector.y, vector.z, vector.w);
}

void Shader::s_vector(const char* uniform, vec3 vector)
{
     glUniform3f(location(uniform), vector.x, vector.y, vector.z);
}

void Shader::s_vector(const char* uniform, vec2 vector)
{
     glUniform2f(location(uniform), vector.x, vector.y);
}

void Shader::s_float(const char* uniform, float value)
{
    glUniform1f(location(uniform), value);
}

unsigned int Shader::shader(const char* glsl, GLenum type)
{
    unsigned int shaderID = glCreateShader(type);
    
    glShaderSource(shaderID, 1, &glsl, NULL);
    glCompileShader(shaderID);
    
    int success;
    char log[4096];
    
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    
    if(!success)
    {
        glGetShaderInfoLog(shaderID, 4096, NULL, log);
        
        cout << "Shader compilation failed.\n" << log << endl;
    }
    
    return shaderID;
}

string Shader::read(const char* file)
{
    ifstream in(file, ios::in);
    
    if (in.is_open())
    {
        
        char buffer[4096];
        
        while (!in.eof())
        {
            in.getline(buffer, 4096);
        }
        
        in.close();
        
        return buffer;
    }
    
    return nullptr;
}

unsigned int Shader::location(const char* uniform)
{
    return glGetUniformLocation(programID, uniform);
}
