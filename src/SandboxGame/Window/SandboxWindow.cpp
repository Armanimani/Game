#include "src\SandboxGame\Window\SandboxWindow.h"
#include <iostream>
#include <vector>
#include "src\Engine\Model\ShapeGenerator.h"
using std::vector;
using glm::vec3;

bool SandboxWindow::initialize(){

	bool state;
	state = clock.initialize();
	if (state != true){

		qDebug() << "failed to initialize clock";
		return state;
	}

	


	return true;
}

bool SandboxWindow::shutdown(){

	bool state;
	state = clock.shutdown();
	if (state != true){

		qDebug() << "failed to shutdown clock";
		return state;
	}

	return true;
}

void SandboxWindow::initializeGL(){
	
	glewInit();
	renderer.initialize();

	connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
	timer.start(1000 / settings.eng.MAX_FPS);

	model = ShapeGenerator::create_colored_triangle();
	model2 = ShapeGenerator::create_textured_triangle();
	loader.processModel(&model2);

	loader.load();

	ModelEntity entity = ModelEntity(&model2,2,vec3(0.2,0.2,0.0),vec3(0.0,0.0,0.0),vec3(0.1,0.1,0.1));
	renderer.processEntity(entity);

}

void SandboxWindow::paintGL(){

	glViewport(0, 0, width(), height());
	renderer.prepare();
	
	renderer.render();

}

void SandboxWindow::update(){

	clock.newFrame();
	checkKeyState();
	repaint();
}

void SandboxWindow::checkKeyState(){

	if (GetAsyncKeyState(VK_ESCAPE)){
		close();
	}
}


//deconstrutor: ModelRenderer.cleanup();