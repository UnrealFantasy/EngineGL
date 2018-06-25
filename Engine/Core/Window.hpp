//
//  Window.hpp
//  Odyssey
//
//  Created by Dexter Burk on 6/24/18.
//  Copyright © 2018 Dexter Burk. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

using namespace std;

class Window {
    int width, height;
    
    const char* title;
    
    GLFWwindow* handle;
    
public:
    Window(int with, int height, const char* title);
    
    void create();
    
    void clear();
    void update();
    
    void close();
    
    GLFWwindow* getHandle();
    
    bool input(int key);
};

#endif

