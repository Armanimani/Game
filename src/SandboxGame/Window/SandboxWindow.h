#pragma once

#include <GL\glew.h>
#include <QtOpenGL\qglwidget>
#include <QtCore\qtimer.h>
#include "src\Engine\Tming\Clock.h"
#include <QtCore\qdebug.h>
#include "src\SandboxGame\Settings\SanboxSettings.h"
#include "src\Engine\Loader\Loader.h"
#include "src\Engine\Renderer\Renderer.h"
#include "src\Engine\Model\Model.h"
#include "src\Engine\Model\TexturedModel.h"
#include "src\Engine\Entities\ModelEntity.h"

class SandboxWindow : public QGLWidget{

	Q_OBJECT

public:

	bool initialize();
	bool shutdown();

protected:

	void initializeGL();
	void paintGL();

private:

	SandboxSettings settings;

	Loader loader;
	Renderer renderer;
	ColoredModel model;
	TexturedModel model2;
	Camera camera;

	QTimer timer;
	Clock clock;

	void checkKeyState();

private slots:

	void update();
};