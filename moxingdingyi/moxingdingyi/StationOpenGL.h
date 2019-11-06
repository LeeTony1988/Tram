#pragma once

#include <GL/glut.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<math.h>
#define MAX_CHAR 128



using namespace System::Windows::Forms;

namespace StationOpenGLForm
{
	public ref class StationCOpenGL : public System::Windows::Forms::NativeWindow
	{
	public:
		//�������ڵĴ���
		StationCOpenGL(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight)

		{
			CreateParams^ cp = gcnew CreateParams;

			// ����λ�� �� ��
			cp->X = 0;
			cp->Y = 0;
			cp->Height = iHeight;
			cp->Width = iWidth;

			// Specify the form as the parent.
			cp->Parent = parentForm->Handle;

			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			// Create the actual window
			this->CreateHandle(cp);

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			if (m_hDC)
			{
				//�������ڳɹ��� ��ʼ�����ڵĴ���
				MySetPixelFormat(m_hDC);//���ô������ظ�ʽ
				ReSizeGLScene(iWidth, iHeight);
				InitGL();
			}
		}

		//ʹ��opengl��������
		void drawString(const char* str) {
			static int isFirstCall = 1;
			static GLuint lists;
			if (isFirstCall) { // ����ǵ�һ�ε��ã�ִ�г�ʼ��
								// Ϊÿһ��ASCII�ַ�����һ����ʾ�б�
				isFirstCall = 0;

				// ����MAX_CHAR����������ʾ�б���
				lists = glGenLists(MAX_CHAR);

				// ��ÿ���ַ��Ļ������װ����Ӧ����ʾ�б���
				wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
			}
			// ����ÿ���ַ���Ӧ����ʾ�б�����ÿ���ַ�
			for (; *str != '\0'; ++str)
				glCallList(lists + *str);
		}
		//ѡ������
		void selectFont(int size, int charset, const char* face) {
			HFONT hFont = CreateFontA(size, 0, 0, 0, FW_MEDIUM, 0, 0, 0,
				charset, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
				DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, face);
			HFONT hOldFont = (HFONT)SelectObject(wglGetCurrentDC(), hFont);
			DeleteObject(hOldFont);
		}
		// ����ǰ����������wglUseFontBitmaps������������ʾ�����ַ��ˡ�
		void drawCNString(const char* str) {
			int len, i;
			wchar_t* wstring;
			HDC hDC = wglGetCurrentDC();
			GLuint list = glGenLists(1);

			// �����ַ��ĸ���
			// �����˫�ֽ��ַ��ģ����������ַ����������ֽڲ���һ���ַ�
			// ����һ���ֽ���һ���ַ�
			len = 0;
			for (i = 0; str[i] != '\0'; ++i)
			{
				if (IsDBCSLeadByte(str[i]))
					++i;
				++len;
			}

			// ������ַ�ת��Ϊ���ַ�
			wstring = (wchar_t*)malloc((len + 1) * sizeof(wchar_t));
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str, -1, wstring, len);
			wstring[len] = L'\0';

			// �������ַ�
			for (i = 0; i < len; ++i)
			{
				wglUseFontBitmapsW(hDC, wstring[i], 1, list);
				glCallList(list);
			}

			// ����������ʱ��Դ
			free(wstring);
			glDeleteLists(list, 1);
		}
		
		const GLfloat Pi = 3.14159f;
		const GLfloat R = 0.018f;
		const int n = 100;
		int i;
		const int winWidth=500, winHeight=500;

		System::Void Render(System::Void)
		{
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
			// Clear screen and depth buffer
			glLoadIdentity();									// Reset the current modelview matrix
			glTranslatef(-0.25f, 0.25f, -2.0f);						// Move left 1.5 units and into the screen 6.0
			
			//���ƴ��룬ע������ά���꣬z���궼����Ϊ0����
			//��������ģʽ
			//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glClear(GL_COLOR_BUFFER_BIT);

			glEnable(GL_LINE_STIPPLE);//��ʼ������
			glColor3f(0.0f, 0.5f, 0.5f); //������ɫ
			glLineStipple(1, 0x0F0F);
			glLineWidth(2.0f);
			glBegin(GL_LINES);
			glVertex2f(-0.7f, 0.2f);//�������꣬���
			glVertex2f(0.6f, 0.2f);//�������꣬�Ҷ�
			glEnd();

			glEnable(GL_LINE_STIPPLE);//��ʼ������
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ����ɫ
			glLineStipple(1, 0x0F0F);
			glLineWidth(2.0f);
			glBegin(GL_LINES);
			glVertex2f(-0.7f, -0.2f);//�������꣬���
			glVertex2f(0.6f, -0.2f);//�������꣬�Ҷ�
			glEnd();

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(-0.7+R*cos(2 * Pi / n * i), +0.2+R*sin(2 * Pi / n * i));//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) - 0.6, R*sin(2 * Pi / n * i) + 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) - 0.5, R*sin(2 * Pi / n * i) + 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) - 0.4, R*sin(2 * Pi / n * i) + 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) - 0.3, R*sin(2 * Pi / n * i) + 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) - 0.2, R*sin(2 * Pi / n * i) + 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) - 0.1, R*sin(2 * Pi / n * i) + 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) + 0.0, R*sin(2 * Pi / n * i) + 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) + 0.1, R*sin(2 * Pi / n * i) + 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) + 0.2, R*sin(2 * Pi / n * i) + 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) + 0.3, R*sin(2 * Pi / n * i) + 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) + 0.4, R*sin(2 * Pi / n * i) + 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) + 0.5, R*sin(2 * Pi / n * i) + 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) + 0.6, R*sin(2 * Pi / n * i) + 0.2);//Բ������
			glEnd();//������Ⱦ



			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) - 0.7, R*sin(2 * Pi / n * i) - 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) - 0.6, R*sin(2 * Pi / n * i) - 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) - 0.5, R*sin(2 * Pi / n * i) - 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) - 0.4, R*sin(2 * Pi / n * i) - 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) - 0.3, R*sin(2 * Pi / n * i) - 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) - 0.2, R*sin(2 * Pi / n * i) - 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(-0.1+R*cos(2 * Pi / n * i) , R*sin(2 * Pi / n * i) - 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) + 0.0, R*sin(2 * Pi / n * i) - 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) + 0.1, R*sin(2 * Pi / n * i) - 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) + 0.2, R*sin(2 * Pi / n * i) - 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) + 0.3, R*sin(2 * Pi / n * i) - 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) + 0.4, R*sin(2 * Pi / n * i) - 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) + 0.5, R*sin(2 * Pi / n * i) - 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			//glColor3f(0.0f, 0.0f, 0.0f); //������ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) + 0.6, R*sin(2 * Pi / n * i) - 0.2);//Բ������
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			glColor3f(1.0f, 0.0f, 0.0f); //������ɫ����ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) + t - 0.7, R*sin(2 * Pi / n * i) + 0.2);
			glEnd();//������Ⱦ

			glBegin(GL_POLYGON);//��ʼ��Բ
			glColor3f(1.0f, 0.0f, 0.0f); //������ɫ����ɫ
			for (i = 0; i < n; ++i)//��ʼ��Բ
				glVertex2f(R*cos(2 * Pi / n * i) + t - 0.7, R*sin(2 * Pi / n * i) - 0.2);
			glEnd();//������Ⱦ
			
			
			selectFont(12, GB2312_CHARSET, "����_GB2312");
			glColor3f(0.0f, 0.0f, 0.0f);
			
			glRasterPos2f(-0.745, 0.1);
			drawCNString(" �� ");
			glRasterPos2f(-0.745, 0.05);
			drawCNString(" �� ");
			glRasterPos2f(-0.745, 0.0);
			drawCNString(" С ");
			glRasterPos2f(-0.745, -0.05);
			drawCNString(" �� ");
			//
			glRasterPos2f(-0.645, 0.1);
			drawCNString(" �� ");
			glRasterPos2f(-0.645, 0.05);
			drawCNString(" �� ");
			glRasterPos2f(-0.645, 0.0);
			drawCNString(" �� ");
			glRasterPos2f(-0.645, -0.05);
			drawCNString(" ԰ ");
			//
			glRasterPos2f(-0.545, 0.1);
			drawCNString(" �� ");
			glRasterPos2f(-0.545,0.05);
			drawCNString(" �� ");
			glRasterPos2f(-0.545, -0.00);
			drawCNString(" · ");
			glRasterPos2f(-0.545, -0.05);
			drawCNString(" �� ");
			//
			glRasterPos2f(-0.445, 0.1);
			drawCNString(" �� ");
			glRasterPos2f(-0.445, 0.05);
			drawCNString(" �� ");
			glRasterPos2f(-0.445, 0.0);
			drawCNString(" һ ");
			glRasterPos2f(-0.445, -0.05);
			drawCNString(" �� ");
			//
			glRasterPos2f(-0.345,0.1);
			drawCNString(" ÷ ");
			glRasterPos2f(-0.345,0.05);
			drawCNString(" �� ");
			glRasterPos2f(-0.345,0.0);
			drawCNString(" �� ");
			glRasterPos2f(-0.345, -0.05);
			drawCNString(" · ");
			//
			glRasterPos2f(-0.245, 0.1);
			drawCNString(" �� ");
			glRasterPos2f(-0.245, 0.05);
			drawCNString(" ɽ ");
			glRasterPos2f(-0.245,0);
			drawCNString(" �� ");
			glRasterPos2f(-0.245, -0.05);
			drawCNString(" վ ");
			//
			glRasterPos2f(-0.145, 0.1);
			drawCNString(" ӭ ");
			glRasterPos2f(-0.145,0.05);
			drawCNString(" �� ");
			glRasterPos2f(-0.145, 0.0);
			drawCNString(" · ");
			glRasterPos2f(-0.145, -0.05);
			drawCNString(" �� ");
			glRasterPos2f(-0.145,-0.1);
			drawCNString(" �� ");
			//
			glRasterPos2f(-0.045,0.1);
			drawCNString(" �� ");
			glRasterPos2f(-0.045, 0.05);
			drawCNString(" Ԫ ");
			glRasterPos2f(-0.045, 0.0);
			drawCNString(" �� ");
			glRasterPos2f(-0.045,-0.05);
			drawCNString(" �� ");
			glRasterPos2f(-0.045,-0.1);
			drawCNString(" �� ");
			//
			glRasterPos2f(0.055,0.1);
			drawCNString(" �� ");
			glRasterPos2f(0.055, 0.05);
			drawCNString(" ҵ ");
			glRasterPos2f(0.055,0.0);
			drawCNString(" · ");
			glRasterPos2f(0.055, -0.05);
			drawCNString(" �� ");
			//
			glRasterPos2f(0.155,0.1);
			drawCNString(" �� ");
			glRasterPos2f(0.155, 0.05);
			drawCNString(" �� ");
			glRasterPos2f(0.155,0.0);
			drawCNString(" ɽ ");
			//
			glRasterPos2f(0.255,0.1);
			drawCNString(" ÷ ");
			glRasterPos2f(0.255,0.05);
			drawCNString(" �� ");
			glRasterPos2f(0.255, 0.0);
			drawCNString(" �� ");
			glRasterPos2f(0.255,-0.05);
			drawCNString(" · ");
			//
			glRasterPos2f(0.355, 0.1);
			drawCNString(" �� ");
			glRasterPos2f(0.355, 0.05);
			drawCNString(" �� ");
			glRasterPos2f(0.355,0.0);
			drawCNString(" ʯ ");
			glRasterPos2f(0.355, -0.05);
			drawCNString(" �� ");
			//
			glRasterPos2f(0.455, 0.1);
			drawCNString(" �� ");
			glRasterPos2f(0.455,0.05);
			drawCNString(" �� ");
			glRasterPos2f(0.455, 0.0);
			drawCNString(" �� ");
			glRasterPos2f(0.455,-0.05);
			drawCNString(" Ժ ");
			//
			glRasterPos2f(0.555, 0.1);
			drawCNString(" ˮ ");
			glRasterPos2f(0.555, 0.05);
			drawCNString(" ӵ ");
			glRasterPos2f(0.555,0.0);
			drawCNString(" �� ");

			
			timerFunc();

			//glFlush();
		

			//�Լ�����
			//����Ҫ˫���庯����������Ѿ�������
		}

		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC);
		}
		//����
		System::Void timerFunc()
		{
			if (t < 1.3)
				t = t + 0.1;
			else
				t = 0;
			//glutPostRedisplay();
		}
		//��ʲô�ã���
			System::Void myInit()
		{
			glClearColor(1.0, 1.0, 1.0, 0.0);
			glColor3f(0.0f, 0.0f, 0.0f);
			glPointSize(25.0);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluOrtho2D(0.0, 640, 0.0, 480);
		}
			
	private:
		HDC m_hDC;
		HGLRC m_hglrc;
		//����һЩ������λ��
		GLfloat t;


	protected:
		~StationCOpenGL(System::Void)
		{
			this->DestroyHandle();
		}
		//���ô������ظ�ʽ
		GLint MySetPixelFormat(HDC hdc)
		{
			static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
			{
				sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
				1,											// Version Number
				PFD_DRAW_TO_WINDOW |						// Format Must Support Window
				PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
				PFD_DOUBLEBUFFER,							// Must Support Double Buffering
				PFD_TYPE_RGBA,								// Request An RGBA Format
				16,										// Select Our Color Depth
				0, 0, 0, 0, 0, 0,							// Color Bits Ignored
				0,											// No Alpha Buffer
				0,											// Shift Bit Ignored
				0,											// No Accumulation Buffer
				0, 0, 0, 0,									// Accumulation Bits Ignored
				16,											// 16Bit Z-Buffer (Depth Buffer)  
				0,											// No Stencil Buffer
				0,											// No Auxiliary Buffer
				PFD_MAIN_PLANE,								// Main Drawing Layer
				0,											// Reserved
				0, 0, 0										// Layer Masks Ignored
			};

			GLint  iPixelFormat;

			// get the device context's best, available pixel format match 
			if ((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}

			// make that match the device context's current pixel format 
			if (SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}

			if ((m_hglrc = wglCreateContext(m_hDC)) == NULL)
			{
				MessageBox::Show("wglCreateContext Failed");
				return 0;
			}

			if ((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return 0;
			}


			return 1;
		}

		//��ʼ��OPENGL����
		bool InitGL(GLvoid)										// All setup for opengl goes here
		{
			glShadeModel(GL_SMOOTH);							// Enable smooth shading
			glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// ���ڱ���ɫ
			glClearDepth(1.0f);									// Depth buffer setup
			glEnable(GL_DEPTH_TEST);							// Enables depth testing
			glDepthFunc(GL_LEQUAL);								// The type of depth testing to do
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really nice perspective calculations
			return TRUE;										// Initialisation went ok
		}

		GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize and initialise the gl window
		{
			if (height == 0)										// Prevent A Divide By Zero By
			{
				height = 1;										// Making Height Equal One
			}

			glViewport(0, 0, width, height);						// Reset The Current Viewport

			glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
			glLoadIdentity();									// Reset The Projection Matrix

			// Calculate The Aspect Ratio Of The Window
			gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

			glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
			glLoadIdentity();									// Reset The Modelview Matrix
		}
	};
}