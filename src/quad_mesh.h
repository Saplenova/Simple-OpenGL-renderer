#pragma once

class QuadMesh {
public:
QuadMesh();
void draw();
~QuadMesh();

private:
unsigned int EBO, VBO, VAO, vertex_count;
};