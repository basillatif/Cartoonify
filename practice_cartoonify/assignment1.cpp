//
//  main.cpp
//  practice_cartoonify
//
//  Created by Basil Latif on 1/23/18.
//  Copyright © 2018 Basil Latif. All rights reserved.
//

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include <vector>
#include <iostream>
using namespace std;
class Vertex {
    GLfloat x, y;
public:
    Vertex(GLfloat, GLfloat);
    GLfloat get_y() { return y; };
    GLfloat get_x() { return x; };
};
Vertex::Vertex(GLfloat X, GLfloat Y) {
    x = X;
    y = Y; }
void setup() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

vector <Vertex> generate_midpoints(vector<Vertex> control_points){
    vector <Vertex> midpoints_vector;
    for (int p = 0; p < control_points.size()-1; p++){
        Vertex v_0 = control_points[p];
        Vertex v_1 = control_points[p+1];
        GLfloat x1 = (v_0.get_x() + v_1.get_x())/2;
        GLfloat y1 = (v_0.get_y() + v_1.get_y())/2;
        midpoints_vector.push_back(Vertex(x1, y1));
    }
   return midpoints_vector;
}

vector<Vertex> generate_points(vector<Vertex> control_points) {
    vector<Vertex> all_points;
    vector<Vertex> midpoints = generate_midpoints(control_points);
    vector<Vertex> midpoints_of_midpoints = generate_midpoints(midpoints);
    
    Vertex first_point = control_points[0];
    Vertex last_point = control_points[control_points.size()-1];
    
    all_points.push_back(first_point);
    
    for(int i = 0; i < midpoints.size(); i++){
        all_points.push_back(Vertex(midpoints[i].get_x(), midpoints[i].get_y()));
        if (i < midpoints.size() - 1){
        all_points.push_back(Vertex(midpoints_of_midpoints[i].get_x(), midpoints_of_midpoints[i].get_y()));
        }
    }
    all_points.push_back(last_point);
    return all_points;
}

void draw_curve(vector<Vertex> control_points, int n_iter) {
    for(int i = 0; i < n_iter; i++){
        control_points = generate_points(control_points);
    }
    glPointSize(1.0f);
    glBegin(GL_POINTS);
    
    for(int p = 0; p < control_points.size(); p++){
        glVertex2f(control_points[p].get_x(), control_points[p].get_y());
    }
    glEnd();
    
    glLineWidth(1.0f);
    glBegin(GL_LINES);
    
    for (int p = 0; p <= control_points.size()-2; p++){
        glVertex2f(control_points[p].get_x(), control_points[p].get_y());
        glVertex2f(control_points[p+1].get_x(), control_points[p+1].get_y());
    }
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    vector <Vertex> head;
    head.push_back(Vertex(-0.09f, 0.875f));
    head.push_back(Vertex(0.08f, 0.866f));
    head.push_back(Vertex(0.21f, 0.794f));
    head.push_back(Vertex(0.276f, 0.616f));
    head.push_back(Vertex(0.325f, 0.288f));
    head.push_back(Vertex(0.29f, 0.01f));
    head.push_back(Vertex(0.23f, -0.015f));
    head.push_back(Vertex(0.13f, -0.26f));
    head.push_back(Vertex(0.046f, -0.33f));
    head.push_back(Vertex(-0.017f, -0.34f));
    draw_curve(head, 10);
    
    vector <Vertex> head2;
    head2.push_back(Vertex(-0.017f, -0.34f));
    head2.push_back(Vertex(-0.125f, -0.317f));
    head2.push_back(Vertex(-0.197f, -0.266f));
    head2.push_back(Vertex(-0.238f, -0.214f));
    head2.push_back(Vertex(-0.305f, -0.16f));
    head2.push_back(Vertex(-0.333f, -0.086f));
    head2.push_back(Vertex(-0.37f, 0));
    head2.push_back(Vertex(-0.38f, 0.09));
    head2.push_back(Vertex(-0.413f, 0.2f));
    head2.push_back(Vertex(-0.404f, 0.388f));
    head2.push_back(Vertex(-0.41f, 0.553f));
    head2.push_back(Vertex(-0.35f, 0.745f));
    head2.push_back(Vertex(-0.256f, 0.85f));
    head2.push_back(Vertex(-0.09f, 0.875f));
    draw_curve(head2, 10);
    
    vector <Vertex> reye;
    reye.push_back(Vertex(-0.004f, 0.31f));
    reye.push_back(Vertex(0.07f, 0.36f));
    reye.push_back(Vertex(0.136f, 0.317f));
    draw_curve(reye, 10);
    
    vector <Vertex> reyebottom;
    reyebottom.push_back(Vertex(0.136f, 0.317f));
    reyebottom.push_back(Vertex(0.07f, 0.286f));
    reyebottom.push_back(Vertex(-0.004f, 0.31f));
    draw_curve(reyebottom, 10);
    
    vector <Vertex> leye;
    leye.push_back(Vertex(-0.364f, 0.28f));
    leye.push_back(Vertex(-0.287f, 0.326f));
    leye.push_back(Vertex(-0.224f, 0.286f));
    draw_curve(leye, 10);
    
    vector <Vertex> leyeb;
    leyeb.push_back(Vertex(-0.224f, 0.286f));
    leyeb.push_back(Vertex(-0.283f, 0.25f));
    leyeb.push_back(Vertex(-0.364f, 0.28f));
    draw_curve(leyeb, 10);
    
    
    vector <Vertex> toplip;
    toplip.push_back(Vertex(-0.206f, -0.09f));
    toplip.push_back(Vertex(-0.1f, -0.065f));
    toplip.push_back(Vertex(0.07f, -0.06f));
    draw_curve(toplip, 10);
    
    vector <Vertex> bottomlip;
    bottomlip.push_back(Vertex(0.07f, -0.06f));
    bottomlip.push_back(Vertex(0.01f, -0.14f));
    bottomlip.push_back(Vertex(-0.07f, -0.173f));
    bottomlip.push_back(Vertex(-0.18f, -0.17f));
    bottomlip.push_back(Vertex(-0.206f, -0.09f));
    draw_curve(bottomlip, 10);
    
    vector <Vertex> nose;
    nose.push_back(Vertex(-0.08f, 0.3f));
    nose.push_back(Vertex(-0.053f, 0.245f));
    nose.push_back(Vertex(-0.017f, 0.2f));
    nose.push_back(Vertex(0.014f, 0.115f));
    nose.push_back(Vertex(-0.017f, 0.09f));
    nose.push_back(Vertex(-0.19f, 0.08f));
    //nose.push_back(Vertex(-0.166f, 0.25f));
    draw_curve(nose, 10);
    
    vector <Vertex> nose2;
    nose2.push_back(Vertex(-0.16f, 0.26f));
    nose2.push_back(Vertex(-0.184f, 0.164f));
    nose2.push_back(Vertex(-0.19f, 0.08f));
    draw_curve(nose2, 10);
    
    vector <Vertex> ear;
    ear.push_back(Vertex(0.31f, 0.288f));
    ear.push_back(Vertex(0.374f, 0.443f));
    ear.push_back(Vertex(0.41f, 0.304f));
    ear.push_back(Vertex(0.356f, 0.13f));
    draw_curve(ear, 10);
    
    vector <Vertex> ear2;
    ear2.push_back(Vertex(0.356f, 0.13f));
    ear2.push_back(Vertex(0.32f, 0.11f));
    ear2.push_back(Vertex(0.29f, 0.10f));
     draw_curve(ear2, 10);
    
    vector <Vertex> lefteb;
    lefteb.push_back(Vertex(-0.364f, 0.362f));
    lefteb.push_back(Vertex(-0.283f, 0.394f));
    lefteb.push_back(Vertex(-0.215f, 0.353f));
    draw_curve(lefteb, 10);
    
    vector <Vertex> righteb;
    righteb.push_back(Vertex(-0.013f, 0.403f));
    righteb.push_back(Vertex(0.073f, 0.43f));
    righteb.push_back(Vertex(0.18f, 0.407f));
    draw_curve(righteb, 10);
    
    vector <Vertex> suit;
    suit.push_back(Vertex(-0.20f, -0.25f));
    suit.push_back(Vertex(-0.427f, -0.358f));
    suit.push_back(Vertex(-0.616f, -0.475f));
    draw_curve(suit, 10);
    
    vector <Vertex> suitr;
    suitr.push_back(Vertex(0.24f, -0.016f));
    suitr.push_back(Vertex(0.5f, -0.136f));
    suitr.push_back(Vertex(0.6f, -0.21f));
    draw_curve(suitr, 10);
    
    vector <Vertex> toptie;
    toptie.push_back(Vertex(-0.25f, -0.41f));
    toptie.push_back(Vertex(-0.053f, -0.453f));
    toptie.push_back(Vertex(0.04f, -0.453f));
    toptie.push_back(Vertex(0.186f, -0.385f));
    draw_curve(toptie, 10);
    
    vector <Vertex> bottie;
    bottie.push_back(Vertex(-0.186f, -0.674f));
    bottie.push_back(Vertex(-0.043f, -0.572f));
    bottie.push_back(Vertex(0.032f, -0.565f));
    bottie.push_back(Vertex(0.144f, -0.67f));
    draw_curve(bottie, 10);
    
    vector <Vertex> ltie;
    ltie.push_back(Vertex(-0.25f, -0.41f));
    ltie.push_back(Vertex(-0.257f, -0.54f));
    ltie.push_back(Vertex(-0.186f, -0.674f));
    draw_curve(ltie, 10);
    
    vector <Vertex> rtie;
    rtie.push_back(Vertex(0.186f, -0.385f));
    rtie.push_back(Vertex(0.25f, -0.54f));
    rtie.push_back(Vertex(0.144f, -0.67f));
    draw_curve(rtie, 10);
    
    // Set our color to black (R, G, B)
    glColor3f(0.0f, 0.0f, 0.0f);
    // Draw cartoon
    glutSwapBuffers();
}
int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(800,600); // Set your own window size
    glutCreateWindow("Assignment 1");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
