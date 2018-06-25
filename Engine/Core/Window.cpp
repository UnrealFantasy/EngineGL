//
//  Window.cpp
//  Odyssey
//
//  Created by Dexter Burk on 6/24/18.
//  Copyright © 2018 Dexter Burk. All rights reserved.
//

#include "Window.hpp"

Window::Window(int width, int height, const char* title)
{
    Window::width = width;
    Window::height = height;
    Window::title = title;
}

void Window::create()
{
    if(!glfwInit())
    {
        cout << "GLFW failed to initialize." << endl;
        
        glfwTerminate();
    }
    
    glfwDefaultWindowHints();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    
    handle = glfwCreateWindow(width, height, title, NULL, NULL);
    
    if(!handle)
    {
        cout << "GLFW FBO and window failed to create." << endl;
        
        glfwTerminate();
    }
    
    glfwMakeContextCurrent(handle);
    
    glfwSwapInterval(1);
    glfwShowWindow(handle);
    
    glewExperimental = GL_TRUE;
    
    if(glewInit() != GLEW_OK)
    {
        cout << "GLEW failed to initialize." << endl;
    }
}

void Window::clear()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update()
{
    glfwSwapBuffers(handle);
    glfwPollEvents();
}

void Window::close()
{
    glfwDestroyWindow(handle);
    glfwTerminate();
}

GLFWwindow* Window::getHandle()
{
    return handle;
}

bool Window::input(int key)
{
    return glfwGetKey(handle, key) == GLFW_PRESS;
}

