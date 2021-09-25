#include <HeaderFiles/main.h>

int main()
{
	// Checks if initialization of glfw was successfull
	if (glfwInit() == GLFW_FALSE)
	{
		std::cout << "Error initializing GLFW!\n";
		return -1;
	}

	// Sets version of OpenGL and backwards compatibility
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Creates a window and checks if the window was created successfully
	GLFWwindow* Window = glfwCreateWindow(windowWidth, windowHeight, "Vyrgine", NULL, NULL);
	if (Window == NULL)
	{
		std::cout << "Error creating window.\n";
		glfwTerminate();
		return -1;
	}

	glfwSetFramebufferSizeCallback(Window, framebuffer_size_callback);

	glfwMakeContextCurrent(Window);

	// Makes sure GLAD was initialized successfully
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// Creates a VertexShader, FragmentShader and a ShaderProgram that then links both of these progams together
	Shader newShader("Shaders/vertexShader.vs", "Shaders/fragmentShader.frs");

	// First two arguments specify the lower left corner of the viewport rectangle in pixels the rest sets the viewport width and height
	glViewport(0, 0, windowWidth, windowHeight);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	srand(seed);

	// Holds information about each vertex. later can hold colors atd.

	std::vector<glm::vec3> verticies;

	VAO newVAO;
	VBO newVBO;
	EBO newEBO;

	std::vector<unsigned int> indicies;
	GenerateTriangle(newVAO, newVBO, newEBO, verticies, indicies);

	InitImGui(Window);

	while (!glfwWindowShouldClose(Window))
	{
		processInput(Window);
		glfwSwapBuffers(Window);
		glClearColor(0.1f, 0.2f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::Begin("OpenGL ImGui");

		newShader.use();

		glm::mat4 proj = glm::mat4(1.0f);
		proj = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 100.f);
		newShader.setMat4("proj", proj);

		glm::mat4 translateMove = glm::mat4(1.0f);
		translateMove = glm::translate(translateMove, glm::vec3(0.0f, 0.0f, -10.f));
		translateMove = glm::rotate(translateMove, (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
		newShader.setMat4("translateMove", translateMove);

		if (ImGui::Button("Generate Triangle"))
		{
			GenerateTriangle(newVAO, newVBO, newEBO, verticies, indicies);
		}

		ImGui::Checkbox("Draw Triangle?", &bDrawTriangle);
		ImGui::ColorEdit4("Color RGBA:", color);
		ImGui::SliderFloat3("Size: ", sizeMultipe, 1.0f, 2.0f);
		ImGui::End();

		newShader.setVec4("color", color);
		newShader.setVec3("size", sizeMultipe);

		if (bDrawTriangle)
		{
			newVAO.Bind();
			newEBO.Bind();
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
			newEBO.UnBind();
			newVAO.UnBind();
		}

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwPollEvents();
	}
	// Clean up the buffers and terminate GLFW
	newEBO.Delete();
	newVBO.Delete();
	newVAO.Delete();
	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	aspectRatio = (float)width / (float)height;
}

std::vector<glm::vec3> trinagleVertices(float radius)
{
	glm::vec3 test = glm::vec3(1.0f);
	std::vector<glm::vec3> vectorArray;
	glm::vec3 centerCircle = glm::vec3(0.0f, 0.0f ,0.0f);
	float angle = 0.0f;
	for (int i = 0; i < 3; i++)
	{
		angle += rand() % 20 + 20;
		glm::vec3 circleVector = glm::vec3(glm::cos(angle) * radius, glm::sin(angle), 0.0f);
		glm::vec3 finalVector = centerCircle + circleVector;
		vectorArray.push_back(finalVector);
	}
	return vectorArray;
}

void GenerateTriangle(VAO newVAO, VBO newVBO, EBO newEBO,std::vector<glm::vec3> &vertices, std::vector<unsigned int> indicies)
{
	vertices = trinagleVertices(rand() % 5 + 1);
	indicies = GenerateIndicies(vertices);
	newVAO.Bind();

	newVBO.Bind();	
	newVBO.BindBufferData(vertices.size() * sizeof(glm::vec3), vertices);

	newEBO.Bind();
	newEBO.BindBufferData(indicies);

	newVAO.LinkVBO(0, 0, (void*)0);



	newEBO.UnBind();
	newVBO.UnBind();
	newVAO.UnBind();
}

void InitImGui(GLFWwindow* window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
	ImGui::StyleColorsDark();
}

std::vector<unsigned int> GenerateIndicies(std::vector<glm::vec3> vertices)
{
	std::vector<unsigned int> arr;
	for(int i = 0; i < vertices.size(); i++)
	{
		arr.push_back(i);
	}
	return arr;
}
