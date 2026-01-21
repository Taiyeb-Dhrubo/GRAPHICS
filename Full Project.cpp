#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include<math.h>
using namespace std;
bool isDay = true;

/// #############  Circle  #############
void circle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++)
    {
        float pi = 3.1416;
        float A  = (i*2*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

void halfCircle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 180; i++)
    {
        float pi = 3.1416;
        float A  = (i*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

/// #############  Sun  #############
float moveSun = 0.0f;
float sunSpeed =0.3f;
float savedSunSpeed = 0.0f;
bool sunPaused = false;

void sun()
{
    if(isDay)
    {
        glPushMatrix();
        glTranslatef(moveSun, 0, 0);
        glColor3f(1,1,0);
        circle(50,650,35);
        glPopMatrix();
    }
}

void updateSun(int value)
{
    if(!sunPaused)
    {
        moveSun += sunSpeed;
        if (moveSun > 1050)
        {
            moveSun = -200;
        }

        glutPostRedisplay();
    }

    glutTimerFunc(16, updateSun, 0);
}

/// ############# Moon #############
float moveMoon = 0;
float moonSpeed =0.3f;
float savedMoonSpeed = 0.0f;
bool moonPaused = false;

void moon()
{
    if(!isDay)
    {
        glPushMatrix();
        glTranslatef(moveMoon, 0, 0);

        glColor3f(1,1,1);
        circle(850,650,40);

        glPopMatrix();
    }
}

void updateMoon(int value)
{
    if(!moonPaused)
    {
        moveMoon -= moonSpeed;
        if (moveMoon < -940)
        {
            moveMoon = 200;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(16, updateMoon, 0);
}

/// #############  SKY  #############
void sky()
{
    glBegin(GL_QUADS);

    if(isDay)
        glColor3f(0.37f, 0.82f, 0.94f);
    else
        glColor3f(0.10f, 0.13f, 0.22f);

    glVertex2f(0,   200);
    glVertex2f(1000,200);
    glVertex2f(1000,700);
    glVertex2f(0,   700);
    glEnd();
}

/// #############  Cloud  #############

float V_moveCloud1 = 0.0f;
float V_cloudSpeed1 =1.0f;
float V_savedCloudSpeed1 = 0.0f;
bool V_cloudPaused1 = false;

float V_moveCloud2 = 0.0f;
float V_cloudSpeed2 =1.0f;
float V_savedCloudSpeed2 = 0.0f;
bool V_cloudPaused2 = false;

float V_moveCloud3 = 0.0f;
float V_cloudSpeed3 =1.0f;
float V_savedCloudSpeed3 = 0.0f;
bool V_cloudPaused3 = false;

float V_moveCloud4 = 0.0f;
float V_cloudSpeed4 =1.0f;
float V_savedCloudSpeed4 = 0.0f;
bool V_cloudPaused4 = false;

void V_cloud1()
{
    glPushMatrix();
    glTranslatef(V_moveCloud1, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    int x = 200, y = 650, r = 20;
    circle(x,    y, r);
    circle(x-25, y+5, r);
    circle(x+25, y+5, r);
    circle(x-10, y+20, r-3);
    circle(x+10, y+20, r-3);

    glPopMatrix();
}

void V_cloud2()
{
    glPushMatrix();
    glTranslatef(V_moveCloud2, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    circle(337,640,18);
    circle(365,640,20);
    circle(390,640,18);
    circle(350,632,20);
    circle(375,632,20);
    circle(355,648,20);
    circle(375,648,20);

    glPopMatrix();
}


void V_cloud4()
{
    glPushMatrix();
    glTranslatef(V_moveCloud4, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);
    circle(830,640,20);
    circle(860,638,22);
    circle(890,640,20);
    circle(845,652,20);
    circle(870,655,28);

    glPopMatrix();
}

void V_updateCloud1(int value)
{
    if(isDay)
    {
        if(!V_cloudPaused1)
        {
            V_moveCloud1 -= V_cloudSpeed1+1;
            if (V_moveCloud1 < -250)
            {
                V_moveCloud1 = 860;
            }

            glutPostRedisplay();
        }
    }
    else
    {
        if(!V_cloudPaused1)
        {
            V_moveCloud1 += V_cloudSpeed1+1;
            if (V_moveCloud1 >1000)
            {
                V_moveCloud1 = -250;
            }

            glutPostRedisplay();
        }
    }
    glutTimerFunc(16, V_updateCloud1, 0);
}

void V_updateCloud2(int value)
{
    if(!V_cloudPaused2)
    {
        V_moveCloud2 -= V_cloudSpeed2+.3;
        if (V_moveCloud2 < -450)
        {
            V_moveCloud2 = 740;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(9, V_updateCloud2, 0);
}

void V_updateCloud4(int value)
{
    if(isDay)
    {
        if(!V_cloudPaused4)
        {
            V_moveCloud4 -= V_cloudSpeed4+1;
            if (V_moveCloud4 < -900)
            {
                V_moveCloud4 = 250;
            }

            glutPostRedisplay();
        }
    }
    else
    {
        if(!V_cloudPaused4)
        {
            V_moveCloud4 += V_cloudSpeed4+2;
            if (V_moveCloud4 >250)
            {
                V_moveCloud4 = -940;
            }

            glutPostRedisplay();
        }
    }
    glutTimerFunc(16, V_updateCloud4, 0);
}

/// ##############################################################  Garden  ###############################################################
void garden()
{
    //Base
    if (isDay)
        glColor3f(0.0f, 0.5f, 0.0f);
    else
        glColor3f(0.1f, 0.3f, 0.1f);

    glBegin(GL_QUADS);
    glVertex2f(0,180);
    glVertex2f(1000,180);
    glVertex2f(1000,200);
    glVertex2f(0,200);
    glEnd();
     for(int i = 0; i< 67; i++)
    {

        /// Cloud shape tree
        if (isDay)
            glColor3f(0.0f, 0.5f, 0.0f);
        else
            glColor3f(0.1f, 0.3f, 0.1f);

        for(int i = 0; i<1000; i+=50)
        {
            halfCircle(i+20,190,25);
        }
    }


}

/// ##############################################################  Road  ###############################################################
void road()
{
    if (isDay)
        glColor3f(.3f, .3f, .3f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    //Base Gray Color
    glBegin(GL_QUADS);
    glVertex2f(0,   0);
    glVertex2f(1000,0);
    glVertex2f(1000,40);
    glVertex2f(0,   40);
    glEnd();

    //Base white line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(0,   40);
    glVertex2f(1000,40);
    glEnd();

    //Main Road
    glBegin(GL_QUADS);

    if(isDay)
        glColor3f(0.3f, 0.3f, 0.3f);
    else
        glColor3f(0,0,0);

    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glVertex2f(1000,40);
    glVertex2f(0,   40);
    glEnd();

    //Upper white line of the road
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glEnd();

    //Upper gray color
    if (isDay)
        glColor3f(0.51f, 0.51f, 0.51f);
    else
        glColor3f(0.25f, 0.25f, 0.25f);

    glBegin(GL_QUADS);
    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glVertex2f(1000,173);
    glVertex2f(0,   173);
    glEnd();

    //Road dash line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 0; x<1000; x+=60)
    {
        glVertex2f(x,   102);
        glVertex2f(x+30,102);
    }
    glEnd();
}

/// ##############################################################  Bus  ###################################################################
float V_moveBus = 0.0f;
float V_busSpeed =1.0f;
float V_savedBusSpeed = 0.0f;
float V_busTireAngle = 0.0f;
bool V_busPaused = false;

void bus()
{
    glPushMatrix();
    glTranslatef(V_moveBus, 0, 0);

    glBegin(GL_QUADS);
    if (isDay)
        glColor3f(1.00f, 0.60f, 0.29f);
    else
        glColor3f(0.70f, 0.35f, 0.20f);

    ///Body
    glVertex2f(400, 130);
    glVertex2f(550, 130);
    glVertex2f(550, 190);
    glVertex2f(400, 190);

    ///Front
    glVertex2f(550, 130);
    glVertex2f(570, 130);
    glVertex2f(570, 160);
    glVertex2f(550, 190);

    glEnd();

    ///  FRONT Light
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(1,1,0);

    glBegin(GL_QUADS);
    glVertex2f(565, 135);
    glVertex2f(570, 135);
    glVertex2f(570, 142);
    glVertex2f(565, 142);

    if(!isDay)
    {
    glColor3f(1,1,.6);
    glVertex2f(570, 135);
    glVertex2f(640, 125);
    glVertex2f(640, 152);
    glVertex2f(570, 142);
    }

    /// Window
    /// FRONT WINDOW
    if (isDay)
        glColor3f(0.92f, 1.0f, 0.996f);
    else
        glColor3f(1,1,.6);

    glBegin(GL_QUADS);
    glVertex2f(533, 180);
    glVertex2f(550, 180);
    glVertex2f(565, 150);
    glVertex2f(533, 160);

    glEnd();

    /// REAR TIRE
    glColor3f(0,0,0);
    halfCircle(425,130,12);

    glPushMatrix();
    glTranslatef(425, 130, 0);
    glRotatef(V_busTireAngle, 0.0, 0.0, 1.0);  // Rotate only the tire
    glTranslatef(-425, -130, 0);

   if (isDay)
    glColor3f(0.8f, 0.8f, 0.8f);
else
    glColor3f(0.5f, 0.5f, 0.5f);

    circle(425,130,11);

    if (isDay)
    glColor3f(1.0f, 1.0f, 1.0f);
else
    glColor3f(0.7f, 0.7f, 0.7f);

    circle(425,130,5);

    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(414,130);
    glVertex2f(436,130);
    glEnd();

    glPopMatrix();

    /// FRONT TIRE
    glColor3f(0,0,0);
    halfCircle(540,130,12);

    glPushMatrix();
    glTranslatef(540, 130, 0);
    glRotatef(V_busTireAngle, 0.0, 0.0, 1.0);  // Rotate only the tire
    glTranslatef(-540, -130, 0);

    if (isDay)
    glColor3f(0.8f, 0.8f, 0.8f);
else
    glColor3f(0.5f, 0.5f, 0.5f);

    circle(540,130,11);

    if (isDay)
    glColor3f(1.0f, 1.0f, 1.0f);
else
    glColor3f(0.7f, 0.7f, 0.7f);

    circle(540,130,5);

    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(529,130);
    glVertex2f(551,130);
    glEnd();

    glPopMatrix();

    glPopMatrix();
}

void V_updateBus(int value)
{
    if(!V_busPaused)
    {
        V_moveBus += V_busSpeed+1;
        if (V_moveBus > 700)
        {
            V_moveBus = -550;
        }
        V_busTireAngle -= 1.0f;
        glutPostRedisplay();
    }
    glutTimerFunc(2, V_updateBus, 0);


}
/// ######################################################## Cargo Track ########################################################
float V_moveCargo = 0.0f;
float V_cargoSpeed =3.0f;
float V_savedCargoSpeed = 0.0f;
float V_cargoTireAngle = 0.0f;
bool V_cargoPaused = false;

void cargoTruck()
{
    glPushMatrix();
    glTranslatef(V_moveCargo, 0, 0);

    /// Head and Body joint
    if (isDay)
        glColor3f(0.5f, 0.5f, 0.5f);
    else
        glColor3f(0.3f, 0.3f, 0.3f);

    glBegin(GL_QUADS);
    glVertex2f(760, 73);
    glVertex2f(730, 73);
    glVertex2f(730, 110);
    glVertex2f(760, 83);
    glEnd();

    ///  ********> Body <********
    if (isDay)
        glColor3f(0.51f, 0.86f, 0.92f);
    else
        glColor3f(0.22f, 0.46f, 0.55f);

    glBegin(GL_QUADS);
    glVertex2f(900, 83);
    glVertex2f(750, 83);
    glVertex2f(750, 150);
    glVertex2f(900, 150);
    glEnd();


    /// Head
    if (isDay)
        glColor3f(0.30f, 0.82f, 0.87f);
    else
        glColor3f(0.15f, 0.42f, 0.48f);

    /// upper quad
    glBegin(GL_QUADS);
    glVertex2f(745, 138);
    glVertex2f(715, 138);
    glVertex2f(690, 113);
    glVertex2f(745, 113);

    if (isDay)
        glColor3f(0.69f, 0.92f, 0.95f);
    else
        glColor3f(0.32f, 0.55f, 0.65f);

    glVertex2f(690, 113);
    glVertex2f(693, 111);
    glVertex2f(713, 132);
    glVertex2f(711, 135);

    if (isDay)
        glColor3f(0.30f, 0.82f, 0.87f);
    else
        glColor3f(0.15f, 0.42f, 0.48f);

    /// down quad
    glVertex2f(745, 75);
    glVertex2f(690, 70);
    glVertex2f(690, 113);
    glVertex2f(745, 113);

    glEnd();

    /// window glass
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(718, 130);
    glVertex2f(737, 130);
    glVertex2f(737, 105);
    glVertex2f(697, 100);
    glVertex2f(697, 110);
    glEnd();

    /// inner glass
    if (isDay)
        glColor3f(0.92f, 1.0f, 0.996f);
    else
        glColor3f(0.60f, 0.75f, 0.78f);

    glBegin(GL_POLYGON);
    glVertex2f(720, 128);
    glVertex2f(735, 128);
    glVertex2f(735, 107);
    glVertex2f(699, 102);
    glVertex2f(701, 110);
    glEnd();

    /// *********>  REAR Light  <***********
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(1,0,0);

    glBegin(GL_QUADS);
    glVertex2f(895, 78);
    glVertex2f(900, 78);
    glVertex2f(900, 90);
    glVertex2f(895, 90);
    glEnd();


    /// *********>  FRONT Light  <***********
    if (isDay)
        glColor3f(1.0f, 1.0f, 0.0f);
    else
        glColor3f(0.8f, 0.8f, 0.2f);

    glBegin(GL_QUADS);
    glVertex2f(689, 82);
    glVertex2f(695, 85);
    glVertex2f(695, 89);
    glVertex2f(689, 89);

    if (isDay)
        glColor3f(1.0f, 0.68f, 0.016f);
    else
        glColor3f(0.8f, 0.5f, 0.01f);

    glVertex2f(689, 94);
    glVertex2f(695, 95);
    glVertex2f(695, 89);
    glVertex2f(689, 89);

    glEnd();

    if(!isDay)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.68f, 0.016f);
        glVertex2f(689, 94);
        glVertex2f(600, 97);
        glVertex2f(600, 50);
        glVertex2f(689, 84);

        glEnd();
    }

    /// Under The Body Black bar
    if (isDay)
        glColor3f(0.5f, 0.5f, 0.5f);
    else
        glColor3f(0.3f, 0.3f, 0.3f);

    glBegin(GL_QUADS);
    glVertex2f(900, 73);
    glVertex2f(730, 73);
    glVertex2f(725, 83);
    glVertex2f(900, 83);

    glEnd();

    /// Front Black Bumper
    if (isDay)
        glColor3f(0.5f, 0.5f, 0.5f);
    else
        glColor3f(0.3f, 0.3f, 0.3f);

    glBegin(GL_POLYGON);
    glVertex2f(690, 70);
    glVertex2f(730, 70);
    glVertex2f(730, 75);
    glVertex2f(695, 75);
    glVertex2f(695, 85);
    glVertex2f(685, 80);

    glEnd();


    /// REAR TIRE
    if (isDay)
        glColor3f(0.46f, 0.46f, 0.46f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    halfCircle(865,69,14);

    if (isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.8f, 0.8f, 0.8f);

    halfCircle(865,69,12);

    glPushMatrix();
    glTranslatef(865, 69, 0);
    glRotatef(V_cargoTireAngle, 0.0, 0.0, 1.0);  // Rotate only the tire
    glTranslatef(-865, -69, 0);

    if (isDay)
        glColor3f(0.7f, 0.7f, 0.6f);
    else
        glColor3f(0.4f, 0.4f, 0.35f);

    circle(865,69,12);

    if (isDay)
        glColor3f(0.70f, 0.73f, 0.73f);
    else
        glColor3f(0.45f, 0.48f, 0.48f);

    circle(865,69,8);

    if (isDay)
        glColor3f(0.57f, 0.60f, 0.61f);
    else
        glColor3f(0.3f, 0.32f, 0.33f);

    circle(865,69,7);

    if (isDay)
        glColor3f(0.89f, 0.89f, 0.89f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(865,69,5);

    if (isDay)
        glColor3f(0.60f, 0.60f, 0.60f);
    else
        glColor3f(0.35f, 0.35f, 0.35f);

    circle(865,69,4);

    glPopMatrix();

    /// FRONT TIRE

    if (isDay)
        glColor3f(0.26f, 0.26f, 0.26f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    halfCircle(725,69,14);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.8f, 0.8f, 0.8f);

    halfCircle(725,69,12);

    glPushMatrix();
    glTranslatef(725, 69, 0);
    glRotatef(V_cargoTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-725, -69, 0);

    // Front Tire
    if (isDay)
        glColor3f(0.7f, 0.7f, 0.6f);
    else
        glColor3f(0.45f, 0.45f, 0.4f);

    circle(725,69,12);

    if (isDay)
        glColor3f(0.70f, 0.73f, 0.73f);
    else
        glColor3f(0.45f, 0.48f, 0.48f);

    circle(725,69,8);

    if (isDay)
        glColor3f(0.57f, 0.60f, 0.61f);
    else
        glColor3f(0.35f, 0.38f, 0.39f);

    circle(725,69,7);

    if (isDay)
        glColor3f(0.89f, 0.89f, 0.89f);
    else
        glColor3f(0.45f, 0.45f, 0.45f);

    circle(725,69,5);

    if (isDay)
        glColor3f(0.60f, 0.60f, 0.60f);
    else
        glColor3f(0.35f, 0.35f, 0.35f);

    circle(725,69,4);

    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(.5,.5,.5);

    glBegin(GL_TRIANGLES);
    glVertex2f(722,70);
    glVertex2f(728,70);
    glVertex2f(725,66);
    glEnd();

    glPopMatrix();
    glPopMatrix();
}

void V_updateCargo(int value)
{
    if(!V_cargoPaused)
    {
        V_moveCargo -= V_cargoSpeed;
        if (V_moveCargo < -940)
        {
            V_moveCargo = 450;
        }
        V_cargoTireAngle += 1.0f;
        glutPostRedisplay();
    }
    glutTimerFunc(2, V_updateCargo, 0);


}

//****** blue car*********

/// ######################################################## Blue Car ########################################################
float V_moveBlueCar = 500.0f;
float V_blueCarSpeed = 2.8f;
float V_blueCarTireAngle = 0.0f;
bool V_blueCarPaused = false;


void blueCar()
{
    glPushMatrix();
    glTranslatef(V_moveBlueCar, 0, 0);

    // Body
    if(isDay)
        glColor3f(0.0f, 0.4f, 0.8f);
    else
        glColor3f(0.1f, 0.2f, 0.5f);

    glBegin(GL_QUADS);
    glVertex2f(620, 73);
    glVertex2f(700, 73);
    glVertex2f(700, 110);
    glVertex2f(620, 110);
    glEnd();

    // Roof
    glBegin(GL_QUADS);
    glVertex2f(635, 110);
    glVertex2f(685, 110);
    glVertex2f(670, 130);
    glVertex2f(650, 130);
    glEnd();

    // ===== WINDOW =====
if(isDay)
    glColor3f(0.05f, 0.05f, 0.05f);   // black glass (day)
else
    glColor3f(0.9f, 0.9f, 0.4f);     // glowing yellow (night)

glBegin(GL_QUADS);
glVertex2f(645, 112);
glVertex2f(675, 112);
glVertex2f(665, 127);
glVertex2f(655, 127);
glEnd();

    // Rear tire
    glColor3f(0,0,0);
    halfCircle(640,73,10);

    glPushMatrix();
    glTranslatef(640,73,0);
    glRotatef(V_blueCarTireAngle,0,0,1);
    glTranslatef(-640,-73,0);
    glColor3f(0.7f,0.7f,0.7f);
    circle(640,73,9);
    glPopMatrix();

    // Front tire
    glColor3f(0,0,0);
    halfCircle(680,73,10);

    glPushMatrix();
    glTranslatef(680,73,0);
    glRotatef(V_blueCarTireAngle,0,0,1);
    glTranslatef(-680,-73,0);
    glColor3f(0.7f,0.7f,0.7f);
    circle(680,73,9);
    glPopMatrix();



   //  LEFT HEADLIGHT
if(!isDay)
{
    // Headlight source (front-left of car)
    glColor3f(1.0f, 1.0f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(620, 86);   // car front-left x
    glVertex2f(626, 86);
    glVertex2f(626, 96);
    glVertex2f(620, 96);
    glEnd();

    // Light light
    glColor4f(1.0f, 1.0f, 0.6f, 0.6f);
    glBegin(GL_QUADS);
    glVertex2f(626, 80);
    glVertex2f(540, 65);
    glVertex2f(540, 115);
    glVertex2f(626, 100);
    glEnd();
}

    glPopMatrix();
}

void V_updateBlueCar(int value)
{
    if(!V_blueCarPaused)
    {
        V_moveBlueCar -= V_blueCarSpeed;

        // reset from right side, behind cargo
        if(V_moveBlueCar < -1000)
            V_moveBlueCar = 1000;

        V_blueCarTireAngle += 3.0f;
        glutPostRedisplay();
    }
    glutTimerFunc(16, V_updateBlueCar, 0);
}




/// ##############################################################  Road Side Wall  ###############################################################
void roadSideWall()
{
    if (isDay)
        glColor3f(0.96f, 0.96f, 0.86f);
    else
        glColor3f(0.42f, 0.22f, 0.13f);

    glBegin(GL_QUADS);
    glVertex2f(0,   170);
    glVertex2f(1000,170);
    glVertex2f(1000,190);
    glVertex2f(0,   190);
    glEnd();

    //Breaks Line
        glColor3f(0.5f, 0.5f, 0.5f);

    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2f(0,   170);
    glVertex2f(1000,170);

    glVertex2f(0,   175);
    glVertex2f(1000,175);

    glVertex2f(0,   180);
    glVertex2f(1000,180);

    glVertex2f(0,   185);
    glVertex2f(1000,185);

    glVertex2f(0,   190);
    glVertex2f(1000,190);


    glEnd();

}

/// ####################################################################### Building ###########################################################
void building()
{
    /// 1st Building
    // Left side
   if (isDay)
        glColor3f(0.4f, 0.4f, 0.4f);
    else
        glColor3f(0.50f, 0.15f, 0.20f);

    glBegin(GL_QUADS);
    glVertex2f(190, 200);
    glVertex2f(235, 200);
    glVertex2f(235, 480);
    glVertex2f(190, 480);

    glVertex2f(235, 200);
    glVertex2f(280, 200);
    glVertex2f(280, 480);
    glVertex2f(235, 480);

    //Top bar
    if (isDay)
        glColor3f(0.50f, 0.15f, 0.20f);
    else
        glColor3f(0.30f, 0.10f, 0.15f);

    glVertex2f(185, 490);
    glVertex2f(285, 490);
    glVertex2f(285, 475);
    glVertex2f(185, 475);

    if (isDay)
        glColor3f(0.50f, 0.15f, 0.20f);
    else
        glColor3f(0.30f, 0.10f, 0.15f);

    for(int y = 410; y>200; y-=70)
    {
        glVertex2f(185, y);
        glVertex2f(285, y);
        glVertex2f(285, y-10);
        glVertex2f(185, y-10);
    }

    glEnd();

    ///     window
    //   white border
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    for(int x = 198; x < 280; x += 47)
    {
        for(int y=454; y>220; y-=70)
        {
            glVertex2f(x,    y);
            glVertex2f(x+26, y);
            glVertex2f(x+26, y-34);
            glVertex2f(x,    y-34);
        }
    }
    glEnd();

    // blue
    if (isDay)
        glColor3f(0.36f, 0.54f, 0.66f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    for(int x = 202; x < 280; x += 47)
    {
        for(int y=450; y>220; y-=70)
        {
            glBegin(GL_QUADS);
            glVertex2f(x,    y);
            glVertex2f(x+18, y);
            glVertex2f(x+18, y-27);
            glVertex2f(x,    y-27);
            glEnd();
        }
    }

    ///              ***> 2nd Building <***
    if (isDay)
        glColor3f(0.4f, 0.7f, 0.9f);
    else
        glColor3f(0.20f, 0.35f, 0.45f);

    glBegin(GL_QUADS);
    glVertex2f(300, 200);
    glVertex2f(400, 200);
    glVertex2f(400, 550);
    glVertex2f(300, 510);

    //Top White
    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glVertex2f(299, 495);
    glVertex2f(401, 540);
    glVertex2f(401, 555);
    glVertex2f(299, 510);

    // Body white quard
    glVertex2f(300, 470);
    glVertex2f(400, 470);
    glVertex2f(400, 455);
    glVertex2f(300, 455);
    glEnd();

    if (isDay)           // inside design lines
        glColor3f(1,1,1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(320, 200);
    glVertex2f(320, 510);

    glVertex2f(340, 200);
    glVertex2f(340, 520);

    glVertex2f(360, 200);
    glVertex2f(360, 530);

    glVertex2f(380, 200);
    glVertex2f(380, 535);

    if (isDay)
        glColor3f(0.30f, 0.42f, 0.51f);
    else
        glColor3f(0.18f, 0.28f, 0.36f);


    for(int y = 455; y> 200; y-=30)
    {
        glVertex2f(300, y);
        glVertex2f(400, y);
    }
    glVertex2f(312, 500);
    glVertex2f(400, 500);


    glEnd();

    /// 3rd Building
    if (isDay)               // outside shape
        glColor3f(0.96f, 0.96f, 0.96f);
    else
        glColor3f(0.70f, 0.70f, 0.70f);

    glBegin(GL_QUADS);
    //Main Body
    glVertex2f(420, 200);
    glVertex2f(550, 200);
    glVertex2f(550, 440);
    glVertex2f(420, 440);

    glEnd();

    //Body white bar
    if (isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glBegin(GL_QUADS);
    glVertex2f(415, 420);
    glVertex2f(555, 420);
    glVertex2f(555, 440);
    glVertex2f(415, 440);
    glEnd();


    //blue glass + inside body + top small 3 piece inside
    if (isDay)
        glColor3f(0.38f, 0.54f, 0.66f);
    else
        glColor3f(0.20f, 0.35f, 0.45f);

    //body
    glBegin(GL_QUADS);
    for(int x = 435; x<550; x+=40)
    {
        glVertex2f(x, 200);
        glVertex2f(x+20, 200);
        glVertex2f(x+20, 400);
        glVertex2f(x, 400);
    }
    glEnd();

//*************************************

    /// 4th Building
    if (isDay)            // outside shape
        glColor3f(0.39f, 0.30f, 0.32f);
    else
        glColor3f(0.19f, 0.15f, 0.16f);

    glBegin(GL_QUADS);
    glVertex2f(730, 200);
    glVertex2f(970, 200);
    glVertex2f(970, 430);
    glVertex2f(730, 430);
    glEnd();

    // top bar
    glColor3f(0.28f, 0.13f, 0.06f);
    glBegin(GL_QUADS);
    glVertex2f(725, 440);
    glVertex2f(975, 440);
    glVertex2f(975, 430);
    glVertex2f(725, 430);
    glEnd();

    //All Window 3 bar shape
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glBegin(GL_QUADS);
    for(int x=759; x<950; x+=150)
            //4 corner window 3 bar shape
        for(int y = 400; y>250; y-=120)
        {
            glVertex2f(x, y);
            glVertex2f(x+32, y);
            glVertex2f(x+32, y-40);
            glVertex2f(x, y-40);
        }



    //All window blue color glass
    if(isDay)
        glColor3f(0.44f, 0.65f, 0.80f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    // blue glass
    for(int x=763; x<950; x+=150)
        for(int y = 397; y>250; y-=120) // 4 side blue color glass
        {
            glVertex2f(x,    y);
            glVertex2f(x+24, y);
            glVertex2f(x+24, y-34);
            glVertex2f(x,    y-34);
        }

    glEnd();

    // Lines of windows 4 corner side
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 775; x<940; x+=150)
        for(int y = 400; y>200; y-=120)
        {
            glVertex2f(x, y);
            glVertex2f(x, y-40);
        }
        glEnd();
}

///*******red car*****
float moveCar = 0.0f;
float carSpeed =1.0f;
float savedCarSpeed = 0.0f;
float carTireAngle = 0.0f;
bool carPaused = false;

void car()
{
    glPushMatrix();
    glTranslatef(moveCar, 0, 0);

    glBegin(GL_POLYGON);
    if (isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.5f, 0.0f, 0.0f);

    glVertex2i(100,125);
    glVertex2i(100,140);
    glVertex2i(105,150);
    glVertex2i(193,150);
    glVertex2i(205,145);
    glVertex2i(205,125);
    glEnd();

    /// Light
    glBegin(GL_QUADS);
    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(1,1,.7);
    /// Front light
    glVertex2i(200,128);
    glVertex2i(205,128);
    glVertex2i(205,135);
    glVertex2i(200,135);

    /// Yellow light for night
    if(!isDay)
    {
        glColor3f(1,1,.7);
        glVertex2i(205,128);
        glVertex2i(260,115);
        glVertex2i(260,140);
        glVertex2i(205,135);

    }

    glEnd();

    glBegin(GL_POLYGON);
    if (isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.5f, 0.0f, 0.0f);

    glVertex2i(110,145);
    glVertex2i(121,168);
    glVertex2i(170,168);
    glVertex2i(190,145);

    glEnd();


    glBegin(GL_QUADS);//////////glass///////
    if (isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glVertex2i(123,150);
    glVertex2i(123,162);
    glVertex2i(145,162);
    glVertex2i(145,150);
    glEnd();


    glBegin(GL_QUADS);/////////////////
    if (isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);
    glVertex2i(125,152);
    glVertex2i(125,160);
    glVertex2i(143,160);
    glVertex2i(143,152);
    glEnd();


    glBegin(GL_QUADS);//////////glass///////
    if (isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glVertex2i(152,151);
    glVertex2i(152,162);
    glVertex2i(168,162);
    glVertex2i(177,151);
    glEnd();


    glBegin(GL_QUADS);/////////////////
    if (isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    glVertex2i(154,149);
    glVertex2i(154,160);
    glVertex2i(166,160);
    glVertex2i(175,149);
    glEnd();


    //first car chakka//
    if (isDay)
        glColor3f(0.34f, 0.34f, 0.34f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    halfCircle(125,125,10);


    if (isDay)
        glColor3f(0.0f, 0.0f, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    circle(125,125,9);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(125,125,3);

    if (isDay)
        glColor3f(0.34f, 0.34f, 0.34f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    circle(175,125,10);


    if (isDay)
        glColor3f(0.0f, 0.0f, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    circle(175,125,9);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(175,125,3);

    glPopMatrix();
}
void updateCar(int value)
{
    if(!carPaused){

         moveCar += carSpeed+1;
    if (moveCar > 900)
    {
        moveCar = -350;
    }

    glutPostRedisplay();
    }

    glutTimerFunc(10, updateCar, 0);
}

void keyboardInput(unsigned char key, int x, int y)
{
    if (key == 'd' || key == 'D')
    {
        isDay = true;
        glutPostRedisplay();
    }

    if(key == 'n' || key == 'N')
    {
        isDay = false;
        glutPostRedisplay();
    }
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    sky();
    moon();
    sun();
    V_cloud1();
    V_cloud2();
    V_cloud4();
    building();
    garden();
    road();
    roadSideWall();
    bus();
    car(); //RED
    cargoTruck();
    blueCar();

    glFlush();
    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 700);
    glutCreateWindow("City Scene Animation");
    glClearColor(0.37f, 0.82f, 0.94f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glutKeyboardFunc(keyboardInput);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 700);

    glutDisplayFunc(display);

    // Register timers
    glutTimerFunc(0, updateSun, 0);
    glutTimerFunc(0, updateMoon, 0);
    glutTimerFunc(0, V_updateCloud1, 0);
    glutTimerFunc(0, V_updateCloud2, 0);
    glutTimerFunc(0, V_updateCloud4, 0);
    glutTimerFunc(0, V_updateBus, 0);
    glutTimerFunc(0, updateCar, 0); //RED
    glutTimerFunc(0, V_updateCargo, 0);
    glutTimerFunc(0, V_updateBlueCar, 0);

    glutMainLoop();
    return 0;
}

