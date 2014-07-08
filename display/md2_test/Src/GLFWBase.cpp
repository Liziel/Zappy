
#include <fstream>
#include <stdlib.h>
#include "Framework.h"

int RunLevel = 1;
bool Keys[GLFW_KEY_LAST] = {false};

void key_callback(GLFWwindow* window, int key, int, int action, int);

GLFWwindow* InitWindow(int ScrX, int ScrY)
{
  GLFWwindow* window;

  if (glfwInit() != GL_TRUE)
    throw "Failed to initialize GLFW.";
  window = glfwCreateWindow(ScrX, ScrY, "OpenGL", NULL, NULL); // dernier param -> partager texture contexte
  if (!window)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window, key_callback);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  float aspect_ratio = ((float)ScrX) / ScrY;
  glFrustum(.5, -.5, -.5 * aspect_ratio, .5 * aspect_ratio, 1, 500);
  glMatrixMode(GL_MODELVIEW);
  glfwSwapBuffers(window);
  glfwPollEvents();
  return (window);
}