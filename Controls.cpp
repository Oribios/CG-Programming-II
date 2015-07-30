//Controls.cpp
//////////////////////////////////////

#include "Application.h";
#include "Controls.h";

glm::vec3 position = glm::vec3(0, 0, 5);
glm::vec3 direction = glm::vec3(0, 0, 0);
glm::vec3 rightV = glm::vec3(0, 0, 0);
glm::vec3 up = glm::vec3(0, 0, 0);

// horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// vertical angle : 0, look at the horizon
float verticalAngle = 0.0f;
// Initial Field of View
float initialFoV = 45.0f;

float speed = 3.0f; // 3 units / second
float mouseSpeed = 0.05f;
double xpos, ypos;

void getMousePosition(){
	glfwGetCursorPos(window, &xpos, &ypos);
	glfwSetCursorPos(window, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
}
void computeNewOrientation(){
	horizontalAngle += mouseSpeed * deltaTime * float(1024/2 - xpos);
	verticalAngle   += mouseSpeed * deltaTime * float( 768/2 - ypos );
}
void movementControls(){
	if (glfwGetKey(window, GLFW_KEY_UP ) == GLFW_PRESS){
		position += direction * deltaTime * speed;
	}
	// Move backward
	if (glfwGetKey(window, GLFW_KEY_DOWN ) == GLFW_PRESS){
		position -= direction * deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey(window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
		position += rightV * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey(window, GLFW_KEY_LEFT ) == GLFW_PRESS){
		position -= rightV * deltaTime * speed;
	}
}
void computeForwardVector() {
	getMousePosition();
	computeNewOrientation();
	movementControls();
	direction = vec3(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle));

	rightV = vec3(
		sin(horizontalAngle - 3.14f/2.0f),
		0,
		cos(horizontalAngle - 3.14f/2.0f));
	up = glm::cross(rightV, direction);
}


