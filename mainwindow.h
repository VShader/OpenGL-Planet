/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the documentation of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "openglwindow.h"

#include <QOpenGLShaderProgram>
#include <vector>


class ControlWidget;
class QCloseEvent;

namespace cg    {
class Mesh;
class Sunsystem;
}



class MainWindow : public OpenGLWindow
{
public:
    MainWindow();
    ~MainWindow();

    void initialize();
    void render();


private slots:
    void setRotation(int x, int y, int z);
    void setSpeed(int speed) {this->speed = speed/100.0f;}
    void keyPressEvent(QKeyEvent &event);
    inline void toggleFullScreen(bool fullScreen);


private:
    GLuint loadShader(GLenum type, const char *source);


    GLuint vao;
    time_t lastTime;
    time_t now;

    QMatrix4x4 scale;
    QMatrix4x4 orbitRotMatrix;
    QMatrix4x4 orbitMatrix;
    QMatrix4x4 rotMatrix;
    QMatrix4x4 projMatrix;
    QMatrix4x4 viewMatrix;

    bool fullScreen;
    GLuint m_position;
    GLuint m_normal;
    GLuint m_mv_matrix;
    GLuint m_view_matrix;
    GLuint m_proj_matrix;
    GLuint m_light;
    GLuint m_ambient;
    GLuint m_diffuse_albedo;
    GLuint m_specular_albedo;
    GLuint m_specular_power;
    GLuint m_light_color;

    QOpenGLShaderProgram *m_program;
    int m_frame;

    ControlWidget *control;
    float speed;
    time_t time;
    GLfloat rotateX;
    GLfloat rotateY;
    GLfloat rotateZ;
    cg::Mesh *myMesh;
    std::vector<std::vector<GLfloat>> lightPositions;


    void closeEvent(QCloseEvent *event);
};
