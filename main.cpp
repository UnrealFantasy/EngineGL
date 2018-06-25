//
//  main.cpp
//  Odyssey
//
//  Created by Dexter Burk on 6/24/18.
//  Copyright © 2018 Dexter Burk. All rights reserved.
//

#include <iostream>

#include "Engine/Core/Window.hpp"

using namespace std;

int main()
{
    cout << "Console application starting..." << endl;
    
    Window window = Window(1270, 700, "Odyssey");
    
    window.create();
    
    while(!glfwWindowShouldClose(window.getHandle()))
    {
        window.clear();
        window.update();
    }
    
    window.close();
}
