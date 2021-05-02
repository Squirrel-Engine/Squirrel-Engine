#include "SkeletalMesh.h"



SkeletalMesh::SkeletalMesh(vector<Vertex> vertic, vector<GLuint> ind, vector<Texture> textur, vector<VertexBoneData> bone_id_weights)
{
	vertices = vertic;
	indices = ind;
	textures = textur;
	bones_id_weights_for_each_vertex = bone_id_weights;

	// Now that we have all the required data, set the vertex buffers and its attribute pointers.
	SetupMesh();
}


SkeletalMesh::~SkeletalMesh()
{
	//cout << "									 Mesh::~Mesh() " << endl;
	//glDeleteBuffers(1, &VBO_vertices);
	//glDeleteBuffers(1, &VBO_bones);
	//glDeleteBuffers(1, &EBO_indices);
	//glDeleteVertexArrays(1, &VAO);
}

void VertexBoneData::addBoneData(uint bone_id, float weight)
{
	for (uint i = 0; i < NUM_BONES_PER_VEREX; i++)
	{
		if (weights[i] == 0.0)
		{
			ids[i] = bone_id;
			weights[i] = weight;
			return;
		}
	}
}


void SkeletalMesh::Draw(GLuint shaders_program)
{
	int diffuse_nr = 1;
	int specular_nr = 1;

	for (int i = 0; i < textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);

		string number;
		string name = textures[i].type;
		if (name == "texture_diffuse")
		{
			number = to_string(diffuse_nr++);
		}
		else if (name == "texture_specular")
		{
			number = to_string(specular_nr++);
		}

		glBindTexture(GL_TEXTURE_2D, textures[i].id);
		glUniform1i(glGetUniformLocation(shaders_program, ("material." + name + number).c_str()), i);

		//cout << "added in shader : " << ("material." + name + number).c_str() << endl;
	}

	//glUniform1f(glGetUniformLocation(shaders_program, "material.shininess"), 32.0f);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glLineWidth(2);
	//Draw
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	for (int i = 0; i < textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

void SkeletalMesh::SetupMesh()
{
	//vertices data
	glGenBuffers(1, &VBO_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_vertices);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//bones data
	glGenBuffers(1, &VBO_bones);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_bones);
	glBufferData(GL_ARRAY_BUFFER, bones_id_weights_for_each_vertex.size() * sizeof(bones_id_weights_for_each_vertex[0]), &bones_id_weights_for_each_vertex[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//numbers for sequence indices
	glGenBuffers(1, &EBO_indices);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_indices);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// create VAO and binding data from buffers to shaders
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_vertices);
	//vertex position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	glEnableVertexAttribArray(1); // offsetof(Vertex, normal) = returns the byte offset of that variable from the start of the struct
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, text_coords));
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//bones
	glBindBuffer(GL_ARRAY_BUFFER, VBO_bones);
	glEnableVertexAttribArray(3);
	glVertexAttribIPointer(3, 4, GL_INT, sizeof(VertexBoneData), (GLvoid*)0); // for INT Ipointer
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(VertexBoneData), (GLvoid*)offsetof(VertexBoneData, weights));
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//indices
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_indices);
	glBindVertexArray(0);
}