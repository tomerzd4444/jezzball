#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <GLFW/glfw3.h>
#include "Ball.h"
#include "Wall.h"
#define STB_IMAGE_IMPLEMENTATION
#include <STB/stb_image.h>
using namespace JezzBall;

int width = 800;
int height = 800;
double xPos, yPos;
bool horizontal = true;
Wall* wall;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
void drawMouse(double xpos, double ypos);

int main(void) {
    //Wall borders[4];
    //borders[0] = Wall(new float[2]{ -1, -1 }, new float[2]{ -0.99, 1 }, true, true);
    //borders[1] = Wall(new float[2]{ -1, -1 }, new float[2]{ 1, -0.99 }, true, true);
    //borders[2] = Wall(new float[2]{  1, -1 }, new float[2]{ 0.99,  1 }, true, true);
    //borders[3] = Wall(new float[2]{ -1,  1 }, new float[2]{ 0.99,  1 }, true, true);

    //Wall left_border;
    //left_border.top_left.push_back(1);
    //left_border.top_left.push_back(1);
    //left_border.bot_right.push_back(1);
    //left_border.bot_right.push_back(1);
    //borders.push_back(left_border);
    //Ball ball;
    //ball.radius = 0.02;
    //ball.position.push_back(0);
    //ball.position.push_back(0);
    //ball.direction.push_back(0.001);
    //ball.direction.push_back(30);
    //Ball* ball = new Ball(new float[2]{ 0, 0 }, new float[2]{ 0.005, 0.008 });
    //double time;
    //Wall test;
    //test.topLeft = new float[2]{ 0, 0 };
    //test.botRight = new float[2]{ -0.01, 0.02 };
    Ball* balls[10];//[1000000];
    std::cout << sizeof(balls) / sizeof(Ball*) << std::endl;
    for (int i = 0; i < sizeof(balls) / sizeof(Ball*); i++) {
        balls[i] = new Ball(
            new float[2]{ (float) rand() / (float) (RAND_MAX / 2.0) - (float) 1.0, (float) rand() / (float) (RAND_MAX / 2.0) - (float)1.0 },
            new float[2]{ (float) rand() / (float) (100.0 * RAND_MAX) + 1/200, (float) rand() / (float) (100.0 * RAND_MAX) + 1/200});
    }
    GLFWwindow* window;
    //std::stringstream file(filename);
    //const char* filename = "../cursor.png";
    //unsigned char* pixels = stbi_load("src/cursor.png", &width, &height, &comp, 0);
    //GLFWimage image;
    //image.width = 16;
    //image.height = 16;
    //image.pixels = pixels;
    //GLFWcursor* cursor = glfwCreateCursor(&image, 0, 0);
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "Jezz Ball", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    //std::cout << window << " cursor: " << cursor << " image: " << &image << std::endl;
    //glfwSetCursor(window, cursor);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetCursorPosCallback(window, cursorPositionCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetKeyCallback(window, keyCallback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        //std::cout << ball->to_string() << std::endl;
        //std::cout << test.toString() << std::endl;
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        //for (Wall border : borders) {
        //    border.draw();
        //}
        if (xPos != NULL && yPos != NULL) {
            drawMouse(xPos, yPos);
        }
        for (Ball* ball : balls) {
            ball->draw();
            ball->update();
            ball->collideBorder();
            if (wall != nullptr) {
                if (ball->checkCollide(wall)) {
                    wall = nullptr;
                }
            }
            
        }
        if (wall != nullptr) {
            wall->draw();
            if (!wall->update()) {
                wall = nullptr;
            }
        }
        //ball->draw();
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        

        /* Poll for and process events */
        glfwPollEvents();
        //ball->update();
        //ball->collideBorder();
    }
    
    glfwTerminate();
    return 0;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        horizontal = !horizontal;
    }
}

void cursorPositionCallback(GLFWwindow* window, double x, double y) {
    x = (x - width / 2) / (width / 2);
    y = (y - height / 2) / (height / 2);
    xPos = x;
    yPos = -y;
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {

    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && wall == NULL) {
        wall = new Wall();
        wall->topLeft = new float[2]{ (float) xPos - 0.01f, (float) yPos - 0.01f};
        wall->botRight = new float[2]{ (float) xPos + 0.01f, (float) yPos + 0.01f };
        wall->horizontal = horizontal;

    }
}

void drawMouse(double xpos, double ypos) {
    glColor3f(0, 1, 0);
    if (horizontal) {
        glBegin(GL_TRIANGLES);
        glVertex2f(xpos - 0.03, ypos - 0.025);
        glVertex2f(xpos - 0.03, ypos + 0.025);
        glVertex2f(xpos - 0.05, ypos);
        glEnd();
        glRectf(xpos - 0.03, ypos - 0.015, xpos + 0.03, ypos + 0.015);
        glBegin(GL_TRIANGLES);
        glVertex2f(xpos + 0.03, ypos - 0.025);
        glVertex2f(xpos + 0.03, ypos + 0.025);
        glVertex2f(xpos + 0.05, ypos);
        glEnd();
        return;
    }
    glBegin(GL_TRIANGLES);
    glVertex2f(xpos - 0.025, ypos - 0.03);
    glVertex2f(xpos + 0.025, ypos - 0.03);
    glVertex2f(xpos, ypos - 0.05);
    glEnd();
    glRectf(xpos - 0.015, ypos - 0.03, xpos + 0.015, ypos + 0.03);
    glBegin(GL_TRIANGLES);
    glVertex2f(xpos - 0.025, ypos + 0.03);
    glVertex2f(xpos + 0.025, ypos + 0.03);
    glVertex2f(xpos, ypos + 0.05);
    glEnd();
}