#include "src\SandboxGame\Window\SandboxWindow.h"
#include <iostream>
#include <vector>
#include "src\Engine\Model\ShapeGenerator.h"
#include "src\Engine\Math\GLMath.h"
#include "src\Engine\Model\OBJFile.h"
#include "src\Engine\Entities\TexturedModelEntity.h"
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


	scene.setProjectionMatrix(GLMath::createProjectionMatrix(settings.eng.FOV, (float)(width()) / (float)(height()), settings.eng.FAR_PLANE, settings.eng.NEAR_PLANE));
	scene.assignCamera(camera);
	renderer.assignScene(scene);

	connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
	timer.start(1000 / settings.eng.MAX_FPS);

	model = ShapeGenerator::create_colored_triangle();
	model2 = ShapeGenerator::create_textured_triangle();

	OBJFile cat;
	cat.modelPath = "res/models/test.obj";
	cat.texturePath = "res/texture/M9.png";
	cat.textureWidth = 512;
	cat.textureHeight = 1024;

	OBJFile dragon;
	dragon.modelPath = "res/models/dragon2.obj";
	model2 = ShapeGenerator::loadTexturedModelOBJFile(cat);
	//model = ShapeGenerator::loadColoredModelOBJFile(dragon);

	loader.processModel(&model2);


	loader.load();

	TexturedModelEntity entity = TexturedModelEntity(&model2,vec3(0.0,0.0,0.0),vec3(0.0,0.0,0.0),vec3(0.05,0.05,0.05));
	renderer.processEntity(entity);

}

void SandboxWindow::paintGL(){

	glViewport(0, 0, width(), height());
	
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
	if(GetAsyncKeyState('W')){
		camera.cameraTranslate(glm::vec2(0.0, -0.01));

	}
	if (GetAsyncKeyState('S')){
		camera.cameraTranslate(glm::vec2(0.0, +0.01));
	}
	if (GetAsyncKeyState('A')){
		camera.cameraTranslate(glm::vec2(0.01, 0.0));
	}
	if (GetAsyncKeyState('D')){
		camera.cameraTranslate(glm::vec2(-0.01, 0.0));
	}
	if (GetAsyncKeyState(VK_LEFT)){
		camera.cameraRotateY(0.5f);
	}
	if (GetAsyncKeyState(VK_RIGHT)){
		camera.cameraRotateY(-0.5f);
	}
	if (GetAsyncKeyState(VK_UP)){
		camera.cameraRotateX(+0.5f);
	}
	if (GetAsyncKeyState(VK_DOWN)){
		camera.cameraRotateX(-0.5f);
	}
	if (GetAsyncKeyState('Q')){
		camera.cameraZoom(+0.05f);
	}
	if (GetAsyncKeyState('E')){
		camera.cameraZoom(-0.05f);
	}
}

//deconstrutor: ColoredModelRenderer.cleanup();