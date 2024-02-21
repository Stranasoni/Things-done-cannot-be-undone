#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int g_windowSizeX = 640, g_windowSizeY = 480;

void glfwWindowSizeCallback(GLFWwindow* pwindow, int width, int height) {
    g_windowSizeX = width;
    g_windowSizeY = height;
    glViewport(0, 0, g_windowSizeX, g_windowSizeY);
};

void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}
int main(void)
{
     

    /* Initialize the library */
    if (!glfwInit()) {
        std::cout << "glfwInit failed " << std::endl;
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
    

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* pwindow = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "Cannot_be_undone", nullptr, nullptr);
    if (!pwindow)
    {
        std::cout << "glfwCreateWindow failed " << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(pwindow,glfwWindowSizeCallback );
    glfwSetKeyCallback(pwindow, glfwKeyCallback);
    /* Make the window's context current */
    glfwMakeContextCurrent(pwindow);

	if(!gladLoadGL()) 
    {
        std::cout<<"Can't loaf GLAD\n";
        return -1;
    }
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    glClearColor(0,1,0,1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pwindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pwindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}